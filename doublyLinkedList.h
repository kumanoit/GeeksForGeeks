/*
 * doublyLinkedList.h
 *
 *  Created on: Jan 26, 2016
 *      Author: kuma
 */

#ifndef DOUBLYLINKEDLIST_H_
#define DOUBLYLINKEDLIST_H_



#endif /* DOUBLYLINKEDLIST_H_ */

void printDoublyLinkedList(struct TreeNode *start) {
	printf("\nPrinting doubly linked list from left to right.\n");
	struct TreeNode *ptr = start;
	while(ptr -> leftChild) {
		ptr = ptr -> leftChild;
	}
	while (ptr) {
		printf("%d\t", ptr -> value);
		ptr = ptr -> rightChild;
	}

	struct TreeNode *lastNode = start;
	while(lastNode -> rightChild) {
		lastNode = lastNode -> rightChild;
	}

	printf("\nPrinting doubly linked list from right to left.\n");
	while (lastNode) {
		printf("%d\t", lastNode -> value);
		lastNode = lastNode -> leftChild;
	}
}

