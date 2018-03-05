#!/bin/BASH
inp=1
while [ $inp -ne  2 ]
do
	echo "1. Display the day 2.exit"
	read inp
	if test $inp -eq 1
	then
		echo "enter day no"
		read day
		case $day in
		1) echo "sunday";;
		2) echo "monday";;
		3) echo "tuesday";;
		4) echo "wednesday";;
		5) echo "thursday";;
		6) echo "friday";;
		7) echo "saturday";;
		*) echo "not valid";;
		esac
	fi
done
		
		 
