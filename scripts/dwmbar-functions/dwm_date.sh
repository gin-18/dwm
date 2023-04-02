#!/bin/sh

dwm_date () {
    Date=$(date +'%Y/%m/%d %a %H:%M')
    printf "^b#f4b8e4^^c#303446^  ^b#303446^^c#f4b8e4^ $Date"
}

dwm_date
