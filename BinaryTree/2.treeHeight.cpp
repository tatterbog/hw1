#include <iostream>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    
    explicit TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};


int treeHeight(TreeNode* root){
    if(!root){
        return 0;
    }
    return std::max(treeHeight(root->left), treeHeight(root->right)) + 1;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    int count = treeHeight(root);
    std::cout << count;
}