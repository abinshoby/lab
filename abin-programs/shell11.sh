#!/bin/BASH
if [ -f "$1" ]
then
	cat $1 | tr "[a e i o u]" "[A E I O U]" | cat > $2
else
	echo "file not found"
fi
	
			
