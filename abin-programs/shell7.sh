#!/bin/BASH
echo "Enter filename:"
read fname
echo "Enter a string:"
read str
#s=cat $fname
#if test  grep 
#then 
#	echo "string found"
#else
#	echo "string not found"
#fi

 var1=$(cat $fname | grep $str | wc -w )
 if test $var1 -gt 0
 then
 	echo "found"
 else
 	echo "not found"
 fi
 
  
