#include<stdio.h>
#include<stdlib.h>
int a[200], top = -1, max_size, item, e;
void push() {
	if(top >= max_size - 1)	
		printf("OVERFLOW!");
	else {
		++top;
		printf("Enter the element to be pushed:");
		scanf("%d", &e);
		a[top] = e;
		printf("\n%d has been pushed into the stack.", e);
	}	
}
void pop() {
	if(top < 0)			
		printf("UNDERFLOW!");
	else {
		item = a[top];
		--top;
		printf("\n%d has been popped from the stack.", item);
	}	
}
void display() {
	printf("The stack now is:\n");
	for(int i = top; i >= 0; i--)
		printf("\n%d", a[i]);
}
void main() {
	int ch, choice = 1, a[200];
	printf("Enter maximum size of stack:");
	scanf("%d", &max_size);
	while(choice == 1){
		printf("\nChoose your option:\n1.Push\n2.Pop\n3.Display stack\n4.Exit\nEnter your option:");
		scanf("%d", & ch);
		switch(ch){
			case 1: push();	  break;
			case 2: pop();	  break;
			case 3: display();break;
			case 4: exit(0);  break;
			default: printf("WRONG OPTION!");
		}
		printf("\n\nWant to perform more operations (1/0)?:");
		scanf("%d", &choice);		
	}
}
