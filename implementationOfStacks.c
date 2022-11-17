// Stack - Arry based implementation.
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 101
int A[MAX_SIZE];
int top = -1;

// Add number to the stack
void Push (int x) {
	if (top == MAX_SIZE -1){
		printf("Error: stack overflow\n");
	}
	top++;
	A[top] = x;
}

// Remove number from the stack
void Pop() {
	if (top == -1){
		printf(" Error: No elements to pop\n");
		return;
	}
	top--;
}

// Print the Top element
int Top() {
	return A[top];
}

// Print the stack
void Print() {
	printf("stack: ");
	for (int i=0;i<=top;i++)
		printf("%d" ,A[i]);
	printf("\n");
}

int main() {
	Push(2); Print();
	Push(5); Print();
	Push(10); Print();
	Pop(); Print();
	Push(12); Print();
}
