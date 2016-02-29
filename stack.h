/*
 * stack.h
 *
 *  Created on: Jan 25, 2016
 *      Author: kuma
 */

#ifndef STACK_H_
#define STACK_H_

#endif /* STACK_H_ */

#ifndef NULL
#define NULL   ((void *) 0)
#endif

#define MAX 100

struct TreeNodeStack {
	struct TreeNode *stack[MAX];
	int top;
};

void setStack(struct TreeNodeStack *stack) {
	stack -> top = -1;
}

void push(struct TreeNodeStack *treeNodeStack, struct TreeNode *node) {
	if (treeNodeStack -> top == MAX) {
		printf("Overflow");
		return;
	}
	treeNodeStack -> stack[++(treeNodeStack -> top)] = node;
}

struct TreeNode *pop(struct TreeNodeStack *treeNodeStack) {
	if (treeNodeStack -> top == -1) {
		printf("Underflow");
		return NULL;
	}
	struct TreeNode *temp = treeNodeStack -> stack[(treeNodeStack -> top)--];
	return temp;
}

struct TreeNode *peek(struct TreeNodeStack *treeNodeStack) {
	return treeNodeStack -> stack[treeNodeStack -> top];
}

int isStackEmpty(struct TreeNodeStack *treeNodeStack) {
	return treeNodeStack -> top == -1;
}
