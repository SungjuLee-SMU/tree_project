#include "이진탐색트리 포인터.h"
#define SN 10;

Nptr Search(Nptr T, int Key)
{

}
void PreOrder(Nptr T)
{

}

void InOrder(Nptr T)
{

}

void PostOrder(Nptr T)
{

}

void SuccessorCopy(Nptr &T, int& Key)
{

}


void Delete(Nptr &T, int Key)
{

}


Nptr Insert(Nptr T, int Key)
{

}

Nptr create(int S[]) {

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

	return 0;
}