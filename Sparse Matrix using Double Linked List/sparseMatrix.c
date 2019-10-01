#include <stdio.h>
#include <stdlib.h>

struct node
{
	int row,col,data;
	struct node *prev, *next;
};

struct node *getnode();
struct node *insert(struct node*, int, int, int);
void displayList(struct node*);
void displayMatrix(struct node*, int, int);

int main()
{
	struct node *list = NULL;
	int nr,nc,num,row,col,data,i;
	printf("Enter no. of rows and columns in the matrix:");
	scanf("%d%d",&nr, &nc);
	printf("Enter no. of non zero elements in the matrix: ");
	scanf("%d",&num);
	printf("Enter non zero elements of the matrix:\n");
	for(i=0;i<num;i++)
	{
		printf("Row: ");
		scanf("%d", &row);
		printf("Column: ");
		scanf("%d", &col);
		printf("Data: ");
		scanf("%d", &data);
		list = insert(list, row, col, data);
	}
	printf("Entered List: \n");
	displayList(list);
	printf("Resultant Matrix: \n");
	displayMatrix(list,nr,nc);
	return 0;
}

struct node *getnode()
{
	struct node *newnode = (struct node*)malloc(sizeof(struct node));
	newnode -> prev = newnode ->next = NULL;
	return newnode;
}

struct node *insert(struct node *head, int r, int c, int d)
{
	struct node *newnode = getnode();
	newnode -> row = r;
	newnode -> col = c;
	newnode -> data = d;
	if(head == NULL)
	{
		head = newnode;
	}
	else
	{
		newnode -> next = head;
		head -> prev = newnode;
		head = newnode;
	}
	return head;
}

void displayList(struct node *head)
{
	if(head == NULL)
	{
		printf("List is Empty\n");
		return;
	}
	struct node *temp = head;
	printf("Row\tColumn\tData\n");
	while(temp!=NULL)
	{
		printf("%d\t %d\t  %d\n",temp->row,temp->col,temp->data);
		temp=temp->next;
	}
}

void displayMatrix(struct node *head, int r, int c)
{
	int i,j,flag;
	struct node *temp = head;
	if(head == NULL)
	{
		printf("Matrix is Empty\n");
		return;
	}
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			temp = head;
			flag = 0;
			while(temp!=NULL)
			{
				if(temp->row == i && temp -> col == j)
				{
					printf("%d ",temp->data);
					flag = 1;
				}
				temp=temp->next;
			}
			if(flag == 0)
				printf("0 ");
		}
		printf("\n");
	}
}
