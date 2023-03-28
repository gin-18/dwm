#!/bin/sh

dwm_alsa () {
  VOL=$(amixer get Master | tail -n1 | sed -r "s/.*\[(.*)%\].*/\1/")
  if [ "$VOL" -eq 0 ]; then
    printf "^b#5e81ac^^c#d8dee9^ 婢 "
  elif [ "$VOL" -gt 0 ] && [ "$VOL" -le 66 ]; then
    printf "^b#5e81ac^^c#d8dee9^ 奔 ^b#2e3440^ %s%%" "$VOL"
  else
    printf "^b#5e81ac^^c#d8dee9^ 墳 ^b#2e3440^ %s%%" "$VOL"
  fi
}

dwm_alsa
