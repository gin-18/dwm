#!/bin/sh

dwm_backlight () {
    printf "^c#11111b^^b#f9e2af^ 󰖙 ^c#f9e2af^^b#1e1e2e^ %d" "$(xbacklight)"
}

dwm_backlight
