<<Documentation
Name : Munawir E
Date : 22/04/2022
Description : Write a script to sort a given number in ascending or descending order
Sample I/P  : 1. ./sorting.sh -a 5 4 6 2 3 8 9 7 1
	      2. ./sorting.sh -d 5 4 6 2 3 8 9 7 1
	      3. ./sorting.sh 5 4 6 2 3 8 9 7 1
	      4. ./sorting.sh
	      5. ./sorting.sh -d 5 4 6 2 -3 8 -9 7 1

Sample O/P  : 1. Ascending order of array is 1 2 3 4 5 6 7 8 9
	      2. Descending order of array is 9 8 6 5 4 3 2 1
	      3. Error : Please pass the choice.
		 Usage : ./sorting -a/-d 4 23 5 6 3
	      4. Error : Please pass the argument through command line.
		 Usage : ./sorting -a/-d 4 23 5 6 3
	      5. Descending order of array is 8 7 6 5 4 2 1 -3 -9
Documentation

#! /bin/bash

array1=($@)					# Storing command line argument in array.
length=$((${#array1[@]}-1))			# Taking length-1 of array.
array=(${array1[@]:1:$length})			# Copying array elements by removing the option.


if [ $# -gt 0 ]					# Checking command line argument is greater than zero.
then

 #  ///***ASCENDING ORDER***///

    if [ $1 = "-a" ]				# Checking the first command line argument is -a.
    then
	for i in `seq 0 $(($length-1))`		# The loop will run from seq 1 to length-1.
	do
	    for j in `seq 0 $(($length-2-$i))`	# The loop will run from seq 0 to length-2-i.
	    do
		if [ ${array[$j]} -gt ${array[$j+1]} ]	# Comparing array elment is greater than that of it's next number.
		then
		    temp=${array[$j]}			# Storing array of jth value in temp.
		    array[$j]=${array[$j+1]}		# Storing array of j+1 value in array of j.
		    array[$j+1]=$temp			# Storing temp value in array of j+1.
		fi
	    done
	done
	echo "Ascending order of array is ${array[@]}"	# Printing the ascending order output.
    
#  ///***DESCENDING ORDER***///
    
    elif [ $1 = "-d" ]			# Checking first command line argument is -d.
    then
	for i in `seq 0 $(($length-1))`		# The loop will run from seq 1 to length-1.
	do  
	    for j in `seq 0 $(($length-2-$i))`		 # The loop will run from seq 0 to length-2-i.
	    do  
		if [ ${array[$j]} -lt ${array[$j+1]} ]		# Comparing array elment is less than that of it's next number.
		then
		    temp=${array[$j]}			# Storing array of jth value in temp.
		    array[$j]=${array[$j+1]}		# Storing array of j+1 value in array of j.
		    array[$j+1]=$temp			# Storing temp value in array of j+1.
	       	fi  
	    done
	done
	echo "Descending order of array is ${array[@]}"		# Printing the descending order.	
    else
	echo -e "Error : Please pass the choice.\nUsage : ./sorting -a/-d 4 23 5 6 3"	# Print error when choie is not passed
    fi
else
    echo -e "Error : Please pass the argument through command line.\nUsage : ./sorting -a/-d 4 23 5 6 3"	# Print error if command line argument is not passed.
fi


