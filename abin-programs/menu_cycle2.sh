#!/bin/BASH

while test $c -ne  'n' 
do
	echo "1.OS  & Kernel info 2.Shells available 3.CPU info 4.Memory info 			5.Hard Disk info 6.File system info (mounted)" 
	read inp
	case $inp in
	1)echo "---------------------------------------------------------------------"
	echo "OS INFO"
	echo "OS $( cat /etc/os-release | head -1 )"
	echo "OS $( cat /etc/os-release | head -2 | tail -1 )"
	echo "OS $( cat  /etc/os-release | head -6 | tail -1 )"
	echo "OS Kernel version $(uname -r)"
	echo "---------------------------------------------------------------------";;
	2)echo "Shells available:"
	cat /etc/shells
	echo "---------------------------------------------------------------------";;
	3)echo "CPU INFO"
	echo $( lscpu  | head -23 )
	echo "---------------------------------------------------------------------";;
	4)echo "Memory Info"
	cat /proc/meminfo
	echo "---------------------------------------------------------------------";;
	5)echo "Hard Disk Info"
	echo $( lsblk -o "NAME,MODEL,MAJ:MIN,RM,SIZE")
	echo "---------------------------------------------------------------------";;
	6)echo "File system mounted:"
	echo "`findmnt -lo source,target,fstype,label,options,used`"
	echo "---------------------------------------------------------------------";;
	*)echo "invalid option"
	esac
	echo "Do you want to continue(y/n)?"
	read c
done

