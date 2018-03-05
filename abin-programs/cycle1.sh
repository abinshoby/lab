#!/bin/BASH
echo "Currently logged in users: `who`"
echo "Currently logged in users login name:$LOGNAME"
echo "current shell: $SHELL"
echo "Type of os:`uname -o`"
echo "home directory: $HOME"
echo "Current path setting:$PATH"
echo "Cuurent working directory:`pwd`"
echo "no of users currently logged in:`who | wc -l`"

