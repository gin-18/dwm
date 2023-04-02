#!/bin/sh

dwm_battery () {
  # Change BAT1 to whatever your battery is identified as. Typically BAT0 or BAT1
  CHARGE=$(cat /sys/class/power_supply/BAT0/capacity)
  STATUS=$(cat /sys/class/power_supply/BAT0/status)

  if [ "$STATUS" = "Charging" ]; then
    printf "^c#303446^^b#81c8be^  ^b#303446^^c#81c8be^ %s%% %s" "$CHARGE"
  else
    printf "^c#303446^^b#81c8be^  ^b#303446^^c#81c8be^ %s%% %s" "$CHARGE"
  fi
}

dwm_battery
