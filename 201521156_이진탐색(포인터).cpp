#include "이진탐색트리 포인터.h"
#define SN 10;

Nptr Search(Nptr T, int Key)
{
	if (T == NULL) {
		printf("노드를 찾을수 없습니다.");
		return T;
	}
	else if (T->Data == Key)
		return T;
	else if (T->Data > Key)
		return Search(T->LChild, Key);
	else
		return Search(T->RChild, Key);
}
void PreOrder(Nptr T)
{
	if (T != NULL)
	{
		cout << T->Data << endl;
		PreOrder(T->LChild);
		PreOrder(T->RChild);
	}
}

void InOrder(Nptr T)
{
	if (T != NULL)
	{
		InOrder(T->LChild);
		cout << T->Data << endl;
		InOrder(T->RChild);
	}
}

void PostOrder(Nptr T)
{
	if (T != NULL)
	{
		PostOrder(T->LChild);
		PostOrder(T->RChild);
		cout << T->Data << endl;
	}
}

void SuccessorCopy(Nptr &T, int& Key)
{
	if (T->LChild == NULL) {
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
	if (T == NULL) {
		printf("키를 찾지 못했습니다.");
	}
	else if (T->Data > Key)
		Delete(T->LChild, Key);
	else if (T->Data < Key)
		Delete(T->RChild, Key);
	else if (T->Data == Key) {
		if ((T->LChild == NULL) && (T->RChild == NULL)) {
			Nptr Temp = T;
			T = NULL;
			delete Temp;
		}
		else if (T->LChild == NULL) {
			Nptr Temp = T;
			T = T->RChild;
			delete Temp;
		}
		else if (T->RChild == NULL) {
			Nptr Temp = T;
			T = T->LChild;
			delete Temp;
		}
		SuccessorCopy(T->RChild, T->Data);
	}


}


Nptr Insert(Nptr T, int Key)
{
	if (T == NULL) {
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
	Nptr root = NULL;
	root = Insert(root, S[0]);
	for (int i = 1; i < 10; i++)
		Insert(root, S[i]);
	return root;
}

void Destroy(Nptr& T) {
	if (T != NULL)
	{
		Destroy(T->LChild);
		Destroy(T->RChild);
		Nptr temp = T;
		T = NULL;
		delete temp;
	}
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

	InOrder(BT);
	cout << endl;

	cout << "search 9 - ";
	cout << Search(BT, 9);
	cout << endl;

	cout << "destroy";
	Destroy(BT);
	InOrder(BT);
	delete BT;
	cout << endl;

	return 0;
}