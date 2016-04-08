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

//http://www.geeksforgeeks.org/lowest-common-ancestor-in-a-binary-tree-set-2-using-parent-pointer/
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

