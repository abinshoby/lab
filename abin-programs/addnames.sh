#!/bin/BASH
if test  $# -eq  2
then
	if [ -f "$1" ]
	then
		if test $( cat $1 | grep $2 | wc -w ) -gt 0
		then echo "username already exists!"
		else
			echo $2 >>  $1
		fi
	else
		echo "file doesn't exist!"
	fi
else
	echo "There should be two arguments!"
fi
	
	
