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

#ifndef VLOOKD_H
#define VLOOKD_H

#include <QApplication>
#include <QDebug>
#include <csignal>

#include "Audio.h"


class VLookd : public QObject
{
    Q_OBJECT
public:
    explicit VLookd(QObject *parent = 0);
    virtual ~VLookd();

signals:
    void volumeChanged();

public slots:
    void checkVolume();

private:
    Audio *audio;
    long lastVolume;
};

#endif // VLOOKD_H
