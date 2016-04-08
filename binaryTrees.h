#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"LinkedList.h"

#define MAX 100
int max(int a, int b){return a>b ? a : b;}
int min(int a, int b){return a<b ? a : b;}

/** Print array
*/
void printArray(int arr[], int size)
{
	int i;
	printf("\n");
	for(i=0;i<size;i++)
		printf("%d   ", arr[i]);
}

int absolute(int a,int b)
{
	return a>b ? a-b : b-a;
}
/*
U n -> nth utility function
	U1-> void preorder_recursion(struct treenode *root)
	U2-> void inorder_recursion(struct treenode *root)
	U3-> void postorder_recursion(struct treenode *root)
	U4-> void preorder_non_recursion(struct treenode *root)
	U5-> void inorder_non_recursion(struct treenode *root)
	U6-> void postorder_non_recursion(struct treenode *root)

M n -> nth main function
	M1-> void display_recursion(struct treenode *root)
	M2-> void display_non_recursion(struct treenode *root)
	M3-> struct treenode* insertTree(struct treenode *root, int ikey)
	M4-> struct treenode* createBTfromArray(struct treenode *root, int arr[], int size)
	M5-case_a -> struct treenode* case_a(struct treenode *root, struct treenode *par, struct treenode *ptr)
	M5-case_b -> struct treenode* case_b(struct treenode *root, struct treenode *par, struct treenode *ptr)
	M5-case_c -> struct treenode* case_c(struct treenode *root, struct treenode *par, struct treenode *ptr)
	M5-> struct treenode* deleteNonRecursively(struct treenode *root, int dkey)
	M6-> struct treenode* deleteRecursively(struct treenode *ptr, int dkey)
	M7-> struct treenode* createBTfromArray(struct treenode *root, int arr[], int size)
	M8-> int height_recursion(struct treenode *ptr)
	M9-> struct treenode* constructFromPreorderInorder(struct node *preptr,struct node *inptr,int size)
	M10-> struct treenode* constructFromPostorderInorder(struct node *postptr,struct node *inptr,int size)

S  -> Stack implementation
	S1 -> int isStackEmpty()
	S2 -> void push(struct treenode *ptr)
	S3 -> struct treenode *pop()

Q  -> Queue implementation
	Q1 -> int isQueueEmpty(struct treenode *queue, int front, int rear)
	Q2 -> void enqueue(struct treenode *ptr,struct treenode *queue, int front, int rear)
	Q3 -> struct treenode *delqueue(struct treenode *queue, int front, int rear)
*/
/******************************		tree treenode structure	******************************/
struct treenode
{
	int info;
	struct treenode *lchild;
	struct treenode *rchild;
	int height;
};
/******************************		create a treenode with a given a value	******************************/
struct treenode *createTreeNode(int info)
{
	struct treenode *tmp;
	tmp = (struct treenode *)malloc(sizeof(struct treenode));
	tmp -> info = info;
	tmp -> rchild = NULL;
	tmp -> lchild = NULL;
	return tmp;
}

/********************************** S-> For stack implementation ********************************/
struct treenode *stack[MAX];
int top = -1;

/********************************** S1-> Returns status of stack ********************************/
int isStackEmpty()
{
	if(top == -1)
		return 1;
	else
		return 0;
}
int isStackEmptyG(int top)
{
	if(top == -1)
		return 1;
	else
		return 0;
}
/********************************** S2-> Inserting a treenode in a stack (pushing)********************************/
void push(struct treenode *ptr)
{
	if(top == MAX-1)
	{
		printf("\nOverflow");
		return;
	}
	stack[++top] = ptr;
}
/********************************** S3-> Deleting a treenode from a stack (popping)********************************/
struct treenode *pop()
{
	struct treenode *ptr = NULL;
	if(top == -1)
	{
		printf("\nUnderflow");
		return NULL;
	}
	ptr = stack[top--];
	return ptr;
}/********************************** S2-> Inserting a treenode in a stack (pushing)********************************/
void pushG(struct treenode *stack[], struct treenode *ptr, int *top)
{
	if(*top == MAX-1)
	{
		printf("\nOverflow");
		return;
	}
	stack[++(*top)] = ptr;
}
/********************************** S3-> Deleting a treenode from a stack (popping)********************************/
struct treenode *popG(struct treenode *stack[], int *top)
{
	struct treenode *ptr = NULL;
	if(*top == -1)
	{
		printf("\nUnderflow");
		return NULL;
	}
	ptr = stack[(*top)--];
	return ptr;
}
/********************************** Q-> For queue implementation ********************************/

/********************************** Q1-> Returns status of queue ********************************/
int isQueueEmpty(struct treenode *queue[MAX], int *front, int *rear)
{
	if(*front==-1 || *front == (*rear)+1)
		return 1;
	else
		return 0;
}
/********************************** Q2-> Inserting a treenode in a Queue (pushing)********************************/
void enqueue(struct treenode *ptr,struct treenode *queue[MAX], int *front, int *rear)
{
	if(*rear == MAX-1)
	{
		printf("\nOverflow in Queue");
		return;
	}
	if(*front == -1)
		*front = 0;
	queue[++(*rear)] = ptr;
}
/********************************** Q3-> Deleting a treenode from a stack (popping)********************************/
struct treenode *dequeue(struct treenode *queue[MAX], int *front, int *rear)
{
	struct treenode *temp;
	if(*front == -1 || *front == *rear+1)
	{
		printf("\nUnderflow in Queue.");
		return NULL;
	}
	temp = queue[(*front)++];
	return temp;
}
/******************************		U1-recursive preorder traversal	******************************/
void preorder_recursion(struct treenode *root)
{
	struct treenode *ptr = root;
	if(root == NULL)
	{
		printf("Tree is empty.");
		return;
	}
	printf(" %3d ",ptr->info);
	if(ptr->lchild)
		preorder_recursion(ptr->lchild);
	if(ptr->rchild)
		preorder_recursion(ptr->rchild);
}
/******************************		U2-recursive inorder traversal	******************************/
void inorder_recursion(struct treenode *root)
{
	struct treenode *ptr = root;
	if(root == NULL)
	{
		printf("Tree is empty.");
		return;
	}
	if(ptr->lchild)
		inorder_recursion(ptr->lchild);
	printf(" %3d ",ptr->info);
	if(ptr->rchild)
		inorder_recursion(ptr->rchild);
}
/******************************		U3-recursive postorder traversal	******************************/
void postorder_recursion(struct treenode *root)
{
	struct treenode *ptr = root;
	if(root == NULL)
	{
		printf("Tree is empty.");
		return;
	}
	if(ptr->lchild)
		postorder_recursion(ptr->lchild);
	if(ptr->rchild)
		postorder_recursion(ptr->rchild);
	printf(" %3d ",ptr->info);
}
/******************************		U4-non-recursive preorder traversal	******************************/
void preorder_non_recursion(struct treenode *root)
{
	struct treenode *ptr = NULL;
	if(root == NULL)
	{
		printf("Tree is empty.");
		return;
	}
	else
	{
		ptr = root;
		push(ptr);
		while(!isStackEmpty())
		{
			ptr = pop();
			printf(" %2d ",ptr->info);
			if(ptr->rchild)
				push(ptr->rchild);
			if(ptr->lchild)
				push(ptr->lchild);
		}
	}
}
/******************************		U5-non-recursive inorder traversal	******************************/
void inorder_non_recursion(struct treenode *root)
{
	struct treenode *ptr = NULL;
	if(root == NULL)
	{
		printf("Tree is empty.");
		return;
	}
	ptr = root;
	while(1)
	{
		while(ptr->lchild)
		{
			push(ptr);
			ptr = ptr->lchild;
		}
		while(ptr->rchild == NULL)
		{
			printf(" %2d ",ptr->info);
			if(isStackEmpty())
				return;
			ptr = pop();
		}
		printf(" %2d ",ptr->info);
		ptr = ptr->rchild;
	}
}
/******************************		U6-non-recursive postorder traversal	******************************/
void postorder_non_recursion(struct treenode *root)
{
	struct treenode *ptr = root, *q=NULL;
	if(root == NULL)
	{
		printf("Tree is empty.");
		return;
	}
	ptr = root;
	while(1)
	{
		while(ptr->lchild)
		{
			push(ptr);
			ptr = ptr->lchild;
		}
		while(ptr->rchild == NULL || ptr->rchild == q)
		{
			printf(" %2d ",ptr->info);
			q = ptr;
			if(isStackEmpty())
				return;
			ptr = pop();
		}
		push(ptr);
		ptr = ptr->rchild;
	}
}
/******************************		U7-non-recursive level order traversal	******************************/
void level_order(struct treenode *root)
{
	struct treenode *queue[MAX];
	int front = -1;
	int  rear = -1;

	struct treenode *ptr = NULL;
	if(root == NULL)
	{
		printf("Tree is empty.");
		return ;
	}
	ptr = root;
	enqueue(ptr,queue,&front,&rear);
	while(!isQueueEmpty(queue,&front,&rear))
	{
		ptr = dequeue(queue,&front,&rear);
		printf(" %2d ",ptr->info);
		if(ptr->lchild)
			enqueue(ptr->lchild,queue,&front,&rear);
		if(ptr->rchild)
			enqueue(ptr->rchild,queue,&front,&rear);
	}
}
/******************************		M1-displaying a tree in all formats using recursive function	******************************/
void display_recursion(struct treenode *root)
{
	printf("\nPreorder Traversal    : ");
	preorder_recursion(root);
	printf("\nInorder Traversal     : ");
	inorder_recursion(root);
	printf("\nPostorder Traversal   : ");
	postorder_recursion(root);
	printf("\nLevel Order Traversal : ");
	level_order(root);
}
/******************************		M2-displaying a tree in all formats using non-recursive function	******************************/
void display_non_recursion(struct treenode *root)
{
	printf("\nPreorder Traversal    : ");
	preorder_non_recursion(root);
	printf("\nInorder Traversal     : ");
	inorder_non_recursion(root);
	printf("\nPostorder Traversal   : ");
	postorder_non_recursion(root);
	printf("\nLevel Order Traversal : ");
	level_order(root);
}
/******************************		M3-insertion in a binary tree non-recursive	******************************/
struct treenode* insertTree(struct treenode *root, int ikey)
{
	struct treenode *ptr = NULL;
	struct treenode *par = NULL;
	struct treenode *temp = NULL;
	
	ptr = root;
	while(ptr)
	{
		par = ptr;
		if(ikey < ptr->info)
			ptr = ptr->lchild;
		else if(ikey > ptr->info)
			ptr = ptr->rchild;
		else
			{
				printf("\n%d already present.",ikey);
				return root;
			}
	}
	temp = (struct treenode *)malloc(sizeof(struct treenode));
	temp ->info = ikey;
	temp ->lchild = NULL;
	temp ->rchild = NULL;

	if(par == NULL)
		root = temp;
	else
		if(ikey<par->info)
			par->lchild = temp;
	else
		par->rchild = temp;
	
	return root;
}
/******************************		M4-insertion in a binary tree recursively	******************************/
struct treenode* insertTreeRecursive(struct treenode *ptr, int ikey)
{
	struct treenode *temp = NULL;
	if(ptr == NULL)
	{
		temp = (struct treenode*)malloc(sizeof(struct node));
		temp -> info   = ikey;
		temp -> lchild = NULL;
		temp -> rchild = NULL;
		return temp;
	}
	else if(ptr->info > ikey)
		ptr->lchild = insertTreeRecursive(ptr->lchild,ikey);
	else if(ptr->info < ikey)
		ptr->rchild = insertTreeRecursive(ptr->rchild,ikey);
	else
		printf("\n%d already present.\n",ikey);
	return ptr;
}
/******************************		M5-case_c deleting a node having no children	******************************/
struct treenode* case_c(struct treenode *root, struct treenode *par, struct treenode *ptr)
{
	struct treenode *temp = ptr;
	if(par == NULL)
		root = NULL;
	else if(ptr == par->lchild)
		par->lchild = NULL;
	else
		par->rchild = NULL;
	free(temp);
	return root;
}

/******************************		M5-case_b deleting a node having only one children	******************************/
struct treenode* case_b(struct treenode *root, struct treenode *par, struct treenode *ptr)
{
	struct treenode *child;
	struct treenode *temp = ptr;
	if(ptr->lchild)
		child = ptr->lchild;
	else
		child = ptr->rchild;
	if(par == NULL)
		root = child;
	else if(par->lchild == ptr)
		par->lchild = child;
	else
		par->rchild = child;
	free(temp);
	return root;
}
/******************************		M5-case_a deleting a node having both children	******************************/
struct treenode* case_a(struct treenode *root, struct treenode *par, struct treenode *ptr)
{
	struct treenode *succ, *parsucc;
	succ = ptr -> rchild;
	parsucc = ptr;
	while(succ->lchild)
	{
		parsucc = succ;
		succ = succ->lchild;
	}
	ptr->info = succ->info;
	root = case_b(root,parsucc,succ);
	return root;
}

/******************************		M5-deletion in a binary tree non- recursively	******************************/
struct treenode* deleteNonRecursively(struct treenode *root, int dkey)
{
	struct treenode *ptr = NULL;
	struct treenode *par = NULL;
	if(root == NULL)
	{
		printf("\nNothing to delete as the tree is empty.");
		return NULL;
	}
	ptr = root;
	while(ptr)
	{
		if(ptr -> info == dkey)
			break;
		par = ptr;
		if(ptr -> info > dkey)
			ptr = ptr->lchild;
		else if(ptr -> info < dkey)
			ptr = ptr -> rchild;
	}
	if(ptr == NULL)
		printf("\n%d NOT FOUND",dkey);
	else if(ptr->lchild != NULL && ptr->rchild != NULL)
		root = case_a(root,par,ptr);// has both child
	else if(ptr->lchild != NULL || ptr->rchild != NULL)
		root = case_b(root,par,ptr);//has only one child
	else
		root = case_c(root,par,ptr);//has no child

	return root;
}
/******************************		M6-deletion in a binary tree recursively	******************************/
struct treenode* deleteRecursively(struct treenode *ptr, int dkey)
{
	struct treenode *temp, *succ;
	if(ptr==NULL)
	{
		printf("%d NOT FOUND",dkey);
		return ptr;
	}
	else if(dkey < ptr->info)
		ptr->lchild = deleteRecursively(ptr->lchild, dkey);
	else if(dkey > ptr->info)
		ptr->rchild = deleteRecursively(ptr->rchild, dkey);
	else
	{
		// ELEMENT has been found. Now its the time to kill it :) :)

		//the node has both children
		if(ptr->lchild && ptr->rchild)
		{
			succ = ptr->rchild;
			while(succ->lchild)
				succ = succ->lchild;
			ptr->info = succ ->info;
			ptr->rchild = deleteRecursively(ptr->rchild,succ->info);
		}
		else
		{
			temp = ptr;
			// the node has only one children
			if(ptr->lchild)
				ptr = ptr->lchild;
			else if(ptr->rchild)
				ptr = ptr->rchild;
			// the node has no children
			else
				ptr = NULL;
			free(temp);
		}
	}
	return ptr;
}
/******************************		M7-Creating a binary tree from array	******************************/
struct treenode* createBTfromArray(struct treenode *root, int arr[], int size)
{
	int i;
	for(i=0;i<size;i++)
		root = insertTree(root,arr[i]);
	return root;
}


struct treenode* createBinaryTreeFromArray(int arr[], int size) {
	if (size == 0) {
		return NULL;
	}
	struct treenode *root = createTreeNode(arr[0]);
	root ->lchild = NULL;
	root ->rchild = NULL;
	struct treenode *queue[MAX];
	int front = -1;
	int rear = -1;
	enqueue(root,queue,&front,&rear);
	int i = 1;
	while(i < size && !isQueueEmpty(queue, &front, &rear)) {
		struct treenode *tmp = dequeue(queue, &front, &rear);
		if (i < size) {
	printf("%d  >> ", arr[i]);
			tmp->lchild = createTreeNode(arr[i++]);
			enqueue(tmp->lchild,queue,&front,&rear);
		}
		if (i < size) {
	printf("%d  >> ", arr[i]);
			tmp->rchild = createTreeNode(arr[i++]);
			enqueue(tmp->rchild,queue,&front,&rear);
		}
	}
	return root;
}
/******************************		M8-Height of binary tree recursive	******************************/
int height_recursion(struct treenode *ptr)
{
	int lheight, rheight;
	if(ptr == NULL)
		return 0;
	lheight = height_recursion(ptr -> lchild);
	rheight = height_recursion(ptr -> rchild);
	return 1 + ((lheight > rheight) ? lheight : rheight);
}
/******************************		M9-Constructing a binary tree recursively from preorder and inorder list	******************************/
struct treenode* constructFromPreorderInorder(struct node *preptr, struct node *inptr, int size)
{
	struct treenode *temp = NULL;
	struct node *q = NULL;
	int i,j;
	if(size == 0)
		return NULL;
	
	temp = (struct treenode *)malloc(sizeof(struct treenode));
	temp -> info = preptr -> info;
	temp -> lchild = NULL;
	temp -> rchild = NULL;
	if(size == 1)
		return temp;
	q = inptr;
	for(i=0;q->info != preptr->info; i++)
		q = q->link;
	temp->lchild = constructFromPreorderInorder(preptr->link,inptr,i);
	for(j=1;j<=i+1;j++)
		preptr = preptr->link;
	temp->rchild = constructFromPreorderInorder(preptr,q->link,size-i-1);
	return temp;
}
/******************************		M10-Constructing a binary tree recursively from postorder and inorder list	******************************/
struct treenode* constructFromPostorderInorder(struct node *postptr,struct node *inptr,int size)
{
	struct treenode *temp = NULL;
	int i,j;
	struct node *ptr=NULL;
	struct node *q=NULL;

	if(size == 0)
		return NULL;
	ptr = postptr;
	for(i=1;i<size;i++)
		ptr = ptr->link;
	temp = (struct treenode *)malloc(sizeof(struct treenode));
	temp -> info = ptr -> info;
	temp -> lchild = NULL;
	temp -> rchild = NULL;
	if(size == 1)
		return temp;
	q=inptr;
	for(i=0;q->info != ptr->info; i++)
		q=q->link;
	temp->lchild = 	constructFromPostorderInorder(postptr,inptr,i);
	for(j=1;j<=i;j++)
		postptr = postptr->link;
	temp->rchild = constructFromPostorderInorder(postptr,q->link,size-i-1);
	return temp;
}
/******************************		M11-Delete all nodes in a binary tree	******************************/
struct treenode* deleteAllNodes(struct treenode *root)
{
	struct treenode *ptr;
	if(root == NULL)
	{
		printf("\nNo nodes present in tree.");
		return root;
	}
	ptr = root;
	while(ptr)
		ptr = deleteRecursively(ptr, ptr->info);

	return ptr;
}
/******************************		M12-Count all nodes in a binary tree	******************************/
int countAllNodes(struct treenode *root)
{
	int count = 0;
	struct treenode *ptr = root;
	if(root == NULL)
		return count;
	push(ptr);
	while(!isStackEmpty())
	{
		ptr = pop();
		count++;
		if(ptr->rchild)
			push(ptr->rchild);
		if(ptr->lchild)
			push(ptr->lchild);
	}
	return count;
}
/******************************		M13-Height of binary tree non-recursive	******************************/
int height_non_recursion(struct treenode *root)
{
	struct treenode *ptr = NULL;
	int height = 0;
	struct treenode *queue[MAX];
	int front = -1;
	int  rear = -1;
	if(root == NULL)
		return height;
	ptr = root;
	ptr -> height = 1;
	height = ptr->height;
	enqueue(ptr,queue,&front,&rear);
	while(!isQueueEmpty(queue,&front,&rear))
	{
		ptr = dequeue(queue,&front,&rear);
		if(ptr->lchild)
		{
			ptr->lchild->height = ptr->height + 1;
			height = max(height,ptr->lchild->height);
			enqueue(ptr->lchild,queue,&front,&rear);
		}
		if(ptr->rchild)
		{
			ptr->rchild->height = ptr->height + 1;
			height = max(height,ptr->rchild->height);
			enqueue(ptr->rchild,queue,&front,&rear);
		}
	}
	return height;
}
/******************************		M14-Print the neighbour nodes of a given key	******************************/
void neighbourNode(struct treenode *root, int key)
{
	struct treenode *queue[MAX];
	int front = -1;
	int rear = -1;
	int beg;
	int end;
	int i;
	
	struct treenode *ptr=root;

	if(root == NULL)
	{
		printf("\nTree is empty.");
		return;
	}
	ptr->height = 1;
	enqueue(ptr,queue,&front,&rear);
	beg = front;								//beginning index of queue
	while(!isQueueEmpty(queue,&front,&rear))
	{
		ptr = dequeue(queue,&front,&rear);
		printf("%2d ",ptr->info);
		if(ptr -> lchild)
		{
			ptr->lchild->height = ptr->height + 1;
			enqueue(ptr->lchild, queue, &front, &rear);
		}
		if(ptr -> rchild)
		{
			ptr->rchild->height = ptr->height + 1;
			enqueue(ptr->rchild, queue, &front, &rear);
		}
	}
	
	end = rear;									//ending index in queue
	for(i=beg;i<=end;i++)
	{
		if(queue[i] -> info == key)
		{
			printf("\nfound at location %d",i+1);
			if((i+1)<=end)
			{
				if(queue[i]->height == queue[i+1]->height)
					printf("\n%d is the right node of %d",queue[i+1]->info,queue[i]->info);
				else
					printf("\n%d doesn't have any right node.",queue[i]->info);

			}
			else
				printf("\n%d doesn't have any right node.",queue[i]->info);

			if((i-1)>=beg)
			{	if(queue[i]->height == queue[i-1]->height)
					printf("\n%d is the left node of %d",queue[i-1]->info,queue[i]->info);
				else
					printf("\n%d doesn't have any left node.",queue[i]->info);
			}
			else
				printf("\n%d doesn't have any left node.",queue[i]->info);
			break;
		}
	}
	if(queue[i] -> info != key )
		printf("\n%d Not found",key);
}
/******************************		M15-Print the postorder traversal from inorder and preorder traversal	******************************/
void printPostptr(int inptr[], int preptr[], int size)
{
	int i;
	for(i=0; inptr[i] != preptr[0]; i++)		// i pointd to first node of preptr in inptr
		;
	if(i!=0)						//see if ith node has any left tree or not
		printPostptr(inptr,preptr+1,i);
	if(i!=size-1)					// see if ith node has any right tree or not
		printPostptr(inptr+i+1,preptr+i+1,size-i-1);
	printf("%2d ",inptr[i]);
}
/******************************		M16-Print the preorder traversal from inorder and postorder traversal	******************************/
void printPreptr(int inptr[], int postptr[], int size)
{
	int i;
	printf("%2d ",postptr[size-1]);
	for(i=0; inptr[i] != postptr[size-1]; i++)		// i pointed to last node of postptr in inptr
		;
	if(i!=0)						//see if ith node has any left tree or not
		printPreptr(inptr,postptr,i);
	if(i!=size-1)					// see if ith node has any right tree or not
		printPreptr(inptr+i+1,postptr+i,size-i-1);
}
/******************************		M17-Print the left view of the tree.	******************************/
void viewLeft(struct treenode *root, int level, int *maxlevel)
{
	if(root == NULL)
		return ;
	level++;
	if(*maxlevel < level)
	{
		printf("%2d ",root->info);
		*maxlevel = level;
	}
	viewLeft(root->lchild, level, maxlevel);
	viewLeft(root->rchild, level, maxlevel);
}
/******************************		M18-Print the right view of the tree.	******************************/
void viewRight(struct treenode *root, int level, int *maxlevel)
{
	if(root == NULL)
		return ;
	level++;
	if(*maxlevel < level)
	{
		printf("%2d ",root->info);
		*maxlevel = level;
	}
	viewRight(root->rchild, level, maxlevel);
	viewRight(root->lchild, level, maxlevel);
}
/******************************		M19(a)-Difference between sums of odd level and even level nodes of a Binary Tree	******************************/
void differenceA(struct treenode *ptr, int level, int *sum)
{
	if(ptr == NULL)
		return ;
	if(level & 1)
		*sum += ptr->info;
	else
		*sum -= ptr->info;
	differenceA(ptr->lchild,level+1,sum);
	differenceA(ptr->rchild,level+1,sum);
}
/******************************		M19(b)-Difference between sums of odd level and even level nodes of a Binary Tree	******************************/
int differenceB(struct treenode *ptr)
{
	if(ptr == NULL)
		return 0;
	return ptr->info - differenceB(ptr->lchild) - differenceB(ptr->rchild);
}
/******************************		M20-Print ancestors of a given binary tree node without recursion.	******************************/
void printAncestor(struct treenode *ptr)
{
	struct treenode *q=NULL;
	int topp;
	int height = -1;

	if(ptr == NULL)
	{
		printf("\nEmpty tree");
		return;
	}

	while(1)
	{
		while(ptr->lchild)
		{
			push(ptr);
			ptr = ptr->lchild;
		}
		while(ptr->rchild == NULL || ptr->rchild == q)
		{
			q = ptr;
			printf("%d  : ",ptr->info);
			topp = top;
			while(topp!=-1)
			{
				printf("%d ",stack[topp]->info);
				topp--;
			}
			if(isStackEmpty())
				return ;
			ptr = pop();
			printf("\n");
		}
		push(ptr);
		ptr = ptr->rchild;
	}
}
/******************************		M21-Print height of a tree non-recursively	******************************/
int heightNR(struct treenode *ptr)
{
	int height = -1;
	struct treenode *q = NULL;
	int flag = 1;

	if(ptr == NULL)
		return 0;

	while(flag)
	{
		while(ptr->lchild)
		{
			push(ptr);
			ptr = ptr->lchild;
		}
		if(height<top)
			height = top;
		while(ptr -> rchild == NULL || q==ptr->rchild)
		{
			q = ptr;
			if(isStackEmpty())
			{
				flag = 0;
				break;
			}
			ptr = pop();
		}
		push(ptr);
		ptr = ptr->rchild;
	}
	return height+2;
}
/******************************		M22-Find depth of the deepest odd level leaf node.	******************************/
void depthLeafNode(struct treenode *ptr, int level, int *maxDepthOdd, int *maxDepthEven)
{
	if(ptr == NULL)
		return;
	// for odd level leaf node
	if(level&1 && *maxDepthOdd<level && !ptr->rchild && !ptr->lchild)
		*maxDepthOdd = level;
	//For even level leaf node
	if(!(level&1) && *maxDepthEven<level && !ptr->rchild && !ptr->lchild)
		*maxDepthEven = level;
		
	depthLeafNode(ptr->lchild, level+1, maxDepthOdd,maxDepthEven);
	depthLeafNode(ptr->rchild, level+1, maxDepthOdd,maxDepthEven);
}
/******************************		M23-GFG-Deepest left leaf node in a binary tree.	******************************/
void deepestLeftLeaf(struct treenode *ptr, int level, int *maxlevel, struct treenode **p, int isLeft)
{
	if(ptr == NULL)
		return ;
	if(ptr->lchild == NULL && ptr->rchild == NULL &&  *maxlevel<level && isLeft)
	{
		*p = ptr;
		*maxlevel = level;
		return;
	}
	deepestLeftLeaf(ptr->lchild,level+1,maxlevel,p,1);
	deepestLeftLeaf(ptr->rchild,level+1,maxlevel,p,0);
}
/******************************		M24a)recursive-Check if all leaves are at same level.	******************************/
int check(struct treenode *ptr, int level, int *firstLeafNode)
{
	if(ptr == NULL)
		return 1;
	if(ptr -> lchild == NULL && ptr ->rchild == NULL)
	{
		if(*firstLeafNode == -1)
		{
			*firstLeafNode = level;
			return 1;
		}
		return (*firstLeafNode==level);
	}
	return (check(ptr->lchild,level+1,firstLeafNode) && check(ptr->rchild,level+1,firstLeafNode));
}
/******************************		M25)non-recursive-Check if all leaves are at same level.	******************************/
int checkB(struct treenode *root)
{
	struct treenode *ptr = root;
	struct treenode *q=NULL;
	int firstLeafNode = -1;
	int flag = 1;
	top = -1;
	if(ptr == NULL)
		return 1;
	while(flag)
	{
		while(ptr->lchild)
		{
			push(ptr);
			ptr=ptr->lchild;
		}
		while(ptr->rchild==NULL || q==ptr->rchild)
		{
			q=ptr;
			if(!(ptr->lchild) && !(ptr->rchild))
			{
				printf(" : %d :",ptr->info);
				if(firstLeafNode == -1)
					firstLeafNode = top+2;
				else if(firstLeafNode != top+2)
					return 0;
			}
			if(isStackEmpty())
			{
				flag = 0;
				break;
			}
			ptr = pop();
		}
		push(ptr);
		ptr=ptr->rchild;
	}
	return 1;
}
/******************************		M26-GFG-Remove all nodes which dont lie in any path with sum>= k.(non-recursive)	******************************/
struct treenode *remov(struct treenode *root, int k)
{
	top = -1;
	int sum = 0;
	struct treenode *q=NULL, *temp = NULL;
	struct treenode *ptr = root,*par=NULL;

	if(ptr == NULL)
		return NULL;
		
	while(1)
	{
		while(ptr->lchild)
		{
			push(ptr);
			sum += ptr->info;
			ptr = ptr->lchild;
		}
		while(ptr->rchild == NULL || q == ptr->rchild)
		{
			q=ptr;
			if(ptr->lchild == NULL && ptr->rchild == NULL && (sum+ptr->info < k))
			{
				if(top == -1)
					return NULL;
				else
				{
					par = pop();
					if(ptr == par->lchild)
						par->lchild = NULL;
					else
						par->rchild = NULL;
					push(par);
				}
			}
			if(isStackEmpty())
				return root;
			ptr = pop();
			sum -= ptr->info;
		}
		push(ptr);
		sum+=ptr->info;
		ptr = ptr->rchild;
	}
}
/******************************		M27-GFG-Remove all nodes which doesn't lie in any path with sum>= k.(recursive)	******************************/
struct treenode *removRecursively(struct treenode *ptr, int k, int *sum)
{
	int lsum,rsum;
	if(ptr == NULL)
		return NULL;

	lsum = rsum = *sum + ptr->info;

	ptr->lchild = removRecursively(ptr->lchild, k, &lsum);
	ptr->rchild = removRecursively(ptr->rchild, k, &rsum);

	if((lsum>rsum ? lsum : rsum) < k)
	{
		free(ptr);
		ptr = NULL;
	}
	return ptr;
}
/******************************		M28-GFG-Convert a given Binary Tree to Doubly Linked List ******************************/
struct treenode *binaryToDLL(struct treenode *ptr)
{
	struct treenode *inpre, *insucc;	//inorder predecessor, inorder predecessor
	if(ptr == NULL)
		return NULL;
	if(ptr->lchild!=NULL)
	{
		inpre = binaryToDLL(ptr->lchild);
		while(inpre -> rchild)
			inpre = inpre -> rchild;
		ptr -> lchild = inpre;
		inpre->rchild = ptr;
	}
	if(ptr -> rchild!=NULL)
	{
		insucc = binaryToDLL(ptr->rchild);
		while(insucc->lchild)
			insucc = insucc -> lchild;
		ptr -> rchild = insucc;
		insucc -> lchild = ptr;
	}
	return ptr;
}
/******************************		M29-GFG-Remove BST keys outside the given range.(recursive) ******************************/
struct treenode *removeBST(struct treenode *root, int lower, int upper)
{
	if(root == NULL)
		return NULL;

	if(root -> info < lower)
		return removeBST(root->rchild,lower,upper);

	if(root -> info > upper)
		return removeBST(root->lchild,lower,upper);

	root->lchild = removeBST(root->lchild,lower,upper);
	root->rchild = removeBST(root->rchild,lower,upper);
	return root;
}
/******************************		M30-GFG-Construct Complete Binary Tree from its Linked List Representation(recursive) ******************************/
struct treenode *LLtoCBT(struct treenode *root, struct node *ptr)
{
	struct treenode *queue[MAX];
	struct treenode *treeptr = NULL;
	int front = -1, rear = -1;
	if(ptr == NULL)
		return NULL;
	root = createTreeNode(ptr->info);
	ptr = ptr->link;
	enqueue(root,queue,&front,&rear);
	while(ptr)
	{
		treeptr = dequeue(queue,&front,&rear);
		treeptr->lchild = createTreeNode(ptr->info);
		enqueue(treeptr->lchild,queue,&front,&rear);
		ptr = ptr -> link;
		if(ptr)
		{
			treeptr->rchild = createTreeNode(ptr->info);
			enqueue(treeptr->rchild,queue,&front,&rear);
			ptr = ptr -> link;
		}
	}
	return root;
}
/******************************		M31-GFG-Reverse Level Order (non-recursive) ******************************/
void reverseLevelOrder(struct treenode *root)
{
	struct treenode *queue[MAX];
	int front = -1;
	int rear = -1;
	struct treenode *stack[MAX];
	int top = -1;
	struct treenode *tmp = NULL;

	if(!root)
		return;
	enqueue(root,queue,&front,&rear);
	while(!isQueueEmpty(queue,&rear,&front))
	{
		tmp = dequeue(queue,&front,&rear);
		push(tmp);
		if(tmp -> rchild)
			enqueue(tmp->rchild,queue,&front,&rear);
		if(tmp -> lchild)
			enqueue(tmp->lchild,queue,&front,&rear);
	printf("\n%d\n",top);
	}
	printf("\n%d\n",top);
	while(!isStackEmpty())
	{
		printf(" %d ",pop()->info);
	}
}
/******************************		M32-GFG-Reverse Level Order (recursive) ******************************/
void printNodeAtLevel(struct treenode *root, int level)
{
	if(!root)
		return;
	if(level == 1)
	{
		printf(" %d ",root->info);
		return;
	}
	printNodeAtLevel(root->lchild, level - 1);
	printNodeAtLevel(root->rchild, level - 1);
}
void reverseLevelOrderNR(struct treenode *root)
{
	int i;
	int h = height_recursion(root);
	for(i = h; i>0; i--)
		printNodeAtLevel(root,i);
}
/******************************		M33-GFG-Find a pair with given sum in a Balanced BST ******************************/
void printSum(struct treenode *root, int sum)
{
	struct treenode *p1 = root;
	struct treenode *stack1[MAX];
	int top1 = -1;
	int value1;
	int done1 = 1;

	struct treenode *p2 = root;
	struct treenode *stack2[MAX];
	int top2 = -1;
	int value2;
	int done2 = 1;
	int value;

	if(root == NULL)
	{
		printf("\nTree is empty.");
		return;
	}

	while(1)
	{
		while(done1)
		{
			if(p1)
			{
				pushG(stack1,p1,&top1);
				p1 = p1->lchild;
			}
			else if(isStackEmptyG(top1))
			{
				printf("\nNOT FOUND ");
				return;
			}
			else
			{
				p1 = popG(stack1,&top1);
				value1 = p1->info;
				p1=p1->rchild;
				done1 = 0;
			}
		}
		while(done2)
		{
			if(p2)
			{
				pushG(stack2,p2,&top2);
				p2 = p2->rchild;
			}
			else if(isStackEmptyG(top2))
			{
				printf("\nNOT FOUND ");
				return;
			}
			else
			{
				p2 = popG(stack2,&top2);
				value2 = p2->info;
				p2 = p2->lchild;
				done2 = 0;
			}
		}
		value = value1 + value2;
		if(value1!=value2 && sum == value)
		{
			printf("\nElements found. \n %d + %d = %d",value1, value2,value);
			return;
		}
		else if(value > sum)
			done2 = 1;
		else
			done1 = 1;
	}
}
/******************************		M33-GFG-Find a duplet with given sum in a Balanced BST ******************************/
void printTriplet(struct treenode *root, int sum)
{
	struct treenode *ptr = root;
	struct treenode *leftmost = NULL;
	struct treenode *rightmost = NULL;
	struct treenode *p1 = NULL ,*p2 = NULL;
	int sumcal;

	if((root == NULL) || root->lchild->lchild == NULL)
	{
		printf("\nNot enough tree exist.");
		return;
	}

	ptr = binaryToDLL(root);
	leftmost = rightmost = ptr;
	while(leftmost->lchild!=NULL)
		leftmost = leftmost->lchild;
	while(rightmost->rchild!=NULL)
		rightmost = rightmost->rchild;

	ptr = leftmost;
	while(ptr!=NULL)
	{
		printf("  %2d  ",ptr->info);
		ptr = ptr->rchild;
	}
	ptr = leftmost;
	p1 = ptr->rchild;
	p2 = rightmost;
	while(1)
	{
		sumcal = ptr->info + p1->info + p2->info ;
		if(ptr->rchild == rightmost)
			break;
		else if(sumcal == sum)
		{
			printf("\nFOUND\n %2d + %2d + %2d = %2d",ptr->info,p1->info,p2->info,sum);
			return;
		}
		else if(p1->info >= p2->info)
		{
			ptr = ptr->rchild;
			p1 = ptr->rchild;
			p2 = rightmost;
		}
		else if(sumcal>sum)
			p2 = p2->lchild;
		else if(sumcal<sum)
			p1 = p1->rchild;
	}
	printf("\nNOT FOUND\n");
}
/******************************		M34-GFG-Morris Inorder no recursion no stack ******************************/
void printMorrisInorder(struct treenode *root)
{
	struct treenode *ptr = root;
	struct treenode *inpre;
	struct treenode *temp = NULL;
	if(!ptr)
	{
		printf("\nTree is empty.");
		return;
	}

	while(ptr)
	{
		if(ptr->lchild == NULL)
		{
			printf(" %2d ",ptr->info);
			ptr = ptr->rchild;
		}
		else
		{
			inpre = ptr -> lchild;
			while(inpre->rchild)
				inpre = inpre->rchild;
			inpre -> rchild = ptr;
			temp = ptr->lchild;
			ptr->lchild = NULL;
			ptr = temp;
		}
	}
}
/******************************		M35-GFG-Morris Preorder no recursion no stack ******************************/
void printMorrisPreorder(struct treenode *root)
{
	struct treenode *ptr = root;
	struct treenode *inpre;
	if(!root)
	{
		printf("\nTree is empty.");
		return;
	}
	while(ptr)
	{
		printf(" %2d ",ptr->info);
		if(ptr->lchild)
		{
			inpre = ptr ->lchild;
			while(inpre ->rchild)
				inpre = inpre->rchild;
			inpre->rchild = ptr->rchild;
			ptr->rchild = NULL;
			ptr = ptr->lchild;
		}
		else
			ptr = ptr->rchild;
	}
}

void printMorrisPostOrder(struct treenode *root)
{
	struct treenode *ptr = root;
	struct treenode *inpre;
	struct treenode *temp;
	if(!root)
	{
		printf("\nTree is empty.");
		return;
	}
	while(ptr)
	{
		temp = ptr;
		printf(" %2d ",ptr->info);
		if(ptr->rchild)
		{
			inpre = ptr ->rchild;
			while(inpre ->lchild)
				inpre = inpre->lchild;
			inpre->lchild = ptr->lchild;
			ptr->lchild = NULL;
			ptr = ptr->rchild;
		}
		else
			ptr = ptr->lchild;
	}
	printf("\n%d", ptr->info);
	while(temp->rchild) {
		printf("%2d ", temp->info);
		temp = temp -> rchild;
	}
}

/******************************		M36-GFG-Convert a BST to a Binary Tree such that sum of all greater keys is added to every key stack ******************************/
void printSumGreater(struct treenode *root,int *sum)
{
	if(root == NULL)
		return;
	if(root->rchild)
		printSumGreater(root->rchild, sum);
	*sum += root->info;
	root->info = *sum;
//	printf(" %2d ",*sum);  Use this only when you dont want to modify tree. but this will print the tree in exactly reverse manner of preorder traversal.
	if(root->lchild)
		printSumGreater(root->lchild, sum);
}
/******************************		M37-GFG-Convert a BST to a Binary Tree such that sum of all lesser keys is added to every key stack ******************************/
void printSumLesser(struct treenode *root,int *sum)
{
	if(root == NULL)
		return;
	if(root->lchild)
		printSumLesser(root->lchild, sum);
	*sum += root->info;
	printf(" %2d ",*sum);
	if(root->rchild)
		printSumLesser(root->rchild, sum);
}
/******************************		M38-GFG-Convert a given tree to its Sum Tree
 ******************************/
int SumTree(struct treenode *root)
{
	int leftSum;
	int rightSum;
	int oldValue;
	if(!root)
		return 0;
	leftSum = SumTree(root->lchild);
	rightSum = SumTree(root->rchild);
	oldValue = root->info;
	root->info = leftSum + rightSum;
	return root->info + oldValue;
}
/******************************		M39a)-GFG-Finding ceiling of a key in BST
 ******************************/
int ceiling(struct treenode *root, int key)
{
	struct treenode *ptr = NULL;
	int temp;
	if(root == NULL)
		return -1;
	if(root ->info == key)
		return key;
	if(root->info < key)
		return ceiling(root->rchild, key);
	temp = ceiling(root->lchild, key);
	return temp>=key ? temp : root->info;
}
/******************************		M39b)-GFG-Finding floor of a key in BST
 ******************************/
int flooring(struct treenode *root, int key)
{
	int temp;
	if(root==NULL)
		return 9999;
	if(root->info == key)
		return root->info;
	if(root->info > key)
		return flooring(root->lchild, key);
	temp = flooring(root->rchild,key);
	return temp<=key ? temp : root->info;
}
/******************************		M40-GFG-Create a BST from preorder
 ******************************/
struct treenode *createBST(int arr[], int size)
{
	struct treenode *root = createTreeNode(arr[0]);
	int i;
	for(i=1;arr[0]<arr[i];i++)
		;
	if(i-1 >= 1)
		root -> lchild = createBST(arr+1,i-1);
	if(size-i-1 >= 1)
		root -> rchild = createBST(arr+i,size-i);
	return root;
}
/******************************		M41-GFG-Check a tree if it is a complete BT or not. returns 1 for yes and  0 for no ******************************/
int checkCBST(struct treenode *root)
{
	struct treenode *queue[MAX], *ptr = root;
	int rear = -1;
	int front = -1;
	int flag = 1;
	if(root == NULL)
		return 1;
	enqueue(root, queue, &front, &rear);
	while(!isQueueEmpty(queue,&front,&rear))
	{
		ptr = dequeue(queue,&front, &rear);
		if(ptr->lchild)
		{
			if(flag == 1)
				enqueue(ptr->lchild,queue,&front,&rear);
			else
				return flag;
		}
		else
			flag = 0;
		if(ptr->rchild)
		{
			if(flag == 1)
				enqueue(ptr->rchild,queue,&front,&rear);
			else
				return flag;
		}
		else
			flag = 0;
	}
	return 1;
}
/******************************		M42-GFG-Construct a special tree from given preorder traversal ******************************/
struct treenode *createSTree1(int pre[], char preLN[], int size)
{
	struct treenode *ptr, *temp, *root;
	struct treenode *stack[MAX];
	int top =-1;
	root = ptr = createTreeNode(pre[0]);
	int i=1;
	do
	{
		if(ptr->lchild && ptr->rchild)
			ptr = pop();
		temp = createTreeNode(pre[i]);
		if(!ptr->lchild)
			ptr->lchild = temp;
		else if(ptr->rchild == NULL)
			ptr->rchild = temp;

		if(preLN[i] == 'N')
		{
			if(!(ptr->lchild && ptr->rchild))
				push(ptr);
			ptr = temp;
		}
		i++;
	}while(i<size);
	return root;
}
struct treenode *createSTree2(int pre[], char preLN[], int size, int *level)
{
	struct treenode *root = NULL;
	if(size == 0 || *level == size)
		return NULL;

	root = createTreeNode(pre[*level]);
	(*level)++;
	if(preLN[*level - 1] == 'N') {
		root -> lchild = createSTree2(pre, preLN, size, level);
		root -> rchild = createSTree2(pre, preLN, size, level);
	}
	return root;

}

/******************************		M43-GFG-Construct Special Binary Tree from given Inorder traversal ******************************/
struct treenode *cons(int pre[], int size)
{
	int i;
	struct treenode *root;
	if(size==1)
		return root=createTreeNode(pre[0]);
	for(i=0; pre[i]<pre[i+1] && i<size-1; i++)
		;
	root = createTreeNode(pre[i]);
	if(i>0)
		root->lchild = cons(pre,i);
	if(size-i-1>0)
		root->rchild = cons(pre+i+1, size-i-1);
	return root;
}
/******************************		M44-GFG-Lowest Common Ancestor in a Binary Search Tree. ******************************/
void printtt(struct treenode *root, int n1, int n2)
{
	if(root == NULL)
	{
		printf("\nThe tree is empty.");
		return;
	}
	if(root->info == n1 || root->info == n2 || (root->info > n1 && root->info < n2))
	{
		printf("\nThe ancestor is %d", root->info);
		return;
	}
	if(root->info > max(n1,n2))
		printtt(root->lchild, n1, n2);

	if(root->info < min(n1,n2))
		printtt(root->rchild, n1, n2);
}
/******************************		MXX-GFG-Level order traversal in spiral form ******************************/
void spiralTree(struct treenode *root)
{
	struct treenode *ptr = NULL;
	struct treenode *q1[MAX], *q2[MAX];
	int front1, front2, rear1, rear2, i;
	front1 = front2 = rear1 = rear2 = -1;
	int n = 1;
	if(root == NULL)
	{
		printf("\nTree is empty.");
		return;
	}
	ptr = root;
	printf(" %2d ",ptr->info);
	enqueue(ptr,q1,&front1,&rear1);
	while(!isQueueEmpty(q1,&front1,&rear1) || !isQueueEmpty(q2,&front2,&rear2))
	{
		if(n)
		{
			ptr = dequeue(q1,&front1,&rear1);
			if(ptr->lchild)
				enqueue(ptr->lchild,q2,&front2,&rear2);
			if(ptr->rchild)
				enqueue(ptr->rchild,q2,&front2,&rear2);
			if(isQueueEmpty(q1,&front1,&rear1))
			{
				n=0;
				printf("\n");
				for(i=rear2;i!=-1;i--)
					printf(" %2d ",q2[i]->info);
				front1 = rear1 = -1;
			}
		}
		else
		{
			ptr = dequeue(q2,&front2,&rear2);
			if(ptr->lchild)
				enqueue(ptr->lchild,q1,&front1,&rear1);
			if(ptr->rchild)
				enqueue(ptr->rchild,q1,&front1,&rear1);
			if(isQueueEmpty(q2,&front2,&rear2))
			{
				n=1;
				printf("\n");
				for(i=front1;i<=rear1 && i!=-1;i++)
					printf(" %2d ",q1[i]->info);
				front2 = rear2 = -1;
			}
		}
	}
}
/******************************		MXX-GFG-Diameter of a tree. ******************************/
int prr(struct treenode *p,int sum)
{
	if(p==NULL)
		return 0;
	sum-=p->info;
	if((!sum && ((p->rchild == NULL) && (p->rchild == NULL))) || prr(p->lchild,sum) || prr(p->rchild,sum))
	{
		{
			printf(" %2d ",p->info);
			return 1;
		}
	}
	return 0;
}
/******************************		M45-GFG-Height Balanced Tree ******************************/
int isHeightBalanced(struct treenode *root, int *hbf)
{
	int lh = 0;
	int rh = 0;

	if(root == NULL)
		return 0;
	if(*hbf)
	{
		lh = isHeightBalanced(root->lchild,hbf);
		if(*hbf)
			rh = isHeightBalanced(root->rchild,hbf);
		if( !(*hbf) || (absolute(lh,rh)) > 1)
		{
			*hbf = 0;
			return 0;
		}
		else
			return (lh>rh ? lh + 1 : rh + 1);
	}
	return 0;
}
/******************************		M46-GFG-Diamter of Balanced Tree ******************************/
int diameterTree(struct treenode *root, int *dia, struct treenode **ptr)
{
	int lh, rh;
	if(root==NULL)
		return 0;
	lh = diameterTree(root->lchild, dia,ptr);
	rh = diameterTree(root->rchild, dia,ptr);

	if((lh + rh) > *dia)
	{
		*ptr = root;
		*dia = lh + rh + 1;
	}
	return lh>rh ? lh + 1: rh + 1;
}
/******************************	XXX	M47-GFG-Print all root to leaf nodes ******************************/
int rootToLeafPath(struct treenode *ptr)
{
	if(ptr == NULL)
		return 1;
	if(ptr->lchild == NULL && ptr->rchild == NULL)
	{
		printf("\n %2d ",ptr->info);
		return 1;
	}
	if(rootToLeafPath(ptr->lchild))
		printf(" %2d ",ptr->info);
	if(rootToLeafPath(ptr->rchild))
		printf(" %2d ",ptr->info);
	return 0;
}
/******************************		M48-GFG-Double this Tree ******************************/
struct treenode *doubleTree(struct treenode *p1)
{
	struct treenode *p2;
	if(p1==NULL)
		return NULL;
	p2=createTreeNode(p1->info);
	p2->lchild=createTreeNode(p1->info);
	if(p1->lchild)
		p2->lchild->lchild=doubleTree(p1->lchild);
	if(p1->rchild)
		p2->rchild=doubleTree(p1->rchild);
	return p2;
}
/******************************		M49-GFG-Print sorted values from a given array notation of a tree (Non recursive) ******************************/
#define left(i) (2*i + 1)
#define right(i) (2*i + 2)
#define parent(i) ((i-1)/2)
void printSortedBTNonRecursive(int arr[], int size)
{
	int i=0,k=0;
	int flag = 1;
	int j = -1;
	if(size == 0)
		return ;
	while(k<size)
	{
		while(left(i)<size)
			i = left(i);
		while((right(i) >= size)&&(k<size))
		{
			j = i;
			printf(" %2d ",arr[i]);
			k++;
			i = parent(i);
			if(j==right(i))
				i = parent(i);
		}
		if(k<size)
		{
			printf(" %2d ",arr[i]);
			k++;
		}i = right(i);
	}
}
/******************************		M50-GFG-Print sorted values from a given array notation of a tree (Recursively) ******************************/
void printSortedBTRecursive(int arr[], int i, int size)
{
	if(i >= size)
		return ;
	printSortedBTRecursive(arr,left(i),size);
	printf(" %2d ",arr[i]);
	printSortedBTRecursive(arr,right(i),size);
}
/******************************		M51-GFG-Print nodes at level k in a given array notation of a tree (Recursively) ******************************/
void printAtLevelK(struct treenode *root, int k)
{
	if(root == NULL)
		return;
	if(k==1)
	{
		printf(" %2d ",root->info);
		return;
	}
	printAtLevelK(root->lchild, k-1);
	printAtLevelK(root->rchild, k-1);
}
/******************************		M52-GFG-Check whether a tree is foldable or not.(Recursively)  ******************************/
int checkFoldable(struct treenode *p1, struct treenode *p2)
{
	if(!((p1&&p2)||(!p1&&!p2)))
		return 0;
	if(p1 && p2)
		return (checkFoldable(p1->lchild, p2->rchild) && checkFoldable(p2->lchild, p1->rchild));
	return 1;
}
/******************************		M53-GFG-Create a balanced binary search tree from inorder traversal(Recursively) ******************************/
struct treenode *createTree(int arr[], int size, int i)
{
	struct treenode *ptr;
	if(i>=size)
		return NULL;
	ptr = createTreeNode(arr[i]);
	ptr->lchild = createTree(arr,size,left(i));
	ptr->rchild = createTree(arr,size,right(i));
	return ptr;
}
/******************************		M54-GFG-Find the k-th largest element in a tree.(Recursively)    ******************************/
void k_thLargest(struct treenode *root, int *k)
{
	if(!root)
		return ;
	if((root->rchild) && k>0)
		k_thLargest(root->rchild,k);
	if(*k<0)
		return;
	(*k)--;
	if(*k==0)
		printf(" %d ",root->info);
	if((root->lchild) && *k>0)
		k_thLargest(root->lchild,k);
	return;
}
//Second method
int k_thLargest1(struct treenode *root, int *k)
{
	int klar = INT_MIN;
	if(!root)
		return INT_MIN;
	if((root->rchild) && k>0)
		klar = k_thLargest1(root->rchild,k);
	(*k)--;
	if(*k==0)
		return root->info;
	if(klar != INT_MIN)
		return klar;
	if(root->lchild)
		return k_thLargest1(root->lchild,k);
	return INT_MIN;
}
/******************************		M55-GFG-Find the k-th smallest element in a tree.(Recursively)    ******************************/
void k_thSmallest(struct treenode *root, int *k)
{
	if(!root)
		return;
	if((root->lchild) && *k>0)
		k_thSmallest(root->lchild,k);
	if(*k<0)
		return;
	(*k)--;
	if(*k==0)
		printf("%d",root->info);
	if((root->rchild) && *k>0)
		k_thSmallest(root->rchild,k);
}
/******************************		M56-GFG-Find the width of a tree.(Recursively)    ******************************/
int width(struct treenode *root, int arr[], int k)
{
	int lh,rh;
	if(root == NULL)
		return 0;
	arr[k]++;
	lh = width(root->lchild,arr,k+1);
	rh = width(root->rchild,arr,k+1);
	return (lh>rh) ? lh + 1 : rh + 1;
}
void findWidth(struct treenode *root)
{
	int arr[MAX] = {0};
	int maxWidth;
	int height = 0;
	int i;
	height = width(root,arr,height);
	maxWidth = arr[0];
	for(i=1; i<height; i++)
		if(arr[i] > maxWidth)
			maxWidth=arr[i];
	printf("\nThe maximumWidth of tree is = %d",maxWidth);
}
/******************************		M57-GFG-Find the width of a tree.(Recursively)    ******************************/
void printAllPath(struct treenode *root, int arr[], int level)
{
	int i;
	if(root == NULL)
	{
		if(level == 0 )
			printf("\nTree is empty.");
		return;
	}
	arr[level] = root->info;
	if(root->lchild == NULL && root->rchild == NULL)
	{
		printf("\n");
		for(i=0;i<=level;i++)
			printf(" %2d ",arr[i]);
		return;
	}
	printAllPath(root->lchild, arr, level+1);
	printAllPath(root->rchild, arr, level+1);
}
/******************************		M58-GFG-Print all nodes which are at a distance k from a given node in a Binary tree.(Recursively)    ******************************/
int printAllNodesAtDistanceK(struct treenode *start, int key)
{
	if(start == NULL)
		return 0;
	if(key == 0)
	{
		printf(" %2d ",start->info);
		return 1;
	}
	printAllNodesAtDistanceK(start->lchild,  key-1);
	printAllNodesAtDistanceK(start->rchild,  key-1);
	return 0;
}
int PrintAllNodesAtDistanceK(struct treenode *start, int info, int *key)
{
	int ld, rd;
	if(start == NULL)
		return 0;
	if(start ->info == info)
	{
		printAllNodesAtDistanceK(start, *key);
		return 1;
	}
	ld = PrintAllNodesAtDistanceK(start->lchild, info, key);
	if(!ld)
		rd = PrintAllNodesAtDistanceK(start->rchild, info, key);
	if(*key == 0)
	{
		printf(" %2d ",start->info);
		return 1;
	}
	if(ld)
	{
		printAllNodesAtDistanceK(start->rchild, (--(*key)));
		return 1;
	}
	else
	{
		printAllNodesAtDistanceK(start->lchild, (--(*key)));
		return 1;
	}

}
/******************************		M60-Creating an ordinary tree form an array.    ******************************/
struct treenode *createOrdinaryTree(int arr[], int size)
{
	struct treenode *root = NULL;
	struct treenode *queue[MAX], *ptr, *tmp;
	int rear = -1, front = -1;
	int i=2;
	if(size < 0)
	{
		printf("\nSorry there are no elements in array.");
		return NULL;
	}
	root = createTreeNode(arr[0]);
	enqueue(root, queue, &front, &rear);
	while(i<=size)
	{
		if(i%2==0)
			ptr = dequeue(queue, &front, &rear);
		tmp =  createTreeNode(arr[i-1]);
		enqueue(tmp, queue, &front, &rear);
		if(i&1)
			ptr->rchild = tmp;
		else
			ptr->lchild = tmp;
		i++;
	}
	return root;
}
int findd(struct treenode *root, int value)
{
	if(root == NULL)
		return 0;
	if (findd(root->lchild, value) || findd(root->rchild, value))
		return 1;
	return 0;
}
int findAncestor(struct treenode *root, int left, int right)
{
	if(root == NULL)
	{
		printf("\nTree is empty.");
		return 0;
	}
	if(root->info == left)
	{
		if( findd(root->lchild, right) || findd(root->rchild, right) )
		{
			printf("Lowest Ancestor is = :%d",root->info );
			return 0;
		}
		else
			return 1;
	}
	else if(root->info == right)
	{
		if( findd(root->lchild, left) || findd(root->rchild, left) )
		{
			printf("Lowest Ancestor is = :%d",root->info );
			return 0;
		}
		else
			return 1;
	}
	if ( findAncestor(root->lchild, left, right) && findAncestor(root->rchild, left, right) )
	{
		printf("Ancestor is %d ", root->info);
		return 0;
	}
	return 0;
}
/*struct node *findLowestAncestor(struct treenode *root, int left, int right)
{
	int findAll = 0;
	return findLowestAncestor(struct treenode *root, int left, int right, int &findAll);
}*/
int isHB(struct treenode *root, int level)
{
	if(root == NULL)
		return level;
	int lh = isHB(root->lchild, level+1) - 1;
	int rh = isHB(root->rchild, level+1) - 1;
	printf("\nInside Height balanced tree. %d : %d : %d", root->info , level, lh-rh);
	if(!lh || !rh)
		return 0;
	int diff = lh - rh;
	if((diff < 0 ? -diff : diff) <=1)
		return lh > rh ? lh : rh;
	else
		return 0;
}


void printPostptrs(int inptr[], int preptr[], int size)
{
	int i;
	if(size <= 0)
		return;
	if(size==1)
		printf("%2d ",preptr[0]);
	for(i=0; inptr[i] != preptr[0]; i++)		// i pointd to first node of preptr in inptr
		;
//	if(i!=0)						//see if ith node has any left tree or not
		printPostptr(inptr,preptr+1,i);
	//if(i!=size-1)					// see if ith node has any right tree or not
		printPostptr(inptr+i+1,preptr+i+1,size-i-1);
	printf("%2d ",preptr[0]);
}


int removRecursivelyy(struct treenode *ptr, int k, int sum)
{
	int lsum,rsum;
	if(ptr == NULL)
		return 0;

	sum = sum + ptr->info;

	int s1 = removRecursivelyy(ptr->lchild, k, sum);
	int s2 = removRecursivelyy(ptr->rchild, k, sum);

	if(s1 == 0)
	{
		ptr->lchild != NULL ?  free(ptr->lchild) : 1;
		ptr->lchild = NULL;
	}
	if(s2 == 0)
	{
		ptr->rchild != NULL ?  free(ptr->rchild) : 1;
		ptr->rchild = NULL;
	}
	if((s1 == 1) || (s2 == 1) || sum >=k )
		return 1;
	return 0;
}


/**
sum of all keys greater than a given key is added to that key
*/
int add(struct treenode *root) {
	if(root == NULL)
		return 0;
	if(root->rchild)
		root->info += add(root->rchild);
	if(root->lchild)
	{
		root->lchild->rchild->info +=
		root->lchild->info += root->info + add(root->lchild->rchild);
	return root->info;
	}
	return 0;
}

int printff(struct treenode *root, int sum)
{
	if(root == NULL )
		return 0;
	sum -= root -> info;
	if((!sum)
	    || printff(root->lchild, sum)
		|| printff(root->rchild, sum)
	   )
	{
		printf("\n%d  : ", root->info);
		return 1;
	}
	return 0;
}

/**
Prints vertical traversal of a tree
**/
void verticalTraversal(struct treenode *root, int *left, int out[10][10], int x)
{
	int j = 0;
	if(root == NULL)
		return ;
	verticalTraversal(root->lchild, left, out, x-1);
	if(*left == -1)
		*left = x;
	while(out[x-*left][j] != 0)
		j++;
	out[x-*left][j] = root->info;
	verticalTraversal(root->rchild, left, out, x+1);
}
void vert(struct treenode *root)
{
	int left = -1, i, j;
	int out[10][10] = {0};
	int x = 0;
	verticalTraversal(root, &left, out, x);
	for(i=0;i<10;i++)
	{
		printf("\n");
		for(j=0;j<10;j++)
		{
			if(out[i][j] == 0)
				break;
			printf(" %2d ", out[i][j]);
		}
	}
}

/**
print all nodes at distance of k from leaf nodes
**/

void printatdistancek(struct treenode *root, int out[], int level, int k)
{
	if(root == NULL || k<0)
		return;
	if(root->lchild == NULL && root->rchild == NULL)
	{
		if((level - k >= 0) && (out[level-k] != 0))
		{
			printf("  %d, ", out[level-k] );
			out[level-k] = 0;
		}
		return;
	}
	out[level] = root->info;
	printatdistancek(root->lchild, out, level + 1, k);
	printatdistancek(root->rchild, out, level + 1, k);

}

/**
prints all nodes which are at distance of k from root.
*/
void printAllNodesAtDistanceOfk(struct treenode *root, int k)
{
	if(root == NULL)
		return;
	if( k == 0)
	{
		printf("  %d ", root->info);
		return;
	}
	printAllNodesAtDistanceOfk(root->lchild, k - 1);
	printAllNodesAtDistanceOfk(root->rchild, k - 1);
}
/**
printing all nodes at a distance of k from a given node
*/
int printAtDistancekFromGivenNode(struct treenode *root, int ptr, int k, int *p)
{
	if(root == NULL)
		return 0;
	if(root -> info == ptr)
	{
		printAllNodesAtDistanceOfk(root, k);
		(*p)++;
		return 1;
	}
	if(printAtDistancekFromGivenNode(root->lchild, ptr, k, p))
	{
		if(k-*p == 0)
			printf(" %d ", root->info);
		else
			printAllNodesAtDistanceOfk(root->rchild, k - *p);
		(*p)++;
		return 1;
	}
	if(printAtDistancekFromGivenNode(root->rchild, ptr, k, p))
	{
		if(k-*p == 0)
			printf(" %d ", root->info);
		else
			printAllNodesAtDistanceOfk(root->rchild, k - *p);
		(*p)++;
		return 1;
	}
	return 0;
}

/**
print the kth largest element in a binary search tree
*/

void pringd(struct treenode *root, int *k)
{
	if(root == NULL || k < 0)
		return;
	pringd(root->rchild, k);
	(*k)--;
	if(*k==0)
	{
		printf("\n %d ", root->info);
		return;
	}
	pringd(root->lchild,k);
}

/**
 *72: construct a tree from level order traversal and inorder traversal
 */
struct treenode *createTreeFromInAndLevel(int in[], int level[], int size)
{
	struct treenode *root = NULL;
	int leftNodes[100] = {0}, rightNodes[100] = {0};
	int i = 0, j, k, m=0, n=0;

	if(size == 0)
		return NULL;
	root = createTreeNode(level[0]);
	if(size == 1)
		return root;
	for(i=0; in[i] != level[0]; i++)
		;
	k=0;
	for(j=1; j<size; j++)
	{
		for(k=0;k<i;k++) {
			if(level[j] == in[k]){
				leftNodes[m++] = level[j];
				break;
			}
		}
		if(k == i)
			rightNodes[n++] = level[j];
	}
	root->lchild = createTreeFromInAndLevel(in, leftNodes, i);
	root->rchild = createTreeFromInAndLevel(in+i+1, rightNodes, n);
	return root;
}

/**
* common ancestor in a binary tree
*/
struct treenode *commonAncestor(struct treenode *root, int n1, int n2, int *flag1, int *flag2) {
	struct treenode *lc=NULL, *rc=NULL;
	if(root == NULL)
		return NULL;
	lc = commonAncestor(root->lchild, n1, n2, flag1, flag2);
	rc = commonAncestor(root->rchild, n1, n2, flag1, flag2);
	if(lc && rc)
		return root;
/*	if(lc)
	{
		if(root->info == n1)
		{
			*flag1 = 1;
			return root;
		}
		else if(root->info == n2)
		{
			*flag2 = 1;
			return root;
		}
		return lc;
	}
	if(rc)
	{
		if(root->info == n1)
		{
			*flag1 = 1;
			return root;
		}
		else if(root->info == n2)
		{
			*flag2 = 1;
			return root;
		}
		return rc;
	}*/
	if(root->info == n1)
	{
		*flag1 = 1;
		return root;
	}
	else if(root->info == n2)
	{
		*flag2 = 1;
		return root;
	}
	return lc ? lc : rc;
}

/**
 * find the distance between any two nodes in a binary tree
 */
int distance(struct treenode *root, int n1, int n2, int *d1, int *d2, int level, int *flag1, int *flag2) {

	int lc, rc;
	lc = rc = 0;
	if(root == NULL) {
		return -1;
	}
	lc = distance(root -> lchild, n1, n2, d1, d2, level+1, flag1, flag2);
	rc = distance(root -> rchild, n1, n2, d1, d2, level+1, flag1, flag2);
	if(lc!=-1 && rc!=-1)
		return level;
	if(lc!=-1)
	{
		if(root->info == n1)
		{
			*d1 = level;
			*flag1 = 1;
			return *d1;
		}
		else if(root->info == n2)
		{
			*d2 = level;
			*flag2 = 1;
			return *d2;
		}
		else
			return lc;
	}
	if(rc)
	{
		if(root->info == n1)
		{
			*d1 = level;
			*flag1 = 1;
			return *d1;
		}
		else if(root->info == n2)
		{
			*d2 = level;
			*flag2 = 1;
			return *d2;
		}
		else
			return rc;
	}
	if(root -> info == n1)
	{
		*flag1 = 1;
		*d1 = level;
		return level;
	}
	if(root -> info == n2)
	{
		*flag2 = 1;
		*d2 = level;
		return level;
	}
	return -1;
}

int findDistance(struct treenode *root, int n1, int n2){
	int d1 = -1;
	int d2 = -1;
	int flag1 = 0;
	int flag2 = 0;
	int d;
	d = distance(root, n1, n2, &d1, &d2, 0, &flag1, &flag2);
	if(d1!=-1 && d2!=-1)
		return d1+d2-2*d;
	return -1;
}

/**
 * print a tree in vertical manner
 */
void setMinMax(struct treenode *root, int *min, int *max, int hd) {
	if(root == NULL) {
		return ;
	}
	if(hd < *min)
		*min = hd;
	else if(hd > *max)
		*max = hd;
	setMinMax(root->lchild, min, max, hd - 1);
	setMinMax(root->rchild, min, max, hd + 1);
}
void setArray(struct treenode *root, int min, int hd, int m[100][100]) {
	int i;
	if(root == NULL)
		return ;
	for(i=0; i<=100; i++){
		if(m[hd - min][i] == 0) {
			m[hd-min][i] = root->info;
		}
	}
	setArray(root->lchild, min, hd-1, m);
	setArray(root->rchild, min, hd+1, m);
}

void printTreeVertical1(struct treenode *root){
	int min = 0;
	int max = 0;
	int i,j;
	int m[100][100] = {0};
	setMinMax(root,&min,&max,0);
	setArray(root,min,0,m);

	for(i=0;i<=max-min+1; i++){
		printf("\n");
		for(j=0;m[i][j]!=0;j++)
			printf("%d  ",m[i][j]);
	}
}
/**
 * print tree vertical method2 o(n^2)
 */

void printTreeAtAGivenHd(struct treenode *root, int hd, int level)
{
	if(root == NULL)
		return;
	if(hd == level){
		printf(" %d ", root->info);
	}
	printTreeAtAGivenHd(root->lchild, hd, level - 1);
	printTreeAtAGivenHd(root->rchild, hd, level + 1);
}

void printTreeVertical2(struct treenode *root) {
	int min = 0;
	int max = 0;
	int i;
	setMinMax(root, &min, &max, 0);
	for(i=min; i<=max; i++){
		printf("\n");
		printTreeAtAGivenHd(root, i, 0);
	}
}

/**
 * printing a tree from given inorder and level order traversal
 */

struct treenode *printInLevel(int in[], int level[], int size) {
	int i,j,k,p=0;
	struct treenode *root = NULL;
	int tmp[100];
	if(size == 0)
		return NULL;
	root = createTreeNode(level[0]);
	if(size == 1)
		return NULL;
	for(i=0; in[i]!=level[0]; i++)
		;
	for(j=0; j<i; j++)
	{
		for(k=0;k<size;k++) {
			if(in[j] == level[k]) {
				tmp[p++] = in[j];
				break;
			}
		}
	}
	root->lchild = printInLevel(in, tmp, i);
	p=0;
	for(j=i+1; j<size; j++)
	{
		for(k=0;k<size;k++) {
			if(in[j] == level[k]) {
				tmp[p++] = in[j];
				break;
			}
		}
	}
	root->rchild = printInLevel(in+1, tmp, size-i-1);
	return root;
}

/**
 * Printing at a distance of k from a given node
 */
void printAtDistanceK2(struct treenode *root, int k)
{
	if((root == NULL) || k<0)
		return;
	if(k == 0)
	{
		printf(" %d ", root->info);
		return;
	}
	printAtDistanceK2(root->lchild, k-1);
	printAtDistanceK2(root->rchild, k-1);
}

int printAtDistanceOfKFromGivenNode(struct treenode *root, int *k, int value) {
	if((root == NULL) || *k < 0)
		return 0;
	if(root->info == value)
	{
		printAtDistanceK2(root, *k);
		(*k)--;
		return 1;
	}
	if(printAtDistanceOfKFromGivenNode(root->lchild, k, value)) {
		if(*k == 0)
			printf(" %d ", root->info);
		else
			printAtDistanceK2(root->rchild, *k-1);
		(*k)--;
		return 1;
	}
	if(printAtDistanceOfKFromGivenNode(root->rchild, k, value)) {
		if(*k == 0)
			printf(" %d ", root->info);
		else
			printAtDistanceK2(root->lchild, *k-1);
		(*k)--;
		return 1;
	}
	return 0;
}

/**
 * sum of all nodes greater than the given key is added to that key
 */

void addAllKeysGreaterThanTheCurrentKey(struct treenode *root, int *sum)
{
	if(root == NULL)
		return ;
	addAllKeysGreaterThanTheCurrentKey(root->rchild, sum);
	*sum += root->info;
	root->info = *sum;
	addAllKeysGreaterThanTheCurrentKey(root->lchild, sum);
}

/**
 * Print all non sibling nodes
**/
void findNonSiblingNode(struct treenode *root) {
	if(root == NULL)
		return ;

	if(!root->lchild && root->rchild) {
		printf("  %d  ", root->rchild->info);
	}
	if(root->lchild && !root->rchild) {
		printf("  %d  ", root->lchild->info);
	}
	findNonSiblingNode(root->rchild);
	findNonSiblingNode(root->lchild);
}
/**
 * print a tree in zig zag manner
 */

void printZigZag(struct treenode *root) {
	struct treenode *stack1[10];
	struct treenode *stack2[10];
	int top1 = -1;
	int top2 = -1;

	struct treenode *ptr = root;
	pushG(stack1, ptr, &top1);
	while(!isStackEmptyG(top1) || !isStackEmptyG(top2)) {
		printf("\n");
		while(!isStackEmptyG(top1)) {
			ptr = popG(stack1, &top1);
			printf(" %d ", ptr->info);
			if(ptr->lchild) {
				pushG(stack2, ptr->lchild, &top2);
			}
			if(ptr->rchild) {
				pushG(stack2, ptr->rchild, &top2);
			}
		}
		printf("\n");
		while(!isStackEmptyG(top2)) {
			ptr = popG(stack2, &top2);
			printf(" %d ", ptr->info);
			if(ptr->rchild) {
				pushG(stack1, ptr->rchild, &top1);
			}
			if(ptr->lchild) {
				pushG(stack1, ptr->lchild, &top1);
			}

		}
	}
}


/**
 * 77-print boundary elements in a tree
 */
void printLeft(struct treenode *root) {
	if(root == NULL)
		return;
	if(root -> lchild == NULL && root->rchild == NULL)
		return;
	printf("%d  ", root->info);
	if(root->lchild)
		printLeft(root->lchild);
	else if(root -> rchild)
		printLeft(root->rchild);
}

void printLeaf(struct treenode *root) {
	if(root == NULL)
		return;
	if(root -> lchild == NULL && root -> rchild == NULL) {
		printf("%d  ", root->info);
		return;
	}
	printLeaf(root->lchild);
	printLeaf(root->rchild);
}

void printRight(struct treenode *root) {
	if(root == NULL)
		return;
	if(root->lchild == NULL && root->lchild == NULL)
		return;
	if(root -> rchild)
		printRight(root->rchild);
	else if(root->lchild)
		printRight(root->lchild);
	printf("%d  ", root->info);
}

void printBoundaryElements(struct treenode *root) {
	if(root == NULL)
		return;
	printLeft(root);
	printLeaf(root);
	if(root->lchild)
		printRight(root->rchild);
}


/**
 * creating a tree from preorder traversal in O(n) time
 */
struct treenode *createTreeFromPreOrderTraversal(int arr[], int size) {

	struct treenode *root = NULL;
	struct treenode *ptr = NULL, *lastPop = NULL;
	int i = 1;

	if(size <= 0)
		return NULL;
	root=createTreeNode(arr[0]);
	if(size == 1)
		return root;
	push(root);
	while(i<size) {
		if(stack[top]->info > arr[i]) {
			stack[top] -> lchild = createTreeNode(arr[i]);
			push(stack[top]->lchild);
		}
		else if(stack[top]->info < arr[i]) {
	//		lastPop = stack[top];
			while((!isStackEmpty() && (ptr = pop())->info < arr[i])) {
				lastPop = ptr;
			}
			if(!isStackEmpty()) {
				push(ptr);
			}
			lastPop -> rchild = createTreeNode(arr[i]);
			push(lastPop -> rchild);
		}
		i++;
	}
	return root;
}

/**
 * Find the inorder successor of a node in binary Search tree
 */
struct treenode *inSucc(struct treenode *root, int value,struct treenode **insuccNoRightChild)
{
	struct treenode *insucc = NULL;
	if(root == NULL)
		return root;
	if(root->info == value) {
		if(root->rchild){
			insucc = root->rchild;
			while(insucc -> lchild)
				insucc = insucc->lchild;
			return insucc;
		}
		else
			return *insuccNoRightChild;
	}
	else if(root -> info > value) {
		*insuccNoRightChild = root;
		return inSucc(root->lchild, value, insuccNoRightChild);
	}
	return inSucc(root->rchild, value, insuccNoRightChild);
}

/**
 * convert a DLL to a binary Tree
 */
 
struct treenode *DLLToBinary(struct treenode **start, int size) {

	if(start == NULL || size<=0 )
		return NULL;
	struct treenode *root = NULL;
	struct treenode *lc = DLLToBinary(start, size/2);
	root = *start;
	root->lchild = lc;
	*start = (*start)->rchild;
	root->rchild = DLLToBinary(start, size - size/2 - 1);
	return root;
}
/**
 * convert a tree to preorder linked list
 */
 
void createPreorderr(struct treenode *root)
{
	struct treenode *ptr = root;
	struct treenode *temp = NULL;
	while(ptr)
	{
		if(ptr->rchild)
		{
			push(ptr->rchild);
			ptr -> rchild = NULL;
		}
		if(ptr->lchild)
			ptr = ptr->lchild;
		else if(!isStackEmpty())
			{
				temp = pop();
				ptr->lchild = temp;
				ptr = temp;
			}
		else
			ptr = NULL;
	}
	
	ptr = root;
	printf("\nResult");
	while(ptr)
	{        
		printf("  %d  ", ptr->info);
		ptr = ptr->lchild;
	}
}

/**
 * convert a tree to preorder linked list
 */

struct treenode *createPreorder1(struct treenode *root)
{
	struct treenode *ptr = NULL;
	if(root == NULL || (root->lchild == NULL && root->rchild == NULL))
		return root;
	ptr = createPreorder1(root->lchild);
	if(root->rchild)
	{
		if(!ptr)
			root->lchild = root->rchild;
		else
			ptr -> lchild = root->rchild;
		root->rchild = NULL;
		ptr = createPreorder1(root->lchild);
	}
	if(ptr)
		return ptr;
	return root->lchild;
}

void createPreorder(struct treenode *root)
{
	createPreorder1(root);
	printf("\nCreating preorder ...... \n");
	while(root)
	{
		printf("  %d", root->info);
		root = root->lchild;
	}
}

/**********************************
maximum chain length
*********************************/
int getMaxChainLength(struct treenode *root, int isLeft, int isRight, struct treenode **ptr, int *maxChainLength)
{
	int lc;
	int rc;
	if(root == NULL)
	{
		return 0;
	}
	lc = getMaxChainLength(root->lchild, 1, 0, ptr, maxChainLength);
	rc = getMaxChainLength(root->rchild, 0, 1, ptr, maxChainLength);
	
	if(*maxChainLength < lc + rc + 1)
	{
		*maxChainLength = lc + rc + 1;
		*ptr = root;
	}
	if(isLeft)
		return lc + 1;
	else if(isRight)
		return rc + 1;
	else
		return lc + rc + 1;
}

/**
** adding left values to right nodes
**/
void addToRight(struct treenode *root, int *arr, int level)
{
	if(!root)
		return;
	root -> info += arr[level];
	arr[level] = root->info;
	addToRight(root->lchild, arr, level+1);
	addToRight(root->rchild, arr, level+1);

}
void addToRightWrapper(struct treenode *root)
{
	int height = height_recursion(root);
	int *arr = (int *) malloc (height);
	int i;
	for(i = 0; i < height; i++)
		arr[i] = 0;
	addToRight(root, arr, 0);
}

void diagonalSum(struct treenode *root, int *arr, int level)
{
	if(!root)
		return;
	arr[level] += root->info;
	diagonalSum(root -> lchild, arr, level+1);
	diagonalSum(root -> rchild, arr, level);
}

void diagonalSumWrapper(struct treenode *root)
{
	int height = height_recursion(root);
	int *arr = (int *) malloc (height);
	int i;
	for(i = 0; i < height; i++)
		arr[i] = 0;
	diagonalSum(root, arr, 0);
	for(i = 0; i < height; i++)
		printf("\n%d  %d", (i+1), arr[i]);
}


struct treenode *getBiggestBinarySearchTree(struct treenode *root) {
	struct treenode *bstRoot = NULL;
	display_recursion(root);
	int min = INT_MAX;
	int max = INT_MIN;
	int maxHeight = 0;
	getBiggestBST(root, &min, &max, bstRoot, &maxHeight);
	display_recursion(bstRoot);
	return bstRoot;
}

int getBiggestBST(struct treenode *root, int *maximum, int *minimum, struct treenode *bigRoot, int *maxHeight) {

printf("%d >> ", root -> info);
	if (!root) {
		return 0;
	}

	int isBst = 1;
	int leftBstHeight = getBiggestBST(root -> lchild, maximum, minimum, bigRoot, maxHeight);
	if (leftBstHeight == -1 || root -> info < *minimum) {
		isBst = 0;
	}

	int rightBstHeight = getBiggestBST(root -> rchild, maximum, minimum, bigRoot, maxHeight);
	if (rightBstHeight == -1 || root -> info > *maximum) {
		isBst = 0;
	}

	*minimum = *minimum < root -> info ? *minimum : root -> info;
	*maximum = *maximum > root -> info ? *maximum : root -> info;

	if (isBst && (*maxHeight < leftBstHeight + rightBstHeight + 1)) {
		bigRoot = root;
		*maxHeight = leftBstHeight + rightBstHeight + 1;
		return *maxHeight;
	}
	return -1;
}
