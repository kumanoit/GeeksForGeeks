/*
 * TreeNode.h
 *
 *  Created on: Jan 23, 2016
 *      Author: kuma
 */

#ifndef TREENODE_H_
#define TREENODE_H_



#endif /* TREENODE_H_ */

struct TreeNode {
	int value;
	struct TreeNode *leftChild;
	struct TreeNode *rightChild;
};

int isLeaf(struct TreeNode *root) {
	return root -> leftChild == NULL && root -> rightChild == NULL;
}
