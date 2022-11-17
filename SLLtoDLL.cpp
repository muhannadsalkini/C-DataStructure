// Stack - Linked list based implementation.
#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
};

struct Node* head1;
struct Node* head2;

void Insert(int x){
	struct Node* temp = (Node*) malloc(sizeof(struct Node));
	temp ->data = x;
	temp ->next = NULL;
	if(head1 != NULL) temp->next = head1;
	head1 = temp;
}

void SLLtoDLL(){
	head2=head1;
	while(head2->next==NULL) // stop when you meet the null node 
	{ 
   	head2->prev->next = head2; // link back the current and next nodes 
   	head2 = head2->next;       // march to the next node and do the same 
	}  

}

void Print2(struct Node* head){
	struct Node* temp = head;
	printf("Forward: ");
	while (temp != NULL){
		printf("%d " ,temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void ReversePrint(struct Node* head){
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


int main(){
	Insert(20);
	Insert(12);
	Insert(8);
	Insert(5);
	Print2(head1);
	SLLtoDLL();
	Print2(head2);
}
