<<Documentation
Name : Munawir E
Date :16/04/22
Description :Write a script to print the length of each and every string using arrays
Sample I/P  : 1. ./string_length.sh hello hai how are you?
	      2. ./string_length.sh
Sample O/P  : 1. output
Length of string (hello) - 5
Length of string (hai) - 3
Length of string (how) - 3
Length of string (are) - 3
Length of string (you?) - 4
	      2.output
Error : Please pass the arguments through command-line.
Documentation

#! /bin/bash
array=($@)				# Storing values of command line argument to array varable.
if [ $# -gt 0 ]				# Checking count of command line argument is greater than zero or not.
then
    for i in `seq 0 $((${#array[@]}-1))`  # Depends upon the count of 'array-1' loop will run.
	do
	    echo "Length of string (${array[$i]}) - ${#array[$i]}"	# Print the length of each and every string in arrays.
	done 
else									# If command line argument not greater than zero.
    echo "Error : Please pass the arguments through command-line."	# Printing error message.
fi

