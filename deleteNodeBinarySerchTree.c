/*Binary Serch Tree Delete a Node From a Tree */

/* 
1- root is a leaf node
2- root has no left subtree
3- root has no right subtree
4- root has right and left subtre
*/

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

// Delete a node 
struct BstNode* Delete(struct BstNode* root,int x){
	struct BstNode* p;
	struct BstNode* q;

	if(root==NULL)	// no tree
		return NULL; 
	
	if(root->data==x){	// find x in root
	 	if(root->left==root->right==NULL){	// root is a  leaf node
			 free(root);
			 return NULL;
		}
		
  		else {
			if(root->left==NULL){
				p=root->right;
				free(root);
				return p;
			}
			else if(root->right==NULL){
				p=root->left;
				free(root);
				return p;
			}
			else { 
				p=q=root->right;
				while(p->left!=NULL) 
					p=p->left; 
				p->left=root->left;
				free(root);
				return q;
			}
		}	
	}
	
	if(root->data<x){
		root->right=Delete(root->right,x);
	}
	else {
		root->left=Delete(root->left,x);
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

int main(){
	
	/*Code to test the logic*/
	root = Insert(root, 15);
	root = Insert(root, 10);
	root = Insert(root, 20);
	root = Insert(root, 5);
	root = Insert(root, 30);
	root = Insert(root, 25);
	
	printf("Inorder: "); inorder (root);
	
	root = Delete(root, 15);
	printf("\nInorder: "); inorder (root);
	
	root = Insert(root, 15);
	root = Delete(root, 30);
	printf("\nInorder: "); inorder (root);
	
}
