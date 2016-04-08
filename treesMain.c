#include"treesUtility.h"
/*
 * TreesMain.c
 *
 *  Created on: Jan 23, 2016
 *      Author: kuma
 */

int array1[] = {1,2,3,4,5,6,7,8,9};
int array2[] = {1,2,3,4,5,6,7,8,9};
int array3[] = {83,67,50,5,80,24,64,8,38,70,90,20,30,55,110};
int array4[] = {1,2,3,4,5};
int array5[] = {10, 8, 2, 3, 5, 2};
int array6[] = {50, 30, 22, 38, 35, 60, 55, 59, 94, 98};
int preorder[] = {50, 30, 22, 38,35, 60, 55, 59, 94, 98};
int inorder[] = {22, 30, 35, 38, 50, 55, 59, 60, 94, 98};
int postoder[] = {22, 35, 38, 30, 59, 55, 98, 94, 60, 50};
int levelorder[] = {50, 30, 60, 22, 38, 55, 94, 35, 59, 98};
int srno = 9009;

struct TreeNode *root1 = NULL;
struct TreeNode *root2 = NULL;
struct TreeNode *root3 = NULL;
struct TreeNode *root4 = NULL;
struct TreeNode *emptyTree = NULL;
struct TreeNode *childrenSumProperty = NULL;
struct TreeNode *binarySearchTree = NULL;

void initialize() {
	root1 = createBinaryTree(array1, sizeof(array1) / sizeof(array1[0]));
	root2 = createBinaryTree(array2, sizeof(array2) / sizeof(array2[0]));
	root3 = createBinaryTree(array3, sizeof(array3) / sizeof(array3[0]));
	root4 = createBinaryTree(array4, sizeof(array4) / sizeof(array4[0]));
	childrenSumProperty = createBinaryTree(array5, sizeof(array5) / sizeof(array5[0]));
	binarySearchTree = createBST(array6, sizeof(array6) / sizeof(array6[0]));
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

void printLevelOrderSpiralFormDemo() {
	display(root1);
	printf("\n");
	printLevelOrderSpiralForm(root1);
}

void isChildrenSumPropertyIntactDemo() {
	isChildrenSumPropertyIntact(childrenSumProperty) == 1 ? printf("\nChildrenSumProperty") : printf("\nChildrenSumProperty_violated");
	isChildrenSumPropertyIntact(root1) == 1 ? printf("\nChildrenSumProperty") : printf("\nChildrenSumProperty_violated");
}

void constructCSPDemo() {
	display(root4);
	constructCSP(root4);
	display(root4);
}

void printRootLeafSumEqualToGivenNumberDemo() {
	printRootLeafSumEqualToGivenNumber(root4, 7);
}

void morrisInorderTraversalDemo() {
	display(root4);
	printf("\n");
	morrisInorderTraversal(root4);
}

void morrisPreorderTraversalDemo() {
	display(binarySearchTree);
	printf("\n");
	morrisPreorderTraversal(binarySearchTree);
}

void deleteTreeNodeDemo() {
	display(root4);
	deleteTreeNode(root4, 1);
	display(root4);
}

void createBSTDemo() {
	struct TreeNode *root = createBST(array6, sizeof(array6) / sizeof(array6[0]));
	display(root);
}

void constructBinaryTreeToDoublyLinkedListDemo() {
	display(root4);
	constructBinaryTreeToDoublyLinkedList(root4);
	printDoublyLinkedList(root4);
}

void isBinaryTreeBSTDemo() {
//	display(binarySearchTree);
//	(1 == isBinaryTreeBST(binarySearchTree, NULL)) ? printf("\nYes") : printf("\nNo");
	display(root1);
	struct TreeNode *returnValue = NULL;
	(1 == isBinaryTreeBST(binarySearchTree, &returnValue)) ? printf("\nYes") : printf("\nNo");
	(1 == isBinaryTreeBST(root1, &returnValue)) ? printf("\nYes") : printf("\nNo");
}

void largestBinarySearchTreeDemo() {
	struct TreeNode *ptr = NULL;
	int max = INT_MIN;
	int min = INT_MAX;
	int maxSize = -1;
	display(root3);
	largestBinarySearchTree2(root3, &max, &min, &ptr, &maxSize);
	printf("\nMaximum size is %d", maxSize);
	if (ptr != NULL) {
		printf("\nMaximum size BST's root is %d with %d nodes", ptr -> value, maxSize);
	}
}

void printNodesAtDistanceKFromAnyNodeDemo() {
	int p = 0;
	printNodesAtDistanceKFromAnyNode(root3, 55, 4, &p);
}
void demo(int a, int *b, int *c) {
	if (a == 0) {
		b = c;
		return;
	}
	demo(a-1, b, c);
}

void getMinimumDistanceLeafFromAnyNodeDemo() {
	int value = 30;
	int dummy = 0;
	int array[] = {50, 30, 22, 38, 35, 60, 34, 18, 20};
	binarySearchTree = createBST(array, sizeof(array) / sizeof(array[0]));
	display(binarySearchTree);
	printf("\n%d", getMinimumDistanceLeaf(binarySearchTree));
	printf("\nMinimum distance : %d",
		getMinimumDistanceLeafFromAnyNode(binarySearchTree, value, &dummy));
}

void printMatrix(int mat[3][3], int n) {
	int i,j;
	for(i = 0; i < n; i++) {
		printf("\n");
		for (j = 0; j < n; j++) {
			printf("%d\t", mat[i][j]);
		}
	}
}
void inplaceRotation(int mat[3][3], int n)
{
	int i;
	int k;
	int oldValue;
	int newValue;
	int start_i;
	int start_j;
	int next_i;
	int next_j;
	int iter_i;
	int iter_j;
	for (k = 0; k < n / 2; k++) {
		for (i = 0; i < n -k - 1; i++) {
			start_i = k;
			start_j = i;
			oldValue = mat[start_i][start_j];
			iter_i = start_i;
			iter_j = start_j;
			do {
				next_i = start_j;
				next_j = n - start_i - 1;
				newValue = mat[next_i][next_j];
				mat[next_i][next_j] = oldValue;
				oldValue = newValue;
				iter_i = next_i;
				iter_j = next_j;
			} while(iter_i != start_i && iter_j != start_j);
		}
	}
}

void constructBSTFromPostorderDemo() {
	int post[] = {22, 35, 38, 30, 59, 55, 98, 94, 60, 50};
	int size = sizeof(post) / sizeof(post[0]);
	struct TreeNode *root = constructBSTFromPostorder(post, size);
	display(root);
}

void constructBSTFromPreorderDemo() {
	int pre[] = {50, 30, 22, 38, 35, 60, 55, 59, 94, 98};
	int size = sizeof(pre) / sizeof(pre[0]);
	struct TreeNode *root = constructBSTFromPreorder(pre, size);
	display(root);
}

void getMinimumDifferenceDemo() {
	printf("\nMaxDifference = %d", getMaximumDifference(root3));
}
void isLeafTraversalSameDemo() {
//	struct TreeNode *root1 = binarySearchTree;
//	struct TreeNode *root2 = constructTreeInorderPreorder(inorder, preorder,
//			sizeof(preorder) / sizeof(preorder[0]));
	printf("\nPrinting leaf nodes in root1");
	countLeafNodes(root2);
	printf("\nPrinting leaf nodes in root2");
	countLeafNodes(root3);
	isLeafTraversalSame(root3, root2);
}

//http://www.geeksforgeeks.org/check-sum-covered-uncovered-nodes-binary-tree/
void checkSumOfCoveredUncoveredNodesDemo() {
	struct TreeNode *root = binarySearchTree;
	display(root);
	int leftBoundarySum = getLeftBoundarySum(root);
	int rightBoundarySum = getRightBoundarySum(root);
	printf("\nSum of left boundary is = %d", leftBoundarySum);
	printf("\nSum of right boundary is = %d", rightBoundarySum);
	int boundarySum = leftBoundarySum + rightBoundarySum - root -> value;
	int treeSum = getTreeSum(binarySearchTree);
	int innerNodeSum = treeSum - boundarySum;
	printf("\nTreeSum = %d", treeSum);
	printf("\nBoundary Node sum = %d", boundarySum);
	printf("\nInner Node Sum = %d", innerNodeSum);
}

void checkBinaryTreeDivisionInTwoHalvesDemo() {
	int res = 0;
	binarySearchTree = deleteTreeNode(binarySearchTree, 98);
	int n = getTreeSize(binarySearchTree);
	printf("\nSize of binary tree = %d", n);
	if ((n & 1) == 0) {
		checkBinaryTreeDivisionInTwoHalves(binarySearchTree, n, &res);
	}
	if (res == 0) {
		printf("\nCant divide tree into two equal halves.");
	} else {
		printf("\nYes divide tree into two equal halves.");
	}
}

int main() {
	initialize();
	getMinimumDistanceLeafFromAnyNodeDemo();
	return 0;
}

void countDivisors(int n)
{    // Initialize count of divisors
    int count = 0,i;

    // Note that this loop runs till square root
    for (i=1; i*i<=n; i++)
    {
        if (n%i==0) {

            // If divisors are equal,increment
            // count by one
            // Otherwise increment count by 2
            count += (n/i == i)? 1 : 2;
            printf("%d\t", i);
        }
    }

    printf("\n");
    if (count%2==0)
        printf("Even\n");
    else
        printf("Odd\n");
}

int mainC() {

	double x = 1.14;
	double res = x * (pow(x, 9) - 1) / (x - 1);
	printf("%f", res);
}

