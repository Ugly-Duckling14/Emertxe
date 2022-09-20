<<Documentation
Name : Munawir E
Date :19/04/22
Description :Write script called say_hello, which will print greetings based on time
Sample I/P  : NIL
Sample O/P  : Good Morning user, Have nice day!
	      This is Thursday 08 in June of 2017 (10:44:10 AM)
Documentation

#! /bin/bash

day=`date +%A`					# Storing day in day.
month=`date +%B`				# Storing the current month in month.
year=`date +%Y`					# Storing the current year in year.
date1=`date | cut -d " " -f2`			# Storing the current date in dat1.
time=`date +%r | cut -d " " -f1-2`		# Storing current time in time.

hrs=`date +%H`					# Storing hours in hrs
if [ $hrs -ge 5 -a $hrs -lt 12 ]		# If hour is between 5 am to 12 pm this statement executes.
then
    echo "Good Morning user, Have nice day!"	# Printing the output.
elif [ $hrs -ge 12 -a $hrs -le 13 ]		# Checking hour is between 12 pm to1pm.
then
    echo "Good Noon user, Have nice day!"	# Printing the output.
elif [ $hrs -ge 14 -a $hrs -lt 17 ]		# Checking hour is between 2pm to 5pm.
then
    echo "Good Afternoon user, Have nice day!"	# Printing the output.
elif [ $hrs -ge 17 -a $hrs -lt 21 ]		# Checking hour is between 5pm to 9pm.
then
    echo "Good Evening user, Have nice day!"	# Printing the output.
else						# Checking hour is between 9 pm to 5 am.
    echo "Good Night user, Have nice day!"	# Printing the output.
fi
echo "This is $day $date1 in $month of $year ($time)"	#Printing the output.
