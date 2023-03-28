#!/bin/sh

dwm_date () {
    Date=$(date +'%Y/%m/%d %a %H:%M')
    printf "^b#b48ead^^c#2e3440^  ^b#2e3440^^c#b48ead^ $Date"
}

dwm_date
