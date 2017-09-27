#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <ctype.h>
#include <datetimeapi.h>
#include "sorter.h"

//string
//num
//datetime
void swap(a, b) {
	a ^= b;
	b ^= a;
	a ^= b;
}

int main(int argc, char * argv) {
	
	int i = 0;
	//counter indicates the first place that has a value
	int counter = 0;
	char* tmp = NULL;

	for (i = 0; i < strlen(list); i++)
	{
		//put '\0' to the front
		/*if (isspace(list[i])) {

		swap(needtosort[counter], needtosort[i]);
		counter++;
		}*/
		if (list.targetCol[i] == NULL || list.targetCol[i] == '\0') {
			strcpy(tmp, list.targetCol[i]);
			strcpy(list[counter], list.targetCol[i]);
			strcpy(list.targetCol[i], tmp);
			counter++;
		}

	}


		//判斷type
	int dig = 0;
	int db = 0;
	int a = 0;
	for (i = 0; i < strlen(list.targetCol[counter]); i++) {
		if (isalpha(list[counter].targetCol[i])) {
			a++;
		}
		if (isdigit)
		{
			dig++;
		}
		if (list[counter].targetCol[i] == '.')
		{
			db++;
		}
	}
	
	
	//sort string
	if (a > 0 && db != 1) {

		lexi(list, counter);

	}

	//sort int

	if (a = 0 && db == 0) {

	//regular mergesort number

		int a = 0;
		
		//print null
		for (a = 0; a < counter; a++) {
		//	printf(needtosort[a]);
		}

		mergeint(list, counter, strlen(list)-1);

	}
	//sort float
	if (a = 0 && db = 1 && dig > 0) {
		mergefloat(list, counter, strlen(list)-1);
	}

	return 0;
}

char lexi(char * needtosort, int counter)
{
	int first, second;
	char* tmp;
	for (first = counter; first<(strlen(needtosort) - 1); first++)
		for (second = first + 1; second<strlen(needtosort); second++)
		{
			if (strcmp(needtosort[first], needtosort[second])>0)
			{

				strcpy(tmp, needtosort[first]);
				strcpy(needtosort[first], needtosort[second]);
				strcpy(needtosort[second], tmp);

				//swap(needtosort[first], needtosort[second]);
			}
		}

	for (first = 0; first<strlen(needtosort); first++)
	{
		printf("%s\n", needtosort[first]);
	}

	return 0;
}

//divide
int mergeint(void * needtosort, int start, int end) {
	int * input[] = (int*)needtosort;
	int mid = (end - start) / 2;
	if (start = end) { return; }

	int * Left;
	int * Right;
	Left = (int*)malloc(mid * sizeof(int));
	Right = (int*)malloc((end - mid) * sizeof(int));

	int i = 0;

	for (i = 0; i < mid; i++) {
		Left[i] = input[i];
	}

	for (i = mid; i < end; i++) {
		Right[i - mid] = input[i];
	}


	mergeint(Left,0,mid);
	mergeint(Right, end - mid,end);
	intmerge(input, Left, mid, Right);

	free(Left);
	free(Right);
}

//conqur
int intmerge(int* input, int *left, int mid, int *right) {
	int *output[] = sizeof(input);
	int ptr = 0;
	int L = 0;
	int R = 0;

	while (L<strlen(left) && R< strlen(right)) {
		if (left[L] < right[R]) {
			output[ptr++] = left[L++];
		}
		else {
			output[ptr++] = right[R++];
		}
	}
	while (L < strlen(left)) {

		output[ptr++] = left[L++];

	}

	while (R < strlen(right)) {

		output[ptr++] = right[R++];

	}

	for (ptr = 0; ptr < strlen; ptr++) {
		puts(output[ptr]);
	}

}

//divide
float mergefloat(void * needtosort, int start, int end) {
	float * input[] = (float*)needtosort;
	int mid = (end - start) / 2;
	if (start = end) { return; }

	float * Left;
	float * Right;
	Left = (float*)malloc(mid * sizeof(float));
	Right = (float*)malloc((end - mid) * sizeof(float));

	int i = 0;

	for (i = 0; i < mid; i++) {
		Left[i] = *input[i];
	}

	for (i = mid; i < end; i++) {
		Right[i - mid] = *input[i];
	}


	mergefloat(Left, 0, mid);
	mergefloat(Right, end - mid,end);
	floatmerge(input, Left, mid, Right);

	free(Left);
	free(Right);
}

//conqur
float floatmerge(float* input, float *left, int mid, float *right) {
	float output[] = sizeof(input);
	int ptr = 0;
	int L = 0;
	int R = 0;

	while (L<strlen(left) && R< strlen(right)) {
		if (left[L] < right[R]) {
			output[ptr++] = left[L++];
		}
		else {
			output[ptr++] = right[R++];
		}
	}
	while (L < strlen(left)) {

		output[ptr++] = left[L++];

	}

	while (R < strlen(right)) {

		output[ptr++] = right[R++];

	}

	for (ptr = 0; ptr < strlen; ptr++) {
		puts(output[ptr]);
	}

}
