#!/bin/sh

dwm_backlight () {
    printf "%s滛 %.0f%s\n" "$SEP1" "$(xbacklight)" "$SEP2"
}

dwm_backlight
