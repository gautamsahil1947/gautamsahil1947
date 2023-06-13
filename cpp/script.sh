#!/bin/bash


if [[ $(xrandr -q | grep -x "DP-1 connected.*") ]]; then
    xrandr --output DP-1 --mode 1360x768 --left-of eDP-1
    xwallpaper --output DP-1 --zoom /home/sahil/.config/wallpapers/main.jpg
    xwallpaper --output eDP-1 --zoom /home/sahil/.config/wallpapers/main.jpg
    wal -i /home/sahil/.config/wallpapers/main.jpg
else
    xwallpaper --output eDP-1 --zoom /home/sahil/.config/wallpapers/main.jpg
    wal -i /home/sahil/.config/wallpapers/main.jpg
fi

