#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};

struct Node *rootPtr;

struct Node *GetNewNode(int data)
{
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

struct Node *Insert(struct Node *rootPtr, int data)
{
	if (rootPtr == NULL)
	{
		rootPtr = GetNewNode(data);
	}
	else if (data <= rootPtr->data)
	{
		rootPtr->left = Insert(rootPtr->left, data);
	}
	else
	{
		rootPtr->right = Insert(rootPtr->right, data);
	}
	return rootPtr;
}

int Search(struct Node *rootPtr, int data)
{
	if (rootPtr == NULL)
	{
		return 0;
	}
	else if (rootPtr->data == data)
	{
		return 1;
	}
	else if (data <= rootPtr->data)
	{
		return Search(rootPtr->left, data);
	}
	else
	{
		return Search(rootPtr->right, data);
	}
}

int main()
{
	rootPtr = Insert(rootPtr, 15);
	rootPtr = Insert(rootPtr, 10);
	rootPtr = Insert(rootPtr, 20);
	rootPtr = Insert(rootPtr, 5);
	rootPtr = Insert(rootPtr, 30);
	rootPtr = Insert(rootPtr, 25);

	// Ask user to enter a number.
	int number;
	printf("Enter number to be searched: \n");
	scanf("%d", &number);
	// Serch for the number
	if (Search(rootPtr, number))
	{
		printf("Found\n");
	}
	else
	{
		printf("Not Found\n");
	}
}
