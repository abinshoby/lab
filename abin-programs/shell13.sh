#!/bin/BASH
#NAME ROLL MARKS
if [ -f  "$1" ]
then
 sort $1 -k3 -r -o $1

else
	echo "file not found" 
fi
