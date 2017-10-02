
//gcc -g sorter.c -o sorter &&  ./sorter -c duration <movie.csv
//valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./sorter -c movie_facebook_likes <movie_full.csv
#include "mergesort.c"
#include "sorter.h"



int getType(Row * list)
{
    //return 1 if string
    //return 0 if float
    int isString = 0;
    char *col = list[0].targetCol;
    int counter = 1;
	int dotCounter=0;

    //check the first char, if is a digit, continue to check the whole column
	if(col[0]=='.')
		dotCounter++;
    if(isdigit(col[0])||col[0]=='.'||col[0]=='-'){
		while (col[counter]) {
			
			if(col[counter]=='.'){
				dotCounter++;
			}
			if(dotCounter>1 || !isdigit(col[counter])){
				isString=1;
				break;
			}
		}
	}else{
		isString=1;
	}
    return isString;
}

void cleanBuffer(char *buffer, int size)
{
    int i = 0;

    while (i <= size - 1) {
        buffer[i] = '\0';
        i++;
    }
}
void trim(char *row)
{
    int read = 0, write = 0, zero = 0;
    int enClosed = 0;
    int comma = 1;

    while (row[read]) {
        if (row[read] == ' ') {
            zero++;
            read++;
        } else {
            if (row[read] == '"') {
                enClosed = !enClosed;
            }
            //criComma
            if (row[read] == ',' && !enClosed) {
                comma = 1;
                row[write] = row[read];
                write++;
                read++;
                zero = 0;
                continue;
            }
            //nonComma&nonCriComma
            else {
                if ((!comma) && (zero != 0)) {

                    //write zero
                    int i;

                    for (i = 0; i < zero; i++) {
                        row[write + i] = ' ';
                    }
                    write = write + zero;
                }
                comma = 0;
                row[write] = row[read];
                write++;
                read++;
                zero = 0;
            }
        }
    }
    row[write] = row[read];
    //printf("trim:%s\n", row);
}

//give string, give comma num, return the sort column string
char *getCriticalCol(char *row, int num)
{

    //return the column string
    int commaCounter = 0;
    int charCounter = 0;
    int colPtr = 0;
    int enClosed = 0;
    char *criticalCol = (char *)malloc(sizeof(char) * 500);

    cleanBuffer(criticalCol, 500);
    while (row[charCounter] != '\0'&&row[charCounter] != '\n'&&row[charCounter] != '\r') {
        if (row[charCounter] == '"') {
            enClosed = !enClosed;
        }
        if (row[charCounter] == ',' && !enClosed) {

            //criticalComma
            commaCounter++;
            if (commaCounter > num) {

                break;
            }

        } else {

            //if comma, treat as nonComma
            if (commaCounter == num) {
                if (row[charCounter] != '"') {
                    criticalCol[colPtr] = row[charCounter];
                    colPtr++;
                }

            }

        }
        charCounter++;
    }

    criticalCol[colPtr] = '\0';
    return criticalCol;
}

Row *parse(char *row, int commaNum)
{

    //give a row string, parse it to Row struct
    Row *newRow = (Row *) malloc(sizeof(Row));

    trim(row);
    strcpy(newRow->rowString, row);
    char *criCol = getCriticalCol(row, commaNum);

    strcpy(newRow->targetCol, criCol);
    free(criCol);
    //printf("target: %s\n", newRow->targetCol);
    return newRow;
}

int findCommaNum(char *buffer, char *target)
{
    int num = -1;
    char cursor = 'a';
    int cursorCounter = 0;
    int found = 0;
    int ptr = 0;
    char columnBuffer[100];

    cleanBuffer(columnBuffer, 100);
    int isEnclosed = 0;

    while (cursor) {
        cursor = buffer[cursorCounter];
        if (cursor == '"') {
            isEnclosed = !isEnclosed;
        }

        else if (cursor == ',') {
            if (!isEnclosed) {

                //effective comma
                num++;
                if (strcmp(columnBuffer, target) == 0) {
                    cleanBuffer(columnBuffer, 100);
                    found = 1;
                    break;
                } else {
                    //compare not successful
                    cleanBuffer(columnBuffer, 100);
                    ptr = 0;
                }
            } else {
                columnBuffer[ptr] = cursor;
                ptr++;
            }
        } else {
            columnBuffer[ptr] = cursor;
            ptr++;
        }
        cursorCounter++;
    }
    if (columnBuffer[0] != '\0') {
        num++;
        columnBuffer[ptr - 1] = '\0';
        columnBuffer[ptr - 2] = '\0';
        columnBuffer[ptr - 3] = '\0';
        if (strcmp(columnBuffer, target) == 0)
            found = 1;
    }
    if (found) {
        return num;
    } else
        return -1;
}
int main(int argc, char *argv[])
{
    //printf("argc is %d\n", argc);
    if (argc != 3||!strcmp(argv[1],"-c")) {
        printf("%s\n", "argc wrong");
		return 0;
    }
    
    char *sortColumn = argv[2];

    //check format
    //error message
    char buffer[5000];

    //first line
    fgets(buffer, 5000, stdin);
	printf("%s",buffer);
    int commaNum = findCommaNum(buffer, sortColumn);

    if (commaNum == -1) {
        //error message
        return 0;
    }
    Row *list;
    int rowCounter = 0;

    list = (Row *) malloc(sizeof(Row));
    //printf("while loop \n");
    while (fgets(buffer, 5000, stdin)) {
        //printf("buffer is \n%s\n", buffer);
        //create a list of struct
        Row *newRow = parse(buffer, commaNum);

        memcpy(list + rowCounter, newRow, sizeof(Row));
        free(newRow);
        //printf("col is, %s\n", list[rowCounter].targetCol);
        rowCounter++;
        //printf("realloc = %d\n", rowCounter);
        list = (Row *) realloc(list, sizeof(Row) * (rowCounter + 1));
        // if (list == NULL) {
            // printf("null pointer \n");
            // return 0;
        // }
    }

    //finish generate list
    //check type, give merge sort an input

    //using merge sort on the list
    //print
    //printf("row type is: %d\n", getType(list));
	int i = 0;
    // for (i = 0; i < rowCounter; i++) {
        // printf("%s\n", list[i].targetCol);
    // }
	
	
	
    mergesort(list, 0, rowCounter - 1, getType(list));
    

    for (i = 0; i < rowCounter; i++) {
        printf("%s", list[i].targetCol);
    }
    free(list);
    return 0;
}
