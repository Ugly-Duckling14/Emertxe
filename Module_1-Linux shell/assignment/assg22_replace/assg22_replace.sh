<<Documentation
Name : Munawir E
Date : 25/04/2022
Description : Write a script to replace 20% lines in a C file randomly and replace it with the pattern  
Sample I/P  : 1. ./replace_DEL.sh main.c
	      2. ./replace_DEL.sh main1.c
	      3. ./replace_DEL.sh main2.c
	      4. ./replace_DEL.sh

Sample O/P  : 1. Before replacing
		 #incude <stdio.h>
	         int main()
		 {	 
         	   printf(“Hello world\n”);
    		 }		
		 After replacing
		 #incude <stdio.h>
		 int main()
		 {
		 <-----------Deleted------------>
		 }
	      2. Error : No such a file.
	      3. Error : main2.c is empty file. So can’t replace the string.
	      4. Error : Please pass the file name through command line.
Documentation

#! /bin/bash

if [ $# -eq 1 ]							# Checking command line argument is equal to one.
then
    if [ -f $1 ]						# Checking file command line argument is file or not
    then
	if [ -s $1 ]						# Checking file content is greater than zero.
	then
	    total=`wc -l < $1`	    				# Storing the total number of line present in the given file.
	    if [ $total -ge 5 ]					# Checking total number of line is greater than five.
	    then
		echo "Before replacing"				# Printing output.
		cat $1						# Display file content before replacing.
		linedelete=`echo "$total * (20 / 100)" | bc`	# Storing 20 percent of line number count that required to delete.
		for  i in `seq 1 $linedelete`			# Loop will run from seq one to linedelete.
		do
		    random=`shuf -i 1-$total -n1`		# Generating a random number to decide which line to delete.
		    sed -i "$random s/.*/<-----------Deleted------------>/" $1		# Deleting the line and replace that line with <----deleted----> .
		done
		echo  "After replacing"							# Printing output.
		cat $1									# Displaying file contents after replacing it
	    fi
	else
	    echo "Error : main2.c is empty file. So can’t replace the string."		# Display error if file is an  empty file.
	fi
    else
	echo "Error : No such a file."							# Display error if the given file name is not present in current dir.
    fi
else
    echo "Error : Please pass the file name through command line."		# Display error if command line argument is not passed.
fi

