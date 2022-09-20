<<Documentation
Name : Munawir E
Date : 18/04/22
Description : Write a script to print system information using commands
Sample I/P  :
  1. Currently logged users
  2. Your shell directory
  3. Home directory
  4. OS name & version
  5. Current working directory
  6. Number of users logged in
  7. Show all available shells in your system
  8. Hard disk information
  9. CPU information.
  10. Memory Informations
  11. File system information.
  12. Currently running process.
  Enter the choice : 2
  Do you want to continue (y/n) ? y
  1. Currently logged users
  2. Your shell directory
  3. Home directory
  4. OS name & version
  5. Current working directory
  6. Number of users logged in
  7. Show all available shells in your system
  8. Hard disk information
  9. CPU information.
  10. Memory Informations
  11. File system information.
  12. Currently running process.
  Enter the choice : 13
  Do you want to continue(y/n) ? n
Sample O/P  : 1. Your shell directory is /bin/bash
              2.  Error : Invalid option, please enter valid option
Documentation


#! /bin/bash




function information()			# Defining the function
{
    echo -e "1. Currently logged users\n2. Your shell directory\n3. Home directory\n4. OS name & version\n5. Current working directory\n6. Number of users logged in\n7. Show all available shells in your system\n8. Hard disk information\n9. CPU information.\n10. Memory Informations\n11. File system information.\n12. Currently running process."			# Displaying the available option.


read -p "Enter the choice : " choice					# Reading user's choice.
    case $choice in							# Case will jump from 1 to 12 according to user input,else jump default.
	1) echo "Currently logged users is $USER"			# Prints current logged in users.
	    ;;
	2) echo "Your shell directory is $SHELL"			# Prints shell directory path.
	    ;;
	3) echo "Home directory is $HOME"				# Prints home directory path.
	    ;;
	4) echo "OS name is `uname -r`"					# Prints OS name.
	    echo "OS version is `uname -v`"				# Prints OS version.
	    ;;
	5) echo "Current working directory is $PWD"			# Prints path of current working directory.
	    ;;
	6) echo "Number of users logged in is `who |wc -l`"		# Prints number of users logged in the system.
	    ;;
	7) echo "Showing all available shells in your system is `cat /etc/shells`"	# Display all shells available is the PC.
	    ;;
	8) echo "Hard disk information is `df -h`"			# Display hard disk informations.
	    ;;
	9) echo "CPU information is `cat /proc/cpuinfo`"		# Display CPU informations.
	    ;;
	10) echo "Memory Informations is `grep | cat /proc/meminfo`"	# Display Memory informations.
	    ;;
	11) echo "File system information is `df -Th | grep "^/dev"`"	# Display file informations.
	    ;;
	12) echo "Currently running process is `ps -aux`"		# Displays currently running process.
	    ;;
	*) echo "Error : Invalid option, please enter valid option"	# Default case throws error when uses choose other than 1 to 12 as choice
	    ;;
    esac
read -p "Do you want to continue(y/n) ? " yn				# Reading input for continue or not.

if [ $yn = "y" -o $yn = "Y" ]						# Checking continue option is equal to y (case ignores) or not.
then
    information								# Function call.
else
    exit								# Terminate the code.
fi
echo foo

    }

information								# Function call.
