#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int key;
    struct TreeNode *left, *right;
} TreeNode;

TreeNode* search(TreeNode *node, int key)
{
    /*Binary Search*/
    if(node == NULL) return NULL;
    if(node->key == key) return node;
    else if(node->key > key)
        return search(node->left, key);
    else
        return search(node->right, key);
}

TreeNode* Create(int item)
{
    TreeNode *temp = (TreeNode *)malloc(sizeof(TreeNode));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

TreeNode* insert_node(TreeNode *node, int key)
{
    if(node == NULL) return Create(key);
    
    if(key < node->key)
        node->left = insert_node(node->left, key);
    else if(key > node->key)
        node->right = insert_node(node->right, key);
    
    return node;
}

TreeNode* max_value_node(TreeNode *node)
{
    TreeNode *curr = node;
    
    while(curr->right != NULL)
        curr = curr->right;
    return curr;
}

TreeNode* min_value_node(TreeNode *node)
{
    TreeNode *curr = node;
    
    while(curr->left != NULL)
        curr = curr->left;
    return curr;
}

TreeNode* delete_node(TreeNode *root, int key)
{
    if(root == NULL) return NULL;
    
    if(key < root->key)
        root->left = delete_node(root->left, key);
    else if(key > root->key)
        root->right = delete_node(root->right, key);
    else
    {
        //leaf node
        if(root->left == NULL)
        {
            TreeNode *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            TreeNode *temp = root->left;
            free(root);
            return temp;
        }
        //parent node
        TreeNode *temp = min_value_node(root->right);
        
        root->key = temp->key;
        root->right = delete_node(root->right, temp->key);
    }
    return root;
}

/*TreeNode* Traverse(TreeNode *root, int key) {
    
    if (strcmp(node, "UnUsed") == 0) {
    	printf("%d", node);
    	printf("\n");
    	
        if (root->left != -1) {
            Traverse(root->left);
        }
        if (root->right != -1) {
            Traverse(root->right);
        }
    }
}*/

TreeNode* Destroy(TreeNode *node) {
	if(node->left != NULL)
        node->left = Destroy(node->left);
        node->left = NULL;
    if(node->right != NULL)
        node->right = Destroy(node->right);
        node->right = NULL;
    
        if((node->left == NULL) && (node->right == NULL))
        {
            printf("destroy\n");
            free(node);
            node = NULL;
            return node;
        }
    
}

TreeNode* IsEmpty(TreeNode *node) {
	if(node == NULL) 
		printf("IsEmpty\n");
	else
		printf("NoEmpty\n");
}		


int main(int argc, const char * argv[]) {
    TreeNode* root = NULL;
    
    IsEmpty(root);
    
    root = insert_node(root, 20);
    root = insert_node(root, 10);
    root = insert_node(root, 25);
    root = insert_node(root, 5);
    root = insert_node(root, 15);
    root = insert_node(root, 30);
    
    IsEmpty(root);

    if(search(root, 30))
        printf("\nThere is %d\n", 30);
    else
        printf("\nThere isn't %d\n", 30);
    
    Destroy(root);
    
    return 0;
}
