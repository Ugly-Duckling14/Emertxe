<<Documentation
Name : Munawir E
Date :14/04/22
Description :Write a script to print chess board
Sample I/P : NIL
Sample O/P : 8x8 black and white colored chessboard
Documentation

#! /bin/bash

for i in `seq 8`				#depends upon the i value loop will run 
do  
    for j in `seq 8`				#depends upon the j value loop will run
    do  
	if [ $((($i+$j)%2)) -eq 0 ]		#checking the condition i+j modulus 2 equal to zero or not
	then
	    echo -e -n "\e[47m" " "		#printing white colored box
	else
	    echo -e -n "\e[40m" " "		#printing black colored box
	fi
    done
echo -e "\e[0m" " "				# to make it normal
done




