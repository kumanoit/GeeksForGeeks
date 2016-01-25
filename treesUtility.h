/*
 * Trees.h
 *
 *  Created on: Jan 23, 2016
 *      Author: kuma
 */

#ifndef TREES_H_
#define TREES_H_



#endif /* TREES_H_ */

#include<stdio.h>
#include<stdlib.h>

#include"queues.h"
#include"myMath.h"

void printPreOrder(struct TreeNode *root) {
	if (!root) {
		return;
	}
	printf("%d\t", root -> value);
	printPreOrder(root -> leftChild);
	printPreOrder(root -> rightChild);
}

void printInOrder(struct TreeNode *root) {
	if (!root) {
		return;
	}
	printInOrder(root -> leftChild);
	printf("%d\t", root -> value);
	printInOrder(root -> rightChild);
}

void printPostOrder(struct TreeNode *root) {
	if (!root) {
		return;
	}
	printPostOrder(root -> leftChild);
	printPostOrder(root -> rightChild);
	printf("%d\t", root -> value);
}

void printLevelOrder(struct TreeNode *root) {
	if (!root) {
		return;
	}
	struct TreeNodeQueue queue;
	setQueue(&queue);
	enqueue(&queue, root);
	while (!isQueueEmpty(&queue)) {
		struct TreeNode *temp = dequeue(&queue);
		printf("%d\t", temp -> value);
		if (temp -> leftChild) {
			enqueue(&queue, temp -> leftChild);
		}
		if (temp -> rightChild) {
			enqueue(&queue, temp -> rightChild);
		}
	}
}

void display(struct TreeNode *root) {
	printf("\nPreOrder  Traversal : \t");
	printPreOrder(root);
	printf("\nInOrder   Traversal : \t");
	printInOrder(root);
	printf("\nPostOrder Traversal : \t");
	printPostOrder(root);
	printf("\nLeveOrder Traversal : \t");
	printLevelOrder(root);

}
struct TreeNode *createTreeNode(int info) {
	struct TreeNode *root = (struct TreeNode *) malloc (sizeof(struct TreeNode));
	root -> value = info;
	root -> leftChild = NULL;
	root -> rightChild = NULL;
	return root;
}

struct TreeNode *createBinaryTree(int array[], int size) {
	if (size == 0) {
		printf("Tree is empty.");
		return NULL;
	}
	struct TreeNode *root = createTreeNode(array[0]);

	struct TreeNodeQueue queue;
	setQueue(&queue);

	enqueue(&queue, root);

	int i = 1;
	while (i < size) {
		struct TreeNode *temp = dequeue(&queue);
		temp -> leftChild = createTreeNode(array[i++]);
		enqueue(&queue, temp -> leftChild);
		if (i < size) {
			temp -> rightChild = createTreeNode(array[i++]);
			enqueue(&queue, temp -> rightChild);
		}
	}
	return root;
}

int getTreeSize(struct TreeNode *root) {
	if (!root) {
		return 0;
	}
	return 1 + getTreeSize(root->leftChild) + getTreeSize(root -> rightChild);
}

int areIdentical(struct TreeNode *root1, struct TreeNode *root2) {
	if (!root1 && !root2) {
		return 1;
	}
	if (!root1 || !root2 || root1 -> value != root2 -> value) {
		return 0;
	}
	return areIdentical(root1 -> leftChild, root2 -> leftChild) &&
			areIdentical(root1 -> rightChild, root2 -> rightChild);
}

int getHeightOfTree(struct TreeNode *root) {
	if (!root) {
		return 0;
	}
	int leftHeight = getHeightOfTree(root -> leftChild);
	int rightHeight = getHeightOfTree(root -> leftChild);
	return 1 + max(leftHeight, rightHeight);
}

void deleteTree(struct TreeNode *root) {
	if (!root) {
		return;
	}
	deleteTree(root -> leftChild);
	deleteTree(root -> rightChild);
	struct TreeNode *temp = root;
	root = NULL;
	free(temp);
}

struct TreeNode *convertToMirrorTree(struct TreeNode *root) {
	if (!root) {
		return NULL;
	}
	convertToMirrorTree(root -> leftChild);
	convertToMirrorTree(root -> rightChild);
	struct TreeNode *temp = root -> leftChild;
	root -> leftChild = root -> rightChild;
	root -> rightChild = temp;
	return root;
}

void printAllRootToLeafPath(struct TreeNode *root, int level, int output[]) {
	if (!root) {
		return;
	}
	int i = 0;
	output[level] = root -> value;
	if (isLeaf(root)) {
		for(i = 0; i <= level; i++) {
			printf("%d\t", output[i]);
		}
		printf("\n");
		return;
	}
	printAllRootToLeafPath(root -> leftChild, level + 1, output);
	printAllRootToLeafPath(root -> rightChild, level + 1, output);
}

struct TreeNode *lowestCommonAncestor(struct TreeNode *root, int num1, int num2) {
	if (!root) {
		return NULL;
	}
	struct TreeNode *fromLeftTree = lowestCommonAncestor(root -> leftChild, num1, num2);
	struct TreeNode *fromRightTree = lowestCommonAncestor(root -> rightChild, num1, num2);
	if (root -> value == num1) {
		return root;
	}
	if (root -> value == num2) {
		return root;
	}
	if (fromLeftTree && fromRightTree) {
		return root;
	}
	return fromLeftTree != NULL ? fromLeftTree : fromRightTree;
}

void printAncestor(struct TreeNode *root, int value, int output[], int level) {
	if (!root) {
		return;
	}
	int i;
	if (root -> value == value) {
		for(i = 0; i < level; i++) {
			printf("%d\t", output[i]);
		}
		printf("\n");
		return;
	}
	output[level] = root -> value;
	printAncestor(root -> leftChild, value, output, level + 1);
	printAncestor(root -> rightChild, value, output, level + 1);
}

int getLevelOfNode(struct TreeNode *root, int value, int level) {
	if (!root) {
		return -1;
	}
	if (root -> value == value) {
		return level;
	}
	int left = getLevelOfNode(root -> leftChild, value, level + 1);
	int right = getLevelOfNode(root -> rightChild, value, level + 1);
	return left != -1 ? left : right;
}

void printNodesAtDistanceKFromRoot(struct TreeNode *root, int k) {
	if (!root) {
		return;
	}
	if (k == 0) {
		printf("%d\t", root -> value);
		return;
	}
	printNodesAtDistanceKFromRoot(root -> leftChild, k - 1);
	printNodesAtDistanceKFromRoot(root -> rightChild, k - 1);
}

int isFoldable(struct TreeNode *root1, struct TreeNode *root2) {
	if (!root1 && !root2) {
		return 1;
	}
	if (!root1 || !root2) {
		return 0;
	}
	return isFoldable(root1 -> leftChild, root2 -> rightChild) &&
			isFoldable(root1 -> rightChild, root2 -> leftChild);
}

int computeMaximumWidth(struct TreeNode *root, int level, int output[]) {
	if (!root) {
		return 0;
	}
	output[level]++;
	int leftHeight = computeMaximumWidth(root -> leftChild, level + 1, output);
	int rightHeight = computeMaximumWidth(root -> rightChild, level + 1, output);
	return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int getMaximumWidth(struct TreeNode *root) {
	int output[100] = {0};
	int height = computeMaximumWidth(root, 0, output);
	int maxWidth = output[0];
	int i = 0;
	for (i = 1; i < height; i++) {
		maxWidth = max(maxWidth, output[i]);
	}
	return maxWidth;
}

void doubleTree(struct TreeNode *root) {
	if (!root) {
		return;
	}
	doubleTree(root -> leftChild);
	doubleTree(root -> rightChild);
	struct TreeNode *temp = createTreeNode(root -> value);
	temp -> leftChild = root -> leftChild;
	root -> leftChild = temp;
}

struct TreeNode *constructTreeInorderPreorder(int in[], int pre[], int size) {
	if (size == 0) {
		return NULL;
	}
	struct TreeNode *root = createTreeNode(pre[0]);
	int i = 0;
	while (pre[0] != in[i]) {
		i++;
	}
	root -> leftChild = constructTreeInorderPreorder(in, pre + 1, i);
	root -> rightChild = constructTreeInorderPreorder(in + i + 1, pre + i + 1, size -i - 1);
	return root;
}

struct TreeNode *constructTreeInorderPostorder(int in[], int post[], int size) {
	if (size == 0) {
		return NULL;
	}
	struct TreeNode *root = createTreeNode(post[size - 1]);
	int i = 0;
	while (post[size - 1]  != in[i]) {
		i++;
	}
	root -> leftChild = constructTreeInorderPostorder(in, post, i);
	root -> rightChild = constructTreeInorderPostorder(in + i + 1, post + i, size - i - 1);
	return root;
}

struct TreeNode *constructTreeInorderLevelorder(int in[], int level[], int size) {
	if (size == 0) {
		return NULL;
	}
	struct TreeNode *root = createTreeNode(level[0]);
	int i = 0;
	while (level[0] != in[i]) {
		i++;
	}
	int leftTreeNodes[i];
	int rightTreeNodes[size - i - 1];
	int p = 0;
	int q= 0;
	int j = 1;
	int l = i + 1;
	int found = 0;
	for (j = 1; j < size; j++) { // traversing level[]
		found = 0;
		for (l = i + 1; l < size && p != size - i - 1; l++) { // traversing right nodes in[]
			if (level[j] == in[l]) {
				found = 1;
				rightTreeNodes[p++] = level[j];
				break;
			}
		}
		if (!found) {
			leftTreeNodes[q++] = level[j];
		}
	}
	root -> leftChild = constructTreeInorderLevelorder(in, leftTreeNodes, i);
	root -> rightChild = constructTreeInorderLevelorder(in + 1 + i, rightTreeNodes, size - i - 1);
	return root;
}

int countLeafNodes(struct TreeNode *root) {
	if (!root) {
		return 0;
	}
	if (isLeaf(root)) {
		printf("\t >> %d", root -> value);
		return 1;
	}
	return countLeafNodes(root -> leftChild) + countLeafNodes(root -> rightChild);
}

void printLevelOrderSpiralForm(struct TreeNode *root) {
	if (!root) {
		return;
	}
}
