#!/bin/sh
x=1
while [ $x -le 1000 ]; do
	cd ~/Quiz6/test/
	touch $x.txt
	x=$((x+1))
done


