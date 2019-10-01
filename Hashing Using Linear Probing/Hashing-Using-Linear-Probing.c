#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 5

void insert(int[], int);
void delete(int[], int);
void search(int[], int);
void display(int[]);

int main()
{
	int htable[TABLE_SIZE]={};
	int i;
	for(i=0;i<TABLE_SIZE;i++)
		htable[i] = -1;
	int ch,ele;
	while(1)
	{
		printf("Current Table: ");
		display(htable);
		printf("\n1. Insert Element\n2. Delete Element\n3.Search Element\n4.EXIT\n");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
				printf("Enter element to be inserted: ");
				scanf("%d", &ele);
				insert(htable, ele);
				break;
			case 2:
				printf("Enter element to be deleted: ");
				scanf("%d", &ele);
				delete(htable, ele);
				break;
			case 3:
				printf("Enter element to be searched: ");
				scanf("%d", &ele);
				search(htable, ele);
				break;
			case 4:
				exit(0);
			default:
				printf("Invalid Choice\n");
		}
	}
	return 0;
}

void insert(int htable[TABLE_SIZE], int ele)
{
	int i, index,flag=0;
	for(i=0; i<TABLE_SIZE; i++)
	{
		index = (i+ele)%TABLE_SIZE;
		if(htable[index] == -1)
		{
			htable[index] = ele;
			flag = 1;
			break;
		}
	}
	if(flag == 0)
		printf("Element cannot be inserted\n");
	else
		printf("Element Successfully Inserted\n");
}

void delete(int htable[TABLE_SIZE], int ele)
{
	int i, index,flag=0;
	for(i=0;i<TABLE_SIZE;i++)
	{
		index = (i+ele)%TABLE_SIZE;
		if(htable[index] == ele)
		{
			htable[index] = -1;
			flag =1;
			break;
		}
	}
	if(flag == 1)
		printf("Element successfully deleted\n");
	else
		printf("Element cannot be deleted\n");
}

void search(int htable[TABLE_SIZE], int key)
{
	int i, index,flag=0,pos;
	for(i=0;i<TABLE_SIZE;i++)
	{
		index = (i+key)%TABLE_SIZE;
		if(htable[index] == key)
		{
			flag = 1;
			pos = index;
			break;
		}
	}
	if(flag == 1)
		printf("Element Found at Position: %d\n", pos);
	else
		printf("Element Not Found\n");
}

void display(int htable[TABLE_SIZE])
{
	int i;
	for(i=0;i<TABLE_SIZE;i++)
		printf("%d ", htable[i]);
}