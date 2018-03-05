#!/bin/BASH
inp=1
while [ $inp -ne 5 ]
do
	echo "1.add 2.subtract 3.multiply 4.divide 5.exit"
	read inp
	
	case $inp in
		1) echo "enter two numbers "
			read f
			read s
			echo "sum=`expr $f + $s`";;
		2)echo "enter two numbers "
			read f
			read s
			echo "difference=`expr $f - $s`";;
		3)echo "enter two numbers "
			read f
			read s
			echo "product=`expr $f \* $s`";;
		4)echo "enter two numbers "
			read f
			read s
			echo "division=`expr $f / $s`";;
		5)echo "thank you";;
		*)echo "invalid operation";;
	esac
done
		
