#!/bin/sh

dwm_backlight () {
    printf "^c#ef9f76^%s滛 %.0f%s\n" "$SEP1" "$(xbacklight)" "$SEP2"
}

dwm_backlight
