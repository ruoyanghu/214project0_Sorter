#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include "mergesort.h"







void cleanBuffer(char *buffer, int size);
void trim(char *row);
char *getCriticalCol(char *row, int num);
Row *parse(char *row, int commaNum);
int findCommaNum(char *buffer, char *target);
void mergesort(Row* list,int low, int high, int isString);
