#include"treesUtility.h"
/*
 * TreesMain.c
 *
 *  Created on: Jan 23, 2016
 *      Author: kuma
 */

int array1[]		=	{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
int array2[]		=	{1,3,2,7,6,4,5};
int array3[]		=	{83,67,50,5,80,24,64,8,38,70,90,20,30,55,110,74,187,56,108,201};
int array4[]		=	{1,3,2,4,7,6,5};
int array5[]		=	{26, 10, 3, 4, 6, 3};
int mirror[]		=	{1,2,2,3,4,4,3};
int binaryTree2[]	=	{50, 30, 100, 10, 5, 4, 1, 20, 25, 23, 40, 75, 200, 45, 43, 41,48, 49, 150};
int binaryTree[]	=	{50, 30, 22, 38, 35, 60, 55, 59, 94, 98};
int preorder[]		=	{50, 30, 22, 38, 35, 60, 55, 59, 94, 98};
int inorder[]		=	{22, 30, 35, 38, 50, 55, 59, 60, 94, 98};
int postoder[]		=	{22, 35, 38, 30, 59, 55, 98, 94, 60, 50};
int levelorder[]	=	{50, 30, 60, 22, 38, 55, 94, 35, 59, 98};
int srno = 9009;

struct TreeNode *root1 = NULL;
struct TreeNode *root2 = NULL;
struct TreeNode *root3 = NULL;
struct TreeNode *root4 = NULL;
struct TreeNode *mirrorTree = NULL;
struct TreeNode *emptyTree = NULL;
struct TreeNode *childrenSumProperty = NULL;
struct TreeNode *binarySearchTree = NULL;
struct TreeNode *binarySearchTree2 = NULL;

void initialize() {
	root1 = createBinaryTree(array1, sizeof(array1) / sizeof(array1[0]));
	root2 = createBinaryTree(array2, sizeof(array2) / sizeof(array2[0]));
	root3 = createBinaryTree(array3, sizeof(array3) / sizeof(array3[0]));
	root4 = createBinaryTree(array4, sizeof(array4) / sizeof(array4[0]));
	mirrorTree = createBinaryTree(mirror, sizeof(mirror) / sizeof(mirror[0]));
	childrenSumProperty = createBinaryTree(array5, sizeof(array5) / sizeof(array5[0]));
	binarySearchTree = createBST(binaryTree, sizeof(binaryTree) / sizeof(binaryTree[0]));
	binarySearchTree2 = createBST(binaryTree2, sizeof(binaryTree2) / sizeof(binaryTree2[0]));
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

void getHeightNonRecursiveDemo() {
	printf("\n%d", getHeightNonRecursive(root1));
	printf("\n%d", getHeightNonRecursive(root2));
	printf("\n%d", getHeightNonRecursive(root3));
	printf("\n%d", getHeightNonRecursive(emptyTree));
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

void lowestCommonAncestorInBSTDemo() {
	printf("\n%d", lowestCommonAncestor(binarySearchTree, 55, 98) -> value);
	printf("\n%d", lowestCommonAncestor(binarySearchTree, 30, 35) -> value);
	printf("\n%d", lowestCommonAncestor(binarySearchTree, 60, 59) -> value);
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
	struct TreeNode *root = createBST(binaryTree, sizeof(binaryTree) / sizeof(binaryTree[0]));
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

void getDistanceBetweenTwoNodesDemo() {
	int d1 = -1;
	int d2 = -1;
	int n1 = 59;
	int n2 = 60;
	struct TreeNode **ptr = (struct TreeNode **) malloc (sizeof (struct TreeNode *));
	struct TreeNode *root = binarySearchTree;
	display(binarySearchTree);
	int d = getDistanceBetweenTwoNodes(root, n1, n2, 0, &d1, &d2, ptr);
	printf("\nDistance of n1 = %d", d1);
	printf("\nDistance of n2 = %d", d2);
	printf("\nCommonAncestor of n1 and n2 = %d", (*ptr) -> value);
	printf("\nDistance of commonAncestor = %d", d);
	printf("\nDistance between %d and %d is %d", n1, n2, d1 + d2 - 2*d);

}

void maximumSumInPathDemo() {
	int maxSum = 0;
	maximumSumInPath(binarySearchTree, &maxSum);
	printf("%d", maxSum);
}

void maximumSumPathBetweenTwoLeavesDemo() {
	int maxSum = 0;
	maximumSumPathBetweenTwoLeaves(root1, &maxSum);
	printf("%d", maxSum);
}

void printBoundaryNodesDemo() {
	printBoundaryNodes(binarySearchTree);
}

void getVerticalSumDemo() {
	getVerticalSum(binarySearchTree);
}

void printAllNodesVerticallyDemo() {
	printAllNodesVertically(binarySearchTree);
}

void getMultiplicationOfSumWrapperDemo() {
	getMultiplicationOfSumWrapper(binarySearchTree);
}

void TreeTraversal() {
	printf("InOrder");
	printf("\nNon Recursively.\t");
	printInOrderNonRecursively(root4);
	printf("\nRecursively.\t\t");
	printInOrder(root4);

	printf("\n\nPostOrder");
	printf("\nNon Recursively.\t");
	printPostOrderNonRecursively(root4);
	printf("\nRecursively.\t\t");
	printPostOrder(root4);

	printf("\n\nPreOrder");
	printf("\nNon Recursively.\t");
	printPreOrderNonRecursively(root4);
	printf("\nRecursively.\t\t");
	printPreOrder(root4);

}

void printAllRootToLeafPathWithGivenSumWrapperDemo() {
	printAllRootToLeafPathWithGivenSumWrapper(root4, 8);
	printf("\nAnother approach.\n");
	printAllRootToLeafPathWithSum(root4, 8);
}

void isHeightBalancedDemo() {
	int res = 1;
	isHeightBalanced(binarySearchTree, &res);
	if (res) {
		printf("Height balanced.");
	} else {
		printf("Height is not balanced.");
	}
}

void getDiameterDemo() {
	int diameter = -1;
	printf("\nHeight of tree = %d", getDiameter(binarySearchTree, &diameter));
	printf("\nDiameter of this tree is : %d", diameter);
}

void createTreeFromPrePostDemo() {
	int pre[] = {1, 2, 4, 8, 9, 5, 3, 6, 7};
	int post[] = {8, 9, 4, 5, 2, 6, 7, 3, 1};
	struct TreeNode *root = createTreeFromPrePost(pre, post, 9);
	display(root);
}

void boundaryTraversalDemo() {
	boundaryTraversal(binarySearchTree);
}

void isCompleteBinaryTreeDemo() {
	if (isCompleteBinaryTree(root1)) {
		printf("\nComplete Binary Tree");
	} else {
		printf("\nNot a complete binary tree");
	}
}

void constructSpecialTreeDemo() {
	int pre[] = {10, 30, 20, 5, 15};
	char preLN[] = {'N', 'N', 'L', 'L', 'L'};
	int index = 0;
	int size = sizeof(pre) / sizeof(pre[0]);
	display(constructSpecialTree(pre, preLN, size, &index));
}

void constructTreeFromInorderTraversalDemo() {
	int inorder[] = {5, 10, 40, 30, 28};
	int size = sizeof(inorder) / sizeof(inorder[0]);
	display(constructTreeFromInorderTraversal(inorder, size));
}

void maximumSumRootToLeafPathDemo() {
	int maxSum = INT_MIN;
	maximumSumRootToLeafPath(binarySearchTree, &maxSum, 0);
	printf("\nMaximum sum root to leaf path = %d", maxSum);
}

void constructSumTreeDemo() {
	constructSumTree(childrenSumProperty);
	display(childrenSumProperty);
}

void isSumTreeDemo() {
	int status = 1;
	display(childrenSumProperty);
	isSumTree(childrenSumProperty, &status);
	if (status) {
		printf("\nSum Tree");
	} else {
		printf("\nNot a sum tree");
	}
}

void isIsomorphicDemo() {
	if(isIsomorphic(root1, root4)) {
		printf("Isomorphic");
	} else {
		printf("Not isomorphic");
	}
}

void getDifferenceBetweenOddEvenLevelNodesDemo() {
	printf("\nDifference = %d", getDifferenceBetweenOddEvenLevelNodes(root1));
}

void printPostOrderFromInorderPreOrderDemo() {
	printPostOrderFromInorderPreOrder(preorder, inorder, 10);
}

void depthOfDeepestOddLevelLeafNodeDemo() {
	struct TreeNode *ptr = NULL;
	int maxLevel = 0;
	depthOfDeepestOddLevelLeafNode(binarySearchTree, 1, &maxLevel, &ptr);
	printf("\nMax level is %d : ", maxLevel);
	printf("\nNode at is : %d ", ptr -> value);
}

void deepestLeafLeafNodeDemo() {
	struct TreeNode *ptr = NULL;
	int maxLevel = 0;
	deepestLeafLeafNode(binarySearchTree, 1, &maxLevel, 0, &ptr);
	printf("\nMax level is %d : ", maxLevel);
	printf("\nNode at is : %d ", ptr -> value);
}

void isAllLeafAtSameLevelDemo() {
	int maxLevel = -1;
	if (isAllLeafAtSameLevel(binarySearchTree, 0, &maxLevel)) {
		printf("Yes all leaves are at the same level.");
	} else {
		printf("No all leaves are not at the same level.");
	}
	printf("\n%d", maxLevel);
}

void convertToDoublyLinkedListDemo() {
	struct TreeNode *root = convertToDoublyLinkedList(binarySearchTree);
	while(root -> leftChild) {
		root = root -> leftChild;
	}
	while(root) {
		printf("%d\t", root -> value);
		root = root -> rightChild;
	}
}

void removeNodesWhoseSumIsLesserThanKDemo() {
	int sum = 0;
	int k = 120;
	display(binarySearchTree);
	removeNodesWhoseSumIsLesserThanK(binarySearchTree, k, &sum);
	display(binarySearchTree);
}

void removeAllPathsLessThanKDemo() {
	display(binarySearchTree);
	int length = 0;
	removeAllPathsLessThanK(binarySearchTree, 4, &length);
	display(binarySearchTree);
}

void removeAllPathsLessThanK2Demo() {
	display(binarySearchTree);
	removeAllPathsLessThanK2(binarySearchTree, 1, 50);
	display(binarySearchTree);
}

void reverseLevelOrderTraversalDemo() {
	reverseLevelOrderTraversal(binarySearchTree);
}

void reverseLevelOrderTraversal2Demo() {
	reverseLevelOrderTraversal2(binarySearchTree);
}

void extractLeavesInDoublyLinkedListDemo() {
	struct TreeNode *start = NULL;
	int pre[] = {1,2,4,7,8,5,3,6,9,10};
	int in[] = {7,4,8,2,5,1,3,9,6,10};
	struct TreeNode *root = constructTreeInorderPreorder(
		in, pre, 10);
	display(root);
	extractLeavesInDoublyLinkedList(root, &start);
	printf("Tree after extraction of leaves");
	display(root);
	printf("\nDoubly Linked list is : ");
	while(start) {
		printf("\t%d", start -> value);
		start = start -> rightChild;
	}
}

void printLeftRightViewDemo() {
	int maxLevel = -1;
	printf("\nLeft view\n");
	printLeftView(binarySearchTree, 0, &maxLevel);
	maxLevel = -1;
	printf("\nRight view\n");
	printRightView(binarySearchTree, 0, &maxLevel);
}

void printAllNodesAtDistanceKFromLeafNodeDemo() {
	int output[100] = {0};
	printAllNodesAtDistanceKFromLeafNode(binarySearchTree, 0, output, 2);
}

void sumOfAllNumberFormedFromRootToLeafDemo() {
	int totalSum = 0;
	sumOfAllNumberFormedFromRootToLeaf(root1, 0, &totalSum);
	printf("\nThe total sum is : %d",totalSum);
}

void printAllNodesBetweenTwoLevelsDemo() {
	printAllNodesBetweenTwoLevels(root3, 2, 4, 1);
}

void getDepthOfTreeDemo() {
	int parent[] = {1, 5, 5, 2, 2, -1, 3};
//	int parent[] = {-1, 0, 0, 1, 1, 3, 5};
	int size = sizeof(parent) / sizeof(parent[0]);
	printf("\nDepth is = %d", getDepthOfTree(parent, size));

}

void checkIfTwoNodesAreCousinDemo() {
	if (checkIfTwoNodesAreCousin(binarySearchTree, 38, 35)) {
		printf("\nAre cousins");
	} else {
		printf("\nAre not cousins.");
	}
}

void constructBinaryTreeToDoublyLinkedList2Demo() {
	constructBinaryTreeToDoublyLinkedList2(binarySearchTree);
}

void constructBinaryTreeToDoublyLinkedList3Demo() {
	struct TreeNode *start = NULL;
	constructBinaryTreeToDoublyLinkedList3(binarySearchTree, &start);
	printDoublyLinkedList(start);
}

void printAllNodesWithoutSiblingsDemo() {
	printAllNodesWithoutSiblings(binarySearchTree);
}

void reverseAlternateLevelsWrapperDemo() {
	reverseAlternateLevelsWrapper(root1);
}

void printTreeVerticallyHashmapDemo() {
	printTreeVerticallyHashmap(binarySearchTree);
}

void printNodesVerticallyDemo() {
	printNodesVertically(binarySearchTree);
}

void printTopAndBottomViewDemo() {
	printTopAndBottomView(binarySearchTree);
}

void getLeftLeafSumDemo() {
	printf("%d", getLeftLeafSum(binarySearchTree, 0));
}

void getMinimumDepthOfBinaryTreeDemo() {
	printf("\nMinimum depth is %d", getNearestLeafDistance(binarySearchTree));
}

void getNearestLeafDistanceFromANodeDemo() {
	int minDistance = INT_MAX;
	int p = 0;
	display(binarySearchTree2);
	getNearestLeafDistanceFromANode(binarySearchTree2, 30, &p, &minDistance);
	printf("\nNearest leaf distance from node is = %d", minDistance);
}
int main() {
	initialize();
	getNearestLeafDistanceFromANodeDemo();
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

