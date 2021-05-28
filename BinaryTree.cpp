#include <iostream>
#include <string.h>
using namespace std;
#define MAX 50
#pragma warning(disable : 5208)

int num;

typedef struct {
	char data[20];
	int Lchild;
	int Rchild;
}node;
node Tree[MAX];

void Create(node Tree[MAX]) {
	Tree[0].Lchild = 0;
	Tree[0].Lchild = 1;
	cout << "Tree에 넣을 횟수(최대 50): ";
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> Tree[i].data; //0일 때, 1일 때, 2일 때,
		Tree[i].Lchild++;    //   1  ,    3  ,    5  ,
		Tree[i].Rchild++;    //   2  ,    4  ,    6  ,
	}
	cout << "Successfully Create" << endl;
}

void IsEmpty(node Tree[MAX]) {
	if (Tree->Lchild == 0)
		cout << "Is Empty" << endl;
	else
		cout << "Is Not Empty" << endl;
}

void Destroy(node Tree[MAX]) {
	free(Tree);
}

void Search(node Tree[MAX], int key) {
	cout << Tree[key].data << endl;
}

void Traverse(node Tree[MAX], int i) {
	if (strcmp(Tree[i].data, "UnUsed") != 0) {
		cout << Tree[i].data << endl;
		
		if (Tree[i].Lchild != 0) {
			Traverse(Tree, Tree[i].Lchild);
		}
		if (Tree[i].Rchild != 1) {
			Traverse(Tree, Tree[i].Rchild);
		}
		i++;
	}
}

int main() {
	node Tree[MAX];

	IsEmpty(Tree);
	Create(Tree);
	IsEmpty(Tree);
	Search(Tree, 2);
	Search(Tree, 0);
	Traverse(Tree, 0);
	Destroy(Tree);

	return 0;
}