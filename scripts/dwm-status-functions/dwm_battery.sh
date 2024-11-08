#!/bin/sh

dwm_battery () {
  # Change BAT1 to whatever your battery is identified as. Typically BAT0 or BAT1
  CHARGE=$(cat /sys/class/power_supply/BAT0/capacity)
  STATUS=$(cat /sys/class/power_supply/BAT0/status)

  if [ "$STATUS" = "Charging" ]; then
    printf "^c#11111b^^b#a6e3a1^  ^b#1e1e2e^^c#a6e3a1^ %s%% %s" "$CHARGE"
  else
    if [ "$CHARGE" -le 5 ]; then
      shutdown -h now
    elif [ "$CHARGE" -le 15 ]; then
      printf "^c#11111b^^b#f38ba8^  ^b#1e1e2e^^c#f38ba8^ %s%% %s" "$CHARGE"
    elif [ "$CHARGE" -le 30 ]; then
      printf "^c#11111b^^b#f9e2af^  ^b#1e1e2e^^c#f9e2af^ %s%% %s" "$CHARGE"
    else
      printf "^c#11111b^^b#74c7ec^  ^b#1e1e2e^^c#74c7ec^ %s%% %s" "$CHARGE"
    fi
  fi
}

dwm_battery
