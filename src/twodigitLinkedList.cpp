/*
OVERVIEW:  Given a single linked list (two digits as a node).Convert that to number


INPUTS:  SLL head pointer

OUTPUT: Create a number from the linked list given ,In each node there are two numbers ,digit1 and digit1 ,
So if the nodes are 12->34->56->78 , Final number would be 12345678 ( Integer)

ERROR CASES:

NOTES: Only Postive Numbers
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int digit1;
	int digit2;
	struct node *next;
};

int convert_sll_2digit_to_int(struct node *head){

	int num, temp1, temp2;
	int temp = 100, N = 0;
	int i = 0,count = 0;

	while (head)
	{
		temp1 = head->digit1;    //storing first digit
		temp2 = head->digit2;	 //storing second digit
		num = temp1 * 10 + temp2;//finding a number from 2-digits
		N = N * temp + num;     //finding complete number(till current node)
		head = head->next;
		count++;
	}
	
	return N;
}
