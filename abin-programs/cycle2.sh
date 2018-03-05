#!/bin/BASH
echo "---------------------------------------------------------------------"
echo "OS INFO"
echo "OS $( cat /etc/os-release | head -1 )"
echo "OS $( cat /etc/os-release | head -2 | tail -1 )"
echo "OS $( cat  /etc/os-release | head -6 | tail -1 )"
echo "OS Kernel version $(uname -r)"
echo "---------------------------------------------------------------------"
echo "Shells available:"
cat /etc/shells
echo "---------------------------------------------------------------------"
echo "CPU INFO"
echo $( lscpu  | head -23 )
echo "---------------------------------------------------------------------"
echo "Memory Info"
cat /proc/meminfo
echo "---------------------------------------------------------------------"
echo "Hard Disk Info"
echo $( lsblk -o "NAME,MODEL,MAJ:MIN,RM,SIZE")
echo "---------------------------------------------------------------------"
echo "File system mounted:"
echo "`findmnt -lo source,target,fstype,label,options,used`"
echo "---------------------------------------------------------------------"
