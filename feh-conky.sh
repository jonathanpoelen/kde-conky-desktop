#!/bin/bash

d=

s=`grep -E 'desktop=|wallpaper=' ~/.kde/share/config/plasma-desktop-appletsrc\
| while read l ; do
  read -n 1 c <<< "$l"
  if [ "$c" == d ] ; then
    d=${l//desktop=/}
  elif [ $d != '-1' ] ; then
    echo "$d ${l//wallpaper=/}"
  fi
done | sort | sed 's/[0-9] //'`

. `dirname "$0"`/current-desktop-notifier/CurrentDesktopNotifier | while read d ; do
  feh --no-fehbg --bg-scale "`awk NR==$d <<< "$s"`"
done
