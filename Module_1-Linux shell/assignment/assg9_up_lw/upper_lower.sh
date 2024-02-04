<<Documentation
Name : Munawir E
Date :20/04/2022
Description : Write a script to rename a file/directory replaced by lower/upper case letters
Sample I/P  : Before running the script
 	      $ ls
	      File.txt MyScript.SH MyFile007.txt dir/ Assign1/ newfolder/
Sample O/P  : $ ./file_upper_lower.sh
	      Files are rename in lowercase and directories are renamed in upper case
	      $ ls
	      file.txt myfile007.txt myscript.sh DIR/ ASSIGN1/ NEWFOLDER/
Documentation

#! /bin/bash
array=`(ls)`	# Storing file and directory in current working directory to array.

for i in $array	# Loop will run until array element  is empty.
do
 
  if  [ -d "$i" ]	# Checking i is file or not.
  then
	mv $i `echo $i | tr a-z A-Z`	# Renaming the file to lower case.
   elif [ -f "$i" ]	# Checking i directory or not.
   then
	mv $i `echo $i | tr A-Z a-z`	# Renaming the directory to upper case.
  fi
done

