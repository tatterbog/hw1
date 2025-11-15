#include <iostream>

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data = 0) : data(data), left(nullptr), right(nullptr) {}
};

int findMinBST(TreeNode* root){
    if(!root){
        return 0;
    }

    while(root->left){
        root = root->left;
    }
    return root->data;
}

int findMaxBST(TreeNode* root){
    if(!root){
        return 0;
    }
    while(root->right){
        root = root->right;
    }
    return root->data;
}

int main(){
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);

    int minVal = findMinBST(root);  // minVal = 1
    int maxVal = findMaxBST(root);  // maxVal = 7
    std::cout << minVal << maxVal;
}