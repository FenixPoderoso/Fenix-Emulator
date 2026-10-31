// SPDX-FileCopyrightText: Copyright 2026 Eden Emulator Project
// SPDX-License-Identifier: GPL-3.0-or-later

// SPDX-FileCopyrightText: Copyright 2018 yuzu Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later


#include <QDialogButtonBox>
#include <QIcon>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include "ui_aboutdialog.h"
#include "yuzu/about_dialog.h"

AboutDialog::AboutDialog(QWidget* parent)
    : QDialog(parent), ui{std::make_unique<Ui::AboutDialog>()} {
    ui->setupUi(this);
    setWindowTitle(QStringLiteral("Acerca de Fenix Emulator"));
    setWindowIcon(QIcon(QStringLiteral(":/img/fenix.ico")));
    ui->labelLogo->setPixmap(QIcon(QStringLiteral(":/img/fenix.ico")).pixmap(180));
    ui->labelYuzu->setText(QStringLiteral("<span style='font-size:26pt'>Fenix Emulator</span>"));
    ui->labelBuildInfo->setText(QStringLiteral("Versión 0.0.1"));
    ui->labelAbout->setText(QStringLiteral(
        "Proyecto de FenixPoderoso.<br>Un espacio propio para tu biblioteca de juegos.<br><br>"
        "Interfaz Fenix con configuración de video, audio y controles. "
        "Esta versión conserva el motor de emulación y el parche gráfico HSETP2."));
    ui->labelLinks->clear();
    ui->labelLiability->setText(QStringLiteral(
        "Proyecto independiente. Nintendo Switch es una marca de Nintendo."));
    auto* credits = ui->buttonBox->addButton(QStringLiteral("Licencias y créditos"),
                                            QDialogButtonBox::ActionRole);
    connect(credits, &QPushButton::clicked, this, [this] {
        QDialog dialog(this);
        dialog.setWindowTitle(QStringLiteral("Licencias y créditos"));
        dialog.setMinimumWidth(590);
        auto* layout = new QVBoxLayout(&dialog);
        auto* notice = new QLabel(QStringLiteral(
            "<h2>Software libre y atribuciones</h2>"
            "<p>Fenix Emulator 0.0.1 es una modificación de Eden-NS2, derivado de Eden "
            "y del proyecto yuzu. Copyright de sus respectivos autores.</p>"
            "<p>Copyright 2026 Eden Emulator Project.<br>"
            "Copyright yuzu Emulator Project y Citra Emulator Project.</p>"
            "<p>El código se distribuye conforme a GPL-3.0-or-later y a los avisos "
            "SPDX de cada archivo. Se conservan LICENSE.txt y LICENSES en la distribución.</p>"
            "<p>Los cambios de Fenix afectan a la presentación; el parche HSETP2 "
            "proviene del avance local documentado.</p>"
            "<p>Origen: <a href='https://github.com/0x2593/Eden-NS2'>Eden-NS2</a></p>"),
            &dialog);
        notice->setWordWrap(true);
        notice->setOpenExternalLinks(true);
        layout->addWidget(notice);
        auto* buttons = new QDialogButtonBox(QDialogButtonBox::Close, &dialog);
        connect(buttons, &QDialogButtonBox::rejected, &dialog, &QDialog::reject);
        layout->addWidget(buttons);
        dialog.exec();
    });
}

AboutDialog::~AboutDialog() = default;
