#!/bin/sh

dwm_date () {
    Date=$(date +'%Y/%m/%d %a %H:%M')
    printf "\x01  $Date"
}

dwm_date
