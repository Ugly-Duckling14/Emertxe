<<Documentation
Name : Munawir E
Date :14/04/22
Description : Read 'n' and generate a pattern given below(number increasing from Top to bottom)
Sample I/P  : Enter the number : 4
Sample O/P  : 
Documentation

#! /bin/bash
read -p "Enter the number : " n		#reading value for n
print=1					# assiging value 1 in print
for i in `seq $n`			#depends upon the $n value this loop will run
do
    for j in `seq $i`			#depends upon the $i value this loop will run
    do  
        
        echo -n " $print"		#print the value in print
	print=$(($print+1))		#increment the value in print
    done
echo					#enter newline
done




