#include <iostream>


struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int val = 0) : data(val), left(nullptr), right(nullptr){}
};

int countNodesAtDepth(TreeNode* root, int k){
    if (!root){
        return 0;
    }

    if (k <= 0){
        return 0;
    }

    if (k == 1){
        return 1;
    }
    return countNodesAtDepth(root->left, k - 1) + countNodesAtDepth(root->right, k - 1);
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);  
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    int count = countNodesAtDepth(root, 3);
    // count = 2 (узлы 4 и 5)   
    std::cout << count << '\n';
}