#!/bin/sh
echo "Is it morning? Please answer yes or no"
read timeofday
if [ $timeofday = "yes" ]; then
echo "Good morning"
elif [ $timeofday = "no" ]; then
echo "Good afternoon"
else
echo "Sorry, $timeofday not recognized. Enter yes or
no"
exit 1
34
fi
exit 0 