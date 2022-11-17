// Binary Search Tree - Implementation in C
// Simple program to create a BST of integers and search an element in it 
#include <stdio.h>
#include <stdlib.h>

// Definition of Node for Binary search tree
struct BstNode {
    int data;
    struct BstNode* left;
    struct BstNode* right;
};

// Function to create a new Node in heap
struct BstNode* GetNewNode(int data){
	struct BstNode* newNode = (struct BstNode*)malloc(sizeof(struct BstNode));
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;	
}

// To insert data in BST, returns address of root node 
struct BstNode* Insert(struct BstNode* rootPtr, int data){
	if(rootPtr == NULL){
		rootPtr = GetNewNode(data);
	}
	else if(data <= rootPtr->data) {
		rootPtr->left = Insert(rootPtr->left, data);
	}
	else {
		rootPtr->right = Insert(rootPtr->right, data);
	}
	return rootPtr;
}

//To search an element in BST, returns true if element is found
int Search(struct BstNode* rootPtr, int data) {
	if(rootPtr == NULL) {
		return false;
	}
	else if(rootPtr->data == data) {
		return true;
	}
	else if(data <= rootPtr->data) {
		return Search(rootPtr->left, data);
	}
	else {
		return Search(rootPtr->right, data);
	}
}

int main(void){
	struct BstNode* rootPtr = NULL; // Creating an empty tree
	
	/*Code to test the logic*/
	rootPtr = Insert(rootPtr, 15);
	rootPtr = Insert(rootPtr, 10);
	rootPtr = Insert(rootPtr, 20);
	rootPtr = Insert(rootPtr, 5);
	rootPtr = Insert(rootPtr, 30);
	rootPtr = Insert(rootPtr, 25);
	printf("%d",rootPtr->data);
	// Ask user to enter a number.
	int number;
	printf("Enter number to be searched: \n");
	scanf("%d",&number);
	// Serch for the number
	if(Search(rootPtr, number)) {
		printf("Found\n");
	}
	else {
		printf("Not Found\n");
	}
}
