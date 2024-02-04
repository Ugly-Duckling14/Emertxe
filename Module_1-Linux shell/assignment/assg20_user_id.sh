<<Documentation
Name : Munawir E
Date : 23/04/2022
Description : Count the number of users with user IDs between given range.
Sample I/P  : 1. ./user_ids.sh
	      2. ./user_ids.sh 0 100
	      3. ./user_ids.sh 100
	      4. ./user_ids.sh 200 100

Sample O/P  : 1. Total count of user ID between 500 to 10000 is: 2
	      2. Total count of user ID between 0 to 100 is : 3
	      3. Error : Please pass 2 arguments through CL.
	         Usage : ./user_ids.sh 100 200
	      4. Error : Invalid range. Please enter the valid range through CL. 
	      
Documentation

#! /bin/bash

userid=(`cat /etc/passwd | cut -d ":" -f3`)			# Storing all userid available in system.
count=0								# Count is equal to zero.


if [ $# -eq 0 ]							# Command line argument is equal to zero, Program execute the default case.
then
    for i in `seq 0 $((${#userid[@]}-1))`			# Loop will run from seq of zero to end of array.
    do
	if [ ${userid[$i]} -ge 500 -a ${userid[$i]} -le 10000 ]	# Checking how many userid is greater than or equal to 500 and less than or equal to 10000.
	then
	   
	    count=$(($count+1))					# Incrementing the value of count.
	fi
    done
    echo "Total count of user ID between 500 to 10000 is: $count" 	# Printing the total number of userid present between 500 to 10000.

elif [ $# -eq 2 ]							# Checking If command line argument equal to two.
then

    if [ $1 -lt $2 ]							# Checking first command line argument is less than second command line argument.
    then
	for i in `seq 0 $((${#userid[@]}-1))`				# Loop will run from seq of zero to end of array.
	do  
	    if [ ${userid[$i]} -ge $1 -a ${userid[$i]} -le $2 ]		# Checking how many userid is greater than or equal to $1 and less than or equal to $2.
	    then
		count=$(($count+1))					# Incrementing the value of count.
	    fi  
	done
	echo "Total count of user ID between $1 to $2 is : $count"	# Printing the total number of userid present between $1 and $2.
    else
	echo "Error : Invalid range. Please enter the valid range through CL."	# Display error message if $2 is less than $1.
    fi
else
    echo -e "Error : Please pass 2 arguments through CL.\nUsage : ./user_ids.sh 100 200"	# Display error message if command line argument is not passed.

fi
