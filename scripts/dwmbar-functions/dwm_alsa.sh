#!/bin/sh

dwm_alsa () {
  VOL=$(amixer get Master | tail -n1 | sed -r "s/.*\[(.*)%\].*/\1/")
  if [ "$VOL" -eq 0 ]; then
    printf "^b#8caaee^^c#414559^ 婢 "
  elif [ "$VOL" -gt 0 ] && [ "$VOL" -le 66 ]; then
    printf "^b#8caaee^^c#414559^ 奔 ^c#c6d0f5^^b#303446^ %s%%" "$VOL"
  else
    printf "^b#8caaee^^c#414559^ 墳 ^c#c6d0f5^^b#303446^ %s%%" "$VOL"
  fi
}

dwm_alsa
