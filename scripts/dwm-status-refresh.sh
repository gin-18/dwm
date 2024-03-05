#!/bin/bash

LOC=$(readlink -f "$0")
DIR=$(dirname "$LOC")

. "$DIR/dwmbar-functions/dwm_battery.sh"
. "$DIR/dwmbar-functions/dwm_backlight.sh"
. "$DIR/dwmbar-functions/dwm_alsa.sh"
. "$DIR/dwmbar-functions/dwm_date.sh"

xsetroot -name "$(dwm_backlight) $(dwm_alsa) $(dwm_battery)$(dwm_date) "
