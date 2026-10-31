// SPDX-License-Identifier: GPL-3.0-or-later
#pragma once

#include <QApplication>
#include <QAction>
#include <QFile>
#include <QLabel>
#include <QMainWindow>
#include <QPalette>
#include <QPushButton>
#include <QRegularExpression>
#include <QToolBar>
#include <QToolButton>
#include <QTranslator>

class FenixTranslator final : public QTranslator {
public:
    using QTranslator::QTranslator;

    bool isEmpty() const override { return false; }

    QString translate(const char* context, const char* source, const char* disambiguation = nullptr,
                      int n = -1) const override {
        QString text = QTranslator::translate(context, source, disambiguation, n);
        if (text.isEmpty()) {
            const QString original = QString::fromUtf8(source);
            if (!original.contains(QStringLiteral("eden"), Qt::CaseInsensitive)) {
                return {};
            }
            text = original;
        }
        // Product wording is independent of translation contexts and persisted setting keys.
        if (text.contains(QStringLiteral("eden"), Qt::CaseInsensitive)) {
            text.remove(QRegularExpression(QStringLiteral("<a\\s+[^>]*href=[\"'][^\"']*eden[^\"']*[\"'][^>]*>"),
                                           QRegularExpression::CaseInsensitiveOption));
            text.replace(QRegularExpression(QStringLiteral("\\bEden\\b"),
                                            QRegularExpression::CaseInsensitiveOption),
                         QStringLiteral("Fenix Emulator"));
        }
        return text;
    }
};

namespace FenixUI {

inline void ApplyTheme() {
    QPalette palette;
    palette.setColor(QPalette::Window, QColor(QStringLiteral("#101722")));
    palette.setColor(QPalette::WindowText, QColor(QStringLiteral("#e5eaf3")));
    palette.setColor(QPalette::Base, QColor(QStringLiteral("#111c2a")));
    palette.setColor(QPalette::AlternateBase, QColor(QStringLiteral("#162232")));
    palette.setColor(QPalette::Text, QColor(QStringLiteral("#e5eaf3")));
    palette.setColor(QPalette::Button, QColor(QStringLiteral("#223147")));
    palette.setColor(QPalette::ButtonText, QColor(QStringLiteral("#e5eaf3")));
    palette.setColor(QPalette::Highlight, QColor(QStringLiteral("#366c65")));
    palette.setColor(QPalette::HighlightedText, QColor(QStringLiteral("#ffffff")));
    palette.setColor(QPalette::Link, QColor(QStringLiteral("#80dcca")));
    qApp->setPalette(palette);
    QFile stylesheet(QStringLiteral(":/fenix/style.qss"));
    if (stylesheet.open(QFile::ReadOnly)) {
        qApp->setStyleSheet(QString::fromUtf8(stylesheet.readAll()));
    }
}

inline void InstallShell(QMainWindow* window, QAction* open, QAction* configure,
                         QAction* about, QAction* fullscreen, QAction* add_directory) {
    window->setWindowIcon(QIcon(QStringLiteral(":/img/fenix.ico")));
    auto* header = new QToolBar(window);
    header->setObjectName(QStringLiteral("FenixHeader"));
    header->setMovable(false);
    header->setFloatable(false);
    header->setContextMenuPolicy(Qt::PreventContextMenu);
    auto* mark = new QLabel(header);
    mark->setPixmap(QIcon(QStringLiteral(":/img/fenix.ico")).pixmap(48, 48));
    mark->setContentsMargins(18, 10, 12, 10);
    header->addWidget(mark);
    auto* title = new QLabel(QStringLiteral("<b style='font-size:20px;letter-spacing:3px'>FENIX</b>"
                                           "<br><span style='color:#8d9db7;font-size:10px'>EMULATOR / 0.0.1</span>"), header);
    header->addWidget(title);
    auto* space = new QWidget(header);
    space->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    header->addWidget(space);
    auto* launch = new QPushButton(QStringLiteral("Abrir juego"), header);
    launch->setObjectName(QStringLiteral("FenixPrimary"));
    QObject::connect(launch, &QPushButton::clicked, open, &QAction::trigger);
    header->addWidget(launch);
    auto* margin = new QWidget(header);
    margin->setFixedWidth(20);
    header->addWidget(margin);
    window->addToolBar(Qt::TopToolBarArea, header);

    auto* rail = new QToolBar(window);
    rail->setObjectName(QStringLiteral("FenixNavigation"));
    rail->setMovable(false);
    rail->setFloatable(false);
    rail->setContextMenuPolicy(Qt::PreventContextMenu);
    rail->setFixedWidth(192);
    auto* section = new QLabel(QStringLiteral("TU ESPACIO"), rail);
    section->setObjectName(QStringLiteral("FenixEyebrow"));
    section->setContentsMargins(20, 26, 12, 16);
    rail->addWidget(section);
    auto* library = new QLabel(QStringLiteral("  Biblioteca"), rail);
    library->setObjectName(QStringLiteral("FenixLibrary"));
    library->setMinimumHeight(44);
    rail->addWidget(library);
    const auto button = [rail](const QString& text, QAction* action) {
        auto* item = new QToolButton(rail);
        item->setText(text);
        item->setToolButtonStyle(Qt::ToolButtonTextOnly);
        item->setMinimumSize(176, 44);
        QObject::connect(item, &QToolButton::clicked, action, &QAction::trigger);
        QObject::connect(action, &QAction::changed, item, [item, action] {
            item->setEnabled(action->isEnabled());
        });
        item->setEnabled(action->isEnabled());
        rail->addWidget(item);
    };
    button(QStringLiteral("+  Añadir carpeta"), add_directory);
    rail->addSeparator();
    auto* options = new QLabel(QStringLiteral("PREFERENCIAS"), rail);
    options->setObjectName(QStringLiteral("FenixEyebrow"));
    options->setContentsMargins(20, 18, 12, 12);
    rail->addWidget(options);
    button(QStringLiteral("Configuración"), configure);
    button(QStringLiteral("Pantalla completa"), fullscreen);
    auto* stretch = new QWidget(rail);
    stretch->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
    rail->addWidget(stretch);
    button(QStringLiteral("Acerca de Fenix"), about);
    auto* footer = new QLabel(QStringLiteral("FENIX  /  0.0.1"), rail);
    footer->setObjectName(QStringLiteral("FenixEyebrow"));
    footer->setContentsMargins(20, 12, 12, 20);
    rail->addWidget(footer);
    window->addToolBar(Qt::LeftToolBarArea, rail);
}

inline void SetLibraryVisible(QMainWindow* window, bool visible) {
    for (const auto& name : {QStringLiteral("FenixHeader"), QStringLiteral("FenixNavigation")}) {
        if (auto* toolbar = window->findChild<QToolBar*>(name)) {
            toolbar->setVisible(visible);
        }
    }
}

} // namespace FenixUI
