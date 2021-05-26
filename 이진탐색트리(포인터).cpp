#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct node {
	int data;
	struct node* rightChild;
	struct node* leftChild;
}Node;

typedef Node* treePointer;

treePointer Search(treePointer T, int Key);
treePointer Insert(treePointer T, int Key);
treePointer Create(int S[]);
void print(treePointer T);
void PreOrder(treePointer T);
void InOrder(treePointer T);
void PostOrder(treePointer T);
void SuccessorCopy(treePointer& T, int& Key);
void Delete(treePointer& T, int Key);



treePointer Search(treePointer T, int Key)
{
	if (T == NULL)
		printf("오류");
	else if (T->data == Key)
		return T;
	else if (T->data > Key)
		return Search(T->leftChild, Key);

	else
		return Search(T->rightChild, Key);
}

treePointer Insert(treePointer T, int Key)
{
	if (T == NULL) {
		T = new node;
		T->data = Key;
		T->leftChild = NULL;
		T->rightChild = NULL;
	}
	else if (T->data > Key) {
		T->leftChild = Insert(T->leftChild, Key);
	}
	else {
		T->rightChild = Insert(T->rightChild, Key);
	}
	return T;
}


treePointer Create(int S[]) {
	treePointer root = NULL;
	root = Insert(root, S[0]);
	for (int i = 0; i < 10; i++) {
		Insert(root, S[i]);
	}

	return root;
}


void print(treePointer T) {
	if (T == NULL)
		return;
	printf("%d ", T->data);
	print(T->leftChild);
	print(T->rightChild);
}

void PreOrder(treePointer T)
{
	if (T != NULL) {
		return;
	}
	printf("%d ", T->data);
	print(T->leftChild);
	print(T->rightChild);
}

void InOrder(treePointer T)
{
	if (T != NULL) {
		return;
	}
	print(T->leftChild);
	printf("%d ", T->data);
	print(T->rightChild);
}

void PostOrder(treePointer T)
{
	if (T != NULL) {
		return;
	}
	print(T->leftChild);
	print(T->rightChild);
	printf("%d ", T->data);
}

void SuccessorCopy(treePointer& T, int& Key)
{
	if (T->leftChild == NULL) {
		Key = T->data;
		treePointer Temp = T;
		T = T->rightChild;
		delete Temp;
	}
	else
		SuccessorCopy(T->leftChild, Key);
}


void Delete(treePointer& T, int Key)
{
	if (T == NULL)
		printf("오류");
	else if (T->data > Key)
		Delete(T->leftChild, Key);
	else if (T->data < Key)
		Delete(T->rightChild, Key);
	else if (T->data == Key) {
		if ((T->leftChild == NULL) && (T->rightChild == NULL)) {
			treePointer Temp = T;
			T = NULL;
			delete Temp;
		}
		else if (T->leftChild == NULL) {
			treePointer Temp = T;
			T = T->rightChild;
			delete Temp;
		}
		else if (T->rightChild == NULL) {
			treePointer Temp = T;
			T = T->leftChild;
			delete Temp;
		}
		else
			SuccessorCopy(T->rightChild, T->data);
	}
}






int main() {
	treePointer BT = NULL;
	int S[10] = { 6,4,8,3,5,7,9,1,2,10 };

	BT = Create(S);
	PreOrder(BT);
	cout << endl;

	InOrder(BT);
	cout << endl;

	PostOrder(BT);
	cout << endl;

	Delete(BT, 10);
	PreOrder(BT);
	cout << endl;

	Delete(BT, 9);
	PreOrder(BT);
	cout << endl;

	Delete(BT, 1);
	PreOrder(BT);
	cout << endl;

	Delete(BT, 5);
	PreOrder(BT);
	cout << endl;

	InOrder(BT);
	cout << endl;

	return 0;
}