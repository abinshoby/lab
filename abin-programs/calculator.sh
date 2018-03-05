# !/bin/BASH
inp=1
while [ $inp -ne 6 ]
do
	echo "1.Add 2.Subtract 3.Multiply 4.Divide 5.Modulus 6.Exit"
	read inp
	case $inp in
	1)echo "Enter 2 numbers "
		read f
		read s
		echo "sum=`expr $f + $s`";;
	2)echo "Enter 2 numbers "
		read f
		read s
		echo "Difference=`expr $f - $s`";;
	3)echo "Enter 2 numbers "
		read f
		read s
		echo "Product =`expr $f \* $s`";;
	4)echo "Enter 2 numbers "
		read f
		read s
		if test $s -eq 0
		then
			echo "Infinite"
		else
			echo "Division=`expr $f / $s`"
		fi;;
	5)echo  "Enter 2 numbers "
		read f
		read s
		if test $s -eq 0
		then 
			echo "undefined"
		else
			echo "Modulus =`expr $f % $s`"
		fi;;
	6)echo "Thank you";;
	*)echo "Invalid operation"
	esac
done
