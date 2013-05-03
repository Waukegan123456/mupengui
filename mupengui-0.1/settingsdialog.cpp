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
    //connect(ui->radioWindowed, SIGNAL(toggled(bool)), this, SLOT(on_radioWindowedFullscreen_toggled()));
    //connect(ui->radioFullscreen, SIGNAL(toggled(bool)), this, SLOT(on_radioWindowedFullscreen_toggled()));

    //WINDOWED_FULLSCREEN = "WINDOWED";

     WINDOWED_FULLSCREEN = "WINDOWED";

    if (MySettings.value(WINDOWED_FULLSCREEN).toString() == "WINDOWED") {
        ui->radioWindowed->setChecked(true);
    } else if (MySettings.value(WINDOWED_FULLSCREEN).toString() == "FULLSCREEN") {
        ui->radioFullscreen->setChecked(true);
    }

    this->setFixedSize(404, 266);

}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

/*
void SettingsDialog::on_radioWindowedFullscreen_toggled()
{
    //QTextStream out(stdout);
    //out << "Settings: " << MySettings.value(WINDOWED_FULLSCREEN).toString();




}
*/

void SettingsDialog::accept()
{
    //QTextStream out(stdout);
    //out << "Accept " << "ACCEPTED";

    if (ui->radioFullscreen->isChecked()) {
        MySettings.setValue(WINDOWED_FULLSCREEN, "FULLSCREEN");
    } else if (ui->radioWindowed->isChecked()) {
        MySettings.setValue(WINDOWED_FULLSCREEN, "WINDOWED");
    }

    this->close();
}


