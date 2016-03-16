/*
OVERVIEW: Given a single linked list, remove every Kth node in the linked list.
E.g.: 1->2->3->4->5 and K 2, output is 1->3->5.

INPUTS: A linked list and Value of K.

OUTPUT: Remove every Kth node in the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * removeEveryKthNode(struct node *head, int K) {

	struct node *temp = head;
	struct node *temp1;

	int count = 1;

	if (K <= 0 || K == 1 || head == NULL)
		return NULL;

	while (temp) 
	{
		//to remove last node if needed
		if (((count) % K == 0) && temp->next->next == NULL) {
			temp->next = NULL;
			break;
		}
		if (count % K == 0 ) {			
			//to remove node in middle of the list
			temp1 = temp->next;
			temp->num = temp1->num;
			temp->next = temp1->next;
			count++;
		}
		if (temp->next == NULL)
			break;

		//this if helps to remove last node if needed
		if ((count + 1) % K != 0 || temp->next->next != NULL)
		temp = temp->next;
		count++;
	}

	return head;
	
}