#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *link;
};

/**
		4-> Reversing a linked list
*/
struct node* reverseSameLL(struct node *start)
{
	struct node *ptr = NULL;
	struct node *pre = NULL;
	struct node *next = NULL;
	ptr = start;
	while(ptr != NULL)
	{
		next = ptr -> link;
		ptr -> link = pre;
		pre = ptr;
		ptr = next;
	}
	start = pre;
	return start;	
}	

void display(struct node *);
/**
			To generate some random numbers

int random_number_generator(int num)
{
	return arr[num];
}
*/
/**
			insertion of a single element in a list
*/
struct node* insert(struct node *start, int data)
{
	struct node *temp = (struct node* )malloc(sizeof(struct node));
	temp -> info = data;
	temp -> link = NULL;
	
	if(start == NULL)			//Linked list is empty.
	{
		start = temp;
		return start;
	}	
	
	struct node *ptr = start;
	while(ptr -> link != NULL)
		ptr = ptr -> link;
	ptr -> link = temp;
	
	return start;
}

/**
			Copies a list
*/
struct node* copy(struct node *start1)
{
	struct node *ptr1 = NULL,*ptr2 = NULL, *start2 = NULL, *tmp = NULL;
	ptr1 = start1;
	while(ptr1)
	{
		tmp = (struct node*)malloc(sizeof(struct node));
		tmp -> info = ptr1->info;
		tmp ->link=NULL;
		if(start2 == NULL)
		{
			start2 = tmp;
			ptr2 = start2;
		}
		else
		{
			ptr2->link = tmp;
			ptr2 = tmp;
		}
		ptr1 = ptr1 ->link;
	}
	
	return start2;
}

/**
			Displays a list
*/
void display(struct node *start)
{
	struct node *ptr = start;
	if(start == NULL)
		printf("\nLinked List is empty.");
	else
	{	
		printf("\n");
		while(ptr != NULL)
		{
			printf(" %3d ", ptr -> info);
			ptr = ptr -> link;
		}
	}	
}

/**
		1-> creates a list with given array elements.
*/
struct node* create(struct node *start, int arr[], int array_size)
{
	int i;
	for(i=0;i<array_size;i++)
		start = insert(start, arr[i]);
	return start;	
}

/**
		2-> creates a list with random numbers.
*/
struct node* createRandom(struct node *start,int count)
{
	int i;
	int arr[] = {234,6543,4325,-46,234,-456,234,56,46,226,894,45,823,45,36};
	for(i=0;i<count;i++)
		start = insert(start,arr[i]);
	return start;	
}
/**
		3->	search for a number
*/
void search(struct node* start, int data)
{
	struct node *ptr;
	int pos = 0;
	int found = 0;
	if(start == NULL)
		printf("List is empty");
	else
	{	
		ptr = start;
		while(ptr != NULL)
		{
			pos++;
			if(ptr -> info == data)
			{
				printf("\n%d found at position %d\n",data,pos);
				found = 1;
				break;
			}
			ptr = ptr->link;
		}
	}
	if(found == 0)
		printf("\n%d not found :( ",data);
}
/**
		4-> Reversing a linked list
*/
struct node* reverse(struct node *start1)
{
	struct node *ptr = NULL;
	struct node *pre = NULL;
	struct node *next = NULL;
	struct node *start2 = NULL;
	start2 = copy(start1);
	ptr = start2;
	while(ptr != NULL)
	{
		next = ptr -> link;
		ptr -> link = pre;
		pre = ptr;
		ptr = next;
	}
	start2 = pre;
	return start2;	
}	
/**
		5-> Sorting via selection sort by exchanging information
*/
void countSortExchangingInfo(struct node *start)
{
	struct node *p,*q;
	int tmp;
	if(start == NULL)
		return;
	for(p = start; p -> link != NULL; p = p -> link)
		for(q = p->link; q != NULL; q = q->link)
			if(p -> info > q -> info)
			{
				tmp = p->info;
				p->info = q->info;
				q->info = tmp;
			}
}

/**
		6-> Sorting via bubble sort by exchanging information
*/
void bubbleSortExchangingInfo(struct node *start)
{
	struct node *p,*q;
	struct node *end;
	int tmp;
	
	if(start == NULL)
		return;
	for(end = NULL; end!= start->link; end = q)
		for(p=start; p->link != end; p=p->link)
		{
			q = p->link;
			if(p->info > q->info)
			{
				tmp = p->info;
				p->info = q->info;
				q->info = tmp;
			}
		}
}

/**
		7-> Sorting via selection sort by exchanging Links
*/
struct node* countSortExchangingLinks(struct node *start)
{
	struct node *p,*q,*temp,*r,*s;
	if(start == NULL)
		return;
	for(r=p=start; p->link != NULL; r=p, p=p->link)
		for(s=q=p->link; q!=NULL; s=q, q=q->link)
		{
			if(p->info > q->info)
			{
				temp = p->link;
				p->link = q->link;
				q->link = temp;
				if(p == start)
					start = q;
				else
					r->link = q;
				s->link = p;
					
				temp = p;
				p = q;
				q = temp;	
			}
		}
	return start;	
}

/**
		8-> Sorting via bubble sort by exchanging Links
*/
struct node* bubbleSortExchangingLinks(struct node *start)
{
	struct node *p,*q,*r;
	struct node *end,*tmp;

	if(start == NULL)
		return;

	for(end = NULL; end != start->link; end = q)
		for(r=p=start; p->link != end; r=p,p=p->link)
		{
			q = p->link;
			if(p->info > q->info)
			{
				p->link = q->link;
				q->link = p;
				if(p == start)
					start = q;
				else
					r->link = q;
				
				tmp = p;
				p = q;
				q = tmp;
			}
		}
	return start;
}

/**
		9-> Create a single linked list that is reverse of a given linked list. (Ques 5 in DS)
*/
void createReverse(struct node *start)
{
	struct node *ptr,*tmp, *start1 = NULL;
	if(start == NULL)
	{
		printf("The list is empty.");
		return;
	}
	ptr = start;
	while(ptr != NULL)
	{
		tmp = (struct node *) malloc(sizeof(struct node));
		tmp -> info = ptr->info;
		if(start1 == NULL)
		{
			tmp ->link = NULL;
			start1 = tmp;
		}	
		else
		{
			tmp->link = start1;
			start1 = tmp;
		}
		ptr = ptr -> link;
	}
	printf("\nHere is your reversed list.");
	display(start1);
}
/**
		10-> Swap adjacent number using information.	
*/
void swapInfo(struct node *start)
{
	struct node *p, *q ;
	int tmp;
	if(start == NULL)
		return;
	for(p=start; p->link != NULL; )
	{
		q=p->link;

		tmp = p->info;
		p->info = q->info;
		q->info = tmp;
		
		if(q->link != NULL)
			p = q->link;
		else
			break;
	}
}

/**
		11-> Swap adjacent numbers using by links.
*/
struct node* swapLink(struct node *start)
{
	struct node *p, *q , *r;
	struct node *tmp;
	if(start == NULL)
		return;
	
	for(p=start; p->link != NULL;)
	{
		q=p->link;
		p->link = q->link;
		if(p == start)
			start = q;
		else
			r->link = q;
		q->link = p;
		
		tmp = p;
		p = q;
		q = tmp;
		r = q;
		
		if(q->link != NULL)
			p=q->link;
		else
			break;
	}
	return start;
}		
/**
		12-> Swap first and last element in linked list.(by information) (ques 8 (a)		pg 105 in DS)
*/
void swapFirstLastInfo(struct node *start)
{
	struct node *ptr,*ptrStart;
	int tmp;
	
	if((start == NULL) || (start ->link == NULL))
		return;
	ptrStart = ptr = start;	
	while(ptr -> link !=NULL)
		ptr = ptr->link;
	tmp = ptrStart -> info;
	ptrStart->info = ptr->info;
	ptr->info = tmp;
}

/**
		13-> Swap first and last element in linked list.(by information) (ques 8 (b)		pg 105 in DS)
*/
struct node* swapFirstLastLink(struct node *start)
{	
	struct node *ptr,*tmp;
		
	if((start == NULL) || (start ->link == NULL))
		return;
	ptr = start;	
	while(ptr -> link ->link != NULL)
		ptr = ptr->link;
	tmp = ptr ->link;
	ptr->link = start;
	tmp->link = start->link;
	start->link =NULL;		//i.e. NULL
	start = tmp;
	return start;
}	


/**
		14-> Swap largest element to end in linked list.(by information) (ques 9 (b)		pg 105 in DS)
*/
struct node* largestToLast(struct node *start)
{	
	struct node *largeptr = NULL;
	struct node *ptr = start;
	int largest = start->info;
	
	if(start == NULL)
		return;
	
	while(ptr->link != NULL)
	{
		if(ptr->link->info > largest)
		{
			largest = ptr->link->info;
			largeptr = ptr;
		}
		ptr = ptr -> link;
	}
	
	if(largeptr == NULL)		//largest element is at beginning
	{
		ptr ->link =start;
		start = start->link;
		ptr->link ->link =NULL;
	}
	else if(largeptr->link->link != NULL)		//largest element is somewhere in middle
	{
		ptr->link = largeptr->link;
		largeptr->link = largeptr->link->link;
		ptr->link->link = NULL;
	}
	else
	{
			// largest is already at last
	}
	
	return start;
}

/**
		15-> Move smallest element to beginning in linked list.(by information) (ques 10 (b)		pg 105 in DS)
*/
struct node* smallestToBeginning(struct node *start)
{	
	struct node *smallptr = NULL,*tmp;
	struct node *ptr = start;
	int smallest = start->info;
	
	if(start == NULL)
		return;
	
	while(ptr->link != NULL)
	{
		if(ptr->link->info < smallest)
		{
			smallest = ptr->link->info;
			smallptr = ptr;
		}
		ptr = ptr -> link;
	}
	
	if(smallptr != NULL)
	{
		tmp = smallptr->link->link;
		smallptr->link->link= start;
		start = smallptr->link;
		smallptr->link = tmp;
	}
	
	return start;
}


/**
		16-> Delete all occurrences of an element from a linked list. (ques 11 pg 105)	
*/
struct node* deleteAllOccurences(struct node *start, int num)
{
	struct node *ptr,*tmp;
	if(start == NULL)
		return;
	while(start ->info == num)
	{
		tmp = start;
		start = start->link;
		free(tmp);
		printf("Amit");
	}
	if(start == NULL)
		return;
	ptr = start;
	while(ptr->link!=NULL)
	{
		if(ptr->link->info == num)
		{
			tmp = ptr->link;
			ptr->link = ptr->link->link;
			free(tmp);
		}
		if(ptr->link != NULL)
			ptr = ptr->link;
	}
	return start;
}
/**
		17-> Print elements of second list acording to first list. (ques 12 pg 105)	
*/

void printAccordingly(struct node *start1,struct node *start2)
{
	struct node *ptr1, *ptr2;
	int count = 1;
	int c;
	ptr2 = start2;

	if(start1 == NULL || start2 == NULL)
		return;
	for(ptr1 = start1; ptr1!=NULL && ptr2!=NULL; ptr1 = ptr1->link)
	{
		c=ptr1->info;
		while((ptr2!=NULL) && c!=count)
		{
			count++;
			ptr2 = ptr2->link;
		}
		if(ptr2 == NULL)
		{
			printf("\nThe number of elements is lesser than %d.",c);
			return;
		}
		printf(" %d ",ptr2->info);
	}
}

/**
		18-> Move a pointer n positions forward.(ques 15 on 105)
*/
void moveByNpos(struct node *start,int pos)
{
	struct node *ptr1,*ptr2,*tmp;
	int count = 5;
	//Moving ptr 5 position forward manually as we have to move a given node.
	if(!start)
		return;
	ptr1 = start;
	while(ptr1 && count--)
		ptr1 = ptr1->link;
	ptr2=ptr1;
	while(ptr2 && pos--)
		ptr2 = ptr2->link;
	if(ptr2 == NULL)
	{
		printf("\nNot enough elements to perform the operations.");
		return;
	}	
	tmp = (struct node *)malloc(sizeof(struct node));
	tmp -> info = ptr1->info;
	tmp->link = ptr2->link;
	ptr2->link = tmp;
	ptr1->info = ptr1->link->info;
	ptr1->link = ptr1->link->link;
}

/**
		19: Insert a node before and after a pointer.(ques17 on 105)
*/

void insertBeforeAndAfter(struct node *start,int num1, int num2)
{
	struct node *ptr,*tmp,*tmp1;
	int count = 5;
	//Moving ptr 5 position forward manually as we have to move a given node.
	if(!start)
		return;
	ptr = start;
//	while(ptr && count--)		//Commented out to check if it is right for starting node
//		ptr = ptr->link;
	while(ptr->link)			//To test for the last element
		ptr = ptr->link;
	tmp = (struct node*)malloc(sizeof(struct node));
	tmp->info = ptr->info;
	tmp->link = ptr->link;
	ptr->link = tmp;
	ptr->info = num1;
	
	tmp1 = (struct node*)malloc(sizeof(struct node));
	tmp1->info = num2;
	tmp1->link = tmp->link;
	tmp->link = tmp1;
	
}
/**
		20: Delete all nodes in a linked list.(ques18 on 106)
*/
struct node* destroy(struct node *start)
{
	struct node *tmp;
	if(start == NULL)
		return start;
	while(start!=NULL)
	{
		tmp = start;
		start=start->link;
		free(tmp);
	}
	return start;
}
/**
		21: Delete all duplicate nodes in a sorted linked list.(ques19 on 106)
*/
struct node* deleteDuplicateSorted(struct node *start)
{
	struct node *tmp,*ptr;
	if(start == NULL)
		return NULL;
	start = countSortExchangingLinks(start);
	printf("\nLinked List after sorting.");
	display(start);
	
	ptr=start;
	while((ptr)&&(ptr->link))
	{
		if(ptr->info == ptr->link->info)
		{
			tmp = ptr->link;
			ptr->link=tmp->link;
			free(tmp);
		}
		else
			ptr = ptr->link;
	}
	return start;

}

/**
		22: Delete all duplicate nodes in an unsorted linked list.(ques20 on 106))
*/

struct node* deleteDuplicateUnsorted(struct node *start)
{
	struct node *ptr1, *ptr2,*tmp;
	ptr1 = start;
	for(ptr1 = start; ptr1->link->link; ptr1 = ptr1->link)
	{
		for(ptr2 = ptr1->link; ptr2->link;)
		{
			if(ptr2 == ptr1->link && ptr1->info == ptr2->info)
			{
				tmp = ptr2;
				ptr1->link = ptr2->link;
				ptr2=ptr2->link;
				free(tmp);
			}
			else
				if(ptr1->info == ptr2->link->info)
				{
					tmp = ptr2->link;
					ptr2->link = tmp->link;
					free(tmp);
				}
			else 
				ptr2=ptr2->link;	
		}
	}
	return start;
}

/**
		23: Intersection of two linked lists.(ques21 on 106)
*/
struct node *intersection(struct node *start1, struct node *start2)
{

	struct node *ptr1, *ptr2, *ptr3;
	struct node *tmp;
	struct node *start3=NULL;
	start1=countSortExchangingLinks(start1);
	start2=countSortExchangingLinks(start2);
	printf("\nAfter sorting:");
	display(start1);
	display(start2);
	
	ptr1=start1;
	ptr2=start2;
	while(ptr1 && ptr2)
	{
		if(ptr1->info == ptr2->info)
		{
			tmp=(struct node*)malloc(sizeof(struct node));
			tmp->info=ptr1->info;
			tmp->link = NULL;
			if(start3 == NULL)
			{
				start3 = tmp;
				ptr3=start3;
			}
			else
			{
				ptr3->link = tmp;
				ptr3=tmp;
			}
			ptr1 = ptr1->link;
			ptr2 = ptr2->link;
		}
		else if(ptr1-> info > ptr2->info)
			ptr2 = ptr2->link;
		else 
			ptr1 = ptr1->link;
	}
	return start3;
}
//		24: Union of two linked lists.(ques22 on 106)
struct node* unionn(struct node *start1, struct node *start2)
{
	struct node *ptr1, *ptr2, *ptr3;
	struct node *tmp;
	struct node *start3=NULL;
	start1=countSortExchangingLinks(start1);
	start2=countSortExchangingLinks(start2);
	printf("\nAfter sorting:");
	display(start1);
	display(start2);
	
	ptr1=start1;
	ptr2=start2;
	while(ptr1 && ptr2)
	{
		if(ptr1->info == ptr2->info)
		{
			start3=insert(start3, ptr1->info);
			while((ptr1->link)&&(ptr1->info == ptr1->link->info))
				ptr1 = ptr1->link;
			while((ptr2->link)&&(ptr2->info == ptr2->link->info))
				ptr2 = ptr2->link;
			ptr1 = ptr1->link;
			ptr2 = ptr2->link;
		}
		else if(ptr1-> info < ptr2->info)
		{
			start3 = insert(start3,ptr1->info);
			while((ptr1->link)&&(ptr1->info == ptr1->link->info))
				ptr1 = ptr1->link;
			ptr1 = ptr1->link;
		}	
		else 
		{
			start3 = insert(start3,ptr2->info);
			while((ptr2->link)&&(ptr2->info == ptr2->link->info))
				ptr2 = ptr2->link;
			ptr2 = ptr2->link;
		}
	}
	while(ptr1)
	{
		start3=insert(start3,ptr1->info);
		ptr1=ptr1->link;
	}
	while(ptr2)
	{
		start3=insert(start3,ptr2->info);
		ptr2=ptr2->link;
	}
	
	return start3;
}
/**
		25: Separate +ve and -ve nodes.(ques23 on 106)
*/
struct node* separate(struct node* start)
{
	struct node *startPositive=NULL, *startNegative=NULL;
	struct node *ptrPositive = NULL;
	struct node *ptrNegative = NULL;
	if(start == NULL)
		return NULL;
	while(start)
	{
		if(start->info >= 0)
		{
			if(startPositive == NULL)
			{
				startPositive = start;
				start = start->link;
				startPositive ->link = NULL;
				ptrPositive = startPositive;
			}	
			else
			{
				ptrPositive->link = start;
				start = start->link;
				ptrPositive->link->link=NULL;
				ptrPositive= ptrPositive->link;
			}
		}
		else
		{
			if(startNegative == NULL)
			{
				startNegative = start;
				start = start->link;
				startNegative ->link = NULL;
				ptrNegative = startNegative;
			}	
			else
			{
				ptrNegative->link = start;
				start = start->link;
				ptrNegative->link->link=NULL;
				ptrNegative= ptrNegative->link;
			}
		}
	}
	printf("\nPositive list.");
	display(startPositive);
	printf("\nNegative list.");
	display(startNegative);
	return start;
}
/**
		26: Delete alternate nodes in a linked list.(ques25 on 106)
*/
struct node* deleteAlternate(struct node *start)
{
	struct node *ptr=NULL,*tmp=NULL;
	if(!start)
		return NULL;
	ptr=start;	
	while(ptr && ptr->link)
	{
		tmp = ptr->link;
		ptr->link = tmp->link;
		free(tmp);
		if(ptr->link)
			ptr=ptr->link;
	}
	return start;
}
/**
		27: Print nth element from end. (ques 26 on 106)
*/
void printNthFromEnd(struct node *start, int n)
{
	struct node *ptr1=NULL, *ptr2=NULL;
	ptr1 = ptr2 = start;
	while((--n)&&(ptr1))
		ptr1 = ptr1->link;
	if(!ptr1)
	{
		printf("\nInsufficient number of elements in linked list.");
		return ;
	}
	while(ptr1->link)
	{
		ptr2 = ptr2->link;
		ptr1 = ptr1->link;
	}
	printf("%d from end is %d",n,ptr2->info);
	return ;
}
/**
		28: Detect a cycle and remove it. (ques 27 on 106)
*/
void detectCycle(struct node *start)
{

	struct node *ptr1=start,*ptr2=start;
	int n=9,count=1;
	struct node *slow=NULL, *fast=NULL;

	//making a cycle;
	while(ptr1->link)
		ptr1=ptr1->link;
	while(n--)
		ptr2=ptr2->link;
	ptr1->link=ptr2;	
	
	//Detecting a cycle
	slow=fast=start;
	do{
		slow=slow->link;
		fast=fast->link->link;
	}while(slow!=fast);

	
	slow=start;
	while(slow->link!=fast->link)
	{
		slow=slow->link;
		fast=fast->link;
		count++;
	}
	fast->link=NULL;
	
	printf("\nCycles start at location=%d",count+1);
	display(start);
}
/**
		29: Print the middle element without counting all elements in a single pass. (ques 28 on 106)
*/
void printMiddle(struct node *start)
{
	struct node *ptr1=NULL;
	struct node *ptr2=NULL;
	ptr1=ptr2=start;
	do
	{
		ptr1=ptr1->link;
		ptr2=ptr2->link->link;
	}while(ptr2 && ptr2->link &&ptr2->link->link);
	printf("\nThe middle element is %d",ptr1->info);
}
/**
		30: Combine alternate nodes in a linked list.(ques32 on 106)
*/
struct node* combineAlternate(struct node *start1, struct node *start2)
{
	struct node *start3=NULL;
	struct node *ptr1=start1, *ptr2=start2, *ptr3=start3;
	struct node *tmp=NULL;
	
	do
	{
		if(ptr1)
		{
			tmp=(struct node*)malloc(sizeof(struct node));
			tmp->info = ptr1->info;
			tmp->link = NULL;
			if(start3 == NULL)
			{
				start3 = tmp;
				ptr3 = start3;
			}
			else
			{
				ptr3->link = tmp;
				ptr3=tmp;
			}
			ptr1=ptr1->link;
		}
		if(ptr2)
		{
			tmp=(struct node*)malloc(sizeof(struct node));
			tmp->info = ptr2->info;
			tmp->link = NULL;
			if(start3 == NULL)
			{
				start3 = tmp;
				ptr3 = start3;
			}
			else
			{
				ptr3->link = tmp;
				ptr3=tmp;
			}
			ptr2=ptr2->link;
		}
	}while(ptr1 || ptr2);
	return start3;
}
/**
		31: Check a linked list whether it is a palindrome or not.(ques36 on 106)
*/
void checkPalindrome(struct node *start1)
{
	struct node *ptr1=start1;
	struct node *start2 = reverse(start1);
	printf("\nOriginal linked list:");
	display(start1);
	printf("\nReversed Linked list:");
	display(start2);
	struct node *ptr2=start2;
	while(ptr1!=NULL && ptr2!=NULL && (ptr1->info == ptr2->info))
	{	
		ptr1 = ptr1->link;
		ptr2 = ptr2->link;
	};
	if(ptr1==NULL && ptr2==NULL)
		printf("\n***************>>>>>>>>>>  Palindrome <<<<<<<<<<<<<***********");
	else
		printf("\n***************>>>>>>>>>> Not a palindrome <<<<<<<<<<<<<***********");
}
/**
		32: Find a triplet from three linked lists summing equal to a given number. (GFG)
*/
void findThreeNumbers(struct node *start1, struct node *start2, struct node *start3,int num)
{
	struct node *ptr1 = NULL;
	struct node *ptr2 = NULL;
	struct node *ptr3 = NULL;
	int no, temp;
	int flag = 1; 		//sets to 0 when such a triplet is found.
	
	
//	start1 = bubbleSortExchangingLinks(start1);	//not necessary to sort this
	start2 = bubbleSortExchangingLinks(start2);
	start3 = bubbleSortExchangingLinks(start3);
	start3 = reverse(start3);
	display(start1);
	display(start2);
	display(start3);
	
	ptr1 = start1;
	
	for(ptr1 = start1 ; ptr1!=NULL && flag; ptr1 = ptr1->link)
	{
		ptr2 = start2;
		ptr3 = start3;
		no = num - ptr1->info;
		
		while(ptr2 && ptr3)
		{
			temp = ptr2->info + ptr3->info;
			if(temp == no)
			{
				printf("\nGOTCHAAAAA :%3d + %3d + %3d + = %d",ptr1->info, ptr2->info, ptr3->info, num);
				flag = 0;
				break;
			}
			else if(temp < no)
				ptr2 = ptr2 ->link;
			else	
				ptr3 = ptr3 ->link;
		}
	}
	if(flag)
		printf("\nSuch a triplet is not present in this linked list.");
	
}
/**
		33: Add two numbers represented by linked list.
*/
struct node* addNumbers(struct node *start1, struct node * start2)
{
	struct node *start3 = NULL, *tmp = NULL;
	struct node *ptr1 = NULL, *ptr2 = NULL, *ptr3 = NULL;
	ptr1 = start1;
	ptr2 = start2;
	int sum;
	int carry = 0;
	
	if(start1 == NULL || start2 == NULL)
	{	
		printf("\nNothing to add.");
		return NULL;
	}	
	
	while(ptr1 && ptr2)
	{
		sum = ptr1->info + ptr2->info + carry;
		if(sum > 9)
		{
			sum = sum-10;
			carry = 1;
		}
		else
			carry = 0;
		tmp = (struct node *)malloc(sizeof(struct node));
		tmp -> info = sum;
		tmp->link = NULL;
		if(start3 == NULL)
		{
			start3 = tmp;
			ptr3 = start3;
		}
		else 
		{
			ptr3 -> link = tmp;
			ptr3 = tmp;
		}
		ptr1 = ptr1->link;
		ptr2 = ptr2->link;
	}
	while(ptr1)
	{
		sum = ptr1->info + carry;
		if(sum > 9)
		{
			sum = sum-10;
			carry = 1;
		}
		else
			carry = 0;
		tmp = (struct node *)malloc(sizeof(struct node));
		tmp -> info = sum;
		tmp->link = NULL;
		ptr3 -> link = tmp;
		ptr3 = tmp;
		ptr1 = ptr1->link;
	}
	while(ptr2)
	{
		sum = ptr2->info + carry;
		if(sum > 9)
		{
			sum = sum-10;
			carry = 1;
		}
		else
			carry = 0;
		tmp = (struct node *)malloc(sizeof(struct node));
		tmp -> info = sum;
		tmp->link = NULL;
		ptr3 -> link = tmp;
		ptr3 = tmp;
		ptr2 = ptr2->link;
	}
	if(carry)
	{
		tmp = (struct node *)malloc(sizeof(struct node));
		tmp -> info = carry;
		tmp->link = NULL;
		ptr3 -> link = tmp;
		ptr3 = tmp;
	}
	return start3;
}
/**
		34: Segregate even and odd nodes in a Linked List.
*/
struct node* segregate(struct node *start)
{
	struct node *tmp = NULL;
	struct node *startEven = NULL, *ptr=NULL, *ptrEven=NULL;
	struct node *startOdd = NULL, *ptrOdd=NULL;
	
	ptr=start;
	while(ptr)
	{
		tmp = (struct node*)malloc(sizeof(struct node));
		tmp->info = ptr->info;
		tmp->link=NULL;
		
		if((ptr->info % 2 )== 0)
		{
			if(startEven == NULL)
			{
				startEven = tmp;
				ptrEven = startEven;
			}
			else
			{
				ptrEven -> link = tmp;
				ptrEven = tmp;
			}	
		}
		else
		{
			if(startOdd == NULL)
			{
				startOdd = tmp;
				ptrOdd = startOdd;
			}
			else
			{
				ptrOdd -> link = tmp;
				ptrOdd = tmp;
			}	
		}
		ptr=ptr->link;
	}
	ptrEven->link = startOdd;
	return startEven;
}
/**
		35: Delete nodes which have a greater value on right side. (GFG)
*/
struct node* deleteGreaterNode(struct node *start)
{
	struct node *tmp=NULL, *ptr=NULL,*start2=NULL;
	start = reverse(start);
	display(start);
	ptr = start;
	int max=ptr->info;
	while(ptr->link)
	{
		if(ptr->link->info > max)
		{
			max = ptr->link->info;
			ptr = ptr->link;
		}	
		else if(ptr->link->info == max)
			ptr = ptr->link;
		else
		{
			tmp = ptr->link;
			ptr->link= tmp->link;
			free(tmp);
		}
	}
	start = reverse(start);
	return start;
}
/**
		36: Reverse alternate K nodes in a Singly Linked List (GFG)
*/
struct node* reverseAlternateKNode(struct node *start, int k, int choice)
{
	int count = k-1;
	struct node *ptr=NULL, *last = NULL;
	if(start == NULL)
		return NULL;
	if(k==1)
		return start;
	ptr = start;
	if(choice == 1)
	{
		while(ptr && ptr->link && count--)
			ptr = ptr->link;
		last = ptr->link;
		ptr->link = NULL;
		choice = 0;
		ptr=start;
		ptr = reverseSameLL(ptr);
		start->link = reverseAlternateKNode(last,k,choice);
		return ptr;
	}
	else
	{
		while(ptr && ptr->link && count--)
			ptr = ptr->link;
		choice = 1;	
		ptr->link = reverseAlternateKNode(ptr->link,k,choice);
		return start;
	}
}
/**
		37: Deleting alternate node of a linked list recursively.
*/
struct node* deleteAlternateNode(struct node *start)
{
	struct node *tmp;
	if(start == NULL || start->link == NULL)
		return start;
	tmp = start ->link;
	start->link = deleteAlternateNode(start->link -> link);
	free(tmp);
	return start;
}
/**
		38: Reverse a Linked List in groups of given size GFG
*/
struct node* reverseInGroupOfKNode(struct node *start, int k)
{
	struct node *ptr = NULL, *next = NULL;
	int count = k;
	if(start == NULL || k == 1 || start->link == NULL)
		return start;
	ptr = start;
	while(ptr->link && --count)
		ptr = ptr->link;
	next = ptr->link;
	ptr->link = NULL;
	ptr = reverseSameLL(start);
//	start->link = reverseInGroupOfKNode(next, k);
	start->link = next;
	count = k;
	while(next && --count)
		next = next->link;
	if(next)
		next->link = reverseInGroupOfKNode(next -> link,k);
	return ptr;
}

struct node *reverseLL(struct node *start, int k)
{
	if(start == NULL)
		return NULL;
	struct node *ptr = start;
	struct node *old_ptr = NULL;
	int count = 0;
	while(ptr && ptr->link && count != k)
	{
		old_ptr = ptr;
		ptr = ptr->link;
		count++;
	}
	old_ptr->link = NULL;
	old_ptr = reverseSameLL(start);
	start->link = reverseLL(ptr, k);
	return old_ptr;
}
/**
		39: Merge two sorted list
*/
struct node* merge(struct node *start1 , struct node *start2)
{
	struct node *start3 = NULL;
	struct node *ptr1 = NULL, *ptr2= NULL, *ptr3=NULL;
	struct node *tmp = NULL;
	if((start1 == NULL) && (start2 == NULL))
		return NULL;
	if(!start1)
		return start2;
	if(!start2)
		return start1;
	ptr1 = start1;
	ptr2 = start2;
	while(ptr1 && ptr2)
	{
		if(ptr1->info < ptr2->info)
		{
			tmp = (struct node *)malloc(sizeof(struct node));
			tmp -> info = ptr1->info;
			tmp -> link = NULL;
			if(start3 == NULL)
			{
				start3 = tmp;
				ptr3 = start3;
			}
			else
			{	
				ptr3->link = tmp;
				ptr3 = tmp;
			}
			ptr1 = ptr1->link;
		}
		else if(ptr1->info >= ptr2->info)
		{
			tmp = (struct node *)malloc(sizeof(struct node));
			tmp -> info = ptr2->info;
			tmp -> link = NULL;
			if(start3 == NULL)
			{
				start3 = tmp;
				ptr3 = start3;
			}
			else
			{	
				ptr3->link = tmp;
				ptr3 = tmp;
			}
			ptr2 = ptr2->link;
		}
	}
	while(ptr1)
	{
		tmp = (struct node *)malloc(sizeof(struct node));
		tmp -> info = ptr1->info;
		tmp -> link = NULL;
		ptr3->link = tmp;
		ptr3 = tmp;
		ptr1 = ptr1->link;
	}
	while(ptr2)
	{
		tmp = (struct node *)malloc(sizeof(struct node));
		tmp -> info = ptr2->info;
		tmp -> link = NULL;
		ptr3->link = tmp;
		ptr3 = tmp;
		ptr2 = ptr2->link;
	}
	return start3;
}
/**
		40: reverse LL recursively
*/
struct node* reverseRecursively(struct node *start)
{
	struct node *tmp = NULL;
	if(start == NULL)
		return NULL;
	if(start -> link == NULL)
		return start;
	tmp = reverseRecursively(start->link);
	start->link->link = start;
	start->link = NULL;
	return tmp;
}
/*********************************isPalindrome returns 1 if true else returns false **********************************/
int isPalindrome(struct node **start, struct node *p)
{
	if(!p)
		return 1;
	if(	!isPalindrome(start, p->link) || ((*start)->info) != p->info)
		return 0;
	else
		*start = (*start)->link;
	return 1;
}

/************
42.Given a linked list, reverse alternate nodes and append at the end

nput List:  1->2->3->4->5->6
Output List: 1->3->5->6->4->2

Input List:  12->14->16->18->20
Output List: 12->16->20->18->14
**********/
struct node *reverseAlternateNodes(struct node *start)
{
	struct node *ptr = NULL;
	struct node *newStart = NULL, *next = NULL;
	struct node *prevPtr = NULL;
	if((start == NULL) || start -> link == NULL)
		return start;
	ptr = start;
	
	while(ptr && ptr->link)
	{
		next = ptr->link;
		ptr->link = next->link;
		if(!newStart)
		{
			next->link = NULL;
			newStart = next;
		}
		else
		{
			next->link = newStart;
			newStart = next;
		}
		prevPtr = ptr;
		ptr = ptr->link;
	}
	if(ptr)
		ptr->link = newStart;
	else
		prevPtr->link = newStart;
	return start;
}


/**
 * 43. reversing in pairs
 */
struct node *reverseInPair(struct node *start) {
	struct node *ptr, *next, *pre=NULL;
	if(!start || !(start ->link))
		return start;
	ptr = start;
	while(ptr && ptr->link) {
		next = ptr->link;
		ptr->link = next->link;
		next->link = ptr;
		if(pre == NULL) {
			start = next;
		}
		else
			pre->link = next;
		pre = ptr;
		ptr = ptr->link;
	}
	return start;
}

struct node *mergeLlAlternately(struct node *start1, struct node *start2) {
	struct node *p1 = start1, *p2 = start2, *t1 = NULL, *t2=NULL;
	if(start1 == NULL && start2 == NULL) {
		return start1;
	}
	if(start1 == NULL && start2 != NULL)
		return start2;
	if(start1 != NULL && start2 == NULL)
		return start1;
	while(p1 && p2) {
		t1 = p1 -> link;
		p1->link = p2;
		t2 = p2->link;
		if(t1 != NULL)
			p2->link = t1;
		p1 = t1;
		p2 = t2;
	}
	return start1;
}



/**
 *  pairwise swap elements in a linked list
 *  1, 2, 3, 4, 5, 6, 7
 *  2, 1, 4, 3, 6, 5, 7
 */
 struct node *pairwiseSwap(struct node *start)
 {
	if(!start || !start->link)
		return start;
	struct node *ptr = start, *next = NULL, *pre = NULL;
	while(ptr && ptr->link)
	{
		next = ptr -> link;
		ptr->link = next->link;
		next->link = ptr;
		if(start == ptr)
			start = next;
		else
			pre->link = next;
		pre = ptr;
		ptr = ptr->link;
	
	}
	return start;
 }
struct node *pairwiseSwap2(struct node *start)
{
	struct node *tmp = NULL, *nextStart = NULL;
	if(!start || !start->link)
		return start;
	tmp = start->link->link;
	start->link->link = start;
	nextStart = start->link;
	start->link = pairwiseSwap2(tmp);
	return nextStart;
}
 
 
/**
 * Given a linked list, reverse alternate nodes and append at the end.
 * Input List:  1->2->3->4->5->6
 * Output List: 1->3->5->6->4->2
 */
 
struct node *reverseAlternate(struct node *start1)
{
	struct node *ptr = NULL, *next = NULL, *start2 = NULL, *pre = NULL, *lastptr = NULL;
	if(!start1 || !start1->link)
		return start1;
	ptr = start1;
	while(ptr && ptr->link)
	{
		next = ptr->link;
		ptr->link = next->link;
		next->link = NULL;
		if(start2 == NULL)
			start2 = next;
		else
			pre -> link = next;
		lastptr = ptr;
		ptr = ptr->link;
		pre = next;
	}
	if(ptr)
		ptr->link = start2;
	else
		lastptr->link = start2;
	return start1;
}

/**
 * Quick Sort in linked List
 */
 
 struct node *PARTITION(struct node *start, struct node *end, struct node **pre, struct node **last)
 {
	struct node *ptr = start, *old = end, *tmp = NULL;
	while(ptr != end)
	{
		if(ptr->info >= end->info)
		{
			if(ptr == start)
				start = ptr -> link;
			else
				(*pre)->link = ptr->link;
			old->link = ptr;
			old = old->link;
		}
		else
			*pre = ptr;
		ptr = ptr->link;
	}
	*last = old;
	return end;
 }
 
 struct node *QS(struct node *start, struct node *end)
 {
	struct node *ptr = NULL, *old = NULL, **last = NULL;
	struct node **pre = NULL;
	if(start != end)
	{
		ptr = PARTITION(start, end, pre, last);
		old = QS(start, *pre);
		if(old)
			old-> link = ptr;
		if(ptr)
			ptr->link = QS(ptr->link, *last);
		return *last;
	}
 }

 struct node *PARTITIONA(struct node *start)
{
	struct node *tmp = start;
	struct node *ptr = tmp->link;
	struct node *startFirst = NULL;
//	*startFirst = NULL;
	
	while(ptr)
	{
		if(ptr->info < start->info)
		{
			tmp->link = ptr->link;
			ptr->link = startFirst;
			startFirst = ptr;
			ptr = tmp->link;
		}
		else
		{
			tmp = tmp->link;
			ptr = ptr->link;
		}
	}
	ptr = startFirst;
//	if(start == *startFirst)
	{
	//	*startFirst = NULL;
		//return start;
	}	
	//while(ptr && ptr->link != start)
//		ptr = ptr->link;
	//ptr->link = NULL;
	return startFirst;
} 
 
 struct node *QuickSort(struct node *start)
 {
	struct node *tmp = NULL, *startFirst = NULL;
	struct node *start1 = NULL;
	struct node *start2 = NULL;
	if(!(start) || !((start->link)))
		return start;
	startFirst = PARTITIONA(start);
	start1 = QuickSort(startFirst);
	tmp = start1;
	start2 = QuickSort(start->link);
	if(start1 != NULL) {
		while(start1->link)
			start1 = start1->link;
		start1->link = start;
	}
	start->link = start2;
	return tmp ? tmp : start;
 }

/**
 * Swap kth npode from beginning and from end
 */ 
struct node *swapKfromBegEnd(struct node *start, int k)
{
	if(start == NULL || k < 1)
		return NULL;
	
	struct  node *ptr2 = start, *ptr1 = start, *prev1, *prev2, *tmp;
	prev1 = prev2 = tmp = NULL;
	struct node *tmp1 = NULL, *tmp2 = NULL;
	while(--k && ptr2)
	{	
		prev1 = ptr2;
		ptr2 = ptr2->link;
	}
	if(!ptr2)
	{
		printf("\n Number of elements in linked list is lesser than k.");
		return NULL;
	}
	while(ptr2->link)
	{
		prev2 = ptr1;
		ptr1 = ptr1->link;
		ptr2 = ptr2->link;
	}
	if(prev1 == NULL)
	{
		tmp = start -> link;
		start -> link = NULL;
		prev2 -> link -> link = tmp;
		tmp = prev2 -> link;
		prev2 -> link = start;
		start = tmp;
		return start;
	}
	
	if(prev1 == prev2)
	{
		return start;
	}
	
	tmp1 = prev1->link->link;
	tmp2 = prev2->link->link;
	prev1->link->link = tmp2;
	prev2->link->link = tmp1;
	tmp = prev1->link;
	prev1->link=prev2->link;
	prev2->link = tmp;
	return start;
} 

struct node *swapKfromBegEnd2(struct node *start, int k)
{
	if(start == NULL || k < 1)
		return start;
	struct node *ptr1 = start;
	struct node *ptr2 = start;
	struct node *par1 = NULL;
	struct node *par2 = NULL;
	struct node *tmp1, *tmp2;
	tmp1 = tmp2 = NULL;
	
	while(ptr1 && --k)
	{
		par1 = ptr1;
		ptr1 = ptr1->link;
	}
	if(ptr1 == NULL)
	{
		printf("\nNot enough numbers in linked list so leaving the linked list unchanged.");
		return start;
	}
	while(ptr1->link)
	{
		par2 = ptr2;
		ptr1 = ptr1->link;
		ptr2 = ptr2->link;
	}
	if(par1 == par2)
	{
		printf("\nThe k-th number from beginning and end is same.");
		return start;
	}
	ptr1 = par1 ? par1->link : start;
	if(ptr1 == par2)
	{
		par1 -> link = ptr2;
		ptr1 -> link = ptr2->link;
		ptr2 -> link = ptr1;
		return start;
	}
	
	tmp1 = ptr1->link;
	tmp2 = ptr2->link;
	ptr1->link = tmp2;
	ptr2->link = tmp1;
	par2->link = ptr1;
	if(par1)
		par1->link = ptr2;
	else
		start = ptr2;
	return start;
}
 
 
 /**
 * merge sorting 
 */
struct node *mergee(struct node *p, struct node *q)
{
	struct node *start = NULL, *ptr = NULL;
	while(p && q)
	{
		if(p->info < q->info)
		{
			if(start == NULL) {
				start = p;
				ptr = p;
			}
			else {
				ptr->link = p;
				ptr = p;
			}
			p = p->link;
		}
		else
		{
			if(start == NULL) {
				start = q;
				ptr = q;
			}
			else {
				ptr->link = q;
				ptr = q;
			}
			q = q->link;
		}
	}
	if(p)
		ptr->link = p;
	if(q)
		ptr->link = q;
	return start;
}
struct node *mergeSort(struct node *start)
{
	struct node *slow = NULL, *fast = NULL, *par = NULL; 
	struct node *first = NULL;
	struct node *second = NULL;
	if(!start || !start->link)
		return start;
	slow = fast = start;
	while(fast && fast->link)
	{
		par = slow;
		slow = slow->link;
		fast = fast->link->link;
	}
	par->link = NULL;
	first = mergeSort(start);
	second = mergeSort(slow);
	start = mergee(first, second);
	return start;
}

struct node *mergeAlternately(struct node *p, struct node *q)
{
	struct node *tmp1 = NULL, *tmp2 = NULL;
	struct node *start = p;
	
	if(!p && !q)
		return NULL;
	if(!p)
		return q;
	if(!q)
		return p;
	while(p&&q)
	{
		tmp1 = p->link;
		p->link = q;
		tmp2 = q->link;
		if(!tmp1)
			break;
		q->link = tmp1;
		p = tmp1;
		q = tmp2;
	}
	return start;
}
 
 
/**
 * delete N nodes after M nodes in a linked list.
 */
struct node *deleteMAfterN(struct node *start, int N, int M)
{
	struct node *tmp = NULL;
	if(!start || (N <= 0 && M <= 0))
		return start;
	if(N == 1)
	{
		start->link = deleteMAfterN(start->link, N-1, M);
		return start;
	}
	if(N>1)
		return deleteMAfterN(start->link, N-1, M);
	if(M>0)
	{	
		tmp = start->link;
		free(start);
		return deleteMAfterN(tmp, N, M-1);
	}
}
// PRACTICE

struct node *pairWiseSwap(struct node *start)
{
	struct node *tmp = NULL;
	if(!start || !start->link)
		return start;

	tmp = start->link;
	start->link = tmp -> link;
	tmp->link = start;
	start->link = pairWiseSwap(start->link);
	return tmp;
}


