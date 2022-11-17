#include <stdlib.h>
#include <stdio.h>

//Linked List: Inserting a node at beginning
struct Node{
	int data;
	struct Node* next;
};

//struct Node* head;

void Print(struct Node* p){
	if( p == NULL) return; // Exit condition
	printf("%d",p->data); // Fist print the value in the node
	Print(p->next); // Recusive call
}

void PrintReverse(struct Node* p){
	if( p == NULL) return; // Exit condition
	PrintReverse(p->next); // Recusive call
	printf("%d",p->data); // Fist print the value in the node
}

struct Node* Insert(Node* head,int data){
	Node *temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data= data;
	temp->next = NULL;
	if(head == NULL) head = temp;
	else {
		Node* temp1 = head;
		while(temp1->next != NULL) temp1 = temp1->next;
		temp1->next = temp;
	}
	return head;
}

int main(){
	
	struct Node* head = NULL; // local variable
	head = Insert(head,2);
	head = Insert(head,4);
	head = Insert(head,6);
	head = Insert(head,5);
	Print(head);
	printf("\n");
	PrintReverse(head);
}
