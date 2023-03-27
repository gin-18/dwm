#!/bin/sh

dwm_alsa () {
  VOL=$(amixer get Master | tail -n1 | sed -r "s/.*\[(.*)%\].*/\1/")
  if [ "$VOL" -eq 0 ]; then
    printf "婢"
  elif [ "$VOL" -gt 0 ] && [ "$VOL" -le 66 ]; then
    printf "奔 %s%%" "$VOL"
  else
    printf "墳 %s%%" "$VOL"
  fi
}

dwm_alsa
