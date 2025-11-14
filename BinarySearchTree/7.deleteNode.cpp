#include <iostream>

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

TreeNode* deleteNode(TreeNode* root, int val){
    if(!root){
        return nullptr;
    }

    if(root->data > val){
        root->left = deleteNode(root->left, val);
    }

    else if(root->data < val){
        root->right = deleteNode(root->right, val);
    }

    else{
        if(!root->left){
            TreeNode* tmp = root->right;
            delete root;
            return tmp;
        }
        else if(!root->right){
            TreeNode* tmp = root->left;
            delete root;
            return tmp;
        }

        TreeNode* min = root->right;
        while(min && min->left){
            min = min->left;
        }
        root->data = min->data;
        root->right = deleteNode(root->right, val);
    }
    return root;
}

int main(){
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->right->right = new TreeNode(9);

    root = deleteNode(root, 7);
    print(root);
}