#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <datetimeapi.h>

//string
//num
//datetime

typedef struct row {
	char rowString[5000];
	char targetCol[100];
} Row;

char lexi(char * needtosort[])
{
	int first, second;
	
	for (first = 0; first<(strlen(needtosort)-1); first++)
		for (second = first + 1; second<strlen(needtosort); second++)
		{
			if (strcmp(needtosort[first], needtosort[second])>0)
			{
				/*
				strcpy(temp, needtosort[first]);
				strcpy(needtosort[first], needtosort[second]);
				strcpy(needtosort[second], temp);
				*/
				//shorter ver, thanks to Russell's 211
				swap(needtosort[first], needtosort[second]);
			}
		}

	for (first = 0; first<strlen(needtosort);first++)
	{
		puts(needtosort[first]);
	}

	return 0;
}

//int merge


void swap(a, b) {
	a ^= b;
	b ^= a;
	a ^= b;
}


int main(int argc, char * argv) {
	//initial an array, put all targetcol into it
	char* needtosort[] = NULL;
	int i = 0;
	//counter indicates the first place tha has a value
	int counter = 0;
	int endo = 0;

	for ( i = 0; i < strlen(Row.targetCol); i++)
	{ 
		//put '\0' to the front
		if (isspace(needtosort[i])) {

			swap(needtosort[counter], needtosort[i]);
			counter++;
		}

			needtosort[i] = Row.targetCol[i];
			
			endo++;
					

		return;
	}

	needtosort[endo] = '\0';
	

	//sort string
	if (isalpha(needtosort[counter])) {
		
		lexi(needtosort);
		
	}
	
	if (isdigit(needtosort[counter])) {
		//regular mergesort number

		int a = 0;

		//null print 
		for (a = 0; a < counter; a++) {
			puts(needtosort[a]);
		}

		mergeint(needtosort, counter, endo);

	}
	
	mergefloat(needtosort, counter, endo);
		
}
void mergeint(char * needtosort, int start, int end) {
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


	mergeint(Left, mid);  
	mergeint(Right, end - mid); 
	intmerge(input, Left, mid, Right); 
	
	free(Left);
	free(Right);
}

void intmerge(int* input, int *left, int mid, int *right) {
	int output[] = sizeof(input);
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

void mergefloat(char * needtosort, int start, int end) {
	float * input[] = (float*)needtosort;
	int mid = (end - start) / 2;
	if (start = end) { return; }

	float * Left;
	float * Right;
	Left = (float*)malloc(mid * sizeof(float));
	Right = (float*)malloc((end - mid) * sizeof(float));

	int i = 0;

	for (i = 0; i < mid; i++) {
		Left[i] = input[i];
	}

	for (i = mid; i < end; i++) {
		Right[i - mid] = input[i];
	}


	mergefloat(Left, mid);
	mergefloat(Right, end - mid);
	floatmerge(input, Left, mid, Right);

	free(Left);
	free(Right);
}

void floatmerge(float* input, float *left, int mid, float *right) {
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