/*
Name : Munawir E
Date : 27/07/2022
Description : Provide a menu to manipulate or display the value of variable of type t.
 Pr-requisites:-
  * Pointers
  * Dynamic memory allocation
 Objective: -
  * Dynamic memory allocation

Sample I/P  :
 1) 1. Add element
    2. Remove element
    3. Display element
    4. Exit from the program

    Choice ---> 1
    Enter the type you have to insert:
    1. int
    2. char
    3. float
    4. double
    Choice ---> 2
    Enter the char : k
    1. Add element
    2. Remove element
    3. Display element
    4. Exit from the program
    Choice ---> 3

    1. Add element
    2. Remove element
    3. Display element
    4. Exit from the program
    Choice ---> 1
    Enter the type you have to insert:
    1. int
    2. char
    3. float
    4. double
    Choice ---> 1
    Enter the int : 10
    1. Add element
    2. Remove element
    3. Display element
    4. Exit from the program
    Choice ---> 3

    1. Add element
    2. Remove element
    3. Display element
    4. Exit from the program

    Choice ---> 2
    0 -> k
    1 -> 10

    1. Add element
    2. Remove element
    3. Display element
    4. Exit from the program
    Choice ---> 4

Sample O/P  :
 1) -------------------------
    0 -> k
    -------------------------

    ------------------------
    0 -> k (char)
    1 -> 10 (int)
    ------------------------

    Enter the index value to be deleted : 0
    index 0 successfully deleted.
*/

#include <stdio.h> 
#include <stdlib.h>

int main()
{
    // Initializing the variables.
    int choice, option, flag_c1 = 0, flag_c2 = 0, flag_i = 0, flag_f = 0, flag_d = 0,flag_sh = 0, i;
    void *array = malloc( 8 * 1), *ptr = array;
    int num;
    char char1, char2;
    short short1;
    float float1;
    double double1;
    
    while( 1 )
    {
        printf("Menu :\n1. Add element\n2. Remove element\n3. Display element\n4. Exit from the program\n");
        printf("Choice ---> ");
        scanf("%d", &choice);

        // Adding elements.
        if( choice == 1 )
        {
            printf("Enter the type you have to insert:\n");
            printf("1. int\n2. char\n3. short\n4. float\n5. double\nChoice ---> ");
            scanf("%d", &option );
    
            if( option == 1 && flag_i == 0 && flag_f == 0 && flag_d == 0 )
            {
                // For adding integer value.
                printf("Enter the int : ");
                scanf("%d", &num);
                *((int *)ptr + 4)= num;
                flag_i++;
            }
            else if( option == 2 && (flag_c1 == 0 || flag_c2 == 0) && flag_d == 0)
            {
                // For adding characters.
                if(flag_c1 == 0)
                {
                    printf("Enter the char : ");
                    scanf("\n%c", &char1);
                    *((char*)ptr + 0) = char1;
                    flag_c1++;
                }
                else
                {
                    printf("Enter the char : ");
                    scanf("\n%c", &char2);
                    *((char*)ptr + 1) = char2;
                    flag_c2++;
                }
            }
            else if( option == 3 && flag_sh == 0 && flag_d == 0 )
            {
                // For adding short values.
                printf("Enter the short : ");
                scanf("%hd", &short1);
                *((short*)ptr + 2) = short1;
                flag_sh++;
            }
            else if( option == 4 && flag_f == 0 && flag_i == 0 && flag_d == 0)
            {
                // For adding float values.
                printf("Enter the float : ");
                scanf("%f", &float1);
                *((float*)ptr + 4) = float1;
                flag_f++;
            }
            else if( option == 5 && flag_c1 == 0 && flag_c2 == 0 && flag_f == 0 && flag_i == 0 && flag_d == 0)
            {
                // For adding double values
                printf("Enter the double : ");
                scanf("%lf", &double1);
                *((double*)ptr + 0) = double1;
                flag_d++;
            }
            else
            {
                printf("Not enough memory\n");
                break;
            }

        }
        else if( choice == 2 )      // Removing the elements.
        {
            if( flag_c1 == 0 && flag_c2 == 0 && flag_sh == 0 && flag_i == 0 && flag_f == 0 && flag_d == 0 )
            {
                printf("Array is empty\n");
            }
            else
            {   
                // Displaying the available elements with it's index values.
                i = 0;
                if( flag_c1 == 1)
                {
                    printf("%d-> %c\n", i++, char1);
                }
                if( flag_c2 == 1)
                {
                    printf("%d-> %c\n", i++, char2);
                }
                if( flag_sh == 1)
                {
                    printf("%d-> %hd\n", i++, short1);
                }
                if( flag_i == 1 )
                {
                    printf("%d-> %d\n", i++, num);
                }
                if( flag_f == 1)
                {
                    printf("%d-> %f\n", i++, float1);
                }
                if( flag_d == 1)
                {
                    printf("%d-> %lf\n", i++, double1);
                }

                // Removing the elements according to the index value.
                i = 0;
                int index;
                printf("Enter the index value to be deleted : ");
                scanf("%d", &index);
                if( flag_c1 == 1 && index == i++ )
                {
                    flag_c1 = 0;
                }
                if( flag_c2 == 1 && index == i++ )
                {
                    flag_c2 = 0;
                }
                if( flag_sh == 1 && index == i++ )
                {
                    flag_sh = 0;
                }
                if( flag_i == 1 && index == i++ )
                {
                    flag_i = 0;
                }
                if( flag_f == 1 && index == i++ )
                {
                    flag_f = 0;
                }
                if( flag_d == 1 && index == i++ )
                {
                    flag_d = 0;
                }
                printf("index %d successfully deleted.", index);
            }
        }
        else if( choice == 3)
        {
            // Displaying the elements.
            if( flag_c1 == 0 && flag_c2 == 0 && flag_sh == 0 && flag_i == 0 && flag_f == 0 && flag_d == 0 )
            {
                printf("Array is empty");
            }
            else
            {
                for( i = 0; i < 15; i++) printf("-");
                printf("\n");
                i = 0;
                if( flag_c1 == 1)
                {
                    printf("%d-> %c (char)\n", i++, char1);
                }
                if( flag_c2 == 1)
                {
                    printf("%d-> %c (char)\n", i++, char2);
                }
                if( flag_sh == 1)
                {
                    printf("%d-> %hd (short)\n", i++, short1);
                }
                if( flag_i == 1 )
                {
                    printf("%d-> %d (int)\n", i++, num);
                }
                if( flag_f == 1)
                {
                    printf("%d-> %f (float)\n", i++, float1);
                }
                if( flag_d == 1)
                {
                    printf("%d-> %lf (double)\n", i++, double1);
                }

                for( i = 0; i < 15; i++) printf("-");
                printf("\n");
                
            }
        }
        else if( choice == 4 )
        {
            // Exit from program.
            break;
        }
        else
        {
            printf("Invalid Option.\n");
        }
    }
}