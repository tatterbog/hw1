#include <iostream>
#include <vector>

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data = 0) : data(data), left(nullptr), right(nullptr) {}
};

void print(TreeNode* root){
    if(!root){
        return;
    }

    print(root->left);
    std::cout << root->data << ' ';
    print(root->right);
}

TreeNode* sorter(std::vector<int> arr, int start, int end){
    if(start > end){
        return nullptr;
    }

    TreeNode* root = new TreeNode(arr[(start + end) / 2]);
    root->left = sorter(arr, start, ((start + end) / 2) - 1);
    root->right = sorter(arr, ((start + end) / 2) + 1, end);
    return root;
}

TreeNode* sortedArrayToBST(std::vector<int> arr){
    return sorter(arr, 0, arr.size() - 1);
}

int main(){
    std::vector<int> arr = {1, 3, 5, 7, 9};
    TreeNode* root = sortedArrayToBST(arr);
    print(root);
}