#include <stdlib.h>
#include <stdio.h>

//Linked List: Inserting a node at beginning
struct Node {
	int data;
	struct Node* next;
};

struct Node* head; // global vriable, can be accessed anywhere

void Insert(int x){
	struct Node* temp = (Node*) malloc(sizeof(struct Node));
	temp ->data = x;
	temp ->next = NULL;
	if(head != NULL) temp->next = head;
	head = temp;
}

void Print(){
	struct Node* temp = head;
	printf("List is: ");
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp= temp->next;
	}
	printf(" \n");
}

int main(){
	head = NULL;  // empty list
	printf("How many numbers?\n");
	int n,x;
	scanf("%d",&n);
	
	for (int i=0;i<n;i++){
		printf("Enter the number: \n");
		scanf("%d",&x);
		Insert(x);
		Print();
		
	}
}
