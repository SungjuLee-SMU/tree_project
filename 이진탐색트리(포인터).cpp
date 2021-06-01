#include "이진탐색트리 포인터.h"
#define SN 10;

Nptr Search(Nptr T, int Key)
{
	if (T == NULL) {
		printf("No Such Node");
		return T;
	}
	else if (T->Data == Key)
		return T;
	else if (T->Data > Key)
		return Search(T->LChild, Key);
	else
		return Search(T->RChild, Key);
}
void PreOrder(Nptr Root)
{
	if (Root == NULL)
	{
		return;
	}

	cout << Root->Data << endl;
	preorder(Root->LChild);
	preorder(Root->RChild);
}


void InOrder(Nptr Root)
{
	if (Root == NULL)
	{
		return;
	}
	inorder(Root->LChild);
	cout << Root->Data << endl;
	inorder(Root->RChild);
}

void PostOrder(Nptr Root)
{
	if (Root == NULL)
	{
		return;
	}
	postorder(Root->LChild);
	postorder(Root->RChild);
	cout << Root->Data << endl;
}

void SuccessorCopy(Nptr &T, int& Key)
{
	if (T->LChild == NULL)
	{ 
		Key = T->Data;
		Nptr Temp = T;
		T = T->RChild;
		delete Temp;
	}
	else
		SuccessorCopy(T->LChild, Key);
}


void Delete(Nptr &T, int Key)
{
	if (T == NULL)
		printf("No Record with Such Key");
	else if (T->Data > Key)
		Delete(T->LChild, Key);
	else if (T->Data < Key)
		Delete(T->RChild, Key);
	else if (T->Data == Key)
	{ 
		if ((T->LChild == NULL) && (T->RChild == NULL))
		{
			Nptr Temp = T; 
			T = NULL; 
			delete Temp;
		}
		else if (T->LChild == NULL)
		{
			Nptr Temp = T; 
			T = T->RChild; 
			delete Temp;
		}
		else if (T->RChild == NULL)
		{
			Nptr Temp = T; 
			T = T->LChild; 
			delete Temp;
		}
		else
		   SuccessorCopy(T->RChild, T->Data);
	}
}


Nptr Insert(Nptr T, int Key)
{
	if (T == NULL)
	{
		T = new node;
		T->Data = Key;
		T->LChild = NULL; 
		T->RChild = NULL;
	}
	else if (T->Data > Key)
		T->LChild = Insert(T->LChild, Key);
	else
		T->RChild = Insert(T->RChild, Key);
	return T;
}

Nptr create(int S[]) {
	Nptr Root = NULL;
	Root = Insert(Root, S[0]);
	for (int i = 1; i < 10; i++) {
		Insert(Root, S[i]);
	}
	return Root;
}

int main() {
	Nptr BT=NULL;
	int S[10] = {6,4,8,3,5,7,9,1,2,10};

	BT = create(S);
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

	Nptr Root = create(S);
	PostOrder(Root);
	return 0;
}