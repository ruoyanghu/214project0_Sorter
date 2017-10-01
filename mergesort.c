#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void mergesort(char ***s, int low, int high, char type, int collen, int tosort)
{
    if (low >= high)
        return;
    int mid = low + (high - low) / 2;

    mergesort(s, low, mid, type, collen, tosort);
    mergesort(s, mid + 1, high, type, collen, tosort);
    //========================================================================
    int i = 0, j = 0, k = low, t;
    int lenLeft = mid - low + 1, lenRight = high - mid;
    double comp;
    char ***left = (char ***)malloc(sizeof(char **) * lenLeft);
    char ***right = (char ***)malloc(sizeof(char **) * lenRight);

    for (t = 0; t < lenLeft; t++)
        left[t] = s[low + t];
    for (t = 0; t < lenRight; t++)
        right[t] = s[mid + t + 1];
    //========================================================================
    while (i < lenLeft && j < lenRight) {
        if (type == 's')
            comp = strcmp(left[i][tosort], right[j][tosort]);
        else
            comp = atof(left[i][tosort]) - atof(right[j][tosort]);
        if (comp > 0)           // stable
            s[k++] = right[j++];
        else
            s[k++] = left[i++];
    }
    while (i < lenLeft)
        s[k++] = left[i++];
    while (j < lenRight)
        s[k++] = right[j++];
    //========================================================================
    free(left);
    free(right);
}
