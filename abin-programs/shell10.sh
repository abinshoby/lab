#!/bin/BASH
echo "enter character:"
read c
var=$(ls | grep "^"$c | wc -w)
echo "no of files=:$var"


