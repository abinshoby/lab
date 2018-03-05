#!/bin/BASH
if [ -f  "$1" ]
then
	if [ -f "$2" ]
	then 
		cat $1 | cat >> $2
		echo "appended the content"
	else
		cat $1 | cat > $2
		echo " copy sucessfull"
	fi
else
	echo "source doesn't exist"
fi
