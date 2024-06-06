#!/bin/sh

dwm_backlight () {
    printf "^c#1e1e2e^^b#fab387^ 󰖙 ^c#fab387^^b#1e1e2e^%s %.0f%s\n" "$SEP1" "$(xbacklight)" "$SEP2"
}

dwm_backlight
