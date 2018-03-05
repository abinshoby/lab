#!/bin/BASH
echo "Enter no of lines:"
read no
if test -f  "$1" 
then
	if test -f  "$2"
	then
		head -$no $1 | cat > $3
		head -10 $2 | cat >> $3 
		echo "copy sucessfull"
	else
		echo "file not found"
	fi
else
	echo "file not found"
fi	
