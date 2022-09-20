<<Documentation
Name : Munawir E
Date : 07/05/2022
Description : LS project to for taking test through terminal and display output.

Sample I/P  :

****************************************************************************
*     __________     Welcome to command line test exam!     __________     *
*                                                                          *
****************************************************************************
1) Sign Up.
2) Sign In.
3) Exit

What do you want to do ? 2
Enter the username : zxc
Enter the log in password : 

You Have scussefully log in

1) Take test now 
2) Exit. 

Enter your choice : 1
1. What is the command to find your current shell?
a. echo $BASH
b. echo $SHELL
c. echo $SH
d. echo $shell

 Choose option 9 :  a

2. Which command will give OS details on Linux
a. sysinfo -l
b. sysinfo -a
c. uname -a
d. ifconfig

 Choose option 10 : 

3. Which one causes an error while assigning a variable in scripting?
a. $COUNT=$PATH
b. COUNT=$PATH
c. COUNT="$PATH"
d. COUNT='$PATH'

 Choose option 10 : 

4. How to print or access VALUE of shell variables?
a. @
b. $
c. *
d. #

 Choose option 9 :  c

5. How can you run two commands in shell, and print the output of both the command?
a. ls & date
b. ls | date
c. ls ; date
d. ls , date

 Choose option 5 : c

6. How to change the permission to read only
a. chmod 700 file
b. chmod 600 file
c. chmod 400 file
d. chmod 200 file

 Choose option 9 :  c

7. What is the o/p of this command echo "expr 6 + 3"
a. None
b. 9
c. expr 6 + 3 is printed
d. Syntax Error

 Choose option 1 :  

8. What does this do? head -15 /etc/hosts
a. Prints first 15 lines from the file
b. Print everything except the last 15 lines from the file
c. Prints the first 15th character from the file
d. prints the last 15 lines from the file

 Choose option 1 :  


Sample O/P  :


#######################################################
#                                                     #
#                  YOUR  RESULT IS                    #
#                                                     #
#######################################################


 1. What is the command to find your current shell?
    a. echo $BASH
    b. echo $SHELL
    c. echo $SH
    d. echo $shell

Wrong Answer
    b. echo $SHELL  is correct is correct answer


 2. Which command will give OS details on Linux
    a. sysinfo -l
    b. sysinfo -a
    c. uname -a
    d. ifconfig

Correct Answer

 3. Which one causes an error while assigning a variable in scripting?
    a. $COUNT=$PATH
    b. COUNT=$PATH
    c. COUNT="$PATH"
    d. COUNT='$PATH'

Correct Answer

 4. How to print or access VALUE of shell variables?
    a. @
    b. $
    c. *
    d. #

Correct Answer

 5. How can you run two commands in shell, and print the output of both the command?
    a. ls & date
    b. ls | date
    c. ls ; date
    d. ls , date

Wrong Answer
    c. ls ; date  is correct is correct answer


 6. How to change the permission to read only
    a. chmod 700 file
    b. chmod 600 file
    c. chmod 400 file
    d. chmod 200 file

Wrong Answer
    c. chmod 400 file  is correct is correct answer


 7. What is the o/p of this command echo "expr 6 + 3"
    a. None
    b. 9
    c. expr 6 + 3 is printed
    d. Syntax Error

Wrong Answer
    c. expr 6 + 3 is printed  is correct is correct answer


 8. What does this do? head -15 /etc/hosts
    a. Prints first 15 lines from the file
    b. Print everything except the last 15 lines from the file
    c. Prints the first 15th character from the file
    d. prints the last 15 lines from the file

Time Out


Total correct answer 3/8


Documentation

#! /bin/bash

echo -e "\e[1m\e[96m****************************************************************************\n*     __________     \e[4mWelcome to command line test exam!\e[0m\e[1m\e[96m     __________     *\n*                                                                          *\n****************************************************************************\e[0m"			# Showing the welcome message to user.
resultdisplay ()				# Function to display the user's test result.
{
    echo -e "\n\n\e[34m#######################################################\n#                                                     #\n#                  \e[4m\e[1mYOUR  RESULT IS\e[0m\e[34m                    #\n#                                                     #\n#######################################################\e[0m\n\n"          		# Display the title of result section.
    total=`wc -l result.txt | cut -d " " -f1`			# Storing total number of answers available in result.txt.
    line=`wc -l question.txt |cut -d " " -f1`			# Storing total number of line present in question.txt.
    answer=(`cat correct_answer.txt`)				# Storing correct answer in array.
    index=1							# Assigning index is 1.
    
    
    for i in `seq 5 5 $line`					# Depends upon number of questions available in question.txt loop will run.				
    do	
	cat question.txt | head -$i | tail -5			# Displaying the question with option to the user.
	echo 
	result=`sed -n "$index p"  result.txt`			# Storing the user's test results one by one.
	echo -e "   $result"						# Printing the User's result

	wrong=`echo $result | cut -c 6-10`			# Storing the character from 6-10 containing inside result.
	

        # if the user answer is wrong it display the correct answer to the user while displaying output.
	
	if [ "$wrong" = "Wrong" ]       # Comparing the strings are equal or not.
	then

	    if [ "${answer[$(($index-1))]}" = 'a' ]      									# Checking the correct answer is option a.
	    then
		echo -e "\e[38;5;166m`cat question.txt | head -$i | tail -4 | sed -n '1p'`\e[0m is correct is correct answer\n"			# If the correct answer is option "a" it display the output.
	    elif [ "${answer[$(($index-1))]}" = 'b' ]										# Checking the correct answer is option b.
	    then
		echo -e "\e[38;5;166m`cat question.txt | head -$i | tail -4 | sed -n '2p'`\e[0m  is correct is correct answer\n"			# If the correct answer is option "b" it display the output.
	    elif [ "${answer[$(($index-1))]}" = 'c' ]										# Checking the correct answer is option c.
	    then
		echo -e "\e[38;5;166m`cat question.txt | head -$i | tail -4 | sed -n '3p'`\e[0m  is correct is correct answer\n"			# If the correct answer is option "c" it display the output.
	    elif [ "${answer[$(($index-1))]}" = 'd' ]										# Checking the correct answer is option d.
	    then
		echo -e "\e[38;5;166m`cat question.txt | head -$i | tail -4 | sed -n '4p'`\e[0m  is correct is correct answer\n"			# If the correct answer is option "d" it display the output.
	    fi
	fi
	index=$(($index+1))				# Incrementing the value of index by one.
	echo

    done

    echo -e "\nTotal correct answer $count/$total\n"		# Displaying the marks got by the user in test.

    
    `rm result.txt;rm useranswer.txt`				#removing the result file and useranswer file.
}



answercheck ()					# Function to Evaluate user's test.
{
    useranswer=(`cat useranswer.txt`)		# Storing user's answer into an array.
    answer=(`cat correct_answer.txt`)		# Storing the correct answer to an array.
    length=$((${#answer[@]}-1))			# Storing the length of array-1.
    count=0					# Assigning count is zero.
    for i in `seq 0 $length`			# Depends upon the length value loop will run.
    do
	if [ ${useranswer[$i]} = ${answer[$i]} ]	# Checking useranswer is correct or not.
	then
	    `echo -e "\e[32mCorrect Answer\e[0m" >> result.txt`		# If answer is correct "correct answer" will be appended to result.txt.
	    count=$(($count+1))						# Incrementing the value of count.
	elif [ ${useranswer[$i]} = 'e' ]				# Checking useranswer is equal to e.
	then
	    `echo -e "\e[33mTime Out\e[0m" >> result.txt`		# If useranswer is e "time out" will be appended to result.txt.
	else								# Checking useranswer is wrong answer.
	    `echo  -e "\e[31mWrong Answer\e[0m" >> result.txt`		# If useranswer is wrong "wrong answer will be appended to result.txt.
	fi
    done
    resultdisplay								# Function call for display result.
}


taketest ()					# Function to write the exam/take the test.
{
    line=`wc -l question.txt |cut -d " " -f1`	# Storing total number of lines present in question.txt.

    for i in `seq 5 5 $line`			# Depends upon number of questions available in question.txt loop will run.
    do
	cat question.txt | head -$i | tail -5	# Displaying the question with option to the user.
	echo 
	
	for j in `seq 9 -1 0`			# The loop will run from sequence of 10-1 times with iteration of -1 (currently used for display timer value) 
	do
	    read -n 1 -t 1  option		# Reading the answers option from user with timer of 1s refresh time.
	    echo -ne "\r Choose option $j : \c" # Display the timer to user.
	    
	    if [ $option ]			# Checking option has anyvalues.
	    then
		break				# If option has anyvalue then it will come out of the loop.
	    fi
	done    
	echo -e "\n"				# Printing newline.
	
	if [ -z $option ]			# Checking the option string length is equal to zero.
	then
	    option='e'				# Assigning the value for option is equal to 'e'.
	    `echo "$option" >> useranswer.txt`  # Appending the value of option to useranswer.txt
	else
	    `echo "$option" >> useranswer.txt`  # Appending the value of option to useranswer.txt
	fi

    done
    answercheck					# Function call for Evaluate/validate the  result.

}

login ()					# Function to Display options after sign in.
{
    echo -e "1) Take test now \n2) Exit. \n"	# Displays the options available after.
    read -p "Enter your choice : " choice 	# To read the user's choice.

    case $choice in				# According to the user's choice case will jump to the option.
	1) taketest				# Function call for write/take the test.
	    ;;
	*) exit					# Default case to exit the program
    esac
}

password ()					# Function for adding user sign up password.
{
    echo -e "\nEnter Your Password : "		# Display the contents.
    read -s  password1				# Reading password in hidden mode.

    echo -e "\nRe-Enter  Your Password : "	# Display the contents.
    read -s password2				# Reading password in hidden mode.
    
    if [ $password1 = $password2 ]		# Checking the password1 and passwowd2 is matched or not.
    then
	`echo $username >> user.csv`		# If the value of count is zero then username will append to user.csv.
	`echo "$password2" >> password.csv`	# Password is appending to password.csv
	echo -e "\n\t\e[1m\e[38;5;32m  YOU HAVE SUCCESSFULLY CREATED THE ACCOUNT\e[0m\n"	# Display the message to user that creating the account is success.
	main					# Function call for main function.
    else
	echo -e "\n\t\e[5m\e[1m\e[38;5;124m THE PASSWORD YOU ENTERED DO NOT MATCH, PLEASE RE-ENTER YOUR PASSWORD\e[0m"		# Display error message when the passwords are mismatch.
	password				# Function call for fuction password.
    fi
}

signup ()				# Function for user sign up.
{
    read -p "Enter username : " username	# Reading the username.
    userdata=(`cat user.csv`)			# Storing the contents of user.csv into an array.
    count=0					# Assigning th value of count to zero.

    for i in ${userdata[@]}			# Depending upon the contents inside userdata the loop wil run.
    do
	if [ $username = $i ]			# Checking the Username is present in user.csv or not.
	then
	    count=$(($count+1))                 # IF username present, Increment the value of count.
	fi
    done

    if [ $count -eq 0 ]				# Checking the count value is equal to zero.
    then
	password				# Function call for password function.
    else
	echo -e "\n\t\e[5m\e[1m\e[38;5;11m USERNAME IS ALREADY EXISTS, PLEASE TRY ANOTHER USERNAME\e[0m\n"	# Display error message when the username is already present in user.csv.
	signup					# Function call for signup function.
    fi
}

signin ()						# Function used for sign in process.
{
    read -p "Enter the username : " username		# Reading the username.
    
    userdata=(`cat user.csv`)				# Stroring user.csv into an array.
    passworddata=(`cat password.csv`)			# Storing password.csv into an array.
    length=${#userdata[@]}				# Storing the length of array-1.
    count=0						# Assigning count equal to zero.

    for i in `seq 0 $(($length-1))`			# Depends upon the length of array value loop will run.
    do

	if [ ${userdata[$i]} = $username ]		# Checking the Username is present in user.csv or not.
	then
	    count=$(($count+1))				# Incrementing the value of count.
	    position=$i					# Storing the value of i in position.
	fi
    done

    if [ $count -gt 0 ]					# Checking the count is greater than zero.
    then

	signinpassword ()				# Function to check password match to authenticate sign in process
	{	
	    read -s -p "Enter the log in password : " password1		# Reading the password in hidden mode.
	    echo

	    if [ $password1 = ${passworddata[$position]} ]		# Checking the password1 is matching to the specified user.
	    then
		echo -e "\n\t\e[1m\e[38;5;32m YOU HAVE SUCCESSFULLY LOGGED IN. \e[0m\n"	# Display the message of successful login.
		login				# Function call for login function.
	    else
		echo -e "\n\t\e[5m\e[1m\e[38;5;124m YOU HAVE ENTERED WRONG PASSWORD,PLEASE RE-ENTER THE PASSWORD \e[0m\n"	# Display error message if user entered wrong password.
		signinpassword		# Function call for signin password.
	    fi
	}
    signinpassword			# Function call for signin password.
else
    echo -e "\n\t\e[5m\e[1m\e[38;5;124m USERNAME IS NOT VALID OR REGISTERED. \e[0m\n\t\e[5m\e[1m\e[38;5;124m     PLEASE CREATE A NEW ACCOUNT.     \e[0m" " "   			# Display error message if the username is not valid.
    signup		   # Function call for sign up.
    fi

}

main ()					# Main function of the program.
{
    echo -e "1) Sign Up.\n2) Sign In.\n3) Exit\n"	# Display the option.
    read -p "What do you want to do ? " choice		# Read the user's choice.
    case $choice in				# According to the user's choice case will jump to the option.
	1) signup				# Function call for sign up function.
	    ;;
	2) signin				# Function call for sign in function.
	    ;;
	*) exit					# Default case.
    esac
}

main							# Function call, where the program begins.

