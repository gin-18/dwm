#!/bin/bash

# 自动启动的程序和脚本
arr=("dunst" "fcitx5" "picom")

for value in ${arr[@]}; do
    if [[ ! $(pgrep ${value}) ]]; then
        exec "$value" &
    fi
done

/bin/bash ~/suckless/dwm/scripts/dwm-wallpaper.sh &
xinput --set-prop 12 "libinput Tapping Enabled" 1

# 状态栏的刷新
while true; do
	/bin/bash ./dwm-status-refresh.sh
	sleep 1
done
