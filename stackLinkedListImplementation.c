// Stack - Linked list based implementation.
#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* link;
};

struct Node* top;

// Add element to the stack
void Push (int x){
	struct Node* temp = (Node*)malloc(sizeof(struct Node*));
	temp -> data = x;
	temp -> link = top;
	top = temp;
}

// Remove element from the stack
void Pop() {
	struct Node *temp;
	if (top == NULL) return;
	temp = top;
	top = top->link;
	free(temp);
}

void Print(){
	struct Node* temp = top;
	temp->data = top->data;
	temp->link = top->link;
	while (temp->link!=NULL){
		printf("%d ",temp->data);
		temp = temp->link;
	}
	printf("\n");
}

// Print the Top element
int Top() {
	printf("%d", top->data);
}

int main(){
	
	Push(1); Print();
	Push(2); Print();
	Push(3); Print();
	Push(4); Print();
	Pop(); Print();
	Push(1); Print();
	

}
