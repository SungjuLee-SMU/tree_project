// dataStructure_prac13_BinSearchTree.cpp
#include <iostream>

using namespace std;

typedef struct node {
    int data;
    node *lchild;
    node *rchild;
}node;

typedef node* nptr;

nptr insert(nptr T, int Key) {
    if (T == NULL) {
        T = new node;
        T->data = Key;
        T->lchild = NULL;
        T->rchild = NULL;
    }
    else if(T->data > Key)
        T->lchild = insert(T->lchild, Key);
    else
        T->rchild = insert(T->rchild, Key);
    return T;
}

void SuccessorCopy(nptr &T, int &Key) {
    if(T->lchild == NULL) {
        Key = T->data;
        nptr Temp = T;
        T = T->rchild;
        delete Temp;
    }
    else 
        SuccessorCopy(T->lchild, Key);
}

nptr Delete(nptr &T, int Key) {
    if(T == NULL)
        cout << "No Record with such key" << endl;
    else if(T->data > Key)
        Delete(T->lchild, Key);
    else if(T->data < Key)
        Delete(T->rchild, Key);
    else if(T->data == Key) {
        if((T->lchild == NULL) && (T->rchild == NULL)) {
            nptr Temp = T;
            T = NULL;
            delete Temp;
        } 
        else if(T->lchild == NULL) {
            nptr Temp = T;
            T = T->rchild;
            delete Temp;
        }
        else if(T->rchild == NULL) {
            nptr Temp = T;
            T = T->lchild;
            delete Temp;
        }
        else 
            SuccessorCopy(T->rchild, T->data);
    }
}

nptr Search(nptr &T, int Key) { 
	if (T != NULL) {
        if(T->data > Key)
            return Search(T->lchild, Key);
        else if(T->data < Key)
            return Search(T->rchild, Key);
        else
            return T;
    } 
    else {
        cout << "No Record with such key" << endl;
        return NULL;
    }    
}

void Destroy(nptr &T) { 
  if (T != NULL) {  
    Destroy(T->lchild);
    Destroy(T->rchild);
    delete T;
  }
}

void PreOrder(nptr T) {
    if(T != NULL) {
        cout << T->data << ' ';
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

void InOrder(nptr T) {
    if(T != NULL) {
        InOrder(T->lchild);
        cout << T->data << ' ';
        InOrder(T->rchild);
    }
}

void PostOrder(nptr T) {
    if(T != NULL) {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        cout << T->data << ' ';
    }
}

nptr create(int S[]) {
    nptr Root = NULL;
    Root = insert(Root,S[0]);
    for(int i = 1; i < 10; i++)
        insert(Root,S[i]);
    return Root;
}

int main(void) {
    nptr BT = NULL;
    int S[10] = { 6, 4, 8, 3, 5, 7, 9, 1, 2, 10 };
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

    nptr Search_Node = Search(BT, 3);
    cout << Search_Node->data << endl;

    nptr Search_Node2 = Search(BT, 0);

    Destroy(BT);

    return 0;

}