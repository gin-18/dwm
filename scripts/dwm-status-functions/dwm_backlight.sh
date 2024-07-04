#!/bin/sh

dwm_backlight () {
    printf "^c#1e1e2e^^b#fab387^ 󰖙 ^c#fab387^^b#1e1e2e^ %d" "$(xbacklight)"
}

dwm_backlight
