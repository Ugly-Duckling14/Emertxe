<<Documentation
Name : Munawir E
Date : 20/04/22
Description :
Sample I/P  : 1. ./delete_empty_lines.sh file.txt
		
Hello

         

How

               

are


you?

	      2. ./delete_empty_lines.sh		

Sample O/P  : 1. Empty lines are deleted
Hello
How
are
you?
	      2. Error: Please pass the file name through command line.
Documentation

#! /bin/bash

if [ $# -eq 1 ]		# Checking command line argument is equal to one.
then
    if [ -f $1 ]	# Checking command line argument is a file.
    then
	echo "Empty lines are deleted"	# Printing the output.
	sed -i '/^[[:blank:]]*$/d' $1 
       	cat $1	# Removing empty space and empty lines.
    fi
else
    echo "Error: Please pass the file name through command line."	# Displaying error message.
fi
