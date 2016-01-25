/*
 * Queues.h
 *
 *  Created on: Jan 23, 2016
 *      Author: kuma
 */

#ifndef QUEUES_H_
#define QUEUES_H_



#endif /* QUEUES_H_ */

#include"treeNode.h"

#define MAX 100

struct TreeNodeQueue {
	struct TreeNode *queue[MAX];
	int front;
	int rear;
};

void setQueue(struct TreeNodeQueue *queue) {
	queue -> front = -1;
	queue -> rear = -1;
}

void enqueue(struct TreeNodeQueue *treeNodeQueue, struct TreeNode *node) {
	if (treeNodeQueue -> front == treeNodeQueue -> rear + 1) {
		printf("Overflow");
		return;
	}
	if (treeNodeQueue -> front == -1) {
		treeNodeQueue -> front = 0;
	}
	treeNodeQueue -> queue[++(treeNodeQueue -> rear)] = node;
}

struct TreeNode *dequeue(struct TreeNodeQueue *treeNodeQueue) {
	if (treeNodeQueue -> front == -1) {
		printf("Underflow");
	}
	struct TreeNode *temp = treeNodeQueue -> queue[treeNodeQueue -> front];
	if(treeNodeQueue -> front == treeNodeQueue -> rear) {
		treeNodeQueue -> front = treeNodeQueue -> rear = -1;
	} else {
		(treeNodeQueue -> front)++;
	}
	return temp;
}

int isQueueEmpty(struct TreeNodeQueue *treeNodeQueue) {
	return treeNodeQueue -> front == -1;
}
