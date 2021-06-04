#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    char key;
    char key1;
    char key2;
    struct TreeNode* left, * right;
} TreeNode;

TreeNode* new_node(char item)
{
    TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
TreeNode* search(TreeNode* node, char key)
{
    /*Binary Search*/
    if (node == NULL) return NULL;
    if (node->key == key) return node;
    else if (node->key > key)
        return search(node->left, key);
    else
        return search(node->right, key);
}

TreeNode* insert_node(TreeNode* node, char key, char key1, char key2)
{
    if (search(node,key) == NULL) return new_node(key);
    
    if(key1 != '.')
        node->left = new_node(key1);
    if(key2 !='.')
        node->right = new_node(key2);
    //printf("%c", node->right);

    return node;
}

TreeNode* max_value_node(TreeNode* node)
{
    TreeNode* curr = node;

    while (curr->right != NULL)
        curr = curr->right;
    return curr;
}

//right subtree Min
TreeNode* min_value_node(TreeNode* node)
{
    TreeNode* curr = node;

    while (curr->left != NULL)
        curr = curr->left;
    return curr;
}

TreeNode* delete_node(TreeNode* root, int key)
{
    if (root == NULL) return NULL;

    if (key < root->key)
        root->left = delete_node(root->left, key);
    else if (key > root->key)
        root->right = delete_node(root->right, key);
    else
    {
        //leaf node
        if (root->left == NULL)
        {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        //parent node
        TreeNode* temp = min_value_node(root->right);

        root->key = temp->key;
        root->right = delete_node(root->right, temp->key);
    }
    return root;
}



int main(int argc, const char* argv[]) {
    TreeNode* root = NULL;
    char A, A1, A2;
    int n;

    scanf("%d", &n);

   for(int i=0; i<n; i++){
    scanf("%s%s%s", &A, &A1, &A2);
    getchar();
 
    root = insert_node(root, A, A1, A2);
    }

    //preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    //postorder(root);

    return 0;
}
