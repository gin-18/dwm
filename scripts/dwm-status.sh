#!/bin/bash

LOC=$(readlink -f "$0")
DIR=$(dirname "$LOC")

. "$DIR/dwm-status-functions/dwm_battery.sh"
. "$DIR/dwm-status-functions/dwm_backlight.sh"
. "$DIR/dwm-status-functions/dwm_alsa.sh"
. "$DIR/dwm-status-functions/dwm_date.sh"

xsetroot -name "$(dwm_backlight) $(dwm_alsa) $(dwm_battery)$(dwm_date) "
