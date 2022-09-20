<<Documentation
Name : Munawir E
Date : 23/04/2022
Description :Given album name and corresponding directory, this scripts renames the jpg files with new name passed through command line
Sample I/P  : $ ls
		DSN001.jpg DSN002.jpg DSN003.jpg DSN004.jpg DSN005.jpg

Sample O/P  : 1. All .jpg files in current directory is renamed as
day_out001.jpg day_out002.jpg day_out003.jpg day_out005.jpg day_out004.jpg

	      2. Error : Please pass the prefix name through command line.
Documentation

#! /bin/bash

if [ $# -eq 1 ]		# Checking command line argument is equal to one.
then
for i in *.jpg		# Loop will run until all jpg file in the current directory is found.
do
    var=`echo $i | tr -cd [[:digit:]]`	# Except digit rest of the thing in i is removed.
    mv $i $1$var.jpg			# Renaming the jpg files in current directory.
done
echo "All .jpg files in current directory is renamed as"	# Printing the output.
echo *.jpg							# Printing all renamed jpg files.
else
    echo "Error : Please pass the prefix name through command line." # Display error when command line argumnt is not equal to zero.
fi
