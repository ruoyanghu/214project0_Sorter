#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

typedef struct row {
    char rowString[1000];
    char targetCol[500];
} Row;

void cleanBuffer(char *buffer, int size);
void trim(char *row);
char *getCriticalCol(char *row, int num);
Row *parse(char *row, int commaNum);
int findCommaNum(char *buffer, char *target);
