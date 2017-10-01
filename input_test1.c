
void cleanBuffer(char* buffer, int size);
void cleanBuffer(char* buffer, int size){
	int i = 0;
	while(i!=size-1){
		buffer[i] = '\0';
		i++;
	}
}
typedef struct row{
    char rowString[5000];
    char targetCol[100];
}Row;

 int main(int argc, char *argv[]) 
{
	char a1[10];
	char a2[10];
	char a3[10];
	scanf("%s",&a1);
	scanf("%s",&a2);
	scanf("%s",&a3);
	printf("a1 is %s\n",a1);
	printf("a2 is %s\n",a2);
	printf("a2 is %s\n",a3);
	
	Row* list;
	int rowCounter = 0;
	
	Row row1;
	rowCounter++;
	
	strcpy(row1.rowString,a1);
	printf("row %s\n",row1.rowString);
	
	list = (Row *)malloc(sizeof(Row));
	
	memcpy(list,&row1,sizeof(Row));
	
	printf("get access row %s\n",list[0].rowString);
	
	Row row2;
	rowCounter++;
	strcpy(row2.rowString,a2);
	printf("row %s\n",row2.rowString);
	Row* b = &row2;
	realloc(list,rowCounter*sizeof(Row));
	memcpy(list+1,b,sizeof(Row));
	printf("get access row %s\n",list[1].rowString);
	
	Row row3;
	rowCounter++;
	strcpy(row3.rowString,a3);
	printf("row %s\n",row3.rowString);
	Row* c = &row3;
	realloc(list,rowCounter*sizeof(Row));
	memcpy(list+2,c,sizeof(Row));
	printf("get access row %s\n",list[2].rowString);
	

	
}
