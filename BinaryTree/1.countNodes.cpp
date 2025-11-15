#include <iostream>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    
    explicit TreeNode(int val = 0) : data(val), left(nullptr), right(nullptr) {}
};


int countNodes(TreeNode* root){
    if(!root){
        return 0;
    }
    return countNodes(root->left) + countNodes(root->right) + 1;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    int count = countNodes(root);
    std::cout << count;
}