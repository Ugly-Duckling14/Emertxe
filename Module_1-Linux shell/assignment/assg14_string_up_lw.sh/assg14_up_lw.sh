<<Documentation
Name : Munawir E
Date : 21/04/2022
Description : Shell script to convert string lower to upper and upper to lower
Sample I/P  :1. First case
	      1 – Lower to upper
	      2 – Upper to lower
	      Please select option : 1
	     2. Second case
	      1 – Lower to Upper
	      2 – Upper to Lower
	      Please select option : 2

Sample O/P  : 1. WHAT IS OS?
		 WHAT ARE THE DIFFERENT OS?
	         WHEN IS OS USED?
	         WHAT IS PARTITION AND ITS USE?
	         HOW MANY PARTITIONS CAN BE DONE?
	      2. what is os?
	         what are the different os?
	         when is os used?
	         what is partition and its use?
	         how many partitions can be done?
	      3. Error: No contents inside the file.
	      4. Error : Please pass the file name through command line.
Documentation

#! /bin/bash

if [ $# -eq 1 ]				# Checking command line argument equal to one.
then
    if [ -f $1 ]			# Checking command line argument is a file.
    then
	if [ -s $1 ]			# Checking command line argument contents is greater thanzero.
	then
	    echo -e "1 – Lower to upper\n2 – Upper to lower"	# Printing the available options.
	    read -p "Please select option : " option		# Reading  the option from user.
	    case $option in					# According to the option case will jump to th option.
		1) cat $1 | tr a-z A-Z				# Converting texts to Upper case.
		    ;;
		2) cat $1 | tr A-Z a-z				# Converting texts to lower case.
		    ;;
		*) echo "Invalid"				# Default case.
		    ;;
	    esac
	else
	    echo "Error: No contents inside the file."		# Display error message if  file is empty.
	fi
    fi
else
    echo "Error : Please pass the file name through command line."	# Display erroe message if command line argument not equal to one.
fi
