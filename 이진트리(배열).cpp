#include <iostream>
using namespace std;
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS 
#define MAXNODE 100 

typedef struct{ 
    char Name[50];
    int LChild;
    int RChild;
} node;

void CreateTree(node Mytree[MAXNODE]) {
    for (int i = 0; i < MAXNODE; i++) {
        strcpy(Mytree[i].Name, "UnUsed");
        Mytree[i].LChild=-1;
        Mytree[i].RChild=-1;
    }

    strcpy(Mytree[0].Name, "김");
    Mytree[0].LChild = 1;
    Mytree[0].RChild = 2;
    strcpy(Mytree[1].Name, "이");
    Mytree[1].LChild = 3;
    Mytree[1].RChild = 4;
    strcpy(Mytree[2].Name, "박");
    Mytree[2].LChild = 5;
    Mytree[2].RChild = 6;
    strcpy(Mytree[3].Name, "최");
    Mytree[3].LChild = 7;
    Mytree[3].RChild = -1;
    strcpy(Mytree[4].Name, "정");
    Mytree[4].LChild = -1;
    Mytree[4].RChild = -1;
    strcpy(Mytree[5].Name, "강");
    Mytree[5].LChild = -1;
    Mytree[5].RChild = -1;
    strcpy(Mytree[6].Name, "조");
    Mytree[5].LChild = -1;
    Mytree[5].RChild = -1;
    strcpy(Mytree[7].Name, "윤");
    Mytree[5].LChild = -1;
    Mytree[5].RChild = -1;
}

void Destroy(int i, node Mytree[MAXNODE])
{
    Mytree[i].LChild = NULL;
    Mytree[i].RChild = NULL;
}

void IsEmpty(node Mytree[MAXNODE])
{
    if (Mytree != NULL)
        printf("비어있지 않음");
    else
        printf("비어있음");
}

void Search(char S[], node Mytree[MAXNODE])
{
    for (int i = 0; i < MAXNODE; i++)
    {
        if (strcmp(Mytree[i].Name, S) == 0)
        {
            printf(" %s 있음", S);
        }
        else
            printf("없음");
        //Search(Mytree[i].LChild, Mytree);
        //Search(Mytree[i].RChild, Mytree);
    }
}

void Traverse(int i, node Mytree[MAXNODE]) {
    if (strcmp(Mytree[i].Name, "UnUsed") != 0){
        cout << Mytree[i].Name << endl;
        if (Mytree[i].LChild != -1) {
            Traverse(Mytree[i].LChild, Mytree);
        }
        if (Mytree[i].RChild != -1) {
            Traverse(Mytree[i].RChild, Mytree);
        }
    }
}

int main() {
    node Mytree[MAXNODE];
    CreateTree(Mytree);
    Traverse(0, Mytree);

    return 0;
}
