#!/bin/sh

dwm_date () {
    Date=$(date +'%Y/%m/%d %a %H:%M')
<<<<<<< HEAD
    printf "\x01  $Date"
=======
    printf " $Date"
>>>>>>> c25e2d2 (show color in status bar)
}

dwm_date
