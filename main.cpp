/*
        Copyright 2016 Valeriy Kireev

        This file is part of VLook.

        VLook is free software: you can redistribute it and/or modify
        it under the terms of the GNU General Public License as published by
        the Free Software Foundation, either version 3 of the License, or
        (at your option) any later version.

        VLook is distributed in the hope that it will be useful,
        but WITHOUT ANY WARRANTY; without even the implied warranty of
        MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
        GNU General Public License for more details.

        You should have received a copy of the GNU General Public License
        along with VLook. If not, see <http://www.gnu.org/licenses/>.
*/

#include "main.h"

// Uncomment next line to pretend forking after start
// #define DBG_DONT_FORK

int main(int argc, char *argv[])
{
#ifndef DBG_DONT_FORK
    switch (fork()) {
    case -1:
        qDebug() << "Daemon starting error";
        return -1;
    case 0:
        break;
    default:
        return 0;
    }
#endif

    QApplication a(argc,argv);
    VLook w;

    VLookd daemon;
    QObject::connect(&daemon, SIGNAL(volumeChanged()), &w, SLOT(showVolume()));

    QTimer timer;
    QObject::connect(&timer, SIGNAL(timeout()), &daemon, SLOT(checkVolume()));
    timer.start(CHECKING_INTERVAL);

    return a.exec();
}
