/*
OVERVIEW: Given an unsorted single linked list, sort the linked list without using extra array or linked list.
E.g.: 4->2->1->5->3, output is 1->2->3->4->5.

INPUTS: An unsorted single linked list.

OUTPUT: Sort the linked list.

ERROR CASES: Return NULL for error cases.

NOTES: Without using extra array or linked list.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * sortLinkedList(struct node *head) {

	struct node * list = head;
	int l = 0;
	int array[10];

	if (head == NULL)
		return NULL;

	//finding length of the linked list
	while (list != NULL)
	{
		array[l++] = list->num;
		list = list->next;
	}

	int i, j, temp;
	struct node *temp1, *temp2; //no extra linked list is used ..temp1 & temp2 referencing same head

	temp1 = head;
	for (i = 0; i < l - 1; i++)
	{
		temp2 = temp1->next;

		for (j = i + 1; j < l; j++)
		{
			if (temp1->num > temp2->num)
			{
				//swapping
				temp = temp1->num;
				temp1->num = temp2->num;
				temp2->num = temp;
			}
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}

	
	return head;
}
