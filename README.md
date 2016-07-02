# VLook
Tool for monitoring system sound volume and showing changes to user, created by Valeriy Kireev (https://github.com/ValeriyKr).

## Description
`VLook` is program for system sound volume monitoring. It works like a daemon and shows information window when volume changes.

Now it watching for `Master` channel of `default` soundcard. Later it will be changed.
`VLook` works with ALSA subsystem (i.e, program is Linux-only). It will be changed too.

## Building
```
$ git clone https://github.com/ValeriyKr/VLook.git
$ cd ./VLook
$ mkdir ./build; cd ./build
$ qmake ..
$ make
```
After that, you will be able to use `VLook` binary.

## Bugs
Window displays are not always. For example, it can't displays above mplayer in full-screen mode.
Perhaps, `Qt::WindowStaysOnTopHint` is the reason for that behavior.
