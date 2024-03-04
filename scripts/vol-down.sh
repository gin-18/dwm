#!/bin/bash

/usr/bin/amixer -qM set Master 5%- umute
bash ~/github/gin-18/dwm/scripts/dwm-status-refresh.sh
