#!/bin/sh

dwm_battery () {
    # Change BAT1 to whatever your battery is identified as. Typically BAT0 or BAT1
    CHARGE=$(cat /sys/class/power_supply/BAT0/capacity)
    STATUS=$(cat /sys/class/power_supply/BAT0/status)

    printf "%s" "$SEP1"
    if [ "$IDENTIFIER" = "unicode" ]; then
        if [ "$STATUS" = "Charging" ]; then
            printf "🔌 ‧ %s%% %s" "$CHARGE"
        else
            if [ "$CHARGE" -lt 15 ]; then
                printf "⚠ ‧ %s%% %s" "$CHARGE"
            else
                printf "🔋 ‧ %s%% %s" "$CHARGE"
            fi
        fi
    else
        printf "BAT %s%% %s" "$CHARGE"
    fi
    printf "%s\n" "$SEP2"
}

dwm_battery
