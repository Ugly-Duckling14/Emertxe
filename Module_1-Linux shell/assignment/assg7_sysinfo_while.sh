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

flag=1
while [ $flag -eq 1 ]
do
    echo -e "1. Currently logged users\n2. Your shell directory\n3. Home directory\n4. OS name & version\n5. Current working directory\n6. Number of users logged in\n7. Show all available shells in your system\n8. Hard disk information\n9. CPU information.\n10. Memory Informations\n11. File system information.\n12. Currently running process."


read -p "Enter the choice : " choice
    case $choice in
	1) echo "Currently logged users is $USER"
	    ;;
	2) echo "Your shell directory is $SHELL"
	    ;;
	3) echo "Home directory is $HOME"
	    ;;
	4) echo "OS name is `uname -r`"
	    echo "OS version is `uname -v`"
	    ;;
	5) echo "Current working directory is $PWD"
	    ;;
	6) echo "Number of users logged in is `who |wc -l`"
	    ;;
	7) echo "Showing all available shells in your system is `cat /etc/shells`"
	    ;;
	8) echo "Hard disk information is `df -h`"
	    ;;
	9) echo "CPU information is `cat /proc/cpuinfo`"
	    ;;
	10) echo "Memory Informations is `grep | cat /proc/meminfo`"
	    ;;
	11) echo "File system information is `df -Th | grep "^/dev"`"
	    ;;
	12) echo "Currently running process is `ps -aux`"
	    ;;
	*) echo "Error : Invalid option, please enter valid option"
	    ;;
    esac
read -p "Do you want to continue(y/n) ? " yn

if [ $yn = "y" -o $yn = "Y" ]
then
    flag=1
else
    flag=0
fi
done

