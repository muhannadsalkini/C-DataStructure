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
int Pop() {
	struct Node *temp;
	int x;
	if (top == NULL) return 0;
	x = top->data;
	temp = top;
	top = top->link;
	free(temp);
	return x;
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

int postfix(){
	int x, y, result;
	char exp;
	
	while (top->link != NULL){
		printf("Ender the expression: ");
		scanf("%c ", &exp);
		
		
		switch (exp){
			case '*':{
				x=Pop();
				y=Pop();
				result = x*y;
				break;
			}
			case '/':{
				x=Pop();
				y=Pop();
				result = y/x;
				break;
			}
			case '+':{
				x=Pop();
				y=Pop();
				result = x+y;
				break;
			}
			case '-':{
				x=Pop();
				y=Pop();
				result = y-x;
				break;
			}
			
		}
		Push(result);
	}
	printf("\nresult: %d",result);
	
}

int main(){
	
	Push(5); Print();
	Push(4); Print();
	Push(3); Print();
	Push(2); Print();
	Push(1); Print();
	
	postfix();
	
}
