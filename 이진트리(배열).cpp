#include <iostream>

using namespace std;
#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS
#define MAXNODE 100

typedef struct
{
    char Name[50];
    int LChild;
    int RChild;
} node;

void CreateTree(node Mytree[MAXNODE])
{
    for (int i = 0; i < MAXNODE; i++)
    {
        strcpy(Mytree[i].Name, "UnUsed");
        Mytree[i].LChild = -1;
        Mytree[i].RChild = -1;
    }

    strcpy(Mytree[0].Name, "AA");
    Mytree[0].LChild = 1;
    Mytree[0].RChild = 2;
    strcpy(Mytree[1].Name, "BB");
    Mytree[1].LChild = 3;
    Mytree[1].RChild = 4;
    strcpy(Mytree[2].Name, "CC");
    Mytree[2].LChild = 5;
    Mytree[2].RChild = 6;
    strcpy(Mytree[3].Name, "DD");
    Mytree[3].LChild = 7;
    Mytree[3].RChild = -1;
    strcpy(Mytree[4].Name, "EE");
    Mytree[4].LChild = -1;
    Mytree[4].RChild = -1;
    strcpy(Mytree[5].Name, "FF");
    Mytree[5].LChild = -1;
    Mytree[5].RChild = -1;
    strcpy(Mytree[6].Name, "GG");
    Mytree[5].LChild = -1;
    Mytree[5].RChild = -1;
    strcpy(Mytree[7].Name, "HH");
    Mytree[5].LChild = -1;
    Mytree[5].RChild = -1;
}

void Traverse(int i, node Mytree[MAXNODE])
{
    if (strcmp(Mytree[i].Name, "UnUsed") != 0)
    {
        cout << Mytree[i].Name << endl;
        if (Mytree[i].LChild != -1)
        {
            Traverse(Mytree[i].LChild, Mytree);
        }
        if (Mytree[i].RChild != -1)
        {
            Traverse(Mytree[i].RChild, Mytree);
        }
    }
}

void Search(int i, string a, node Mytree[MAXNODE])
{
    if (a == Mytree[i].Name)
    {
        cout << "검색 값 존재!" << endl;
        return;
    }
    else
    {
        if (Mytree[i].LChild != -1)
        {
            Search(Mytree[i].LChild, a, Mytree);
        }
        if (Mytree[i].RChild != -1)
        {
            Search(Mytree[i].RChild, a, Mytree);
        }
    }
}

int isEmpty(node Mytree[MAXNODE])
{
    if (Mytree[0].Name == "UnUsed")
    {
        cout << "tree is empty" << endl;
        return 1;
    }
    cout << "tree is not empty" << endl;
    return 0;
}

void DestroyTree(node Mytree[MAXNODE])
{
    if (!isEmpty(Mytree))
    {
        for (int i = 0; i < MAXNODE; i++)
        {
            strcpy(Mytree[i].Name, "UnUsed");
            Mytree[i].LChild = -1;
            Mytree[i].RChild = -1;
        }
    }
}

int main()
{
    node Mytree[MAXNODE];
    CreateTree(Mytree);
    Traverse(0, Mytree);
    Search(0, "CC", Mytree);

    DestroyTree(Mytree);
    Traverse(0, Mytree);
    return 0;
}
