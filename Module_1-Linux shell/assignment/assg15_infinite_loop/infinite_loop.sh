<<Documentation
Name : Munawir E
Date : 21/04/2022
Description : Use pipes or redirection to create an infinite feedback loop.

Sample I/P  : Before loop file contents
Hai hello

Sample O/P  : After loop file contents
Hai hello
Hai hello
Hai hello
Hai hello
Hai hello
Hai hello
Hai hello
.
.
.

Documentation

#! /bin/bash

echo "Hai hello" >> file.txt			# Hai hello is stored in file called file.txt (using redirection).
tail -f  file.txt >> file.txt | tail -f file.txt	# Follow output append as the file grows
