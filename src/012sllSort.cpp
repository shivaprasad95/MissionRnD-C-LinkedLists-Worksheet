/*
OVERVIEW:  Given a single linked list of 0s 1s and 2s ,Sort the SLL such that zeroes
will be followed by ones and then twos.


INPUTS:  SLL head pointer

OUTPUT: Sorted SLL ,Head should Finally point to an sll of sorted 0,1,2


ERROR CASES:

NOTES: Only 0,1,2, will be in sll nodes
*/
struct node {
	int data;
	struct node *next;
};


void sll_012_sort(struct node *start)
{
	
	struct node *temp = start;
	int count[3] = {0,0,0};
	// count[0] stores number of 0s
	// count[1] stores number of 1s
	// count[2] stores number of 2s 

	int i = 0;

	while (temp)
	{
		if (temp->data == 0)
			count[0]++;
		else if (temp->data == 1)
			count[1]++;
		else if (temp->data == 2)
			count[2]++;
		temp = temp->next;
	}
	while (start)
	{
		//insert value from start of temp till it reaches NULL
		start->data = i;
		start = start->next;
		count[i]--; //decrement the count of 0's or 1's or 2's
		
		if (count[i] == 0)//changing the value to be inserted(0 or 1 or 2)
			i++;
	}
}
