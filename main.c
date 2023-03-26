/*
 * main.c


 *
 *  Created on: Mar 23, 2023
 *      Author: mohamed
 */
#include <stdio.h>

typedef unsigned char       uint8_t;
typedef signed char         sint8_t;
typedef unsigned short      uint16_t;
typedef signed short        sint16_t;
typedef unsigned int        uint32_t;
typedef signed int          sint32_t;
typedef unsigned long long  uint64_t;
typedef signed long long    sint64_t;

void Clear ();
struct stack {
	uint32_t size[10];
	uint32_t Top;
};

uint32_t is_Empty (struct stack *P);
uint32_t is_Full (struct stack *P);
void Push (struct stack *P , uint32_t data);
uint32_t Pop  (struct stack *P);
uint32_t GetStackTop (struct stack *P);
void print_Stack (struct stack *P);


void main () {
	struct stack *Pstack ,Sta;
	Pstack = &Sta;
	Pstack ->Top = -1;
	uint32_t choice , Data;
	while(1){
		printf("press 0 to push\npress 1 to pop\npress 2 to print all stack\npress 3 to get stack top\npress any other number to exit");
		Clear();
		scanf("%d",&choice);

		if(choice == 0){
			if(is_Full(Pstack)){
				printf("u can't push element cause stack is full");
			}
			else{
				printf("enter the data u need to push : ");
				Clear();
				scanf("%d",&Data);
				Push(Pstack,Data);
			}
		}

		else if (choice == 1){
			if(is_Empty(Pstack)){
				printf("The stack is Empty we Can't pop any element");
			}
			else {
				printf("the element u pop is = %d",Pop(Pstack));
			}
		}

		else if (choice == 2){
			print_Stack(Pstack);
		}

		else if (choice == 3){
			printf("stack top is = %d ", GetStackTop(Pstack));
		}

		else{
			break;
		}
	}
}

void Clear (){
	fflush(stdin);
	fflush(stdout);

}
uint32_t is_Empty (struct stack *P){
	if(P->Top == -1){
		return 1;
	}
	else {
		return 0;
	}
}
uint32_t is_Full (struct stack *P){
	if (P->Top == 9){
		return 1 ;
	}
	else
		return 0 ;
}
void Push (struct stack *P , uint32_t data){
	P->Top=P->Top +1;
	P->size[P->Top] = data ;
}
uint32_t Pop  (struct stack *P){
	uint32_t data ;
	data = P->size[P->Top];
	P->size[P->Top]=0;
	P->Top = P->Top - 1;
	return data;
}
uint32_t GetStackTop (struct stack *P){

	return P->Top;
}

void print_Stack (struct stack *P){
	sint32_t i = P->Top ;
	if(is_Empty(P)){
		printf("The Stack is Empty");
	}
	else{
		for(i ; i >= 0 ; i--){
			printf("element number %d is = %d \n",i,P->size[i]);
		}
	}
}
