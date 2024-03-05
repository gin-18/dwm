#!/bin/sh

dwm_battery () {
  # Change BAT1 to whatever your battery is identified as. Typically BAT0 or BAT1
  CHARGE=$(cat /sys/class/power_supply/BAT0/capacity)
  STATUS=$(cat /sys/class/power_supply/BAT0/status)

  if [ "$STATUS" = "Charging" ]; then
    printf "^c#303446^^b#81c8be^  ^b#1e1e2e^^c#81c8be^ %s%% %s" "$CHARGE"
  else
    if [ "$CHARGE" -le 15 ]; then
      printf "^c#303446^^b#e78284^   ^b#1e1e2e^^c#e78284^ %s%% %s" "$CHARGE"
    elif [ "$CHARGE" -le 30 ]; then
      printf "^c#303446^^b#e5c890^   ^b#1e1e2e^^c#e5c890^ %s%% %s" "$CHARGE"
    else
      printf "^c#303446^^b#81c8be^   ^b#1e1e2e^^c#81c8be^ %s%% %s" "$CHARGE"
    fi
  fi
}

dwm_battery
