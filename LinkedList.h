/*
 * LinkedList.h
 *
 *  Created on: Apr 19, 2016
 *      Author: kuma
 */


#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_



#endif /* LINKEDLIST_H_ */

struct LinkedList {
	int info;
	struct LinkedList *next;
};

struct LinkedList *createLinkedList(int info) {
	struct LinkedList *node = (struct LinkedList *) malloc (sizeof(struct LinkedList));
	node -> info = info;
	node -> next = NULL;
	return node;
}

void insertLinkedList(struct LinkedList **head, int info) {
	struct LinkedList *node = createLinkedList(info);
	if (!(*head)) {
		*head = node;
		return;
	}
	struct LinkedList *ptr = *head;
	while (ptr -> next) {
		ptr = ptr -> next;
	}
	ptr -> next = node;
}

void displayLinkedList(struct LinkedList **head) {
	struct LinkedList *ptr = *head;
	printf("\nPrinting Linked List\n");
	while(ptr) {
		printf("%d ", ptr -> info);
		ptr = ptr -> next;
	}
}
