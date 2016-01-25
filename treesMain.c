#include"treesUtility.h"
/*
 * TreesMain.c
 *
 *  Created on: Jan 23, 2016
 *      Author: kuma
 */

int array1[] = {1,2,3,4,5,6,7,8,9};
int array2[] = {1,2,3,4,5,6,7,8,9};
int array3[] = {33,67,5,2,8,24,64,23,77,29,54,70,98,106, 110};
int array4[] = {1,2,3,4,5};

struct TreeNode *root1 = NULL;
struct TreeNode *root2 = NULL;
struct TreeNode *root3 = NULL;
struct TreeNode *root4 = NULL;
struct TreeNode *emptyTree = NULL;

void initialize() {
	root1 = createBinaryTree(array1, sizeof(array1) / sizeof(array1[0]));
	root2 = createBinaryTree(array2, sizeof(array2) / sizeof(array2[0]));
	root3 = createBinaryTree(array3, sizeof(array3) / sizeof(array3[0]));
	root4 = createBinaryTree(array4, sizeof(array4) / sizeof(array4[0]));
}

void getTreeSizeDemo() {
	printf("\nTreeSize = %d ", getTreeSize(root1));
	printf("\nTreeSize = %d ", getTreeSize(root3));
	printf("\nTreeSize = %d ", getTreeSize(emptyTree));
}

void areIdenticalTreesDemo() {
	areIdentical(root1, root2) == 1 ? printf("\nIdentical") : printf("\nNot Identical");
	areIdentical(root2, root3) == 1 ? printf("\nIdentical") : printf("\nNot Identical");
}

void getHeightOfTreeDemo() {
	printf("\n%d", getHeightOfTree(root1));
	printf("\n%d", getHeightOfTree(root2));
	printf("\n%d", getHeightOfTree(root3));
	printf("\n%d", getHeightOfTree(emptyTree));
}

void deleteTreeDemo() {
	display(root1);
	deleteTree(root1);
	display(root1);
}

void convertToMirrorTreeDemo() {
	display(root1);
	display(convertToMirrorTree(root1));
}

void printAllRootToLeafPathDemo() {
	int output[100];
	printAllRootToLeafPath(root1, 0, output);
	printAllRootToLeafPath(root3, 0, output);
}

void lowestCommonAncestorDemo() {
	printf("\nLCA = %d", lowestCommonAncestor(root3, 23, 77) -> value);
	printf("\nLCA = %d", lowestCommonAncestor(root3, 23, 54) -> value);
	printf("\nLCA = %d", lowestCommonAncestor(root3, 2, 106) -> value);
	printf("\nLCA = %d", lowestCommonAncestor(root3, 67, 29) -> value);
}

void printAncestorDemo() {
	int output[100];
	printAncestor(root3, 54, output, 0);
	printAncestor(root3, 33, output, 0);
	printAncestor(root3, 67, output, 0);
	printAncestor(root3, 23, output, 0);
	printAncestor(root3, 110, output, 0);
}

void getLevelOfNodeDemo() {
	printf("\nLevel of node in tree is = %d", getLevelOfNode(root3, 8, 0));
	printf("\nLevel of node in tree is = %d", getLevelOfNode(root3, 33, 0));
	printf("\nLevel of node in tree is = %d", getLevelOfNode(root3, 70, 0));
	printf("\nLevel of node in tree is = %d", getLevelOfNode(root3, 5, 0));
	printf("\nLevel of node in tree is = %d", getLevelOfNode(root3, 809, 0));
}

void isFoldableDemo() {
	isFoldable(root3 -> leftChild, root3 -> rightChild) != 0 ? printf("\nFoldable") : printf("\nNot Foldable");
	isFoldable(root4 -> leftChild, root4 -> rightChild) != 0 ? printf("\nFoldable") : printf("\nNot Foldable");
}

void printNodesAtDistanceKFromRootDemo() {
	printNodesAtDistanceKFromRoot(root3, 2);
	printf("\n");
	printNodesAtDistanceKFromRoot(root3, 3);
}

void getMaximumWidthDemo() {
	printf("\n%d", getMaximumWidth(root1));
	printf("\n%d", getMaximumWidth(root2));
	printf("\n%d", getMaximumWidth(root3));
	printf("\n%d", getMaximumWidth(root4));
}

void doubleTreeDemo() {
	display(root4);
	printf("\n");
	doubleTree(root4);
	display(root4);
}
void constructTreeInorderPreorderDemo() {
	int pre[] = {1, 2, 4, 8, 9, 5, 3, 6, 7};
	int in[] = {8, 4, 9, 2, 5, 1, 6, 3, 7};
	struct TreeNode *root = constructTreeInorderPreorder(in, pre, sizeof(in) / sizeof(in[0]));
	display(root);
	display(root1);
}

void constructTreeInorderPostorderDemo() {
	int post[] = {8, 9, 4, 5, 2, 6, 7, 3, 1};
	int in[] = {8, 4, 9, 2, 5, 1, 6, 3, 7};
	struct TreeNode *root = constructTreeInorderPostorder(in, post, sizeof(in) / sizeof(in[0]));
	display(root);
	printf("\n");
	display(root1);
}

void constructTreeInorderLevelorderDemo() {
	int level[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int in[]    = {8, 4, 9, 2, 5, 1, 6, 3, 7};
	struct TreeNode *root = constructTreeInorderLevelorder(in, level, sizeof(in) / sizeof(in[0]));
	display(root);
	printf("\n");
	display(root1);
}

void countLeafNodesDemo() {
	printf("\nLeaf nodes = %d", countLeafNodes(root1));
	printf("\nLeaf nodes = %d", countLeafNodes(root2));
	printf("\nLeaf nodes = %d", countLeafNodes(root3));
	printf("\nLeaf nodes = %d", countLeafNodes(root4));
}
int main() {
	initialize();
	countLeafNodesDemo();
	return 0;
}

