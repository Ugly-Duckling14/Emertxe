<<Documentation
Name : Munawir E
Date : 21/04/2022
Description : Write script to print contents of file from given line number to next given number of lines.
Sample I/P  : 1. ./print_lines.sh 5 3 myfile.txt
	      2. ./print_lines.sh myfile.txt
	      3. ./print_lines.sh 5 10 myfile.txt

Sample O/P  : 1. line number 5
	         line number 6
		 line number 7
	      2. Error: arguments missing!
	         Usage: ./file_filter.sh start_line upto_line filename

	         For eg. ./file_filter.sh 5 5 <file>
	      3. Error: data.txt is having only 10 lines. file should have atleast 14 lines
Documentation

#! /bin/bash

if [ $# -eq 3 ]				# Checking command line argument is equal to three.
then
    count=`cat $3 | wc -l`		# Counting number of lines present in the file.
    if [ $((($1+$2)-1)) -le $count ]	# Checking given number of lines is less than of total line in the file.
    then
	echo "`head -$((($1+$2)-1)) $3 | tail -$2`" # Print contents of file from given line number to next given number of lines.
    else
	echo "Error: $3 is having only $count lines. file should have atleast $((($1+$2)-1)) lines"	# Dispaly error message, if the given number of lines is more than that of total line in the file.
    fi
else
    echo -e "Error: arguments missing!\nUsage: ./file_filter.sh start_line upto_line filename\n\nFor eg. ./file_filter.sh 5 5 <file>"	# Display error message, If the command line argument is not qual to three.
fi
