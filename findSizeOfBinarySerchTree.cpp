/*Binary Serch Tree Find Size Of Tree*/
#include <stdio.h>
#include <stdlib.h>

// Definition of Node for Binary search tree
struct BstNode {
	int data;
	struct BstNode* left;
	struct BstNode* right;
}; 

struct BstNode* root; // Global variable

// Function to create a new Node in heap
struct BstNode* GetNewNode(int data){
	struct BstNode* newNode = (struct BstNode*)malloc(sizeof(struct BstNode*));
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

// To insert data in BST, returns address of root node 
struct BstNode* Insert(struct BstNode* root, int data){
	if (root == NULL){
		root = GetNewNode(data);
	}
	else if(data < root->data){
		root->left = Insert(root->left, data);
	}
	else{
		root->right = Insert(root->right, data);
	}
	return root;
}

// To Calcolate The Total Nodes in The Tree
int size (struct BstNode* root)
{ 
	if(root!=NULL) 	
		return (size(root->left) + 1 + size(root->right)); 
	else return 0;
}

// To Print The Tree Inorderly
void inorder(struct BstNode* root){
	if(root!=NULL){
	 	inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
    }
}

int main(){
	
	/*Code to test the logic*/
	root = Insert(root, 15);
	root = Insert(root, 10);
	root = Insert(root, 20);
	root = Insert(root, 5);
	root = Insert(root, 30);
	root = Insert(root, 25);
	
	printf("Inorder: "); inorder (root);
	printf("\nSize of tree: %d\n" ,size(root));
	
}
