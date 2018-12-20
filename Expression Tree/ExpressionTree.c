#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct exptree
{
	char data;
	struct exptree *left;
	struct exptree *right;
};

struct exptree *getnode(char);
struct exptree *createExpTree(char[]);
int precedence(char);
void preOrder(struct exptree*);
void inOrder(struct exptree*);
void postOrder(struct exptree*);

int main()
{
	struct exptree *root;
	char exp[20];
	printf("Enter the Infix Expression: ");
	scanf("%s", exp);
	root = createExpTree(exp);
	printf("PreOrder: ");
	preOrder(root);
	printf("\nInOrder: ");
	inOrder(root);
	printf("\nPostOrder: ");
	postOrder(root);
	return 0;
}

struct exptree *getnode(char ch)
{
	struct exptree *newnode = (struct exptree*)malloc(sizeof(struct exptree));
	newnode ->left = NULL;
	newnode -> right = NULL;
	newnode -> data = ch;
	return newnode;
}

int precedence(char ch)
{
	switch(ch)
	{
		case '^':
			return 3;
		case '/':
		case '*':
			return 2;
		case '-':
		case '+':
			return 1;
		default:
			return 0;
	}
}

void preOrder(struct exptree *root)
{
	if(root != NULL)
	{
		printf("%c ", root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}

void inOrder(struct exptree *root)
{
	if(root!=NULL)
	{
		inOrder(root->left);
		printf("%c ", root->data);
		inOrder(root->right);
	}
}

void postOrder(struct exptree *root)
{
	if(root != NULL)
	{
		postOrder(root->left);
		postOrder(root->right);
		printf("%c ", root->data);
	}
}

struct exptree *createExpTree(char exp[20])
{
	struct exptree *operst[10], *treest[10];
	int top1 = -1, top2 = -1;
	struct exptree *temp, *t1, *t2, *t3;
	char symbol;
	int i;
	for(i=0;i<strlen(exp);i++)
	{
		symbol = exp[i];
		if(isalnum(symbol))
		{
			temp = getnode(symbol);
			treest[++top2] = temp;
		}
		else
		{
			temp = getnode(symbol);
			if(symbol == '(')
			{
				operst[++top1] = temp;
			}
			else if(top1 == -1 ||  precedence(operst[top1]->data< precedence(symbol)))
			{
				operst[++top1] = temp;
			}
			else if(symbol == ')')
			{
				while(operst[top1]->data != '(' && top1 != -1 && top2 != -1 && precedence(operst[top1]->data) >= precedence(symbol))
				{
					t3 = operst[top1--];
					t1 = treest[top2--];
					t2 = treest[top2--];
					t3->right = t1;
					t3->left = t2;
					treest[++top2] = t3;
				}
				if(operst[top1]->data =='(')
					top1--;
			}
			else
			{
				while(top1 != -1 && top2 != -1 && precedence(operst[top1]->data >= precedence(symbol)))
				{
					t3 = operst[top1--];
					t1 = treest[top2--];
					t2 = treest[top2--];
					t3->right = t1;
					t3->left = t2;
					treest[++top2] = t3;
				}
				operst[++top1] = temp;
			}
		}
	}
	while(top1 != -1)
	{
		t3 = operst[top1--];
		t1 = treest[top2--];
		t2 = treest[top2--];
		t3->right = t1;
		t3->left = t2;
		treest[++top2] = t3;
	}
	return treest[top2];
}