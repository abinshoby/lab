#!/bin/BASH
if [ -f "$1" ]
then 
	mv $1 $2
	echo "file renamed sucessfully"
else
	echo "the given file doesn't exist"
fi

