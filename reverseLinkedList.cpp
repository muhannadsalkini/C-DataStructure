#include <stdlib.h>
#include <stdio.h>

//Linked List: Inserting a node at beginnin
struct Node{
	int data;
	struct Node* next;
};

struct Node* head; // global vriable, can be accessed anywhere

void Reverse(){
	struct Node *current,*prev,*next;
	current = head;
	prev = NULL;
	while(current != NULL){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
}

void Insert(int data, int n){
	struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node*));
	temp1 -> data = data;
	temp1 ->next = NULL;
	if(n == 1){
		temp1 ->next = head;
		head = temp1;
		return;
	}
	Node* temp2 = head;
	for(int i=0;i<n-2;i++){
		temp2 = temp2->next;
	}	
	temp1 ->next = temp2->next;
	temp2 ->next = temp1;
}

void Print(){
	Node* temp = head;
	while(temp != NULL){
		printf("%d ",temp->data);
		temp = temp->next;
	}
}

int main(){
	head = NULL; //empty list
	Insert(2,1); //List 2
	Insert(3,2); //List 2,3
	Insert(4,1); //List 4,2,3
	Insert(5,2); //List 4,5,2,3
	Print();
	printf("\n");
	Reverse();
	Print();
}