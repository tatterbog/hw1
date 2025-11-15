#include <iostream>

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data = 0) : data(data), left(nullptr), right(nullptr) {}
};

int countInRange(TreeNode* root, int start, int end){
    if(!root){
        return 0;
    }

    if(root->data < start){
        return  countInRange(root->right, start, end);
    }

    if(root->data > end){
        return countInRange(root->left, start, end);
    }

    return countInRange(root->left, start, end) + countInRange(root->right, start, end) + 1;
}

int main(){
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(18);

    int count = countInRange(root, 7, 15);
// count = 3 (узлы: 7, 10, 15)
    std::cout << count << '\n';
}