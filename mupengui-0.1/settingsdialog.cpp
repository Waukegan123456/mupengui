/**
    Mupen GUI
    Copyright (C) 2013  xpressrazor@gmail.com

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
  */

#include "settingsdialog.h"
#include "ui_settingsdialog.h"

SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);

    if (mySettings.value(WINDOWED_FULLSCREEN).toString() == "WINDOWED") {
        ui->radioWindowed->setChecked(true);
    } else if (mySettings.value(WINDOWED_FULLSCREEN).toString() == "FULLSCREEN") {
        ui->radioFullscreen->setChecked(true);
    }

    this->setFixedSize(404, 266);
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

void SettingsDialog::accept()
{
    if (ui->radioFullscreen->isChecked()) {
        mySettings.setValue(WINDOWED_FULLSCREEN, "FULLSCREEN");
    } else if (ui->radioWindowed->isChecked()) {
        mySettings.setValue(WINDOWED_FULLSCREEN, "WINDOWED");
    }

    this->close();
}


