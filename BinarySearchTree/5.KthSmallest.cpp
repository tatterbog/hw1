#include <iostream>
#include <queue>

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data = 0) : data(data), left(nullptr), right(nullptr) {}
};

void inorder(TreeNode* root, int& k, int& result){
    if(!root || k == 0){
        return;
    }
    
    inorder(root->left, k, result);
    k--;
    if(k == 0){
        result = root->data;
        return;
    }
    inorder(root->right, k, result);
}

int kthSmallest(TreeNode* root, int k){
    int res = 0;
    inorder(root, k, res);
    return res;

}

int main(){
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);

    int result = kthSmallest(root, 3);  // result = 4
    // Отсортированная последовательность: 1, 3, 4, 5, 7
    std::cout << result << '\n';
}