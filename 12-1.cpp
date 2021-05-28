#include <stdio.h>
#include <string.h> 
#define MAX 100 

typedef struct{ 
    char name[50];
    int left;
    int right;
} node;

void Create(node tree[MAX]) {
    for (int i = 0; i < MAX; i++) {
    	
        strcpy(tree[i].name, "UnUsed");
        
        tree[i].left = -1;
        tree[i].right = -1;
    }

    strcpy(tree[0].name, "0");
    tree[0].left = 1;
    tree[0].right = 2;
    
    strcpy(tree[1].name, "1");
    tree[1].left = 3;
    tree[1].right = 4;
    
    strcpy(tree[2].name, "2");
    tree[2].left = 5;
    tree[2].right = 6;
    
}


void Traverse(int i, node tree[MAX]) {
	
    if (strcmp(tree[i].name, "사용하지않음") != 0) {
    	printf("%s\n", tree[i].name);
        
        if (tree[i].left != -1) {
            Traverse(tree[i].left, tree);
        }
        if (tree[i].right != -1) {
            Traverse(tree[i].right, tree);
        }
    }
}

int main() {
    node tree[MAX];
    
    Create(tree);
    Traverse(0, tree);

    return 0;
}
