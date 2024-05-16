#include <stdio.h>
#include <stdlib.h>

struct treenode {
    int val;
    struct treenode* left;
    struct treenode* right;
};


//创建新的node
struct treenode* newnode(int value){
    struct  treenode * node = (struct treenode*)malloc(sizeof(struct treenode));
    node ->val = value;
    node->left = node->right = NULL;
    return node;
}


//插入新的node
struct treenode* insertnode(struct treenode* node, int value){
    if (node == NULL) return 
        newnode(value);
    if (node->val< value)
        node->right = insertnode(node->right,value);
    else if (node ->val > value)
        node->left = insertnode(node->left,value);
    return node;
}

struct treenode* deletenode(struct treenode* root, int value){
    if (root == NULL){
        printf("the tree is null");
        return root;
    }
    if (root->val = value){
        return NULL;
    }
    else if (root){
        
    }


    
}

void inorder(struct treenode* root){
    if(root != NULL){
        inorder(root->left);
        printf("%d\n",root->val);
        inorder(root->right);
    }
}



int main() {
    struct treenode* root = NULL;
    root = insertnode(root, 50);
    insertnode(root,1);
    insertnode(root,23);
    insertnode(root,78);
    inorder(root);
    return 0;
}