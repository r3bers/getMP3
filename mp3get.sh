#!/bin/bash
CH=`date +%H`

killall -q wget > /dev/null
cd ~/mp3
DATE=`date +%Y-%m-%d-%H`
wget -q -O ~/mp3/${DATE}.mp3 http://video.govoritmoskva.ru:8880/rufm_m.mp3 > /dev/null
while [[ $CH = `date +%H` ]]
do
    DATE=`date +%Y-%m-%d-%H-%M`
    wget -q -O ~/mp3/${DATE}.mp3 http://gm.fmtuner.ru > /dev/null
    sleep 60
done
