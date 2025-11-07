#include <iostream>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    
    explicit TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};


int countLeaves(TreeNode* root){
    if(!root){
        return 0;
    }
    
    if(!root->left && !root->right){
        return 1;
    }
    
    return countLeaves(root->left) + countLeaves(root->right);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
   
    int leaves = countLeaves(root);
    std::cout << leaves << '\n';
    // leaves = 3 (узлы 3, 4, 5)
}