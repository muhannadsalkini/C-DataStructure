// Using Stack to reverse
#include <stdio.h>
#include <stdlib.h>
#include <stack> // stack from standard template libraray (STL)

void Reverse(char *C,int n){
	stack<char> S;
	//loop for push
	for (int i=0;i<n;i++){
		S.push(C[i]);
	}
	//loop for pop
	for ( int i=0;i<n;i++){
		c[i] = S.top(); // overwrite the character at index i.
		S.pop(); // perform pop.
	}
}

int main(){
	char C[51];
	printf("Enter a string");
	gets(c);
	Rverse(C,strlen(C));
	printf("Output = %s" ,C);
}
