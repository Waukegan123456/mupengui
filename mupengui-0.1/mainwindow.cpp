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

#include "mainwindow.h"
#include "settingsdialog.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QFileDialog>
#include <QTextStream>
#include <QProcess>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->actionOpenT->setIcon(QApplication::style()->standardIcon(QStyle::SP_DialogOpenButton));
    ui->actionPreferencesT->setIcon(QApplication::style()->standardIcon(QStyle::SP_FileDialogDetailedView));


    connect(ui->actionOpenT, SIGNAL(triggered()), this, SLOT(on_actionOpen_triggered()));
    connect(ui->actionPreferencesT, SIGNAL(triggered()), this, SLOT(on_actionPreferences_triggered()));


    this->setFixedSize(400, 300);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    QFileDialog fileDialog(this);
    QString fileName;


    // FIXME: Native look is good, but this open dialog does not close itself,
    // if we open game on windowed mode
    /*
    QString fileName = fileDialog.getOpenFileName(this, tr("Open File"),
                                                     MySettings.value(DEFAULT_DIR_KEY).toString(),
                                                     tr("Files (*.*)"));
    */

    fileDialog.setNameFilter(tr("File (*.*)"));
    fileDialog.setDirectory(mySettings.value(DEFAULT_DIR_KEY).toString());
    fileDialog.setLabelText(QFileDialog::FileName, tr("Open File"));

    if (fileDialog.exec()) {
        fileName = fileDialog.selectedFiles().at(0);
        //fileName = fileDialog.getOpenFileName(this);
        if (!fileName.isEmpty()) {
            QDir CurrentDir;
            mySettings.setValue(DEFAULT_DIR_KEY, CurrentDir.absoluteFilePath(fileName));
            runFile(&fileName, false);
        }
    }

}

void MainWindow::on_actionPreferences_triggered()
{
    SettingsDialog settingsDialog;
    settingsDialog.exec();
}

void MainWindow::runFile(QString *fileName, bool selfQuit)
{
    // This does not like defining in private
    QTextStream out(stdout);
    QString mode = "--fullscreen";

    if (mySettings.value(WINDOWED_FULLSCREEN).toString() == "WINDOWED")
        mode = "--windowed";

    out << "FileName: " << *fileName;

    if (!fileName->isEmpty()) {
        QProcess p;
        p.start("mupen64plus " + mode + " \"" + *fileName + "\"");
        p.waitForFinished(-1);

        QString p_stdout = p.readAllStandardOutput();
        QString p_stderr = p.readAllStandardError();

        out << "StdOut: " << p_stdout;
        out << "Error: " << p_stderr;

        if (selfQuit) {
            out << "Exiting !! Cheers !!";
            exit(0);
        }
    }
}
