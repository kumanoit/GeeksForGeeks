#include"LinkedList.h"

void main()
{
	struct node *start = NULL;
	struct node *start1 = NULL;
	struct node *start2 = NULL;
	struct node *start3 = NULL;
	struct node *start4 = NULL;
	struct node *start5 = NULL;
	struct node *startResult = NULL;
	
    int arr[] = { 9,8,7,6,5,4,3,2,1}; // 42
//	int arr[] = {10,9,8,7,6,5,3,2,1};
//	int arr[] = { 1,2,3,2,1,2,3,2,1};
//	int arr[] = {13,2,63,-4,38,52,6,5,-44,3,42,1};
	int size = (sizeof(arr)/sizeof(arr[0]));
	int arr1[] = {1,35,72,0,9,45,11};
	int size1 = (sizeof(arr1)/sizeof(arr1[0]));
	int arr2[] = {2,41,6};//,18,110,12,214};
	int size2 = (sizeof(arr2)/sizeof(arr2[0]));
	int arr3[] = {2,44,-6,8,-10,32,-14,16,18};
	int size3 = (sizeof(arr3)/sizeof(arr3[0]));
	int arr4[] = {7,5,9,4,6};
	int size4 = (sizeof(arr4)/sizeof(arr4[0]));
	int arr5[] = {8,4};
	int size5 = (sizeof(arr5)/sizeof(arr5[0]));
	
	
	char choice;
	int num,num1,num2;
	int count;
	int k;
	int N, M;
	
	while(1)
	{
/*		printf("\nMenu List");
*/		printf("\n 1: Create a list from a given array.");
		printf("\n 2: Create a list from some random numbers.");
		printf("\n48: display.");	
/*		printf("\n 3. Search");
		printf("\n 4: Reverse a linked list.");
		printf("\n 5: Sort a linked list (Counting sort - exchanging information)");
		printf("\n 6: Sort a linked list (Bubble sort - exchanging information)");
		printf("\n 7: Sort a linked list (Counting sort - exchanging links)");
		printf("\n 8: Sort a linked list (Counting sort - exchanging links)");
		printf("\n 9: Create a single linked list that is reverse of a given linked list. (Ques 5 pg 105 in DS)");
		printf("\n10: Swap adjacent number using information.(Ques 6 pg 105 in DS)");
		printf("\n11: Swap adjacent number using link.(Ques 6 pg 105 in DS)");
		printf("\n12: Swap first and last element in linked list.(by information) (ques 8 		pg 105 in DS)");
		printf("\n13: Swap first and last element in linked list.(by links) (ques 8 pg 105 in DS)");
		printf("\n14: Move largest element to the end.(ques 9 pg 105 in DS)");
		printf("\n15: Move smallest to beginning.(ques 10 pg 105 in DS)");
		printf("\n16: Delete all occurrences of a given element.");
		printf("\n17: Print elements of second list acording to first list.");
		printf("\n18: Move a pointer n positions forward.(ques15 on 105)");
		printf("\n19: Insert a node before and after a pointer.(ques17 on 105)");
		printf("\n20: Delete all nodes in a linked list.(ques18 on 106)");
		printf("\n21: Delete all duplicate nodes in a sorted linked list.(ques19 on 106)");
		printf("\n22: Delete all duplicate nodes in an unsorted linked list.(ques20 on 106))");
		printf("\n23: Intersection of two linked lists.(ques21 on 106)");
		printf("\n24: Union of two linked list.(ques22 on 106)");
		printf("\n25: Separate +ve and -ve nodes.(ques23 on 106)");
		printf("\n26: Delete alternate nodes in a linked list.(ques25 on 106)");
		printf("\n27: Print the nth element from end.(ques26 on 106)");
		printf("\n28: Detect a cycle in a linked list.(ques27 on 106)");
		printf("\n29: Print the middle element without counting all elements in a single pass. (ques 28 on 106)");
		printf("\n30: Combine alternate nodes in a linked list.(ques32 on 106)");
		printf("\n31: Check a linked list whether it is a palindrome or not.(ques36 on 106)");
		printf("\n32: Find a triplet from three linked lists summing equal to a given number. (GFG)");
		printf("\n33: Add two numbers represented by linked list.(GFG)");
		printf("\n34: Segregate even and odd nodes in a Linked List (GFG)");		
		printf("\n35: Delete nodes which have a greater value on right side. (GFG)");
		printf("\n36: ReversePENDING alternate K nodes in a Singly Linked List (GFG)");
		printf("\n37: Delete alternate nodes in a linked list recursively. GFG");
		printf("\n38: Reverse a Linked List in groups of given size GFG");
		printf("\n39: Merge two sorted Linked Lists GFG");
		printf("\n40: Reverse a Linked List recursively GFG");
		printf("\n41: Check if a LL is palindrome or not GFG");
		printf("\n42: Given a linked list, reverse alternate nodes and append at the end");
		printf("\n43: Reversing linked list in pairs.");
		printf("\n44: Reverse alternately.");
*/		printf("\n45: Swap pairwise.");
		printf("\n46: Reverse alternate node and append at last."); 
		printf("\n47: Quicksort in a linked list.");
		printf("\n49: Swap kth node from beginning and from end");
		printf("\n52: Delete N nodes after M nodes in a linked List");
		printf("\nEnter your choice: ");
		scanf("%d",&num);
		
// The dance begins from here.
		switch(num)
		{
			case  1:start = create(start,arr,size);
					display(start);
					break;

			case  2:printf("\nEnter the number of elements that you want in your list.");
					scanf("%d",&count);
					start = createRandom(start,count);
					display(start);
					break;
					
			case  3: printf("\nEnter the number to be searched.");		
					 scanf("%d",&num);
					 start = create(start,arr,size);
					 search(start,num);
					 break;
				
			case  4: printf("\nPresent Linked list.");
					start = create(start,arr,size);
					display(start);
					printf("\nReversed Linked list.");
					start = reverse(start);
					break;
			
			case  5: printf("Count sorting exchanging informations");
					printf("\nPresent Linked list.");
					start = create(start,arr,size);
					display(start);
					printf("\nSorted Linked list.");
					countSortExchangingInfo(start);
					break;
			
			case  6: printf("Bubble Sort exchanging informations");
					printf("\nPresent Linked list.");
					start = create(start,arr,size);
					display(start);
					printf("\nSorted Linked list.");
					bubbleSortExchangingInfo(start);
					break;
					
			case  7: printf("Count sorting exchanging links");
					printf("\nPresent Linked list.");
					start = create(start,arr,size);
					display(start);
					printf("\nSorted Linked list.");
					start = countSortExchangingLinks(start);
					display(start);
					break;
				
			case  8: printf("Bubble Sort exchanging links");
					 printf("\nPresent Linked list.");
					 start = create(start,arr,size);
					 display(start);
					 printf("\nSorted Linked list.");
					 start = bubbleSortExchangingLinks(start);
					 break;
						
			case  9: printf("Reversing the list in another array.");
					 printf("\nPresent Linked list.");
					 start = create(start,arr,size);
					 display(start);
				  	 createReverse(start);
					 break;

			case 10: printf("Swapping the list by information field.");
					 printf("\nPresent Linked list.");
					 start = create(start,arr,size);
					 display(start);
				  	 swapInfo(start);
					 printf("\nAfter swapping.");
					 display(start);
					 break;

			case 11: printf("Swapping the list by links.");
					 printf("\nPresent Linked list.");
					 start = create(start,arr,size);
					 display(start);
				  	 start = swapLink(start);
					 printf("\nAfter swapping link.");
					 display(start);
					 break;
		
			case 12: printf("Swapping the first & last elements by informations.");
					 printf("\nPresent Linked list.");
					 start = create(start,arr,size);
					 display(start);
				  	 swapFirstLastInfo(start);
					 printf("\nAfter swapping link.");
					 display(start);
					 break;
					 
			case 13: printf("Swapping the list by links.");
					 printf("\nPresent Linked list.");
					 start = create(start,arr,size);
					 display(start);
				  	 start = swapFirstLastLink(start);
					 printf("\nAfter swapping link.");
					 display(start);
					 break;

			case 14: printf("\nLargest element to the end.");
					 printf("\nPresent Linked list.");
					 start = create(start,arr,size);
					 display(start);
				  	 start = largestToLast(start);
					 printf("\nAfter swapping link.");
					 display(start);
					 break;		 

/*			case 14: printf("\nLargest element to the end.");
					 printf("\nPresent Linked list.");
					 start = create(start,arr,size);
					 display(start);
				  	 start = largestToLast(start);
					 printf("\nAfter swapping link.");
					 display(start);
					 break;		 
*/					 
			case 15: printf("\nLargest element to the end.");
					 printf("\nPresent Linked list.");
					 start = create(start,arr,size);
					 display(start);
				  	 start = smallestToBeginning(start);
					 printf("\nAfter swapping link.");
					 display(start);
					 break;		 

			case 16: start = create(start,arr,size);
					 display(start);
					 printf("\nEnter the number to be deleted.");		
					 scanf("%d",&num);
					 start = deleteAllOccurences(start,num);
					 printf("\nAfter deleting all links.");
					 display(start);
					 break;

			case 17: start1 = create(start1,arr1,size1);
					 display(start1);
					 start2 = create(start2,arr2,size2);
					 display(start2);
					 printf("\nHere it goes.");		
					 printAccordingly(start1,start2);
					 break;
		
			case 18: start2 = create(start2,arr,size);
					 display(start2);
					 printf("\nEnter the number of positions	to be moved forwarded");		
					 scanf("%d",&num);
					 moveByNpos(start2,num);
					 printf("\nAfter repostioning.");
					 display(start2);
					 break;
					 
			case 19: start2 = create(start2,arr,size);
					 display(start2);
					 printf("\nEnter the number to be inserted before.");		
					 scanf("%d",&num1);
					 printf("\nEnter the number to be inserted after.");		
					 scanf("%d",&num2);
					 insertBeforeAndAfter(start2,num1,num2);
					 printf("\nAfter insertion.");
					 display(start2);
					 break;

			case 20: printf("\nPresent Linked list.");
					 start = create(start,arr,size);
					 display(start);
				  	 start = destroy(start);
					 printf("\nAfter deleting all nodes.");
					 display(start);
					 break;		 

			case 21: printf("\nPresent Linked list.");
					 start = create(start,arr,size);
					 display(start);
				  	 start = deleteDuplicateSorted(start);
					 printf("\nAfter deleting duplicate.");
					 display(start);
					 break;		 

			case 22: printf("\nPresent Linked list.");
					 start = create(start,arr,size);
					 display(start);
				  	 start = deleteDuplicateUnsorted(start);
					 printf("\nAfter deleting duplicate.");
					 display(start);
					 break;		 

			case 23: printf("\nPresent Linked list.");
					 start1 = create(start1,arr1,size);
					 display(start1);
					 start2 = create(start2,arr2,size);
					 display(start2);
				  	 start3 = intersection(start1, start2);
					 printf("\nIntersection");
					 display(start3);
					 break;		 

			case 24: printf("\nPresent Linked list.");
					 start1 = create(start1,arr1,size);
					 display(start1);
					 start2 = create(start2,arr2,size);
					 display(start2);
				  	 start3 = unionn(start1, start2);
					 printf("\nUnion");
					 display(start3);
					 break;	
					 
			case 25: printf("\nPresent Linked list.");
					 start = create(start,arr,size);
					 display(start);
				  	 start = separate(start);
					 printf("\nAfter separation.");
					 display(start);
					 break;	
				 
			case 26: printf("\nPresent Linked list.");
					 start = create(start,arr,size);
					 display(start);
				  	 start = deleteAlternate(start);
					 printf("\nAfter deletion.");
					 display(start);
					 break;	
					 
			case 27: printf("\nPresent Linked list.");
					 start = create(start,arr,size);
					 display(start);
					 printf("\nEnter the value of n.");
					 scanf("%d",&num);
				  	 printNthFromEnd(start,num);
					 break;		 

			case 28: printf("\nPresent Linked list.");
					 start = create(start,arr,size);
					 display(start);
					 printf("\nDetecting Cycle");
				  	 detectCycle(start);
					 break;		 

			case 29: printf("\nPresent Linked list.");
					 start = create(start,arr,size);
					 display(start);
					 printf("\nMiddle element");
				  	 printMiddle(start);
					 break;		 

			case 30: printf("\nPresent Linked list.");
					 start1 = create(start1,arr1,size1);
					 display(start1);
					 start2 = create(start2,arr2,size2);
					 display(start2);
				  	 start3 = combineAlternate(start1, start2);
					 printf("\nCombining alternate nodes.");
					 display(start3);
					 break;		 

			case 31: start = create(start,arr,size);
					 checkPalindrome(start);
					 break;		 

			case 32: start1 = create(start1, arr1, size1);
					 start2 = create(start2, arr2, size2);
					 start3 = create(start3, arr3, size3);
					 display(start1);
					 display(start2);
					 display(start3);
					 printf("\nEnter the sum.");
					 scanf("%d",&num);
					 findThreeNumbers(start1, start2, start3,num);					 
					 break;
					 
			case 33: start4=create(start4, arr4, size4);
					 start5=create(start5, arr5, size5);
					 display(start4);
					 display(start5);
					 startResult = addNumbers(start4, start5);
					 display(startResult);
					 break;

			case 34: start = create(start,arr,size);
					 display(start);
					 startResult = segregate(start);
					 display(startResult);
					 break;

					 
			case 35: start = create(start, arr, size);
					 display(start);
					 startResult = deleteGreaterNode(start);
					 display(startResult);
					 break;
					 
			case 36: start = create(start, arr, size);
					 display(start);
					 printf("\nEnter the value of k. ");
					 scanf("%d",&num);
					 startResult = reverseAlternateKNode(start,num,1);
					 display(startResult);
					 break;
					 
			case 37: start = create(start, arr, size);
					 display(start);
					 start = deleteAlternateNode(start);
					 display(start);
					 break;

			case 38: start = create(start, arr2, size);
					 display(start);
					 printf("\nEnter the value of k. ");
					 scanf("%d",&num);
					 startResult = reverseInGroupOfKNode(start,num);
					 display(startResult);
					 break;
					 
			case 39: start1 = create(start1, arr1, size1);
					 start2 = create(start2, arr2, size2);
					 display(start1);
					 display(start2);
					 printf("\nMerging");
					 start1 = countSortExchangingLinks(start1);
					 start2 = countSortExchangingLinks(start2);
					 display(start1);
					 display(start2);
					 startResult = merge(start1, start2);
					 display(startResult);
					 break;

			case 40: start = create(start, arr, size);
					 display(start);
					 startResult = reverseRecursively(start);
					 display(startResult);
					 break;					 
					 
			case 41:printf("\nChecking if the LL is palindrome or not."); 
					display(start);
					if(isPalindrome(&start,start))
						printf("\nThe given LL is palindrome.");
					else
						printf("\nNo the LL is not palindrome");
					break;	
					
			case 42: printf("Original LL\n");
					display(start);
					start = reverseAlternateNodes(start);
					printf("After reversal");
					display(start);
					break;
			
			case 43: printf("\nOriginal linked list");
					display(start);
					start = reverseInPair(start);
					printf("\nAfter reversal");
					display(start);
					start = pairWiseSwap(start);
					printf("\nAfter reversal");
					display(start);
					break;
					
			case 44: start1 = create(start1, arr1, size1);
					 printf("\nLinked list >> 1 ");
					 display(start1);
					 start2 = create(start2, arr2, size2);
					 printf("\nLinked list >> 2 ");
					 display(start2);
					 start = mergeLlAlternately(start1, start2);
					 printf("\nAfter merging");
					 display(start);
					 printf("\n\n\n");
					 break;
			
			case 45: printf("\nBefore swapping");
					display(start);
					start = pairwiseSwap2(start);
					printf("\nAfter swapping.");
					display(start);
					break;
					
			
			case 46: printf("\nReverse alternate node and append at last.");
					display(start);
					start = reverseAlternate(start);
					printf("\nAfter reversing.");
					display(start);
					break;

			case 47: printf("\nQuick sort");
					display(start);
					start = QuickSort(start);
					display(start);
					break;
					
			case 48: display(start);
					break;
					
			case 49:printf("\n Swapping kth node.");
					printf("\nEnter the value of k : ");
					scanf("%d", &k);
					display(start);
					start = swapKfromBegEnd2(start, k);
					display(start);
					printf("\n\n\n\n\n\n");
					break;
			case 50: printf("\nMerge sort");
					 start = mergeSort(start);
					 display(start);
					 break;
			
			case 51: printf("\nMerge alternately.");
					 start1 = create(start1,arr1,size1);
					 display(start1);
					 start2 = create(start2,arr2,size2);
					 display(start2);
				  	 display(mergeAlternately(start1, start2));
					 break;
					 
			case 52: printf("\nN = ");
					 scanf("%d", &N);
					 printf("\nM = ");
					 scanf("%d", &M);
					printf("\nDeleting n nodes after m nodes in a linked list.");
					deleteMAfterN(start, N, M);
					display(start);
					break;

			default:printf("\nPoor choice.");
					break;
		}
	}

}



