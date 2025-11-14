#include <iostream>

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data = 0) : data(data), left(nullptr), right(nullptr) {}
};

bool hasPathSum(TreeNode* root, int val){
    if(!root){
        return false;
    }

    if(!root->left && !root->right){
        return val == root->data;
    }

    return hasPathSum(root->left, val - root->data) ||
        hasPathSum(root->right, val - root->data);
}

int main(){
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);

    bool hasPath = hasPathSum(root, 27);
// hasPath = true (путь: 5 -> 4 -> 11 -> 7)
    std::cout << std::boolalpha << hasPath << '\n';
}