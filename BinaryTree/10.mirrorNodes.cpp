#include <iostream>


struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int val = 0) : data(val), left(nullptr), right(nullptr){}
};

void mirrorTree(TreeNode* root){
    if (!root){
        return;
    }

    TreeNode* tmp = std::move(root->left);
    root->left = std::move(root->right);
    root->right = std::move(tmp);

    mirrorTree(root->left);
    mirrorTree(root->right);
}

void preorder(TreeNode* root){
    if(!root){
        return;
    }
    
    std::cout << root->data << ' ';
    preorder(root->left);
    preorder(root->right);
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    preorder(root);
    mirrorTree(root);
    preorder(root);
    // Теперь: root->right = 2, root->left = 3, root->right->right = 4
}