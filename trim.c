#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void trim(char *row);
int main(int argc, char **argv)
{
    char str1[] = "   a  b ,\"dd  ,    d     \",        eee,      eee   ee";

    trim(str1);
    return 0;
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
                if ((!comma)&&(zero!=0)) {

                    //write zero
                    int i;

                    for (i = 0; i <= zero; i++) {
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
    printf("%s\n", row);
}
