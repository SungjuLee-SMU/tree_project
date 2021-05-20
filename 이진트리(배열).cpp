#include <iostream>
using namespace std;
#define MAXNODE 100 
typedef struct{ 
    char Name[50];
    int LChild;
    int RChild;
} node;

node Mytree[MAXNODE];


void Traverse(int i) {
    
    if (strcmp(Mytree[i].Name, "UnUsed") == 0){
        cout << Mytree[i].Name << endl;
        if (Mytree[i].LChild != -1) {
            Traverse(Mytree[i].LChild);
        }
        if (Mytree[i].RChild != -1) {
            Traverse(Mytree[i].RChild);
        }
    }
}

