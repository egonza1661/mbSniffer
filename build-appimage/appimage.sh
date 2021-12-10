#!/bin/sh

#update your linuxdeployqt path
LINUXDEPLOYQT=$HOME/Programs/linuxdeployqt/linuxdeployqt-5-x86_64.AppImage

#update your qmake path
QMAKE_PATH=$HOME/Qt/5.15.2/gcc_64/bin/qmake

APP=./usr/share/applications/mbSniffer.desktop


if [ -f "$LINUXDEPLOYQT" ]
    then
        if [ -f "$QMAKE_PATH" ]
            then
                $LINUXDEPLOYQT $APP -qmake=$QMAKE_PATH -appimage
            else
                echo "update your qmake path in appimge.sh"
        fi
    else
        echo "update your linuxdeployqt path in appimge.sh"
fi
