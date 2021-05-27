#include <iostream>
using namespace std;
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS 
#define MAXNODE 100 

typedef struct {
    char Name[50];
    int LChild;
    int RChild;
} node;


void CreateTree(node Mytree[MAXNODE]) {
    for (int i = 0; i < MAXNODE; i++) {
        strcpy(Mytree[i].Name, "UnUsed");
        Mytree[i].LChild = -1;
        Mytree[i].RChild = -1;
    }

    strcpy(Mytree[0].Name, "±è");
    Mytree[0].LChild = 1;
    Mytree[0].RChild = 2;

    strcpy(Mytree[1].Name, "ÀÌ");
    Mytree[1].LChild = 3;
    Mytree[1].RChild = 4;

    strcpy(Mytree[2].Name, "¹Ú");
    Mytree[2].LChild = 5;
    Mytree[2].RChild = 6;

    strcpy(Mytree[3].Name, "ÃÖ");
    Mytree[3].LChild = 7;
    Mytree[3].RChild = -1;

    strcpy(Mytree[4].Name, "Á¤");
    Mytree[4].LChild = -1;
    Mytree[4].RChild = -1;

    strcpy(Mytree[5].Name, "°­");
    Mytree[5].LChild = -1;
    Mytree[5].RChild = -1;

    strcpy(Mytree[6].Name, "Á¶");
    Mytree[5].LChild = -1;
    Mytree[5].RChild = -1;

    strcpy(Mytree[7].Name, "À±");
    Mytree[5].LChild = -1;
    Mytree[5].RChild = -1;
}


void Traverse(int i, node Mytree[MAXNODE]) {
    if (strcmp(Mytree[i].Name, "UnUsed") != 0) {
        cout << Mytree[i].Name << endl;
        if (Mytree[i].LChild != -1) {
            Traverse(Mytree[i].LChild, Mytree);
        }
        if (Mytree[i].RChild != -1) {
            Traverse(Mytree[i].RChild, Mytree);
        }
    }
}


bool search(node Mytree[MAXNODE], char ch_name) {
    int i = 0;
    while (strcmp(Mytree[i].Name, "UnUsed") != 0) {
        if (*Mytree[i].Name == ch_name) {
            return true;
        }
        i++;
    }
    return false;
}

void Destroy(node* Mytree) {
    for (int i = 0; i < MAXNODE; i++) {
        strcpy(Mytree[i].Name, "UnUsed");
        Mytree[i].LChild = -1;
        Mytree[i].RChild = -1;
    }
}

int main() {
    node Mytree[MAXNODE];
    CreateTree(Mytree);
    Traverse(0, Mytree);

    //search True = 1 False = 0
    cout << search(Mytree, 'À±');
    //Destroy 
    Destroy(&Mytree[0]);

    Traverse(0, Mytree);

    return 0;
}
