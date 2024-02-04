<<Documentation
Name : Munawir E
Date : 25/04/2022
Description : For each directory in the $PATH, display the number of executable files in that directory
Sample I/P  : 1. ./executable_path.sh
Sample O/P  : 1. Current dir: /usr/local/sbin
		 current count: 0
	    	 Current dir: /usr/local/bin
		 current count: 0
	  	 Current dir: /usr/sbin
		 current count: 205
		 Current dir: /usr/bin
		 current count: 1889
		 Current dir: /sbin
		 current count: 187
		 current count: 187
		 Current dir: /bin
		 current count: 159
		 Current dir: /usr/games
		 current count: 5
		 Current dir: /usr/local/games
		 current count: 0
		 Total – 2445
Documentation

#! /bin/bash

total=0					# Storing  total equal to zero.
array=(`echo $PATH | tr ":" " "`)	# Storing path variables into array.

for i in ${array[@]}			# Loop will run until the array element is empty.
do
    cd $i				# Opening the directories in i value.
    count=0				# Storing count is zero.
    for j in `ls`			# Here ls is considered as list and it takes the value of list one by one using loop.
    do
	if [ -x $j ]			# Checking excutable is available in current directory.
	then
	    count=$(($count+1))		# Increment the value of count. 
	    
	fi
    done
    total=$(($total+$count))		# Adding total + count. 
    echo "Current dir: $i"		# Printing current directory.
    echo "current count: $count"	# Printing count.
done
echo "Total – $total"			# Printing total. 
