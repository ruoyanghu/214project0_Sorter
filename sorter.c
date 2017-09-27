#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
typedef struct row {
    char rowString[5000];
    char targetCol[100];
} Row;
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
    int read = 0, write = 0;
    int enClosed = 0;
    int zero = 0;

    while (row[read] != '\0') {
        if (row[read] == ' ') {
            zero++;
            read++;
        } else {
            if (row[read] == '"') {
                enClosed = !enClosed;

            }
            if (zero != 0) {

                //nonComma&Comma;criComma
                if (row[read] == ',' && !enClosed) {
                }

                else {

                    //write zero
                    int i;

                    for (i = 0; i <= zero; i++) {
                        row[write + i] = ' ';
                    }
                    write = write + zero + 1;
                }
            } else {

                //move write 1
                row[write] = row[read];
                write++;
            }

            read++;
        }
    }
}
//give string, give comma num, return the sort column string
char *getCriticalCol(char *row, int num)
{

    //return the column string
    int commaCounter = 0;
    int charCounter = 0;
    int colPtr = 0;
    int enClosed = 0;
   char *criticalCol = (char *)malloc(sizeof(char) * 500);;


    cleanBuffer(criticalCol, 100);
    while (row[charCounter] != '\0') {
        if (row[charCounter] == '"') {
            enClosed = !enClosed;
        }
        if (row[charCounter] == ',' && enClosed) {

            //criticalComma
            commaCounter++;
            if (commaCounter > num) {
                break;
            }
            continue;
        } else {

            //if comma, treat as nonComma
            if (commaCounter == num) {
                criticalCol[colPtr] = row[charCounter];
                colPtr++;
            }
            charCounter++;
        }
    }
	return criticalCol;
}
Row parse(char *row, int commaNum)
{

    //give a row string, parse it to Row struct
	Row newRow;
    trim(row);
	
	strcpy(newRow.rowString,row);
	strcpy(newRow.targetCol,getCriticalCol(row,commaNum));
	
	return newRow;
} 

int findCommaNum(char *buffer, char *target)
{
    int num = -1;
    int cursorCounter = 0;
    int found = 0;
    char cursor = buffer[cursorCounter];
    int ptr = 0;
    char columnBuffer[100];

    cleanBuffer(columnBuffer, 100);
    int isEnclosed = 0;

    while (cursor) {
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
	printf("%s\n","start");
	
	
	printf("argc is %d\n",argc);
	
	if(argc!=3){
		printf("%s\n","argc wrong");
	}
    char *a1 = argv[1];
    char *sortColumn = argv[2];
    printf("%s\n",a1);
	printf("%s\n",sortColumn);

	//check format
	
    //error message
    char buffer[5000];
	//first line
    gets(buffer) ;
	int commaNum = findCommaNum(buffer,sortColumn);
	if(commaNum==-1){
		//error message
		return 0;
	}
    Row* list;
	int rowCounter = 0;
	list = (Row *)malloc(sizeof(Row));
    while (gets(buffer)) {
		//create a list of struct
		Row newRow = parse(buffer,commaNum);
		
		list = (Row*)realloc(list,sizeof(Row)*rowCounter);
		memcpy(list+rowCounter,&newRow,sizeof(Row));
		printf("col is, %s\n",list[rowCounter].targetCol);
    }
	//finish generate list
	//using merge sort on the list
	free(list);
   return 0; 
}

