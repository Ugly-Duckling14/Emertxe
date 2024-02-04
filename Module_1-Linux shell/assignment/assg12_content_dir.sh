<<Documentation
Name : Munawir E
Date : 21/04/22
Description : WAS to print contents of a directory without ls command
Sample I/P  : 1. ./output_ls.sh /home/user/ECEP/Linux_Systems/
	      2. ./output_ls.sh ~ ~/ECEP
	      3. ./ouput_ls.sh Test
Sample O/P  : 1. Assignments Classwork
	      2. /home/user:
		 Downloads Documents Desktop Music Pictures Public Videos
		 /home/user/ECEP:
		 Linux_Systems Advnc_C Linux_Internals Data_Structures 
	      3. output_ls.sh: Cannot access ‘Test’ : No such a file or directory.
Documentation

#! /bin/bash

if [ $# -gt 0 ]				# Checking command line argument is greater than zero.
then
    array=($@)				# Storing command line argument in an array.
    length=${#array[@]}			# Storing length of array.
    number=0
    while [ $number -lt $length ]		# Checking number is less than length.
    do
	if [ -d ${array[$number]} ]	# Checking array element is directory.
	then
    	    cd ${array[$number]}		# Moving to the directory path.
	    echo "`pwd`:"		# Printing current working directory.
	    echo *			# Printing files and directories in current working directory
	else
	    echo "output_ls.sh: Cannot access ‘Test’ : No such a file or directory." # Displaying error message.
	fi
	number=$(($number+1))			# Incrementing value of number.
    done
fi
