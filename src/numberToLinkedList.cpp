/*
OVERVIEW:  Given a number convert that to single linked list (each digit as a node).
E.g.: Input: 234, Output: 2->3->4.

INPUTS:  A number.

OUTPUT: Create linked list from given number, each digit as a node.

ERROR CASES: 

NOTES: For negative numbers ignore negative sign.
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};
struct node *head = NULL;

void insert_node(int num);

struct node * numberToLinkedList(int N) {

	int flag = 0;
	int num;
	head = NULL;

	//if number is negative make it positive
	if (N < 0)
		N = -(N);

	//if number is 0 ,only insert 0
	if (N == 0) {
		insert_node(N);
	}

	//break the number and insert into list
	while (N)
	{
		num = N % 10;
		insert_node(num);
		N = N / 10;
	}

	
	return head;
}

//insert node at beginning of the list
void insert_node(int num)
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->num = num;
	temp->next = NULL;

	if (head == NULL)
	{
		head = temp;
	}
	else
	{
		temp->next = head;
		head = temp;
	}

}
