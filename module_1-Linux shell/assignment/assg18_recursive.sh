<<Documentation
Name : Munawir E
Date : 23/04/2022
Description : Use a recursive function to print each argument passed to the function
Sample I/P  : 1. ./recursion.sh How are you? I am fine
	      2. ./recursion.sh
Sample O/P  : 1. How
		 are
	    	 you?
		 I
	  	 am
		 fine

	      2. Error : Pass the arguments through command line.

Documentation

#! /bin/bash

if [ $# -gt 0 ]				# Checking command line argument is greater than zero.
then
    function recursive()		# Function definition.
    {
	array=($@)			# Storing command line argument in array.
	echo $1				# Printing the output.
 
	if [ $# -ne 0 ]			# Checking command line is not equal to zero.
	then
	    array=(${array[@]:1})	# Removing the first element in array.
	    recursive ${array[@]}	# Calling recursive function.
	else 
	    exit			# Program is terminated when command line argument is zero. 
	fi
    }
recursive $@				# Fuction call.
else
    echo "Error : Pass the arguments through command line."	# Display error message, If command line argument is zero.
fi
