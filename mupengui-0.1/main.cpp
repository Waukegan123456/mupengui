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
#include <QApplication>
#include <qstring.h>
#include <qtextstream.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QTextStream out(stdout);

    if (argc == 2) {
        QString fileName(argv[1]);
        w.runFile(&fileName, true);
        out << "Press (Ctrl + C) to quit\n";
    } else if (argc > 2) {
        out << "Usage: mupengui <filename>\n";
        exit(1);
    } else {
        w.show();
    }

    return a.exec();
}
