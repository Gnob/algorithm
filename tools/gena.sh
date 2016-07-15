#!/bin/sh
if [ $# -eq 0 ]
then
	echo "error - please pass a argument for filename"
fi

touch $1.cc $1-in.txt
vim $1.cc
