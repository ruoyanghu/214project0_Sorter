9/20/2017
214 assignment
project 0

//read data as struct, each struct include two char array, the first one is the whole row as a string, which is stored as char array, the second one is the string of the column which will be used to compare, which is also stored as a char array. The first lind of the input, which is the title, will not be included in the struct array. In the struct array(called "list" in the code), I get access to each struct by using:
list[counter], in which "counter" is an integer and is the index of the array. In order to find the critical column(which is the column that the user wants to use to do the comparison), I will use a method to do string compare(strcmp) and find the input target column, and store the comma number after which comma is the target, and retrun the number. In the process of parsing and building the struct array, I will use another method, which will take the comma number as input to get  from each data row, the critical column that will be used to do the comparison. Also, I have a trim method, which use two pointer, read and write, to trim the space before and after comma. After the struct array is built, the code will call a method from "mergesort.c" which will recursively do the mergesort and change the order of struct in the struct array by memory copy(memcpy). In the end, the code will use a loop to print the row string of the revised sorted struct array by each struct. The title string row will be printed just after it was read, so I will have a nice output file with title and sorted rows according to the target column that the user gave.

//assumption:
I assume for each row, it will not exceed 1000 characters. If the user has a greater input row size, he/she should revise the code.
For each column, it will not exceed 500 characters. Same as the row input if the user has greater columns.
No column title will be empty.

//how to use the code:
Please include mergesort.c, mergesort.h, sorter.c, sorter,h in the same folder.
After you compile the c code on ilab, using the following code to run:
cat input.csv | ./sorter -c  <column you want to sort>      > output.csv
No other arguments beside "-c" is allowed, if the format is wrong, the code will send error messege.
The input file should follow the standard format of a cvs file, and also follow all the previous assumption(size/empty colums/etc.)

//difficulties:
-header file: mergesort.c and mergesort.h, in order to have my struct recognized by the seperated file mergesort.c I created a new header file for the mergesort.c called mergesort.h or else the program is not possible to be compiled with only one header file, sorter.h. In sorter.h it includes mergesort.h
In mergesort.c it includes mergesort.h and sorter.h
In sorter.c it includes mergesort.c and sorter.h
I think the reference of header file is a difficulty.

-struct

-seg fault

-scan

-trim

-group communication
