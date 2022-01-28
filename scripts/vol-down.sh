#!/bin/bash

/usr/bin/amixer -qM set Master 5%- umute
bash ~/suckless/dwm/scripts/dwm-status-refresh.sh
