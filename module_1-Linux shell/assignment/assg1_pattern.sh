<<Documentation
Name : Munawir E
Date :14/04/22
Description :WAP to print the pattern as follow
Sample I/P :if in put is 5
Sample O/P : 1
	     1 2
	     1 2 3
	     1 2 3 4
	     1 2 3 4 5
Documentation

#! /bin/bash
read -p "Enter the number : " n
for i in `seq $n`	#depends upon the $n value this loop will run
do
   for j in `seq $i`	#depends upon the $i value this loop will run
    do 
	echo -n "$j "	#print the value of j
    done
echo			#enter newline
done

