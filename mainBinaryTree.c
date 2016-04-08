#include"binaryTrees.h"
#include<stdio.h>
int main()
{
	int ch;
	int choice;
	int num,info,i,key;
	int left,right, count=0;
	int n1, n2;
	int flag1 = 0;
	int flag2 = 0;
	int output = -1;
	struct treenode *inSuccessor=NULL;
	struct node *start = NULL;
	struct treenode *root = NULL;
	struct treenode *result = NULL;
	struct treenode *ptr1 = NULL, *ptr2 = NULL;
	struct treenode *resultantRoot = NULL;
	int maxChainLength = -1;
	struct treenode *root2 = NULL;
	struct treenode *ptr = NULL;
	struct node *preorder = NULL;
	struct node *inorder = NULL;
	struct node *postorder = NULL;
	int arr[] = {33,67,2,5,8,24,64,23,77,29,54,70,98,106};
	int sizee = sizeof(arr)/sizeof(arr[0]);
	int pre[] = {5,10,40,30,28};// q-43
//	int pre[] = {1, 2, 3, 4, 5};// q-42
	char preLN[] = {'N', 'N', 'N', 'N', 'L'};// q-42
	int size = sizeof(pre)/sizeof(pre[0]);// q-42
//	int arr1[] = {40, 38, 39, 30, 45};	// 41-CBST
//	int arr1[] = {40, 38, 39, 30, 45, 60};	// 41-Not a CBST
//	int arr1[] = {6,-13,14,-8,13,15,7};
//	int arr1[] = {100,60,135,-6,70,215,-7,14,80,-1,-5,12,78,90,91};//46
	//int arr1[] = {50, 20, 40, 30, 35, 32, 33};
	int arr1[] = {50, 30, 60, 22, 38, 55, 94, 35, 59, 98, 13};
//	int arr1[] = {50, 30, 60, 22, 38, 55, 94, 20, 27, 35};		//49
//	int arr1[] = {4, 2, 5, 1, 3};		//49
//	int arr1[] = {5,4,3,2,1};		//45
//	int arr1[] = {1, 2, 3, 4, 5};		//45
//	int arr1[] = {50, 30, 22, 38, 35, 60, 55, 59, 94, 98}; // for q-40
//	int arr1[] = {1,2,3,4,5,6,7,8,9};
//	int arr1[] = {12,10,30,11,40};
	int size1 = sizeof(arr1)/sizeof(arr1[0]);
	int inorder68[] = {4, 8, 10, 12, 14, 20, 22};
	int level68[] = {20, 8, 22, 4, 12, 10, 14};
	int size68 = sizeof(inorder68)/sizeof(inorder68[0]);
	int preorderArr[] = {1,2,4,8,5,3,6,9,7,10,11};
	int size_preorder = sizeof(preorderArr)/sizeof(preorderArr[0]);
	
	int inorderArr[] = {4,8,2,5,1,9,6,3,10,7,11};
	int size_inorder = sizeof(inorderArr)/sizeof(inorderArr[0]);
	
	int postorderArr[] = {8,4,5,2,9,6,10,11,7,3,1};
	int size_postorder = sizeof(postorderArr)/sizeof(postorderArr[0]);

//  for ques 15	and 16
	int preptr[]  = {50, 30, 22, 13, 38, 35, 60, 55, 59, 94, 98};
	int inptr[]   = {13, 22, 30, 35, 38, 50, 55, 59, 60, 94, 98};
	int postptr[] = {13, 22, 35, 38, 30, 59, 55, 98, 94, 60, 50};
	int levelptr[] = {50, 30, 60, 22, 38, 55, 94, 13, 35, 59, 98};
	int size15 = sizeof(preptr)/sizeof(preptr[0]);
	
// for que 17 and 18
	int level;
	int maxLevel;
	
// for que 19,27
	int sum=0;
	
//for que 22
	int maxDepthOdd;
	int maxDepthEven;

//for  que 23
	struct treenode *p=NULL;
//for que 29
//	int arr1[] = {6,-13,14,-8,13,15,7};
	int upper = 195;
	int lower = 100;

	
	
	while(1){
		printf("\n---------------------------------------------------------------------------------");
		printf("\n---------------------------------------------------------------------------------");
		printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>Menu<<<<<<<<<<<<<<<<<<<<<<<<<<<<<");
		printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<");
/*		printf("\n 1-Display a binary Tree.(using recursive functions)");
		printf("\n 2-Display a binary Tree.(using non-recursive functions)");
		printf("\n 3-Insertion in a binary Tree non-recursion.");
		printf("\n 4-Insertion in a binary Tree recursively.");
		printf("\n 5-Deletion in a binary Tree non-recursion.");
		printf("\n 6-Deletion in a binary Tree recursively.");
*/		printf("\n 7-Create a binary tree using an array.");
	/*	printf("\n 8-Height of a binary tree (recursive).");
		printf("\n 9-Creating a binary tree from inorder and preorder.");
		printf("\n10-Creating a binary tree from inorder and postorder.");
		printf("\n11-Deleting all nodes of a binary tree.");
		printf("\n12-Count all nodes of a binary tree.");		
		printf("\n13-Height of a binary tree.(non-recursive)");
		
		printf("\n14-GFG-Find next right node of a given key.");
		printf("\n15-GFG-Given Inorder and Preorder traversals of a binary tree, print Postorder traversal.");
		printf("\n16-GFG-Given Inorder and Postorder traversals of a binary tree, print Preorder traversal.");
		printf("\n17-GFG-Print Left view of a tree.");
		printf("\n18-GFG-Print Right view of a tree.");
		printf("\n19-GFG-Difference between sums of odd level and even level nodes of a Binary Tree");
		printf("\n20-GFG-Print ancestors of a given binary tree node without recursion.");
		printf("\n21-Height of a binary tree.(non-recursive) using postorder traversal.");
		printf("\n22-GFG-Find depth of the deepest odd level leaf node.");
		printf("\n23-GFG-Deepest leaf node in a binary tree.");
		printf("\n24-GFG-Check if all leaf nodes are at the same level.");
		printf("\n25-GFG-Check if all leaf nodes are at the same level.(non-recursive)");
		printf("\n26-GFG-Remove all nodes which don't lie in any path with sum>= k.(non-recursive)");
		printf("\n27-GFG-Remove all nodes which don't lie in any path with sum>= k.(recursive)");
		printf("\n28-GFG-Convert a given Binary Tree to Doubly Linked List.(recursive)");
		printf("\n29-GFG-Remove BST keys outside the given range.(recursive)");
		printf("\n30-GFG-Construct Complete Binary Tree from its Linked List Representation(recursive)");
		printf("\n31-GFG-Reverse Level Order (recursive).");
		printf("\n32-GFG-Find a pair with given sum in a Balanced BST");
		printf("\n33-GFG-Find a triplet with given sum in a Balanced BST");
		printf("\n34-GFG-Find Morris Inorder traversal");
		printf("\n35-GFG-Find Morris Preorder traversal");
		printf("\n36-GFG-Convert a BST to a Binary Tree such that sum of all greater keys is added to every key.");
		printf("\n37-GFG-Convert a BST to a Binary Tree such that sum of all Lesser keys is added to every key.");
		printf("\n38-GFG-Convert a given tree to its Sum Tree");
		printf("\n39-GFG-Find ceiling and Floor of a given key in a BST.");
		printf("\n40-GFG-Create a BST from a preorder traversal.");
		printf("\n41-Check a tree whether it is a complete binary search tree or not.");
		printf("\n42-Construct a special tree from 2 arrays.");
		printf("\n43-Construct a special tree from 1 array.");
		printf("\n44-Lowest Common Ancestor in a Binary Search Tree.");
		printf("\n45-Check Binary Tree to be height balanced.");
		printf("\n46-Diameter of a tree.");
		printf("\n47-Print all root to leaf path.");
		printf("\n48-Double tree.");
		printf("\n49-Print sorted values from array notation of binary search tree.NR");
		printf("\n50-Print sorted values from array notation of binary search tree.R");
		printf("\n51-Print nodes at level k in a given array notation of a tree (Recursively)");
		printf("\n52-Check whether a tree is foldable or not.(Recursively)");
		printf("\n53-Create BST from sorted array.(Recursively)");
		printf("\n54-Find the k-th largest element in a tree.(Recursively)");
		printf("\n55-Find the k-th smallest element in a tree.(Recursively)");
		printf("\n56-Find the width of a tree.(Recursively)");
		printf("\n57-Print all root to leaf path in a binary tree.(Recursively)");
		printf("\n58-Print binary tree in spiral form.(Recursively)");
		printf("\n59-Print all nodes at a distance of k from a given node.");
		printf("\n60-Create an ordianry tree from an array.");
		printf("\n61-Find the lowest common ancestor");
		printf("\n62-Creating a binary tree from inorder and levelorder traversal");
*/		printf("\n69-Common ancestor in a binary tree.");
		printf("\n70-Print distance between any two node in a binary Tree.");
		printf("\n71-Printing a tree vertically");
		printf("\n72-Create a tree from levelorder and inorder traversal trace.");
		printf("\n76-Print a tree in zig zag order.");
		printf("\n77-Print boundary elements in a tree.");
		printf("\n78-create a tree from preorder traversal");
		printf("\n79-Inorder successor of a tree");
		printf("\n80-Convert a doubly linked list to a binary tree.");
		printf("\n81-Convert a tree to its equivalent linked list in preorder form.");
		printf("\n82-Convert a tree to its equivalent linked list in postorder form.");
		printf("\n83-Max Chain lengtffh in a tree");
		printf("\n84-Add values to right node in a tree");
		printf("\n85-Diagonal Sum in a tree");
		printf("\n86-Creating a binary tree.");
		printf("\n87-Biggest bst in a binary tree.");
		printf("\n\nEnter your choice: ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1: display_recursion(root);
					break;
					
			case 2: display_non_recursion(root);
					break;
					
			case 3: printf("How many numbers do you want to enter?");
					scanf("%d",&num);
					for(i=0;i<num;i++)
					{
						printf("Enter %d number that you want to insert in binary tree : ",i+1);
						scanf("%d",&info);
						root = insertTree(root,info);
					}
					printf("\nInorder traversal:");
					display_recursion(root);
					break;

			case 4: printf("How many numbers do you want to enter?");
					scanf("%d",&num);
					for(i=0;i<num;i++)
					{
						printf("Enter %d number that you want to Tree in binary tree : ",i+1);
						scanf("%d",&info);
						root = insertTreeRecursive(root,info);
					}
					printf("\nInorder traversal:");
					display_recursion(root);
					break;

			case 5: printf("\nWhich number do you want to delete?");
					scanf("%d",&num);
					display_non_recursion(root);
					root = deleteNonRecursively(root,num);
					display_non_recursion(root);
					break;
					
			case 6: printf("\nWhich number do you want to delete? ");
					scanf("%d",&num);
					display_non_recursion(root);
					root = deleteRecursively(root,num);
					display_non_recursion(root);
					break;
					
			case 7: printf("Creating binary tree from given array.");
					root = createBTfromArray(root,arr1,size1);
					display_non_recursion(root);
					break;
			
			case 8: printf("\nFinding height of tree.");
					printf("\nHeight = %d",height_recursion(root));
					break;
			
			case 9: preorder = create(preorder,preorderArr,size_preorder);
					inorder = create(inorder,inorderArr,size_inorder);
					printf("\nPreorder List.");
					display(preorder);
					printf("\nInorder List");
					display(inorder);
					printf("\nCreating a tree.");
					root = constructFromPreorderInorder(preorder,inorder,size_inorder);
					display_non_recursion(root);
					break;

			case 10:postorder = create(postorder,postorderArr,size_postorder);
					inorder = create(inorder,inorderArr,size_inorder);
					printf("\nPostorder List.");
					display(postorder);
					printf("\nInorder List");
					display(inorder);
					printf("\nCreating a tree.");
					root = constructFromPostorderInorder(postorder,inorder,size_inorder);
					display_non_recursion(root);
					break;
			
			case 11:root = deleteAllNodes(root);
					display_non_recursion(root);
					break;
					
			case 12:printf("\nTotal numbers of nodes in this tree = %d",countAllNodes(root));		
					break;
					
			case 13:printf("\nFinding height of tree.");
					printf("\nHeight = %d",height_non_recursion(root));
					break;

			case 14: printf("\nFinding next right node.");
					printf("\nEnter the key.");
					scanf("%d",&key);
					neighbourNode(root,key);
					break;
				
			case 15: printf("Making postptr from inptr and preptr traversal.\n");
					printPostptrs(inptr,preptr,size15);
					printf("\n");
					for(i=0;i<size15;i++)
						printf("%2d ",postptr[i]);
					break;
			
			case 16: printf("Making preptr from inptr and postptr traversal.\n");
					printPreptr(inptr,postptr,size15);
					printf("\n");
					for(i=0;i<size15;i++)
						printf("%2d ",preptr[i]);
					break;

			case 17: printf("\nLeft view of tree.");
					level = 0;
					maxLevel = -1;
					viewLeft(root,level,&maxLevel);
					printf("\nThe height of the tree is %d",maxLevel);
					break;

			case 18: printf("\nRight view of tree.");
					level = 0;
					maxLevel = -1;
					viewRight(root,level,&maxLevel);
					printf("\nThe height of the tree is %d",maxLevel);
					break;
					
			case 19:level = 1;
					sum = 0;
					differenceA(root,level,&sum);
					printf("\nDifference between sums of odd level and even level nodes of a Binary Tree by method A= %d",sum);
					printf("\nDifference between sums of odd level and even level nodes of a Binary Tree by method B= %d",differenceB(root));
					break;
					
			case 20:printf("Print ancestors of a given binary tree node without recursion.");
					printAncestor(root);
					break;
					
			case 21:printf("\nHeight of the tree = %d",heightNR(root));
					break;
					
			case 22:level = 1;
					maxDepthOdd = -1;
					maxDepthEven = -1;
					depthLeafNode(root,level,&maxDepthOdd, &maxDepthEven);
					printf("\nDepth of the deepest odd level leaf node = %d and even leaf node = %d",maxDepthOdd,maxDepthEven);
					break;

			case 23:level = 1;
					maxLevel = -1;
					p = NULL;
					deepestLeftLeaf(root,level,&maxLevel,&p,0);
					if(p)
						printf("\nDeepest left leaf node in a binary tree = %d",p->info);
					else
						printf("\nNo left leaf node.");
					break;

			case 24:level = 1;
					maxLevel = -1;
					if(check(root,level,&maxLevel))
						printf("\nYes all leaves are at the same level.");
					else
						printf("\nNo, all leaves are not at the same level.");
					break;
					
			case 25:if(checkB(root))
						printf("\nYes all leaves are at the same level.");
					else
						printf("\nNo, all leaves are not at the same level.");
					break;
					
			case 26:printf("\nRemove all nodes which donâ€™t lie in any path with sum>= %d",154);
					root = remov(root,153);
					display_recursion(root);
					break;
					
			case 27:printf("\nRemove all nodes which donâ€™t lie in any path with sum>= %d",154);
					root = removRecursively(root,153,&sum);
					display_recursion(root);
					break;
					
			case 28: printf("\nConvert a given Binary Tree to Doubly Linked List.");
					root = binaryToDLL(root);
					while(root->lchild != NULL)
						root = root->lchild;
					while(root!=NULL)
					{
						printf("  %2d  ",root->info);
						root = root->rchild;
					}	
					break;
			
			case 29:printf("\n29-GFG-Remove BST keys outside the given range.(recursive)");
					root = removeBST(root, lower, upper);
					display_recursion(root);
					break;
					
			case 30:printf("\nM30-GFG-Construct Complete Binary Tree from its Linked List Representation(recursive)");
					start  = NULL;
					start = create(start,arr1,size1);
					printf("\nHere is your linked list.");
					display(start);
					root = NULL;
					root = LLtoCBT(root, start);
					display_recursion(root);		
					break;
					
			case 31:printf("\nHere is the reversed linked list.");
					reverseLevelOrderNR(root);
					break;
			
			case 32:printf("\nWrite sum.");
					scanf("%d",&sum);
					printSum(root,sum);
					break;
					
			case 33:printf("\nWrite sum.");
					scanf("%d",&sum);
					printTriplet(root,sum);
					break;

			case 34:printf("\nMorris Inorder traversal");
					printMorrisInorder(root);
					break;
					
			case 35:printf("\nMorris Preorder traversal");
					printMorrisPostOrder(root);
					break;
					
			case 36:printf("\nConvert a BST to a Binary Tree such that sum of all greater keys is added to every key.\n");
					sum=0;
					printSumGreater(root,&sum);
					break;
					
			case 37:printf("\nConvert a BST to a Binary Tree such that sum of all lesser keys is added to every key.\n");
					sum=0;
					printSumLesser(root,&sum);
					break;
					
			case 38:printf("\nConvert a given tree to its Sum Tree.\n");
					sum=SumTree(root);
					break;
					
			case 39:printf("\nCeiling & floor");
					printf("\nEnter the number.");
					scanf("%d",&key);
					sum = ceiling(root,key);
					if(sum != -1)
						printf("\nThe ceiling of %2d is %2d.",key,sum);
					else
						printf("\nThe ceiling of %2d is %2d.",key,sum);
					sum = flooring(root,key);
					if(sum != -1)
						printf("\nThe floor of %2d is %2d.",key,sum);
					else
						printf("\nThe floor of %2d is %2d.",key,sum);
					break;

			case 40:printf("\nCreate a BST from preorder");
					root = createBST(arr1,size1);
					break;
					
			case 41:printf("\nCheck a tree whether it is a complete binary search tree or not.");
					sum = checkCBST(root);
					if(sum == 1)
						printf("\nComplete Binary Search Tree.");
					else
						printf("\nNot a Complete Binary Search Tree.");
					break;
			
			case 42:printf("\nCreating tree.");
					root = createSTree1(pre, preLN, size);
					display_non_recursion(root);
					root = NULL;
					info = 0;
					printf("\n");
					root = createSTree2(pre, preLN, size, &info);
					display_non_recursion(root);
					break;
					
			case 43:printf("Creating tree.");
					root = cons(pre,size);
					break;
					
			case 44:printf("Lowest Common Ancestor in a Binary Search Tree.");
					printf("\nEnter the value of n1.");
					scanf("%d",&level);
//					printf("\nEnter the value of n2.");
//					scanf("%d",&sum);
					if(!prr(root,level))
						printf("\nThe sum can't be obtained.");
					break;
					
			case 45:printf("Height balanced tree.");
//					isHeightBalanced(root,&sum);
					sum = isHB(root,1);
					if(sum)
					{
						printf("\nTree is height balanced.: %d", sum);
					}	
					else
						printf("\nTree is not height balanced.");
					break;

			case 46:printf("Diameter of a binary tree.");
					sum = 0;
					ptr = NULL;
					diameterTree(root,&sum,&ptr);
					printf("\nDiameter of tree is %d  root is %d",sum,ptr->info);
					break;
					
			case 47:printf("\nRoot to leaf\n");
					rootToLeafPath(root);
					break;
					
			case 48:printf("\nDouble tree.");
					root = doubleTree(root);
					break;

			case 49:printf("\nPrint sorted list from a given array notation of a binary tree.");
					printSortedBTNonRecursive(arr1,size1);
					break;

			case 50:printf("\nPrint sorted list from a given array notation of a binary tree.");
					printSortedBTRecursive(arr1,0,size1);
					break;

			case 51:printf("\nPrint nodes at level k in a given array notation of a tree (Recursively)");
					printf("\nEnter the level.");
					scanf("%d",&level);
					printAtLevelK(root,level);
					break;

			case 52:printf("\nCheckFoldable");
					if(root==NULL || checkFoldable(root->lchild, root->rchild))
						printf("\nIts a foldable tree.");
					else
						printf("\nIts not a foldable tree.");
					break;
					
			case 53:root = createTree(arr1,size1,0);
					display_recursion(root);
					break;
					
			case 54:printf("\nEnter the value of k.");
					scanf("%d",&sum);
					printf("Your kth largest value is ");
					k_thLargest(root, &sum);
					printf("\nYour kth largest value is ");
					printf("%d",k_thLargest1(root, &sum));
					break;

			case 55:printf("\nEnter the value of k.");
					scanf("%d",&sum);
					printf("Your kth smallest value is ");
					k_thSmallest(root, &sum);
					break;
			
			case 56:printf("\nFinding the maximum width of a tree.");
					findWidth(root);
					break;
				
			case 57:printf("\nPrint all root to leaf nodes.");
					printAllPath(root,arr1,0);
					break;

			case 58:printf("\nPrint spiral tree.");
					spiralTree(root);
					break;

			case 59:printf("\nEnter the value of key.");
					scanf("%d",&key);
					key--;
					printf("\nEnter the value of pivot node.");
					scanf("%d",&info);
					printf("\nPrint all nodes at distance of k.");
					PrintAllNodesAtDistanceK(root,info,&key);
					break;
					
			case 60: printf("\nCreating an ordianry tree from an array of size =%d.",sizee);
					 root = createOrdinaryTree(arr,sizee);
					 break;
					 
			case 61:printf("Lowest Common Ancestor in a Binary Search Tree.");
					printf("\nEnter the value of n1.");
					scanf("%d",&left);
					printf("\nEnter the value of n2.");
					scanf("%d",&right);
					findAncestor(root,left,right);
					break;

			case 62 : printf("\nThe sum of all keys greater than a key is added to that key.");
					  add(root);
					  break;
					  
			case 63: printf("all root to leaf path with sum = sum");
					root = createBTfromArray(root,arr1,size1);
					display_non_recursion(root);
					printf("\nresult   %d  : ",printff(root, 165));
					break;
			
			case 64 : printf("\nPrint the vertical traversal of a tree");
					root = createBTfromArray(root,arr1,size1);
					display_non_recursion(root);
					vert(root);
					break;
					  
			case 65 : printf("\nPrint all nodes at a distance of k from all leaf nodes.");
					root = createBTfromArray(root,arr1,size1);
					display_non_recursion(root);
					int j = 0;
					int out[10] = {0};
					printf("\nPrinting result");
					printatdistancek(root, out, 0, 2);
					break;
					
			case 66: printf("\nprint all the nodes which are at a distance of k from a given node.");
					root = createBTfromArray(root,arr1,size1);
					display_non_recursion(root);
					printf("\nPrinting result");
					int p = 0;
					printAtDistancekFromGivenNode(root, 30, 4, &p);
					break;
					  
			case 67: printf("\nPrint the kth largest element.");
					root = createBTfromArray(root,arr1,size1);
					display_non_recursion(root);
					printf("\nkth largest element");
					int pp = 12;
					pringd(root, &pp);
					break;
					
			case 68: printf("\nOriginal array");
					 printf("\nInorder : ");
					 printArray(inorder68, size68);
					 printf("\nlevel order traversal : ");
					 printArray(level68, size68);
					 root = createTreeFromInAndLevel(inorder68, level68, size68);
					 display_non_recursion(root);
					 break;

			case 69: printf("\nCommon Ancestor");
					 printf("\nEnter your number1 >  ");
					 scanf("%d", &n1);
					 printf("Enter your number2 >  ");
					 scanf("%d", &n2);
					 display_non_recursion(root);
					 flag1 = flag2 = 0;
					 result = commonAncestor(root, n1, n2, &flag1, &flag2);
					 if(flag1 && flag2 && result)
						printf("\n$$$$$$$$$$$$$$$$$$$Common ancestor is = %d", result->info);
					 else
						printf("\nNo ancestor");
					 break;

			case 70: printf("\nDistance between two nodes in a binary tree.");
					 printf("\nEnter your number1 >  ");
					 scanf("%d", &n1);
					 printf("Enter your number2 >  ");
					 scanf("%d", &n2);
					 display_non_recursion(root);
					 printf("The distance between %d and %d is %d", n1, n2, findDistance(root, n1, n2));
					 break;

			case 71: printf("\nPrinting tree vertically");
					 printf("\nPrinting from method 1");
					 printTreeVertical1(root);
					 printf("\nPrinting from method 2");
					 printTreeVertical2(root);
					 break;

			case 72: printf("\nCreate a tree from inorder and level order traversal");
					 root = createTreeFromInAndLevel(inptr, levelptr, size15);
					 display_non_recursion(root);
					 break;

			case 73:printf("\nEnter the value of key.");
					scanf("%d",&key);
					printf("\nEnter the value of pivot node.");
					scanf("%d",&info);
					printf("\nPrint all nodes at distance of k.");
					printAtDistanceOfKFromGivenNode(root,&key, info);
					break;

			case 74: printf("Add value of all nodes greater than the current node");
					size = 0;
					addAllKeysGreaterThanTheCurrentKey(root, &size);
					display_recursion(root);
					break;

			case 75: printf("\nFind all nodes in tree which dont have a sibling");
					findNonSiblingNode(root);
					break;
			case 76: printf("\nPrint a tree in zig zag order.");
					printZigZag(root);
					break;

			case 77: printf("\nPrint boundary elements in a tree:  ");
					printBoundaryElements(root);
					break;
					
			case 78: printf("\ncreate a tree from preorder traversal");
//					 root = createTreeFromPreOrderTraversal({1,2,3,4,5}, size);
	//				 display_recursion(root);
					 break;
			case 79: printf("\nInorder successor of a node in a tree.");
					 printf("\nEnter your number.");
					 scanf("%d", &key);
					 display_recursion(root);
					 inSuccessor = NULL;
					 inSucc(root,key, &inSuccessor);
					 printf("\nInorder successor = : %d ", inSuccessor->info);
					 break;
					
			case 80: printf("Convert a doubly linked list to a binary tree.");
					root = binaryToDLL(root);
					while(root->lchild != NULL)
						root = root->lchild;
					ptr1 = root;
					printf("\nYour doubly linked list is as follows : ");
					while(root!=NULL)
					{
						count++;
						printf("  %2d  ",root->info);
						root = root->rchild;
					}
					root = DLLToBinary(&ptr1, count);
					display_recursion(root);
					break;
					
			case 81: printf("\nconvert a tree to preorder traversal linked list.");
					display_recursion(root);
					createPreorder(root);
					break;
			
			case 83: display_recursion(root);
			getMaxChainLength(root, 0, 0, &resultantRoot, &maxChainLength);
			printf("\nMax chain length in a tree: %d\n", maxChainLength);
					printf("\nThe node is : %d\n\n", resultantRoot->info);
					break;
					
			case 84: display_recursion(root);
					 addToRightWrapper(root);
					 display_recursion(root);
					 break;
					 
			case 85: display_recursion(root);
					 diagonalSumWrapper(root);
					 display_recursion(root);
					 break;
			
			case 86 :printf("Creating binary tree from given array.");
					root = createBinaryTreeFromArray(arr1,size1);
					display_non_recursion(root);
					break;

			case 87 : root = createBinaryTreeFromArray(arr1,size1);
					display_non_recursion(root);printf("\n\nFinding Biggest binary search tree.");
					printf("\nMin = %d, ", INT_MIN);
					printf("\nMax = %d, ", INT_MAX);
					root = getBiggestBinarySearchTree(root);
					break;

			default : printf("\nBad choice.");
					  break;
		}
	}
}


