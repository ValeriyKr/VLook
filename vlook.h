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

#ifndef VLOOK_H
#define VLOOK_H

#include <QApplication>
#include <QDesktopWidget>
#include <QWidget>
#include <QTimer>
#include <QRect>
#include <QDebug>
#include <cmath>

#include "Audio/AudioALSA.h"

#define VISIBILITY_INTERVAL 800
#define CRITICAL_VALUE 80

namespace Ui {
class VLook;
}

class VLook : public QWidget
{
    Q_OBJECT

public:
    explicit VLook(QWidget *parent = 0);
    ~VLook();

private:
    Ui::VLook *ui;
    QTimer *hidingTimer;

public slots:
    void showVolume();
    void changeVolumePBColor(int value);
};

#endif // VLOOK_H
