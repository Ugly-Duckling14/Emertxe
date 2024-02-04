<<Documentation
Name : Munawir E
Date :15/04/22
Description : write a script for arithmetic calculator using command line arguments
Sample I/P  : 1. ./arithmatic_calc.sh 25 + 41
	      2. ./arithmatic_calc.sh 10 x 5
	      3. ./arithmatic_calc.sh 25 / 5
	      4. ./arithmatic_calc.sh 10.2 - 5.6
	      5. ./arithmatic_calc.sh
	      6. ./arithmatic_calc.sh 3.4	

Sample O/P  : 1. 25 + 41 = 66
	      2. 10 x 5 = 50
	      3. 25 / 5 = 5.00
	      4. 10.2 – 5.6 = 4.6
	      5. Error : Please pass the arguments through command line.
	         Usage:./arithmatic_calc.sh 2.3 + 6.7
	      6. Error:Please pass 3 arguments.
	         Usage:./arithmatic_calc.sh 2.3 + 6.7

Documentation
	   
#! /bin/bash

if [ $# -gt 0 ]					# Checking command line argument is greater than zero.
then
    if [ $# -eq 3 ]				# Checking command line argument is equal to three.
    then
	case $2 in				# It checks second argument is an operator or not, if it's an operator then it jump to the desired operator case.
	    +) sum=`echo "$1 + $3" | bc`	# If case + then it add number and store in sum.
		echo "$1 + $3 = $sum"		# Printing the output.
		;;
	    -) sum=`echo "$1 - $3" | bc`	# If case - then it subtract the number and store in sum.
		echo "$1 - $3 = $sum"		# Printing the output.
		;;

	    x) sum=`echo "$1 * $3" | bc`	# If case x then multiply the number and store in sum.
		echo "$1 x $3 = $sum"		# Printing the output.
		;;

	    /) sum=`echo "scale=2;$1 / $3" | bc` # If case / it divide the number and store in sum.
		echo "$1 / $3 = $sum"		 # Printing the output.
		;;
	    *) echo "invalid "			 #default case
	esac
    else					 # If command line argument is not equal to three execute else part.
	echo -e "Error:Please pass 3 arguments.\nUsage:./arithmatic_calc.sh 2.3 + 6.7"     # Display error message. 
    fi
else						# If command line argument is not equal to zero then execute else part.
    echo -e "Error : Please pass the arguments through command line.\nUsage:./arithmatic_calc.sh 2.3 + 6.7"  # Display error message.
fi
