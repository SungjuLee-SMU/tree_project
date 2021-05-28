#include "이진탐색트리 포인터.h"
#define SN 10;

Nptr Search(Nptr T, int Key)
{
	if (T == NULL)
	{
		cout << "No Such Node" << endl;
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

void SuccessorCopy(Nptr &T, int &Key)
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

Nptr create(int S[], Nptr T, int i)
{
	if (T == NULL)
	{
		Nptr T = new node;
		T->Data = S[i];
		T->LChild = NULL;
		T->RChild = NULL;
		return T;
	}

	else if (T->Data > S[i])
	{
		T->LChild = create(S, T->LChild, i);
		return T;
	}

	else
	{
		T->RChild = create(S, T->RChild, i);
		return T;
	}
}

void DestroyTree(Nptr T)
{
	if (T->LChild != NULL)
	{
		DestroyTree(T->LChild);
	}

	if (T->RChild != NULL)
	{
		DestroyTree(T->RChild);
	}

	T = NULL;
	T->LChild = NULL;
	T->RChild = NULL;

	free(T);
}

int main()
{
	int S[10] = {6, 4, 8, 3, 5, 7, 9, 1, 2, 10};
	int length = sizeof(S) / sizeof(S[0]);

	Nptr BT = new node;
	BT->Data = S[0];
	BT->LChild = NULL;
	BT->RChild = NULL;

	for (int i = 1; i < length; i++)
	{
		BT = create(S, BT, i);
	}

	// PreOrder(BT);
	// cout << endl;

	// InOrder(BT);
	// cout << endl;

	// PostOrder(BT);
	// cout << endl;

	// Delete(BT, 4);
	// PreOrder(BT);
	// cout << endl;

	// Delete(BT, 9);
	// PreOrder(BT);
	// cout << endl;

	// Delete(BT, 1);
	// PreOrder(BT);
	// cout << endl;

	// Delete(BT, 5);
	// PreOrder(BT);
	// cout << endl;

	DestroyTree(BT);
	InOrder(BT);
	cout << endl;

	return 0;
}