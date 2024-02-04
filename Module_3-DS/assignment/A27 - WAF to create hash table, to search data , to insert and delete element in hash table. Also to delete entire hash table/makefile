a.out : main.o create_HT.o delete_element.o delete_HT.o display_HT.o insert_HT.o search_HT.o
	gcc -o a.out main.o create_HT.o delete_HT.o delete_element.o display_HT.o insert_HT.o search_HT.o
main.o : main.c
	gcc -c main.c
create_HT.o : create_HT.c
	gcc -c create_HT.c
insert_HT.o : insert_HT.c
	gcc -c insert_HT.c
search_HT.o : search_HT.c
	gcc -c search_HT.c
display_HT.o : display_HT.o
	gcc -c display_HT.c
delete_element.o : delete_element.c
	gcc -c delete_element.c
delete_HT.o : delete_HT.c
	gcc -c delete_HT.c
clean : 
	rm *.out *.o
