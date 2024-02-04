<<Documentation
Name : Munawir E
Date : 22/04/2022
Description : Display the longest and shortest user-names on the system
Sample I/P  : NIL

Sample O/P  : The Longest Name is: speech-dispatcher
	      The Shortest Name is:lp
Documentation

#! /bin/bash

array=(`cut -d ":" -f1 /etc/passwd`)			# Storing the username in array.
length=${#array[@]}					# Storing the length of array.
long=${array[0]}					# Storing first value of array.
small=$long						# Storing first value of array.

for i in ${array[@]}					# The loop will run until the  array elements are empty.
do
    if [ ${#i} -gt ${#long} ]				# Checking length of i value is greater than length of long.
    then
	long=$i						# Storing longest username.
    elif [ ${#i} -lt ${#small} ]			# Checking length of i value is less than length of small.
    then
	small=$i					# Storing smallest username.
    fi
done

echo -e "The Longest Name is: $long\nThe Shortest Name is:$small"	# Printing the output.
