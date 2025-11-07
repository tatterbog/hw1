#include <iostream>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    
    explicit TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

void preorder(TreeNode* root){
    if(!root){
        return;
    }
    
    std::cout << root->data << ' ';
    preorder(root->left);
    preorder(root->right);
}

void inorder(TreeNode* root){
    if(!root){
        return;
    }
    
    inorder(root->left);
    std::cout << root->data << ' ';
    inorder(root->right);
}

void postorder(TreeNode* root){
    if(!root){
        return;
    }
    
    postorder(root->left);
    postorder(root->right);
    std::cout << root->data << ' ';
    
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    preorder(root);   // Вывод: 1 2 3
    inorder(root);    // Вывод: 2 1 3
    postorder(root);  // Вывод: 2 3 1
}