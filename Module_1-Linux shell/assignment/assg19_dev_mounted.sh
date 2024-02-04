<<Documentation
Name : Munawir E
Date : 23/04/2022
Description : Write a script to determine whether a given file system or mount point is mounted
Sample I/P  : 1. ./mounted_fs.sh /dev/sda2
	      2. ./mounted_fs.sh /dev
	      3. ./mounted_fs.sh

Sample O/P  : 1. File-system /dev/sda2 is mounted on / and it is having 98%
	         used space with 3298220 KB free.
	      2. /dev is not mounted.
	      3. Error : Please pass the name of the file-system through command line.

Documentation

#! /bin/bash

filesystem=(`df -h | tr -s " " | cut -d " " -f1`)		# Storing the device filesystem in array.
count=0								# Storing the count value equal to zero.

if [ $# -eq 1 ]							# Checking command line argument is equal to one.
then
    for i in ${filesystem[@]}					# Loop will run until filesytem is empty.
    do
	if [ $i = $1 ]						# Checking command line argument is present in filesystem.
	then
	    aval=`df  $i | tr -s " " | cut -d " " -f4 | tail -1`		# Storing available free space of given device.
	    used=`df  $i | tr -s " " | cut -d " " -f5 | tail -1`		# Storing the value of device used space.
	    count=$(($count+1))	    # Increamenting the value of count.
	fi
    done
#    echo -e "File-system $1 is mounted on / and it is having $used\nused space with $aval KB free."
    if [ $count -eq 0 ]						# Checking count is equal to zero.
    then
	echo "$1 is not mounted."				# Printing device filesystem is not mounted.
    else
	echo -e "File-system $1 is mounted on / and it is having $used\nused space with $aval KB free."	# Printing the output that given device is mounted and showing it's used and free space.
    fi
else
    echo "Error : Please pass the name of the file-system through command line."	# Displaying error message if command line argument is not passed.
fi

