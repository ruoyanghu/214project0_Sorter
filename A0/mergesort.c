#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include "mergesort.h"
#include "sorter.h"


void mergesort(Row * list, int low, int high, int isString)
{
	
    //low and high are 
    if (low >= high)
        return;
    int mid = (low + high) / 2;

    mergesort(list, low, mid, isString);
    mergesort(list, mid + 1, high, isString);

    int leftPtr = 0, rightPtr = 0;
    int leftLen = mid - low + 1;
    int rightLen = high - mid;
    Row *left = (Row *) malloc(sizeof(Row) * (leftLen + 10));
    Row *right = (Row *) malloc(sizeof(Row) * (rightLen + 10));

    //copy into left and right temp array;
    int t = 0;

    for (t = 0; t < leftLen; t++) {
        memcpy(left + t, list + low + t, sizeof(Row));
    }
    for (t = 0; t < rightLen; t++) {
        memcpy(right + t, list + mid + t + 1, sizeof(Row));
    }
    float comp = 0;

    //use t as merge array pointer;
    t = low;
    while (leftPtr < leftLen && rightPtr < rightLen) {
        if (isString) {
            comp =
                strcmp(left[leftPtr].targetCol, right[rightPtr].targetCol);
        } else {
            comp =
                atof(left[leftPtr].targetCol) -
                atof(right[rightPtr].targetCol);
        }
        if (comp > 0) {
            memcpy(list + t, right + rightPtr, sizeof(Row));
            t++;
            rightPtr++;
        } else {
            memcpy(list+t, left+leftPtr, sizeof(Row));
			t++;
            leftPtr++;
        }
    }
    //remind left or right
    while (leftPtr < leftLen) {
        memcpy(list+t, left+leftPtr, sizeof(Row));
		t++;
		leftPtr++;
    }
    while (rightPtr < rightLen) {
        memcpy(list+t, right+rightPtr, sizeof(Row));
		t++;
		rightPtr++;
    }
    free(left);
    free(right);
}