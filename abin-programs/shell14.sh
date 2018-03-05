#!/bin/BASH
echo "enter limit:"
read n
sum1=0
i=0
while  [ $i -le $n ]
do
	 sum1=`expr $sum1 + $i `
	 i=`expr $i + 1 `
done
echo "sum= $sum1"
