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

#include "vlook.h"
#include "ui_vlook.h"

VLook::VLook(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VLook)
{
    ui->setupUi(this);
    QRect screenGeometry = (QApplication::desktop())->screenGeometry();
    int x = (screenGeometry.width() - this->width())/2;
    int y = (screenGeometry.height() - this->height())/2;
    this->move(x, y);

    this->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    this->setAttribute(Qt::WA_ShowWithoutActivating);

    this->hidingTimer = new QTimer;
    QObject::connect(this->hidingTimer, SIGNAL(timeout()), this, SLOT(hide()));
    QObject::connect(this->hidingTimer, SIGNAL(timeout()), this->hidingTimer, SLOT(stop()));

    QObject::connect(ui->pbVolume, SIGNAL(valueChanged(int)), this, SLOT(changeVolumePBColor(int)));
}


void VLook::showVolume() {
    ui->pbVolume->setValue(Audio().getVolume());
    this->show();
    this->hidingTimer->start(VISIBILITY_INTERVAL);
}


void VLook::changeVolumePBColor(int value) {
    // TODO: rewrite all of this
    if (CRITICAL_VALUE <= value) {
        int red = (int) (255.0/exp(100/18.798287063390017)*exp(value/18.798287063390017));
        int green = (int) (85 - (value-80)/20.0*40);
        int blue = (int) (255 - (value-80)/20.0*231);
        ui->pbVolume->setStyleSheet(ui->pbVolume->styleSheet() +
                                    "QProgressBar::chunk{background-color:" +
                                    QColor(red, green, blue).name() +
                                    ";}");
    } else {
        ui->pbVolume->setStyleSheet(ui->pbVolume->styleSheet() + "QProgressBar::chunk {background-color:#5855ff;}");
    }
}


VLook::~VLook()
{
    delete hidingTimer;
    delete ui;
}
