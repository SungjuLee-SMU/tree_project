#include <iostream>
using namespace std;
#define SN 10;
#define MAXNODE 100 

typedef struct node
{
	int Data;
	node* LChild;
	node* RChild;
}node;
typedef node* Nptr;

Nptr Search(Nptr T, int Key)
{
	if (T == NULL) {
		cout << "Empty";
		return T;
	}
	else if (T->Data == Key)
		return T;
	else if (T->Data > Key)
		Search(T->LChild, Key);
	else
		Search(T->RChild, Key);
}

void Destroy(Nptr T) {
	if (T != NULL) {
		Destroy(T->LChild);
		Destroy(T->RChild);
		free(T);
	}
}

void PreOrder(Nptr T)
{
	if (T != NULL) {
		cout << T->Data << " ";
		PreOrder(T->LChild);
		PreOrder(T->RChild);
	}
}

void InOrder(Nptr T)
{
	if (T != NULL) {
		InOrder(T->LChild);
		cout << T->Data << " ";
		InOrder(T->RChild);
	}
}

void PostOrder(Nptr T)
{
	if (T != NULL) {
		PostOrder(T->LChild);
		PostOrder(T->RChild);
		cout << T->Data << " ";
	}
}

void SuccessorCopy(Nptr& T, int& Key)
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


void Delete(Nptr& T, int Key)
{
	if (T == NULL)
		cout << "Empty";
	else if (T->Data > Key)
		Delete(T->LChild, Key);
	else if (T->Data < Key)
		Delete(T->RChild, Key);
	else if (T->Data == Key) {
		if (T->LChild == NULL && T->RChild == NULL) {//자식x
			Nptr Temp = T;
			T = NULL;
			delete Temp;
		}
		else if (T->LChild == NULL) {				 //자식 하나만, 근데 오른쪽
			Nptr Temp = T;
			T = T->RChild;
			delete Temp;
		}
		else if (T->RChild == NULL) {			 	//자식 하나만, 근데 왼쪽
			Nptr Temp = T;
			T = T->LChild;
			delete Temp;
		}
		else										 //자식 2개
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
	else if (T->Data > Key) //키값이 작으면 왼쪽
		T->LChild = Insert(T->LChild, Key);
	else					//키값이 크면 오른쪽
		T->RChild = Insert(T->RChild, Key);
	return T;
}

Nptr create(int S[]) {
	Nptr Root = NULL;
	Root = Insert(Root, S[0]);
	for (int i = 1; i < 10; i++)
		Insert(Root, S[i]);
	return Root;
}

int main() {
	Nptr BT = NULL;
	int S[10] = { 6,4,8,3,5,7,9,1,2,10 };

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

	return 0;
}