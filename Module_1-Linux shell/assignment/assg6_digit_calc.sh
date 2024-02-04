<<Documentation
Name : Munawir E
Date :16/04/22
Description : Write a script to perform arithmetic operation on digits of a given number
Sample I/P  : 1. ./operator_dependent.sh 1234+
	      2. ./operator_dependent.sh 8312-
	      3. ./operator_dependent.sh 5487
	      4. ./operator_dependent.sh 1111x
	      5. ./operator_dependent.sh 12/
	      6. ./operator_dependent.sh

Sample O/P  : 1. output
		Sum of digits = 10
	      2. output
		Subtraction of digits = 2
	      3. output
		Error: Operator missing or invalid operator, please pass operator as last digit (+,-,x,/)
	      4. output
		Multiplication of digits = 1
	      5. output
		Division of digits = .50
	      6. output
		Error : Please pass the arguments through CL.

		Usage : ./operator_dependent.sh 2345+
Documentation

#! /bin/bash		
number=$1				# Storing 1st value of command line argument in number.
length=${#number}			# Storing the length of number
length2=$(($length-1))			# Storing 'length-1'.
operator=${number:$length2:1}		# Storing last digit of number.
result=${number:0:1}			# Storing first digit in number.

if [ $# -gt 0 ]				# Checking the count of command line argument is greater than zero or not.
then
    
	case $operator in		# If last digit is an operator then it jump to the specific case.
            +) for i in `seq 1 $(($length-2))`		# Depends upon the  'length-2' the loop wil run.
               do
                   result=`echo "$result + ${number:$i:1}" | bc` 	# Adding the digits and stores in result.
               done
               echo "Sum of digits = $result"		# Print the result.
               ;;
            -) for i in `seq 1 $(($length-2))`		# Depends upon the 'length-2' the loop run.
               do
                   result=`echo "$result - ${number:$i:1}" | bc`  # Subtracting the digits and stores in result.
               done
               echo "Subtraction of digits = $result"	# Printing the result.
               ;;
            x) for i in `seq 1 $(($length-2))`		# Depends upon the  'length-2' the loop wil run.
               do
                   result=`echo "$result * ${number:$i:1}" | bc`	# Multipling the digits and stores in result.
               done
               echo "Multiplication of digits = $result"	# Printing the result.
               ;;
            /) for i in `seq 1 $(($length-2))`		# Depends upon the  'length-2' the loop wil run.
               do
                   result=`echo "scale=2;$result / ${number:$i:1}" | bc`	# Dividing the digits and stores in result.	
               done
               echo "Division of digits = $result"	# Printing the result.
               ;;
            *) echo "Error: Operator missing or invalid operator, please pass operator as last digit (+,-,x,/)"		# Invalid if the last digit is not an operator it throws the result.
	       ;;
        esac
else
    echo -e "Error : Please pass the arguments through CL.\n\nUsage : ./operator_dependent.sh 2345+"	# If the count of command line argument is not greater than zero else part executes.
fi
