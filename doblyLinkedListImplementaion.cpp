// Doubly linked list implementation
#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node* next;
	struct Node* prev;
};

struct Node* head; // Global variable - pointer to head node.

struct Node* GetNewNode(int x){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node*));
	newNode->data = x;
	newNode->next = NULL;
	newNode->prev = NULL;
}

void Print(){
	struct Node* temp = head;
	printf("Forward: ");
	while (temp != NULL){
		printf("%d" ,temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void ReversePrint(){
	struct Node* temp = head;
	if(temp == NULL) return; // empty list, exit
	// Going to last Node
	while (temp->next != NULL){
		temp = temp->next;
	}
	// Printig backward
	printf("Reverse: ");
	while (temp != NULL){
		printf("%d" ,temp->data);
		temp = temp->prev;
	}
	printf("\n");
}

void InsertAtHead(int x){
	struct Node* newNode = GetNewNode(x);
	if(head == NULL){
		head = newNode;
		return;
	}
	head->prev = newNode;
	newNode->next = head;
	head = newNode;
}

void InsertAtTail(int x){
	struct Node* temp = head;
	struct Node* newNode = GetNewNode(x);
	if(head == NULL){
	head = newNode;
	return;
	}
	while (temp->next != NULL){
		temp = temp->next;
	}
	temp->next = newNode;
	newNode->prev = temp;
	temp = newNode;
	
}
	

int main(){
	head = NULL; // empty list
	InsertAtHead(2); Print(); ReversePrint();
	InsertAtHead(4); Print(); ReversePrint();
	InsertAtHead(6); Print(); ReversePrint();
	InsertAtTail(5); Print(); ReversePrint();
	InsertAtTail(8); Print(); ReversePrint();
	InsertAtTail(9); Print(); ReversePrint();
}





