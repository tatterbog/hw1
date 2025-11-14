#include <iostream>

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data = 0) : data(data), left(nullptr), right(nullptr) {}
};

bool search(TreeNode* root, int val){
    if(!root){
        return false;
    }

    if(root->data > val){
        return search(root->left, val);
    }
   
    if(root->data < val){
        return search(root->right, val);
    }

    return true;
}

int main(){
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);

    bool found = search(root, 3);  // found = true
    bool notFound = search(root, 10);  // notFound = false
    std::cout << found << ' ' << notFound << '\n';
}