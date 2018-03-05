#!/bin/BASH
echo "first number:"
read f
echo "second number:"
read s
echo "sum=`expr $f + $s`"
echo "product=`expr $f \* $s`"
echo "difference=`expr $f - $s`"
echo "division=`expr $f / $s`"

