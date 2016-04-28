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

#include"myMath.h"
#include"queues.h"
#include"stack.h"
#include"doublyLinkedList.h"
#include"TreeLinkedList.h"
#include"linkedList.h"

//http://www.geeksforgeeks.org/iterative-preorder-traversal/
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

//http://www.geeksforgeeks.org/how-to-determine-if-a-binary-tree-is-balanced/
void printInOrderNonRecursively(struct TreeNode *root) {
	if (!root) {
		return;
	}
	struct TreeNodeStack stack;
	setStack(&stack);

	struct TreeNode *ptr = root;
	while (1) {
		while (ptr -> leftChild) {
			push(&stack, ptr);
			ptr = ptr -> leftChild;
		}
		while (ptr -> rightChild == NULL) {
			printf("%d\t", ptr -> value);
			if (isStackEmpty(&stack)) {
				return;
			}
			ptr = pop(&stack);
		}
		printf("%d\t", ptr -> value);
		ptr = ptr -> rightChild;
	}
}

//http://www.geeksforgeeks.org/iterative-postorder-traversal-using-stack/
void printPostOrderNonRecursively(struct TreeNode *root) {
	if (!root) {
		return;
	}
	struct TreeNode *q = NULL;
	struct TreeNodeStack stack;
	setStack(&stack);

	struct TreeNode *ptr = root;
	while (1) {
		while (ptr -> leftChild) {
			push(&stack, ptr);
			ptr = ptr -> leftChild;
		}
		while (ptr -> rightChild == NULL || ptr -> rightChild == q) {
			q = ptr;
			printf("%d\t", ptr -> value);
			if (isStackEmpty(&stack)) {
				return;
			}
			ptr = pop(&stack);
		}
		push(&stack, ptr);
		ptr = ptr -> rightChild;
	}
}

void printPreOrderNonRecursively(struct TreeNode *root) {
	if (!root) {
		return;
	}
	struct TreeNode *ptr = NULL;
	struct TreeNodeStack stack;
	setStack(&stack);
	push(&stack, root);
	while(!isStackEmpty(&stack)) {
		ptr = pop(&stack);
		printf("%d\t", ptr -> value);
		if (ptr -> rightChild) {
			push(&stack, ptr -> rightChild);
		}
		if (ptr -> leftChild) {
			push(&stack, ptr -> leftChild);
		}
	}
}

//http://www.geeksforgeeks.org/level-order-tree-traversal/
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
	if(!root) {
		printf("Empty tree");
	}
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

struct TreeLinkedList *createTreeLinkedList(int info) {
	struct TreeLinkedList *node = (struct TreeLinkedList *) malloc (sizeof (struct TreeLinkedList));
	node -> info = info;
	node -> leftChild = NULL;
	node -> rightChild = NULL;
	node -> next = NULL;
	return node;
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

//http://www.geeksforgeeks.org/write-c-code-to-determine-if-two-trees-are-identical/
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

//http://www.geeksforgeeks.org/write-a-c-program-to-find-the-maximum-depth-or-height-of-a-tree/
int getHeightOfTree(struct TreeNode *root) {
	if (!root) {
		return 0;
	}
	int leftHeight = getHeightOfTree(root -> leftChild);
	int rightHeight = getHeightOfTree(root -> leftChild);
	return 1 + max(leftHeight, rightHeight);
}

//http://www.geeksforgeeks.org/iterative-method-to-find-height-of-binary-tree/
int getHeightNonRecursive(struct TreeNode *root) {
	if (!root) {
		return 0;
	}

	int height = 0;
	struct TreeNode *ptr = root;
	struct TreeNodeStack stack;
	setStack(&stack);

	while(1) {
		while(ptr -> leftChild) {
			push(&stack, ptr);
			ptr = ptr -> leftChild;
		}
		height = max(height, stack.top + 2);
		while (ptr -> rightChild == NULL) {
			if (isStackEmpty(&stack)) {
				return height;
			}
			ptr = pop(&stack);
		}
		ptr = ptr -> rightChild;
	}
	return height;
}

//http://www.geeksforgeeks.org/write-a-c-program-to-delete-a-tree/
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

//http://www.geeksforgeeks.org/write-an-efficient-c-function-to-convert-a-tree-into-its-mirror-tree/
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

//http://www.geeksforgeeks.org/given-a-binary-tree-print-all-root-to-leaf-paths/
//http://www.geeksforgeeks.org/given-a-binary-tree-print-out-all-of-its-root-to-leaf-paths-one-per-line/
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

//http://www.geeksforgeeks.org/root-to-leaf-path-sum-equal-to-a-given-number/
void printAllRootToLeafPathWithGivenSum(struct TreeNode *root, int sum, int output[], int level) {
	if (!root) {
		return;
	}
	int i;
	sum -= root -> value;
	output[level] = root -> value;
	if (isLeaf(root) && sum == 0) {
		printf("\n");
		for (i = 0; i <= level; i++) {
			printf("%d\t", output[i]);
		}
	}
	printAllRootToLeafPathWithGivenSum(root -> leftChild, sum, output, level + 1);
	printAllRootToLeafPathWithGivenSum(root -> rightChild, sum, output, level + 1);
}

//http://www.geeksforgeeks.org/root-to-leaf-path-sum-equal-to-a-given-number/
void printAllRootToLeafPathWithGivenSumWrapper(struct TreeNode *root, int sum) {
	int height = getHeightOfTree(root);
	int *output = (int *) malloc (sizeof(int) * height);
	printAllRootToLeafPathWithGivenSum(root, sum, output, 0);
}

// this approach is good for only binary search trees.
int printAllRootToLeafPathWithSum(struct TreeNode *root, int sum) {
	if (!root) {
		return 0;
	}
	if ((isLeaf(root) && sum - root -> value == 0) ||
			printAllRootToLeafPathWithSum(root -> leftChild, sum - root -> value) ||
			printAllRootToLeafPathWithSum(root -> rightChild, sum - root -> value)) {
		printf("%d\t", root -> value);
		return 1;
	}
	return 0;
}

//http://www.geeksforgeeks.org/lowest-common-ancestor-binary-tree-set-1/
struct TreeNode *lowestCommonAncestor(struct TreeNode *root, int num1, int num2) {
	if (!root) {
		return NULL;
	}
	struct TreeNode *fromLeftTree = lowestCommonAncestor(root -> leftChild, num1, num2);
	struct TreeNode *fromRightTree = lowestCommonAncestor(root -> rightChild, num1, num2);
	if (root -> value == num1 ||
		root -> value == num2 ||
		(fromLeftTree && fromRightTree)) {
		return root;
	}
	return fromLeftTree != NULL ? fromLeftTree : fromRightTree;
}

//http://www.geeksforgeeks.org/lowest-common-ancestor-in-a-binary-search-tree/
struct TreeNode *lowestCommonAncestorInBST(struct TreeNode *root, int n1, int n2) {
	if (!root) {
		return NULL;
	}

	if (root -> value > n1 && root -> value > n2) {
		return lowestCommonAncestorInBST(root -> leftChild, n1, n2);
	}

	if (root -> value < n1 && root -> value < n2) {
		return lowestCommonAncestor(root -> rightChild, n1, n2);
	}

	return root;
}

//http://www.geeksforgeeks.org/print-ancestors-of-a-given-node-in-binary-tree/
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

//http://www.geeksforgeeks.org/get-level-of-a-node-in-a-binary-tree/
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

//http://www.geeksforgeeks.org/print-nodes-at-k-distance-from-root/
void printNodesAtDistanceKFromRoot(struct TreeNode *root, int k) {
	if (!root || k < 0) {
		return;
	}
	if (k == 0) {
		printf("%d\t", root -> value);
		return;
	}
	printNodesAtDistanceKFromRoot(root -> leftChild, k - 1);
	printNodesAtDistanceKFromRoot(root -> rightChild, k - 1);
}

//http://www.geeksforgeeks.org/print-nodes-distance-k-given-node-binary-tree/
int printNodesAtDistanceKFromAnyNode(struct TreeNode *root,
		int ptr, int k, int *p) {
	if (!root) {
		return 0;
	}
	if (root -> value == ptr) {
		printf("\nPrinting values rooted at given root.\n");
		printNodesAtDistanceKFromRoot(root, k);
		*p = 1;
		return 1;
	}

	if (printNodesAtDistanceKFromAnyNode(root ->leftChild, ptr, k, p)) {
		if (k - *p == 0) {
			printf("\t %d", root -> value);
		} else {
			printNodesAtDistanceKFromRoot(root -> rightChild, k - *p - 1);
		}
		(*p)++;
		return 1;
	}

	else if (printNodesAtDistanceKFromAnyNode(root -> rightChild, ptr, k, p)) {
		if (k - *p == 0) {
			printf("\t %d", root -> value);
		} else {
			printNodesAtDistanceKFromRoot(root -> leftChild, k - *p - 1);
		}
		(*p)++;
		return 1;
	}

	return 0;
}

//http://www.geeksforgeeks.org/foldable-binary-trees/
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

//http://www.geeksforgeeks.org/maximum-width-of-a-binary-tree/
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

//http://www.geeksforgeeks.org/double-tree/
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

//http://www.geeksforgeeks.org/construct-tree-from-given-inorder-and-preorder-traversal/
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

//http://www.geeksforgeeks.org/connect-leaves-doubly-linked-list/
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

//http://www.geeksforgeeks.org/construct-tree-inorder-level-order-traversals/
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

//http://www.geeksforgeeks.org/construct-a-binary-search-tree-from-given-postorder/
struct TreeNode *constructBSTFromPostorder(int po[], int size) {
	if (size == 0) {
		return NULL;
	}
	struct TreeNode *root = createTreeNode(po[size - 1]);
	if (size == 1) {
		return root;
	}
	int i = 0;
	for (i = 0; po[size - 1] > po[i]; i++);
	root -> leftChild = constructBSTFromPostorder(po, i);
	root -> rightChild = constructBSTFromPostorder(po + i, size - i - 1);
	return root;
}

struct TreeNode *constructBSTFromPreorder(int pre[], int size) {
	if (size == 0) {
		return NULL;
	}
	struct TreeNode *root = createTreeNode(pre[0]);
	if (size == 1) {
		return root;
	}
	int i = 0;
	for (i = 1; pre[i] < pre[0]; i++);
	root -> leftChild = constructBSTFromPreorder(pre + 1, i - 1);
	root -> rightChild = constructBSTFromPreorder(pre + i, size - i);
	return root;
}

//http://www.geeksforgeeks.org/write-a-c-program-to-get-count-of-leaf-nodes-in-a-binary-tree/
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

//http://www.geeksforgeeks.org/level-order-traversal-in-spiral-form/
void printLevelOrderSpiralForm(struct TreeNode *root) {
	if (!root) {
		return;
	}
	printf("\nSpiral level order traversal.\n");
	struct TreeNodeStack stack1;
	struct TreeNodeStack stack2;
	setStack(&stack1);
	setStack(&stack2);

	push(&stack1, root);

	while(!(isStackEmpty(&stack1) && (isStackEmpty(&stack2)))) {
		struct TreeNode *ptr = NULL;
		while(!isStackEmpty(&stack1)) {
			ptr = pop(&stack1);
			printf("%d\t", ptr -> value);
			if (ptr -> rightChild) {
				push(&stack2, ptr -> rightChild);
			}
			if (ptr -> leftChild) {
				push(&stack2, ptr -> leftChild);
			}
		}
		while(!isStackEmpty(&stack2)) {
			ptr = pop(&stack2);
			printf("%d\t", ptr -> value);
			if (ptr -> leftChild) {
				push(&stack1, ptr -> leftChild);
			}
			if (ptr -> rightChild) {
				push(&stack1, ptr -> rightChild);
			}
		}
	}
}

//http://www.geeksforgeeks.org/check-for-children-sum-property-in-a-binary-tree/
int isChildrenSumPropertyIntact(struct TreeNode *root) {
	if (!root || isLeaf(root)) {
		return 1;
	}
	int left = root -> leftChild ? root -> leftChild -> value : 0;
	int right = root -> rightChild ? root -> rightChild -> value : 0;
	if (root -> value != left + right) {
		return 0;
	}
	return isChildrenSumPropertyIntact(root -> leftChild) &&
			isChildrenSumPropertyIntact(root -> rightChild);
}


void updateChildren(struct TreeNode *root, int diff) {
	if (root -> leftChild) {
		root -> leftChild -> value += diff;
		updateChildren(root -> leftChild, diff);
	} else if (root -> rightChild) {
		root -> rightChild -> value += diff;
		updateChildren(root -> rightChild, diff);
	}
}

/**
 * construct a children sum property tree from a binary tree.
 */
//http://www.geeksforgeeks.org/convert-an-arbitrary-binary-tree-to-a-tree-that-holds-children-sum-property/
int constructCSP(struct TreeNode *root) {
	if(!root) {
		return 0;
	}
	if (isLeaf(root)) {
		return root -> value;
	}
	int leftValue = constructCSP(root -> leftChild);
	int rightValue = constructCSP(root -> rightChild);
	if (root -> value <= leftValue + rightValue) {
		root -> value = leftValue + rightValue;
	} else {
		updateChildren(root, root -> value - (leftValue + rightValue));
	}
	return root -> value;
}

//http://www.geeksforgeeks.org/convert-a-given-tree-to-sum-tree/
int constructSumTree(struct TreeNode *root) {
	if(!root) {
		return 0;
	}
	int leftSum = constructSumTree(root -> leftChild);
	int rightSum = constructSumTree(root -> rightChild);
	int preValue = root -> value;
	root -> value = leftSum + rightSum;
	return preValue + root -> value;
}

//http://www.geeksforgeeks.org/check-if-a-given-binary-tree-is-sumtree/
int isSumTree(struct TreeNode *root, int *status) {
	if (!root) {
		return 0;
	}

	if (isLeaf(root)) {
		return root -> value;
	}

	int left = isSumTree(root -> leftChild, status);
	int right = isSumTree(root -> rightChild, status);
	if (root -> value != left + right) {
		*status = 0;
		return -1;
	}

	return root -> value + left + right;
}

int printRootLeafSumEqualToGivenNumber(struct TreeNode *root, int sum) {
	if (sum < 0) {
		return 0;
	}
	sum -= root -> value;
	if (sum == 0 || printRootLeafSumEqualToGivenNumber(root->leftChild, sum)
			|| printRootLeafSumEqualToGivenNumber(root->rightChild, sum)) {
		printf("%d\t", root -> value);
		return 1;
	}
	return 0;
}

//http://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion-and-without-stack/
void morrisInorderTraversal(struct TreeNode *root) {
	if (!root) {
		return;
	}
	struct TreeNode *ptr = root;
	while(ptr) {
		if (!ptr -> leftChild) {
			printf("%d\t", ptr -> value);
			ptr = ptr -> rightChild;
		}
		else {
			struct TreeNode *inorderPredecessor = ptr -> leftChild;
			while(inorderPredecessor -> rightChild) {
				inorderPredecessor = inorderPredecessor -> rightChild;
			}
			inorderPredecessor -> rightChild = ptr;
			struct TreeNode *temp = ptr -> leftChild;
			ptr -> leftChild = NULL;
			ptr = temp;
		}
	}
}

//http://www.geeksforgeeks.org/morris-traversal-for-preorder/
void morrisPreorderTraversal(struct TreeNode *root) {
	if (!root) {
		return;
	}
	while(root) {
		printf("%d\t", root -> value);
		if (!root -> leftChild) {
			root = root -> rightChild;
		} else {
			struct TreeNode *inPred = root -> leftChild;
			while(inPred -> rightChild) {
				inPred = inPred -> rightChild;
			}
			inPred -> rightChild = root -> rightChild;
			root = root -> leftChild;
		}
	}
}

struct TreeNode *deleteTreeNode(struct TreeNode *root, int value) {
	if (!root) {
		return NULL;
	}
	if (root -> value == value) {
		if (root -> rightChild) {
			struct TreeNode *insucc = root -> rightChild;
			while(insucc -> leftChild) {
				insucc = insucc -> leftChild;
			}
			root -> value = insucc -> value;
			root -> rightChild = deleteTreeNode(root -> rightChild, insucc -> value);
		} else if (root -> leftChild) {
			struct TreeNode *temp = root -> leftChild;
			root -> leftChild = temp -> leftChild;
			root = NULL;
		} else {
			root = NULL;
		}
		return root;
	}
	root -> leftChild = deleteTreeNode(root -> leftChild, value);
	root -> rightChild = deleteTreeNode(root -> rightChild, value);
	return root;
//		Uncomment below code for deletion in binary search tree
//	} else if (root -> value < value) {
//		return deleteTree(root -> rightChild, value);
//	}
//	return deleteTree(root -> leftChild, value);
}

struct TreeNode *insertNodeBST(struct TreeNode *root, int value) {
	if (!root) {
		return createTreeNode(value);
	}
	if (root -> value == value) {
		printf("\n%d already exist.", value);
	}
	if (root -> value > value) {
		root -> leftChild = insertNodeBST(root -> leftChild, value);
	}
	if (root -> value < value) {
		root -> rightChild = insertNodeBST(root -> rightChild, value);
	}
	return root;
}

struct TreeNode *createBST(int array[], int size) {
	if (size == 0) {
		return NULL;
	}
	int i = 0;
	struct TreeNode *root = createTreeNode(array[0]);
	struct TreeNode *temp = root;
	for (i = 1; i < size; i++) {
		temp = insertNodeBST(temp, array[i]);
	}
	return root;
}

//http://www.geeksforgeeks.org/in-place-convert-a-given-binary-tree-to-doubly-linked-list/
struct TreeNode *constructBinaryTreeToDoublyLinkedList(struct TreeNode *root) {
	if (!root) {
		return root;
	}

	if (root -> leftChild) {
		struct TreeNode *inPred = constructBinaryTreeToDoublyLinkedList(root -> leftChild);
		while (inPred -> rightChild) {
			inPred = inPred -> rightChild;
		}
		inPred -> rightChild = root;
		root -> leftChild = inPred;
	}

	if (root -> rightChild) {
		struct TreeNode *inSucc = constructBinaryTreeToDoublyLinkedList(root -> rightChild);
		while (inSucc -> leftChild) {
			inSucc = inSucc -> leftChild;
		}
		inSucc -> leftChild = root;
		root -> rightChild = inSucc;
	}
	return root;
}

void setLeftPointers(struct TreeNode *root) {
	static struct TreeNode *ptr = NULL;
	if (!root) {
		return;
	}
	setLeftPointers(root -> rightChild);
	root -> rightChild = ptr;
	ptr = root;
	setLeftPointers(root -> leftChild);
}

void setRightPointers(struct TreeNode *root) {
	if (!root) {
		return;
	}
	while(root -> rightChild) {
		root -> rightChild -> leftChild = root;
		root = root -> rightChild;
	}
}

//http://www.geeksforgeeks.org/convert-a-given-binary-tree-to-doubly-linked-list-set-2/
void constructBinaryTreeToDoublyLinkedList2(struct TreeNode *root) {
	setLeftPointers(root);
	while (root -> leftChild) {
		root = root -> leftChild;
	}
	struct TreeNode *ptr = root;
	setRightPointers(ptr);
	printDoublyLinkedList(ptr);
}

//http://www.geeksforgeeks.org/convert-given-binary-tree-doubly-linked-list-set-3/
void constructBinaryTreeToDoublyLinkedList3(struct TreeNode *root, struct TreeNode **start) {
	static struct TreeNode *prev = NULL;
	if (!root) {
		return;
	}
	constructBinaryTreeToDoublyLinkedList3(root -> leftChild, start);
	if (prev == NULL) {
		*start = root;
	} else {
		root -> leftChild = prev;
		prev -> rightChild = root;
	}
	prev = root;
	constructBinaryTreeToDoublyLinkedList3(root -> rightChild, start);
}

int isBinaryTreeBST(struct TreeNode *root, struct TreeNode **prevRoot) {
	if (!root) {
		return 1;
	}
	if (!isBinaryTreeBST(root -> leftChild, prevRoot)) {
		return 0;
	}
	if (*prevRoot && (*prevRoot) -> value >= root -> value) {
		return 0;
	}
	*prevRoot = root;
	return isBinaryTreeBST(root -> rightChild, prevRoot);
}

/**
 * incorrect
 * min and max is not correctly set. Min and max should be picked up from a tree
 * but here min and max from other parent tree is taken which is wrong.
 * Ex. it may be possible that min and max set in sibling's root is taken into consideration for current child.
 */
int largestBinarySearchTree(struct TreeNode *root, int *maxValue,
		int *minValue, struct TreeNode **maxBstRoot, int *maxSize) {
	if (!root) {
		return 0;
	}
	int isBst = 1;

	int leftLargestBST = largestBinarySearchTree(root -> leftChild, maxValue, minValue, maxBstRoot, maxSize);
	if (leftLargestBST == -1 || (leftLargestBST != 0 && root -> value <= *maxValue)) {
		isBst = 0;
	}
	int rightLargestBST = largestBinarySearchTree(root -> rightChild, maxValue, minValue, maxBstRoot,maxSize);
	if (rightLargestBST == -1 || (rightLargestBST != 0 && root -> value >= *minValue)) {
		isBst = 0;
	}

	int currMin = (leftLargestBST == 0) ? root -> value : *minValue;
	int currMax = (rightLargestBST == 0) ? root -> value : *maxValue;
	if (isBst) {
		*minValue = currMin;
		*maxValue = currMax;
		if (*maxSize < 1 + leftLargestBST + rightLargestBST) {
			*maxBstRoot = root;
			*maxSize = 1 + leftLargestBST + rightLargestBST;
		}
		return 1 + leftLargestBST + rightLargestBST;
	}
	return -1;
}

int largestBinarySearchTree2(struct TreeNode *root, int *maxValue,
		int *minValue, struct TreeNode **maxBstRoot, int *maxSize) {
	if (!root) {
		return 0;
	}

	int leftMax = INT_MIN;
	int leftLargestBST = largestBinarySearchTree2(root -> leftChild, &leftMax, minValue, maxBstRoot, maxSize);

	int rightMin = INT_MAX;
	int rightLargestBST = largestBinarySearchTree2(root -> rightChild, maxValue, &rightMin, maxBstRoot,maxSize);

	if (leftLargestBST == 0) {
		*maxValue = root -> value;
	} else {
		*maxValue = max(root -> value, *maxValue);
	}

	if (rightLargestBST == 0) {
		*minValue = root -> value;
	} else {
		*minValue = min(root -> value, *minValue);
	}

	if (root -> value > leftMax && root -> value < rightMin) {
		if (*maxSize < 1 + leftLargestBST + rightLargestBST) {
			*maxBstRoot = root;
			*maxSize = 1 + leftLargestBST + rightLargestBST;
		}
		return 1 + leftLargestBST + rightLargestBST;
	}
	return -1;
}

int getMinimumDistanceLeaf(struct TreeNode *root) {
  if (!root) {
	  return 0;
  }
  if (!(root->leftChild) && !(root->rightChild)) {
    return 0;
  }
  return 1 + min(getMinimumDistanceLeaf(root -> leftChild),
		  getMinimumDistanceLeaf(root -> rightChild));
}

//http://www.geeksforgeeks.org/closest-leaf-to-a-given-node-in-binary-tree/
int getMinimumDistanceLeafFromAnyNode(struct TreeNode *root, int info, int *p) {
  if (!root) {
    return 0;
  }
  if (root -> value == info) {
    *p = 1;
    printf("\nMin distance in tree rooted at given node.%d >> %d",
    		root -> value, getMinimumDistanceLeaf(root));
    return getMinimumDistanceLeaf(root);
  }
  int left = getMinimumDistanceLeafFromAnyNode(root -> leftChild, info, p);
  int right = 0;
  if (left == 0) {
    right = getMinimumDistanceLeafFromAnyNode(root -> rightChild, info, p);
  }
  if (left != 0) {
    int minDistanceLeafInRightSubtree = getMinimumDistanceLeaf(root -> rightChild) + *p + 1;
    (*p)++;
    return min(minDistanceLeafInRightSubtree, left);
  }
  if (right != 0) {
    int minDistanceLeafInLeftSubtree = getMinimumDistanceLeaf(root -> leftChild) + *p + 1;
    (*p)++;
    return min(minDistanceLeafInLeftSubtree, right);
  }
  return 0;
}

//http://www.geeksforgeeks.org/maximum-difference-between-node-and-its-ancestor-in-binary-tree/
int getMinimum(struct TreeNode *root, int *maxDiff) {
	if (!root) {
		return INT_MAX;
	}
	int minValue = min(getMinimum(root -> leftChild, maxDiff),
					   getMinimum(root -> rightChild, maxDiff));
	*maxDiff = max(*maxDiff, root -> value - minValue);
	return min(root -> value, minValue);
}

//http://www.geeksforgeeks.org/maximum-difference-between-node-and-its-ancestor-in-binary-tree/
int getMaximumDifference(struct TreeNode *root) {
	int maxDiff = INT_MIN;
	getMinimum(root, &maxDiff);
	return maxDiff;
}

//http://www.geeksforgeeks.org/check-if-leaf-traversal-of-two-binary-trees-is-same/
int isLeafTraversalSameInBothTrees(struct TreeNode *root1, struct TreeNode *root2) {
	if (!root1 && !root2) {
		return 1;
	}
	if (!root1 || !root2) {
		return 0;
	}
	struct TreeNode *ptr1 = root1;
	struct TreeNode *ptr2 = root2;
	struct TreeNodeStack stack1;
	struct TreeNodeStack stack2;
	setStack(&stack1);
	setStack(&stack2);
	push(&stack1, root1);
	push(&stack2, root2);
	while(!(isStackEmpty(&stack1) && isStackEmpty(&stack2))) {

		if (isStackEmpty(&stack1) || isStackEmpty(&stack2)) {
			return 0;
		}

		while(!isStackEmpty(&stack1)) {
			ptr1 = pop(&stack1);
			if (isLeaf(ptr1)) {
				break;
			}
			if (ptr1 -> rightChild) {
				push(&stack1, ptr1 -> rightChild);
			}
			if (ptr1 -> leftChild) {
				push(&stack1, ptr1 -> leftChild);
			}
		}

		while(!isStackEmpty(&stack2)) {
			ptr2 = pop(&stack2);
			if (isLeaf(ptr2)) {
				break;
			}
			if (ptr2 -> rightChild) {
				push(&stack2, ptr2 -> rightChild);
			}
			if (ptr2 -> leftChild) {
				push(&stack2, ptr2 -> leftChild);
			}
		}

		if (ptr1 -> value != ptr2 -> value) {
			printf("\n%d -> %d", ptr1 -> value, ptr2 -> value);
			return 0;
		}
	}
	return 1;
}

void isLeafTraversalSame(struct TreeNode *root1, struct TreeNode *root2) {
	int status = isLeafTraversalSameInBothTrees(root1, root2);
	if (status) {
		printf("\nYes, traversal is same.");
	} else {
		printf("\nNo, traversal is not same.");
	}
}

int getLeftBoundarySum(struct TreeNode *root) {
	if (!root) {
		return 0;
	}
	if (root -> leftChild) {
		return root -> value + getLeftBoundarySum(root -> leftChild);
	}
	return root -> value + getLeftBoundarySum(root -> rightChild);
}

int getRightBoundarySum(struct TreeNode *root) {
	if (!root) {
		return 0;
	}
	if (root -> rightChild) {
		return root -> value + getRightBoundarySum(root -> rightChild);
	}
	return root -> value + getRightBoundarySum(root -> leftChild);
}

//http://www.geeksforgeeks.org/check-if-removing-an-edge-can-divide-a-binary-tree-in-two-halves/
int checkBinaryTreeDivisionInTwoHalves(struct TreeNode *root, int n, int *res) {
	if (!root) {
		return 0;
	}

	int subTreeSize = 1
						+	checkBinaryTreeDivisionInTwoHalves(root -> leftChild, n, res)
						+	checkBinaryTreeDivisionInTwoHalves(root -> rightChild, n, res);
	if (n - subTreeSize == subTreeSize) {
		*res = 1;
	}
	return subTreeSize;
}

int getTreeSum(struct TreeNode *root) {
	if (!root) {
		return 0;
	}
	return root -> value + getTreeSum(root -> leftChild) + getTreeSum(root -> rightChild);
}

//http://www.geeksforgeeks.org/find-distance-two-given-nodes/
int getDistanceBetweenTwoNodes(struct TreeNode *root, int n1, int n2,
		int level, int *ln1, int *ln2, struct TreeNode **ptr) {
	if (!root) {
		return -1;
	}

	int left = -1;
	left = getDistanceBetweenTwoNodes(root -> leftChild, n1, n2,
		level + 1, ln1, ln2, ptr);

	int right = -1;
	right = getDistanceBetweenTwoNodes(root -> rightChild, n1, n2,
		level + 1, ln1, ln2, ptr);

	if (root -> value == n1) {
		*ln1 = level;
		return level;
	}

	if (root -> value == n2) {
		*ln2 = level;
		return level;
	}

	if (left != -1 && right != -1) {
		*ptr = root;
		return level;
	}
	return (left == -1) ? right : left;
}

//http://www.geeksforgeeks.org/symmetric-tree-tree-which-is-mirror-image-of-itself/
int isMirror(struct TreeNode *root1, struct TreeNode *root2) {
	if (!root1 && !root2) {
		return 1;
	}
	if (!root1 || !root2) {
		return 0;
	}
	if (root1 -> value != root2 -> value) {
		return 0;
	}
	return isMirror(root1 -> leftChild, root2 -> rightChild)
			&& isMirror(root1 -> rightChild, root2 -> leftChild);
}

//http://www.geeksforgeeks.org/find-maximum-path-sum-in-a-binary-tree/
int maximumSumInPath(struct TreeNode *root, int *maxSum) {
	if(!root) {
		return 0;
	}
	int leftSum = maximumSumInPath(root -> leftChild, maxSum);
	int rightSum = maximumSumInPath(root -> rightChild, maxSum);
	int localMax = max(max(leftSum, rightSum) + root -> value, root -> value);
	*maxSum = max(*maxSum, max(localMax, leftSum + root -> value + rightSum));
	return localMax;
}

//Find the maximum path sum between two leaves of a binary tree
//http://www.geeksforgeeks.org/find-maximum-path-sum-two-leaves-binary-tree/
int maximumSumPathBetweenTwoLeaves(struct TreeNode *root, int *maxSum) {
	if (!root) {
		return 0;
	}
	if (isLeaf(root)) {
		return root -> value;
	}
	int leftSum = maximumSumPathBetweenTwoLeaves(root -> leftChild, maxSum);
	int rightSum = maximumSumPathBetweenTwoLeaves(root -> rightChild, maxSum);
	int localMax = max(leftSum, rightSum) + root -> value;
	*maxSum = max (*maxSum, leftSum + rightSum + root -> value);
	return localMax;
}

//http://www.geeksforgeeks.org/find-the-maximum-sum-path-in-a-binary-tree/
void maximumSumRootToLeafPath(struct TreeNode *root, int *maximumSum, int sum) {
	if (!root) {
		return;
	}
	sum += root -> value;
	if (isLeaf(root)) {
		*maximumSum = max(*maximumSum, sum);
		return;
	}
	maximumSumRootToLeafPath(root -> leftChild, maximumSum, sum);
	maximumSumRootToLeafPath(root -> rightChild, maximumSum, sum);
}

//http://www.geeksforgeeks.org/print-leftmost-and-rightmost-nodes-of-a-binary-tree/
void printLeftMostNodes(struct TreeNode *root) {
	if (!root) {
		return;
	}
	printf(" %d", root -> value);

	if (root -> leftChild) {
		printLeftMostNodes(root -> leftChild);
	}

	else if (root -> rightChild) {
		printLeftMostNodes(root -> rightChild);
	}
}

//http://www.geeksforgeeks.org/print-leftmost-and-rightmost-nodes-of-a-binary-tree/
void printRightMostNodes(struct TreeNode *root) {
	if (!root) {
		return;
	}
	printf(" %d", root -> value);

	if (root -> rightChild) {
		printRightMostNodes(root -> rightChild);
	}

	else if (root -> leftChild) {
		printRightMostNodes(root -> leftChild);
	}

}

//http://www.geeksforgeeks.org/print-leftmost-and-rightmost-nodes-of-a-binary-tree/
void printBoundaryNodes(struct TreeNode *root) {
	printf("\nLeftMostNode ");
	printLeftMostNodes(root);
	printf("\nRightMostNode ");
	printRightMostNodes(root);
}

void verticalSum(struct TreeNode *root, struct TreeNode *linkedList) {
	if (!root) {
		return;
	}

	linkedList -> value += root -> value;

	if (root -> leftChild) {
		if (linkedList -> leftChild == NULL) {
			struct TreeNode *temp = createTreeNode(0);
			linkedList -> leftChild = temp;
			temp -> rightChild = linkedList;
		}
		verticalSum(root -> leftChild, linkedList -> leftChild);
	}

	if (root -> rightChild) {
		if (linkedList -> rightChild == NULL) {
			struct TreeNode *temp = createTreeNode(0);
			linkedList -> rightChild = temp;
			temp -> leftChild = linkedList;
		}
		verticalSum(root -> rightChild, linkedList -> rightChild);
	}
}

void getVerticalSum(struct TreeNode *root) {
	struct TreeNode *linkedList = createTreeNode(0);
	verticalSum(root, linkedList);
	while(linkedList->leftChild) {
		linkedList = linkedList -> leftChild;
	}
	printf("\nVertical sum for given tree is : ");
	while(linkedList) {
		printf("%d ", linkedList -> value);
		linkedList = linkedList -> rightChild;
	}
}
/**************************************************************************************
 * ************************************************************************************
 * LEFT TO BE DONE PENDING
 * ************************************************************************************
 * ************************************************************************************
 */
struct TreeLinkedList *printVertically(struct TreeNode *root, struct TreeLinkedList **tll) {
	if (!root) {
		return NULL;
	}
	if (!(*tll)) {
		*tll = createTreeLinkedList(root -> value);
	} else {
		insertLinkedList(&((*tll) -> next), root -> value);
	}
	if (root -> leftChild) {
		(*tll) -> leftChild = printVertically(root -> leftChild, &((*tll) -> leftChild));
		(*tll) -> leftChild -> rightChild= (*tll) -> leftChild;
	}
	if (root -> rightChild) {
		(*tll) -> rightChild = printVertically(root -> rightChild, &((*tll) -> rightChild));
		(*tll) -> rightChild -> leftChild = (*tll) -> rightChild;
	}
	return *tll;
}

void printAllNodesVertically(struct TreeNode *root) {
	struct TreeLinkedList *tll = NULL;
	printVertically(root, &tll);
	while(tll -> leftChild) {
		tll = tll -> leftChild;
	}
	while(tll) {
		printf("\n%d ", tll -> info);
		struct LinkedList *tmp = tll -> next;
		while (tmp) {
			printf("%d ", tmp -> info);
			tmp = tmp -> next;
		}
		tll = tll -> rightChild;
	}
}

//http://www.geeksforgeeks.org/find-multiplication-of-sums-of-data-of-all-leaves-at-sane-levels/

void getMultiplicationOfSum(struct TreeNode *root, long **sum, int level) {
	if (!root) {
		return;
	}
	if (isLeaf(root)) {
		(*sum)[level] += root -> value;
	}
	getMultiplicationOfSum(root-> leftChild, sum, level + 1);
	getMultiplicationOfSum(root-> rightChild, sum, level + 1);
}

void getMultiplicationOfSumWrapper(struct TreeNode *root) {
	int height = getHeightOfTree(root);
	printf("%d\n", height);
	int i = 0;
	long *sum = (long *)malloc(sizeof(long) * (height+1));
	for (i = 0; i <= height; i++) {
		sum[i] = 0;
		printf("%ld\t", sum[i]);
	}
	getMultiplicationOfSum(root, &sum, 0);
	long prod = 1;
	for (i = 0; i <= height; i++) {
		if (sum[i] == 0) {
			continue;
		}
		printf(">>%ld", sum[i]);
		prod *= sum[i];
	}
	printf("\nProduct is : %ld", prod);
}

void getMultiplicationLevelOrder(struct TreeNode *root) {
	if (!root) {
		return;
	}
	struct TreeNode *ptr = root;
	while (ptr) {

	}
}

//http://www.geeksforgeeks.org/how-to-determine-if-a-binary-tree-is-balanced/
int isHeightBalanced(struct TreeNode *root, int *res) {
	if (!root) {
		return 0;
	}
	int left = isHeightBalanced(root -> leftChild, res);
	int right = isHeightBalanced(root -> rightChild, res);
	if (abs(left - right) > 1) {
		*res = 0;
		return 0;
	}
	if (!res) {
		return -1;
	}
	return max(left, right) + 1;
}

//http://www.geeksforgeeks.org/diameter-of-a-binary-tree/
int getDiameter(struct TreeNode *root, int *diameter) {
	if (!root) {
		return 0;
	}
	int leftHeight = getDiameter(root -> leftChild, diameter);
	int rightHeight = getDiameter(root -> rightChild, diameter);
	*diameter = max(*diameter, leftHeight + rightHeight + 1);
	return max(leftHeight, rightHeight) + 1;
}

//http://www.geeksforgeeks.org/full-and-complete-binary-tree-from-given-preorder-and-postorder-traversals/
struct TreeNode *createTreeFromPrePost(int pre[], int post[], int size) {
	if (size <= 0) {
		return NULL;
	}

	struct TreeNode *root = createTreeNode(pre[0]);
	if (size == 1) {
		return root;
	}
	int i;
	for (i = 0; pre[1] != post[i]; i++) ;
	root -> leftChild = createTreeFromPrePost(pre + 1, post, i + 1);
	root -> rightChild = createTreeFromPrePost(pre + 2 + i, post + i + 1, size - i - 2);
	return root;
}

void printLeftBoundary(struct TreeNode *root) {
	if (!root) {
		return;
	}
	if (root -> leftChild) {
		printf("%d\t", root -> value);
		printLeftBoundary(root -> leftChild);
		return;
	}
	if (root -> rightChild) {
		printf("%d\t", root -> value);
		printLeftBoundary(root -> rightChild);
		return;
	}
}

void printRightBoundary(struct TreeNode *root) {
	if (!root) {
		return;
	}
	if (root -> rightChild) {
		printRightBoundary(root -> rightChild);
		printf("%d\t", root -> value);
		return;
	}
	if (root -> leftChild) {
		printRightBoundary(root -> leftChild);
		printf("%d\t", root -> value);
		return;
	}
}

void printLeafNodes(struct TreeNode *root) {
	if (!root) {
		return;
	}
	if (isLeaf(root)) {
		printf("%d\t", root -> value);
	}
	printLeafNodes(root -> leftChild);
	printLeafNodes(root -> rightChild);
}

//http://www.geeksforgeeks.org/boundary-traversal-of-binary-tree/
void boundaryTraversal(struct TreeNode *root) {
	printLeftBoundary(root);
	printLeafNodes(root);
	printRightBoundary(root -> rightChild);
}

//http://www.geeksforgeeks.org/check-if-a-given-binary-tree-is-complete-tree-or-not/
int isCompleteBinaryTree(struct TreeNode *root) {
	if (!root) {
		return 1;
	}
	int flag = 1;
	struct TreeNodeQueue queue;
	setQueue(&queue);
	enqueue(&queue, root);
	while (!isQueueEmpty(&queue)) {
		struct TreeNode *ptr = dequeue(&queue);
		if (ptr -> leftChild) {
			if (!flag) {
				return 0;
			}
			enqueue(&queue, ptr -> leftChild);
		} else {
			flag = 0;
		}

		if (ptr -> rightChild) {
			if (!flag) {
				return 0;
			}
			enqueue(&queue, ptr -> rightChild);
		} else {
			flag = 0;
		}
	}
	return 1;
}

//http://www.geeksforgeeks.org/construct-a-special-tree-from-given-preorder-traversal/
struct TreeNode *constructSpecialTree(int pre[], char preLN[], int size, int *index) {
	if (size <= *index) {
		return NULL;
	}

	struct TreeNode *root = createTreeNode(pre[(*index)++]);
	if (preLN[(*index) - 1] == 'N') {
		root -> leftChild = constructSpecialTree(pre, preLN, size, index);
		root -> rightChild = constructSpecialTree(pre, preLN, size, index);
	}

	return root;
}

//http://www.geeksforgeeks.org/construct-binary-tree-from-inorder-traversal/
struct TreeNode *constructTreeFromInorderTraversal(int in[], int size) {
	if (size <= 0) {
		return NULL;
	}
	int i;
	for (i = 0; in[i] < in[i + 1] && i + 1 < size; i++);
	struct TreeNode *root = createTreeNode(in[i]);
	root -> leftChild = constructTreeFromInorderTraversal(in, i);
	root -> rightChild = constructTreeFromInorderTraversal(in + 1 + i, size - i - 1);
	return root;
}

//http://www.geeksforgeeks.org/print-left-view-binary-tree/
void printLeftView(struct TreeNode *root, int level, int *maxLevel) {
	if (!root) {
		return;
	}

	if (*maxLevel < level) {
		*maxLevel = level;
		printf("%d\t", root -> value);
	}

	printLeftView(root -> leftChild, level + 1, maxLevel);
	printLeftView(root -> rightChild, level + 1, maxLevel);
}

//http://www.geeksforgeeks.org/print-right-view-binary-tree-2/
void printRightView(struct TreeNode *root, int level, int *maxLevel) {
	if (!root) {
		return;
	}
	if (*maxLevel < level) {
		*maxLevel = level;
		printf("%d\t", root -> value);
	}
	printRightView(root -> rightChild, level + 1, maxLevel);
	printRightView(root -> leftChild, level + 1, maxLevel);
}
//http://www.geeksforgeeks.org/tree-isomorphism-problem/
int isIsomorphic(struct TreeNode *root1, struct TreeNode *root2) {
	if (!root1 && !root2) {
		return 1;
	}

	if (!root1 || !root2){
		return 0;
	}

	if (root1 -> value != root2 -> value) {
		return 0;
	}

	return (isIsomorphic(root1 -> leftChild, root2 -> leftChild) &&
			isIsomorphic(root1 -> rightChild, root2 -> rightChild)) ||
			(isIsomorphic(root1 -> leftChild, root2 -> rightChild) &&
			isIsomorphic(root1 -> rightChild, root2 -> leftChild));

}

//http://www.geeksforgeeks.org/difference-between-sums-of-odd-and-even-levels/
int getDifferenceBetweenOddEvenLevelNodes(struct TreeNode *root) {
	if (!root) {
		return 0;
	}
	return root -> value - getDifferenceBetweenOddEvenLevelNodes(root -> leftChild)
			- getDifferenceBetweenOddEvenLevelNodes(root -> rightChild);
}

//http://www.geeksforgeeks.org/print-postorder-from-given-inorder-and-preorder-traversals/
void printPostOrderFromInorderPreOrder(int pre[], int in[], int size) {
	if (size <= 0) {
		return;
	}
	int i = 0;
	for (i = 0; pre[0] != in[i]; i++);
	printPostOrderFromInorderPreOrder(pre + 1, in, i);
	printPostOrderFromInorderPreOrder(pre + i + 1, in + i + 1, size - i - 1);
	printf("%d\t", pre[0]);
}

//http://www.geeksforgeeks.org/find-depth-of-the-deepest-odd-level-node/
void depthOfDeepestOddLevelLeafNode(struct TreeNode *root, int level, int *maxLevel, struct TreeNode **ptr) {
	if (!root) {
		return;
	}
	if (isLeaf(root) && (level & 1) && *maxLevel < level) {
		*ptr = root;
		*maxLevel = level;
		return;
	}
	depthOfDeepestOddLevelLeafNode(root -> leftChild, level + 1, maxLevel, ptr);
	depthOfDeepestOddLevelLeafNode(root -> rightChild, level + 1, maxLevel, ptr);
}

//http://www.geeksforgeeks.org/deepest-left-leaf-node-in-a-binary-tree/
void deepestLeafLeafNode(struct TreeNode *root, int level, int *maxLevel, int isLeft, struct TreeNode **ptr) {
	if (!root) {
		return;
	}
	if (isLeaf(root) && isLeft && *maxLevel < level) {
		*maxLevel = level;
		*ptr = root;
		return;
	}
	deepestLeafLeafNode(root -> leftChild, level + 1, maxLevel, 1, ptr);
	deepestLeafLeafNode(root -> rightChild, level + 1, maxLevel, 0, ptr);
}

//http://www.geeksforgeeks.org/check-leaves-level/
int isAllLeafAtSameLevel(struct TreeNode *root, int level, int *maxLevel) {
	if (!root) {
		return 1;
	}
	if (isLeaf(root)) {
		if (*maxLevel == -1) {
			*maxLevel = level;
		}
		return *maxLevel == level;
	}
	return isAllLeafAtSameLevel(root -> leftChild, level + 1, maxLevel)
			&& isAllLeafAtSameLevel(root -> rightChild, level + 1, maxLevel);
}

//http://www.geeksforgeeks.org/in-place-convert-a-given-binary-tree-to-doubly-linked-list/
struct TreeNode *convertToDoublyLinkedList(struct TreeNode *root) {
	if (!root) {
		return NULL;
	}

	if (root -> leftChild) {
		struct TreeNode *inpredecessor =
			convertToDoublyLinkedList(root -> leftChild);
		while (inpredecessor -> rightChild) {
			inpredecessor = inpredecessor -> rightChild;
		}
		inpredecessor -> rightChild = root;
		root -> leftChild = inpredecessor;
	}

	if (root -> rightChild) {
		struct TreeNode *insuccessor =
			convertToDoublyLinkedList(root -> rightChild);
		while (insuccessor -> leftChild) {
			insuccessor = insuccessor -> leftChild;
		}
		insuccessor -> leftChild = root;
		root -> rightChild = insuccessor;
	}
	return root;
}

//http://www.geeksforgeeks.org/remove-all-nodes-which-lie-on-a-path-having-sum-less-than-k/
struct TreeNode *removeNodesWhoseSumIsLesserThanK(struct TreeNode *root, int k, int *sum) {
	if (!root) {
		return NULL;
	}

	int leftSum = 0;
	int rightSum = 0;
	*sum += root -> value;
	leftSum = rightSum = *sum;
	root -> leftChild = removeNodesWhoseSumIsLesserThanK(root -> leftChild, k, &leftSum);
	root -> rightChild = removeNodesWhoseSumIsLesserThanK(root -> rightChild, k, &rightSum);
	*sum = max(leftSum, rightSum);
	if (*sum < k) {
		root = NULL;
	}
	return root;
}

//http://www.geeksforgeeks.org/remove-nodes-root-leaf-paths-length-k/
struct TreeNode *removeAllPathsLessThanK(struct TreeNode *root, int k, int *length) {
	if (!root) {
		return NULL;
	}
	(*length)++;
	int leftLength = *length;
	int rightLength = *length;
	printf("\n%d\t%d\t%d", root -> value, leftLength, rightLength);
	root -> leftChild = removeAllPathsLessThanK(root -> leftChild, k, &leftLength);
	root -> rightChild = removeAllPathsLessThanK(root -> rightChild, k, &rightLength);
	printf("\n%d\t%d\t%d", root -> value, leftLength, rightLength);

	if (((*length) = max(leftLength, rightLength)) < k) {
		root = NULL;
	}
	return root;
}

struct TreeNode *removeAllPathsLessThanK2(struct TreeNode *root, int level, int k) {
	if (!root) {
		return NULL;
	}
	root -> leftChild = removeAllPathsLessThanK2(root -> leftChild, level + 1, k);
	root -> rightChild = removeAllPathsLessThanK2(root -> rightChild, level + 1, k);
	if (isLeaf(root) && level < k) {
		root = NULL;
	}
	return root;
}

//http://www.geeksforgeeks.org/reverse-level-order-traversal/
void reverseLevelOrderTraversal(struct TreeNode *root) {
	int height = getHeightOfTree(root);
	int i = 0;
	for (i = height; i >= 0; i--) {
		printf("\n");
		printNodesAtDistanceKFromRoot(root, i);
	}
}

//http://www.geeksforgeeks.org/reverse-level-order-traversal/
void reverseLevelOrderTraversal2(struct TreeNode *root) {
	if (!root) {
		return;
	}
	struct TreeNode *ptr = root;
	struct TreeNodeQueue queue;
	setQueue(&queue);
	struct TreeNodeStack stack;
	setStack(&stack);

	enqueue(&queue, ptr);
	while (!isQueueEmpty(&queue)) {
		ptr =  dequeue(&queue);
		push(&stack, ptr);
		if (ptr -> rightChild) {
			enqueue(&queue, ptr -> rightChild);
		}
		if (ptr -> leftChild) {
			enqueue(&queue, ptr -> leftChild);
		}
	}

	printf("\nReverse level order traversal.\n");
	while (!isStackEmpty(&stack)) {
		ptr = pop(&stack);
		printf("%d\t", ptr -> value);
	}
}

//http://www.geeksforgeeks.org/connect-leaves-doubly-linked-list/
struct TreeNode *extractLeavesInDoublyLinkedList(struct TreeNode *root, struct TreeNode **start) {
	if (!root) {
		return NULL;
	}
	if (isLeaf(root)) {
		if (*start == NULL) {
			*start = createTreeNode(root -> value);
		} else {
			struct TreeNode *ptr = *start;
			while(ptr -> rightChild) {
				ptr = ptr -> rightChild;
			}
			ptr -> rightChild = createTreeNode(root -> value);
			ptr -> rightChild -> leftChild = ptr;
		}
		return NULL;
	}
	root -> leftChild = extractLeavesInDoublyLinkedList(root -> leftChild, start);
	root -> rightChild = extractLeavesInDoublyLinkedList(root -> rightChild, start);
	return root;
}

//http://www.geeksforgeeks.org/print-nodes-distance-k-leaf-node/
void printAllNodesAtDistanceKFromLeafNode(struct TreeNode *root, int level, int arr[], int k) {
	if (!root) {
		return;
	}
	arr[level] = root -> value;
	if (isLeaf(root) && level - k >= 0) {
		printf("\n%d is at distance of %d from leaf node %d",
				arr[level - k], k, root -> value);
	}
	printAllNodesAtDistanceKFromLeafNode(root -> leftChild, level + 1, arr, k);
	printAllNodesAtDistanceKFromLeafNode(root -> rightChild, level + 1, arr, k);
}

//http://www.geeksforgeeks.org/sum-numbers-formed-root-leaf-paths/
void sumOfAllNumberFormedFromRootToLeaf(struct TreeNode *root, int sum, int *totalSum) {
	if (!root) {
		return;
	}
	sum = sum * 10 + root -> value;
	if (isLeaf(root)) {
		printf("%d\t", sum);
		*totalSum += sum;
	}
	sumOfAllNumberFormedFromRootToLeaf(root -> leftChild, sum, totalSum);
	sumOfAllNumberFormedFromRootToLeaf(root -> rightChild, sum, totalSum);
}

//http://www.geeksforgeeks.org/given-binary-tree-print-nodes-two-given-level-numbers/
void printAllNodesBetweenTwoLevels(struct TreeNode *root, int low, int high, int level) {
	if (!root) {
		return;
	}
	if (level >= low && level <= high) {
		printf("%d\t", root -> value);
	}

	printAllNodesBetweenTwoLevels(root -> leftChild, low, high, level + 1);
	printAllNodesBetweenTwoLevels(root -> rightChild, low, high, level + 1);
}

//http://www.geeksforgeeks.org/find-height-binary-tree-represented-parent-array/
void findDepth(int parent[], int index, int depth[]) {
	if (depth[index] != 0) {
		return;
	}

	if (parent[index] == -1) {
		depth[index] = 1;
		return;
	}

	if (depth[parent[index]] == 0) {
		findDepth(parent, parent[index], depth);
	}

	depth[index] = depth[parent[index]] + 1;
}

int getDepthOfTree(int parent[], int size) {
	int *depth = (int *) malloc (sizeof(int) * size);
	int i = 0;
	for (i = 0; i < size; i++) {
		depth[i] = 0;
	}
	for (i = 0; i < size; i++) {
		findDepth(parent, i, depth);
	}
	int maxDepth = depth[0];
	for (i = 1; i < size; i++) {
		maxDepth = max(maxDepth, depth[i]);
	}
	for (i = 0; i < size; i++) {
		printf("%d\t", depth[i]);
	}
	printf("\n");
	return maxDepth;
}

//http://www.geeksforgeeks.org/check-two-nodes-cousins-binary-tree/
int getLevel(struct TreeNode *root, int n, int level) {
	if (!root) {
		return -1;
	}
	if (root -> value == n) {
		return level;
	}
	int left = getLevel(root -> leftChild, n, level + 1);
	if (left != -1) {
		return left;
	}
	return getLevel(root -> rightChild, n, level + 1);
}

int areSiblings(struct TreeNode *root, int n1, int n2) {
	if (!root) {
		return 0;
	}
	if (isLeaf(root)) {
		return 0;
	}
	if (!root -> leftChild || !root -> rightChild) {
		return 0;
	}
	if ((root -> leftChild -> value == n1 && root -> rightChild -> value == n2) ||
		areSiblings(root -> leftChild, n1, n2) ||
		areSiblings(root -> rightChild, n1, n2)) {
		return 1;
	}
	return 0;
}

//http://www.geeksforgeeks.org/check-two-nodes-cousins-binary-tree/
int checkIfTwoNodesAreCousin(struct TreeNode *root, int n1, int n2) {
	printf("\n level of %d is %d", n1, getLevel(root, n1, 0));
	printf("\n level of %d is %d", n2, getLevel(root, n2, 0));
	return getLevel(root, n1, 0) == getLevel(root, n2, 0) && !areSiblings(root, n1, n2);
}

//http://www.geeksforgeeks.org/print-nodes-dont-sibling-binary-tree/
void printAllNodesWithoutSiblings(struct TreeNode *root) {
	if (!root) {
		return;
	}
	if (root -> leftChild && !root -> rightChild) {
		printf("%d\t", root -> leftChild -> value);
	}
	if (!root -> leftChild && root -> rightChild) {
		printf("%d\t", root -> rightChild -> value);
	}
	printAllNodesWithoutSiblings(root -> leftChild);
	printAllNodesWithoutSiblings(root -> rightChild);
}

//http://www.geeksforgeeks.org/reverse-alternate-levels-binary-tree/
void getAllNodesInAlternateNodes(struct TreeNode *root, int arr[], int level) {
	static int i = 0;
	if (!root) {
		return;
	}
	getAllNodesInAlternateNodes(root -> leftChild, arr, level + 1);
	if (level & 1) {
		arr[i++] = root -> value;
	}
	getAllNodesInAlternateNodes(root -> rightChild, arr, level + 1);
}

void setAllNodesInAlternateNodes(struct TreeNode *root, int arr[], int level, int *i) {
	if (!root) {
		return;
	}
	setAllNodesInAlternateNodes(root -> leftChild, arr, level + 1, i);
	if (level & 1) {
		root -> value = arr[--(*i)];
	}
	setAllNodesInAlternateNodes(root -> rightChild, arr, level + 1, i);
}

void reverseAlternateLevelsWrapper(struct TreeNode *root) {
	display(root);
	int height = getHeightOfTree(root);
	int i = 2;
	int size = 0;
	int nodesPerLevel = 2;
	printf("Height of tree is : %d", height);
	for (i = 2; i <= height; i += 2) {
		size += nodesPerLevel;
		nodesPerLevel = nodesPerLevel * 4;
	}
	printf("\nTotal Array Size : %d", size);
	int *arr = (int *)malloc(sizeof(int) * size);
	getAllNodesInAlternateNodes(root, arr, 0);
	printf("\nNodes to be modified :\n");
	for (i = 0; i < size; i++) {
		printf("%d\t", arr[i]);
	}
	setAllNodesInAlternateNodes(root, arr, 0, &size);
	display(root);
}

void setVerticalElements(struct TreeNode *root, int min, int width, int **verticalElements) {
	if (!root) {
		return;
	}
	int i = 0;
	while(verticalElements[width - min][i] != INT_MIN) {
		i++;
	}
	verticalElements[width - min][i] = root -> value;
	setVerticalElements(root -> leftChild, min, width - 1, verticalElements);
	setVerticalElements(root -> rightChild, min, width + 1, verticalElements);
}

void getMinMaxWidth(struct TreeNode *root, int *min, int *max, int width) {
	if (!root) {
		return;
	}
	if (width < *min) {
		*min = width;
	} else if (width > *max){
		*max = width;
	}
	getMinMaxWidth(root -> leftChild, min, max, width - 1);
	getMinMaxWidth(root -> rightChild, min, max, width + 1);
}

//http://www.geeksforgeeks.org/print-binary-tree-vertical-order-set-2/
void printTreeVerticallyHashmap(struct TreeNode *root) {
	if (!root) {
		return;
	}
	int min = INT_MAX;
	int max = INT_MIN;
	getMinMaxWidth(root, &min, &max, 0);
	int width = max - min + 1;
	int height = getHeightOfTree(root);

	printf("\nmin = %d\nmax = %d\nheight = %d\nwidth", min, max, height);
	int i = 0;
	int j = 0;
	int **verticalElements = (int **) malloc (sizeof(int *) * width);
	for(i = 0; i < width; i++) {
		verticalElements[i] = (int *) malloc (sizeof(int) * (height + 1));
	}
	for (i = 0; i < width; i++) {
		for (j = 0; j <= height; j++) {
			verticalElements[i][j] = INT_MIN;
		}
	}
	setVerticalElements(root, min, 0, verticalElements);
	for (i = 0; i < width; i++) {
		printf("\nLevel : %d : ", i);
		for (j = 0; j <= height && verticalElements[i][j] != INT_MIN; j++) {
			printf("%d\t", verticalElements[i][j]);
		}
	}
}

//http://www.geeksforgeeks.org/print-binary-tree-vertical-order/
void printNodesInVerticalLevel(struct TreeNode *root, int verticalLevel, int width) {
	if (!root) {
		return;
	}
	if (width == verticalLevel) {
		printf("%d\t", root -> value);
	}
	printNodesInVerticalLevel(root -> leftChild, verticalLevel, width - 1);
	printNodesInVerticalLevel(root -> rightChild, verticalLevel, width + 1);
}

void printNodesVertically(struct TreeNode *root) {
	if (!root) {
		return;
	}
	int min = INT_MAX;
	int max = INT_MIN;
	getMinMaxWidth(root, &min, &max, 0);
	int i = 0;
	for (i = min; i <= max; i++) {
		printf("\nVertical Level : %d : ", (i - min));
		printNodesInVerticalLevel(root, i, 0);
	}
}

//http://www.geeksforgeeks.org/print-nodes-top-view-binary-tree/
void printTopView(struct TreeNode *root, int *verticalNodes, int min, int level) {
	if (!root) {
		return;
	}
	if (!verticalNodes[level - min]) {
		verticalNodes[level - min] = root -> value;
	}
	printTopView(root -> leftChild, verticalNodes, min, level - 1);
	printTopView(root -> rightChild, verticalNodes, min, level + 1);
}

//http://www.geeksforgeeks.org/bottom-view-binary-tree/
void printBottomView(struct TreeNode *root, int *verticalNodes, int min, int level) {
	if (!root) {
		return;
	}
	verticalNodes[level - min] = root -> value;
	printBottomView(root -> leftChild, verticalNodes, min, level - 1);
	printBottomView(root -> rightChild, verticalNodes, min, level + 1);
}

void printTopAndBottomView(struct TreeNode *root) {
	if (!root) {
		return;
	}
	int min = INT_MAX;
	int max = INT_MIN;
	getMinMaxWidth(root, &min, &max, 0);
	int width = max - min + 1;
	int i = 0;
	int *verticalNodes = (int *) calloc (sizeof(int), max - min + 1);
	printTopView(root, verticalNodes, min, 0);
	printf("\nTop View\n");
	for (i = 0; i < width; i++) {
		printf("%d\t", verticalNodes[i]);
	}
	printBottomView(root, verticalNodes, min, 0);
	printf("\nBottom View\n");
	for (i = 0; i < width; i++) {
		printf("%d\t", verticalNodes[i]);
	}
}

//http://www.geeksforgeeks.org/find-sum-left-leaves-given-binary-tree/
int getLeftLeafSum(struct TreeNode *root, int isLeft) {
	if (!root) {
		return 0;
	}
	if (isLeaf(root) && isLeft) {
		return root -> value;
	}
	return getLeftLeafSum(root -> leftChild, 1)
			+ getLeftLeafSum(root -> rightChild, 0);
}

//http://www.geeksforgeeks.org/find-minimum-depth-of-a-binary-tree/
int getNearestLeafDistance(struct TreeNode *root) {
	if (!root) {
		return INT_MAX;
	}
	if (isLeaf(root)) {
		return 1;
	}
	return 1 + min(getNearestLeafDistance(root -> leftChild),
			getNearestLeafDistance(root -> rightChild));
}

//http://www.geeksforgeeks.org/find-closest-leaf-binary-tree/
int getNearestLeafDistanceFromANode(struct TreeNode *root, int value, int *p, int *minDistance) {
	if (!root) {
		return 0;
	}
	int minLeafInRightSubTree = INT_MAX;
	int minLeafInLeftSubTree = INT_MAX;
	if (root -> value == value) {
		*minDistance = getNearestLeafDistance(root);
		printf("\nMinDistance in its own tree : %d", *minDistance);
		*p = 1;
		return 1;
	}
	if (getNearestLeafDistanceFromANode(root -> leftChild, value, p, minDistance)) {
		minLeafInRightSubTree = getNearestLeafDistance(root -> rightChild) + *p + 1;
		*minDistance = min (*minDistance, minLeafInRightSubTree);
		(*p)++;
		return 1;
	}
	if (getNearestLeafDistanceFromANode(root -> rightChild, value, p, minDistance)) {
		minLeafInLeftSubTree = getNearestLeafDistance(root -> leftChild) + *p + 1;
		*minDistance = min (*minDistance, minLeafInLeftSubTree);
		(*p)++;
		return 1;
	}
	return 0;
}
