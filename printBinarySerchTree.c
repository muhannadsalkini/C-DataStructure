/*Print Binary Serch Tree*/
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

// To Print The Tree Inorderly
void inorder(struct BstNode* root){
	if(root!=NULL){
	 	inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
    }
}

// To Print The Tree Perorderly
void preorder(struct BstNode* root){
 	if(root!=NULL){
	 	printf("%d ",root->data); 	
		preorder(root->left);
		preorder(root->right);
	}
}

// To Print The Tree Postorderly
void postorder(struct BstNode* root){
	if(root!=NULL){
		postorder(root->left);
		postorder(root->right);  
		printf("%d ",root->data);
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
	printf("\nPreorder: "); preorder (root);
	printf("\nPostorder: "); postorder (root);
	
	
}
