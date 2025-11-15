#include <iostream>
#include <queue>
#include <limits>

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int val = 0) : data(val), left(nullptr), right(nullptr){}
};

int findMax(TreeNode* root){
    if(!root){
        return INT_MIN;
    }

    int maxi = std::max(findMax(root->left), findMax(root->right));
    return std::max(root->data, maxi);
}

int findMin(TreeNode* root){
    if(!root){
        return INT_MAX;
    }
    
    int mini = std::min(findMin(root->left), findMin(root->right));
    return std::min(root->data, mini);
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(1);

    int maxVal = findMax(root);  // maxVal = 8
    int minVal = findMin(root);  // minVal = 1
    std::cout << maxVal << '\n';
    std::cout << minVal << '\n';

}