#include "이진탐색트리 포인터.h"
#define SN 10;



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
	else Insert(PQ->Root, key, Data);
}

Nptr MinTree(Nptr T) {
	Nptr temp = T;
	while (temp->LChild != NULL)
		temp = temp->LChild;

	return temp;

}

int Dequeue(Nptr& T) {
	int min = 0;
	min = MinTree(T)->key;
	Delete(T, min);
	return (T)->Data;
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
	Enqueue(PQ, 1,10);
	Enqueue(PQ, 2,20);
	Enqueue(PQ, 10,100);
//	cout << Dequeue(PQ->Root);
//	cout << Dequeue(PQ->Root);


	return 0;
}