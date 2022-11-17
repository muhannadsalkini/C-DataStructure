/*Print Binary Serch Tree*/
#include <stdio.h>
#include <stdlib.h>

// Definition of Node for Binary search tree
struct BstNode {
	int data;
	struct BstNode* left;
	struct BstNode* right;
	int height;
}; 

struct BstNode* root;
struct BstNode* AVL; // Global variable

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

int RandomNum()
{
    int max = 1000;
    int min = 10;
    srand(time(NULL));
	int x = rand()% max+min;
    return x;
    
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
	int i;
	while (i<500){
		int x = RandomNum();
		root = Insert(root, x);
		
	}
	
	inorder(root);
	
	
}
