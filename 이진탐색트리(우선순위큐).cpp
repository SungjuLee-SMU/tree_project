#include "이진탐색트리 포인터.h"
#define SN 10;

void PreOrder(Nptr T)
{
	if (T != NULL)
	{
		cout << T->Data << endl;
		PreOrder(T->LChild);
		PreOrder(T->RChild);
	}
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
	else if (T->key > Key)
		Delete(T->LChild, Key);
	else if (T->key < Key)
		Delete(T->RChild, Key);
	else if (T->key == Key)
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
		   SuccessorCopy(T->RChild, T->key);
	}
}


Nptr Insert(Nptr T, int Key, int Data)
{
	if (T == NULL)
	{
		T = new node;
		T->key = Key;
		T->Data = Data;
		T->LChild = NULL; 
		T->RChild = NULL;
	}
	else if (T->key > Key)
		T->LChild = Insert(T->LChild, Key, Data);
	else
		T->RChild = Insert(T->RChild, Key, Data);
	return T;
}

int LengthQueue(Nptr T) {
	int count = 0;
	if (T != NULL)
	{
		count++;
		cout << T->Data << endl;
		PreOrder(T->LChild);
		PreOrder(T->RChild);
	}
	return count;
}

Qptr MakePriorityQueue() {

	PriorityQueue *PQ;
	PQ = new PriorityQueue;
	PQ->Length = 0;
	PQ->Root = NULL;

	return PQ;
}
void Enqueue(Qptr PQ, int key, int Data) {
	if (PQ->Length == 0) {
		PQ->Root = Insert(PQ->Root, key, Data);
		PQ->Length++;
	}
	else {
		Insert(PQ->Root, key, Data);
		PQ->Length++;
	}
}

Nptr MinTree(Nptr T) {
	Nptr temp = T;
	while (temp->LChild != NULL)
		temp = temp->LChild;
	return temp;

}
int Dequeue(Qptr PQ) {
	Nptr min;
	int tempKey = 0;
	int tempData = 0;
	
	min = MinTree(PQ->Root);
	tempKey = min->key;
	tempData = min->Data;
	Delete(PQ->Root, min->key);
	PQ->Length--;
	return tempData;
}

int main() {
	PriorityQueue* PQ=NULL;
	int Skey[10] = {6,4,8,3,5,7,9,1,2,10};
	int SData[10] = {60,40,80,30,50,70,90,10,20,100};

	PQ = MakePriorityQueue();

	Enqueue(PQ, 6,60);
	Enqueue(PQ, 4,40);
	Enqueue(PQ, 8,80);
	Enqueue(PQ, 3,30);
	Enqueue(PQ, 5,50);
	Enqueue(PQ, 7,70);
	Enqueue(PQ, 9,90);
	Enqueue(PQ, 1,20000);
	Enqueue(PQ, 2,30000);
	Enqueue(PQ, 10,100);

	cout << "전위순회 " << endl;
	PreOrder(PQ->Root);
	cout << endl;

	cout << Dequeue(PQ) << endl;
	cout << Dequeue(PQ) << endl;
	cout << Dequeue(PQ) << endl;
	cout << Dequeue(PQ) << endl;
	cout << Dequeue(PQ) << endl;
	cout << Dequeue(PQ) << endl;
	cout << Dequeue(PQ) << endl;
	cout << Dequeue(PQ) << endl;
	cout << Dequeue(PQ) << endl;
	cout << Dequeue(PQ) << endl;
	
	cout << "전위순회 "<< endl;
	PreOrder(PQ->Root);
	cout << endl;


	return 0;
}