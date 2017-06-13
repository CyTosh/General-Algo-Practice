// Tree Traversal
// Ref : GEEKSFORGEEKS

#include <stdio.h>
#include <stdlib.h>

struct BNode{
	int data;
	struct BNode *left;
	struct BNode *right;
};

struct BNode* getNode(int data){
	struct BNode *newNode = (struct BNode *)malloc(sizeof(struct BNode));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
}

void inOrder(struct BNode *current){
	if(current == NULL)
		return;
	inOrder(current->left);
	printf("%d", current->data);
	printf(" -> ");
	inOrder(current->right);
}

void preOrder(struct BNode *current){
	if(current == NULL)
		return;
	printf("%d", current->data);
	printf(" -> ");
	preOrder(current->left);
	preOrder(current->right);
}

void postOrder(struct BNode *current){
	if(current == NULL)
		return;
	postOrder(current->left);
	postOrder(current->right);
	printf("%d", current->data);
	printf(" -> ");
}

int main(){
	struct BNode *root = NULL;
	root = getNode(1);
	root->left  = getNode(2);
	root->right = getNode(3);
	root->left->left = getNode(4);
	root->left->right = getNode(5);

	preOrder(root);
	printf("\n");

	inOrder(root);
	printf("\n");

	postOrder(root);
	printf("\n");

	return 0;
}
