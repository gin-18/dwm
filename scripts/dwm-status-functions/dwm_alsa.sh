#!/bin/sh

dwm_alsa () {
  VOL=$(amixer get Master | tail -n1 | sed -r "s/.*\[(.*)%\].*/\1/")
  if [ "$VOL" -eq 0 ]; then
    printf "^b#94e2d5^^c#11111b^ 󰝟 "
  elif [ "$VOL" -gt 0 ] && [ "$VOL" -le 66 ]; then
    printf "^b#94e2d5^^c#11111b^ 󰖀 ^c#94e2d5^^b#1e1e2e^ %s%%" "$VOL"
  else
    printf "^b#94e2d5^^c#11111b^ 󰕾 ^c#94e2d5^^b#1e1e2e^ %s%%" "$VOL"
  fi
}

dwm_alsa
