// Binary Search Tree - Find min and max
#include <stdio.h>
#include <stdlib.h>

// Definition of Node for Binary search tree
struct BstNode {
    int data;
    struct BstNode* left;
    struct BstNode* right;
};

struct BstNode* root = NULL;

struct BstNode* NewNode(int data){
	struct BstNode* newNode = (BstNode*)malloc(sizeof(struct BstNode*));
	newNode->data=data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

struct BstNode* Insert(struct BstNode* root, int data){
 	if(root!=NULL){ 
 		if(data<root->data) 
		 	root->left = Insert(root->left,data);
	   	else
		   root->right = Insert(root->right,data);
	}

	else {root=NewNode(data);} 
	return root;

}

// Code to Find min
int FindMin(BstNode* root){
	if(root == NULL){
		return false;
	}
	else if(root->left == NULL){
		return root->data;
	}
	return FindMin(root->left);
}

// Code to find max
int FindMax(BstNode* root){
	if(root == NULL){
		return false;
	}
	else if(root->right == NULL){
		return root->data;
	}
	return FindMax(root->right);
}

int main(){
	
	/*Code to test the logic*/
	root = Insert(root, 15);
	root = Insert(root, 10);
	root = Insert(root, 20);
	root = Insert(root, 5);
	root = Insert(root, 30);
	root = Insert(root, 25);
	
	printf("Min: %d\n" ,FindMin(root)); printf("Max: %d\n" ,FindMax(root));
}
