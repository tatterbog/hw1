#include <iostream>


struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int val = 0) : data(val), left(nullptr), right(nullptr){}
};

bool areIdentical(TreeNode* t1, TreeNode* t2){
    if (t1 == nullptr && t2 == nullptr){
        return true;
    }

    if (t1 == nullptr || t2 == nullptr){
        return false;
    }

    if (t1->data != t2->data){
        return false;
    }

    return areIdentical(t1->left, t2->left) && areIdentical(t1->right, t2->right);
}

int main(){
    TreeNode* tree1 = new TreeNode(1);
    tree1->left = new TreeNode(2);
    tree1->right = new TreeNode(3);

    TreeNode* tree2 = new TreeNode(1);
    tree2->left = new TreeNode(2);
    tree2->right = new TreeNode(3);

    bool identical = areIdentical(tree1, tree2);
    std::cout << std::boolalpha << identical << '\n';
}