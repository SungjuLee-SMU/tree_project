// dataStructure_prac12_CBT.cpp
#include <iostream>
#include <string>
using namespace std;
#define MAXNODE 100
typedef struct {
	string name;
	int Lchild;
	int Rchild;
}node;

struct Tree {
	int nodeNum;
	node* MyTree;
};

Tree* Create(){
	Tree* tree = new Tree;
	tree->nodeNum = 0;
	tree->MyTree = new node[MAXNODE];

	return tree; 
}

bool IsEmpty(Tree* tree){
	if ( tree->nodeNum == 0 )
		return true;
	else 
		return false;
}	

int Search (Tree* tree, string name) {
	for ( int i = 0; i < tree->nodeNum; i++ ) {
		if ( name.compare(tree->MyTree[i].name) == 0 )
			return i;
	}
	return -1;
}

void Traverse(Tree* tree, int i) {
	string unuse;
	unuse = "UnUsed";

	if ( unuse.compare(tree->MyTree[i].name) == 0 ){
		cout << tree->MyTree[i].name << endl;
		if ( tree->MyTree[i].Lchild != -1 ) {
			Traverse(tree, tree->MyTree[i].Lchild );
		} 

		if ( tree->MyTree[i].Rchild != -1 ){
			Traverse(tree, tree->MyTree[i].Rchild );
		}
	}
}

void Destroy(Tree* tree){
	delete[] tree->MyTree;
	delete tree;
}

int main(void){
	Tree* t = Create();

	cout << IsEmpty(t) << endl;

	t->MyTree[0].name = "Kim";
	t->nodeNum++;
	t->MyTree[0].Lchild = 1;
	t->MyTree[0].Rchild = -1;

	t->MyTree[1].name = "Ahn";
	t->nodeNum++;
	t->MyTree[1].Lchild = -1;
	t->MyTree[1].Rchild = -1;

	cout << IsEmpty(t) << endl;

	cout << Search(t, "Ahn") << endl;

	Traverse(t, 1);

	return 0;

}