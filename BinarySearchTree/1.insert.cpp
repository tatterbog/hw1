#include <iostream>

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data = 0) : data(data), left(nullptr), right(nullptr){} 
};

TreeNode* insert(TreeNode* root, int val){
    if(!root){
        root = new TreeNode(val);
        return root;
    }

    TreeNode* prev = nullptr;
    TreeNode* ptr = root;
    while(ptr){
        if(ptr->data > val){
            prev = ptr;
            ptr = ptr->left;
        }

        else if(ptr->data < val){
            prev = ptr;
            ptr = ptr->right;
        }

        else{
            return root;
        }
    }



    if(prev->data > val){
        prev->left = new TreeNode(val);
    }
    else if(prev->data < val){
        prev->right = new TreeNode(val);
    }

    return root;
}

void print(TreeNode* root){
    if(!root){
        return;
    }

    print(root->left);
    std::cout << root->data << ' ';
    print(root->right);
}

int main(){
    TreeNode* root = nullptr;
    root = insert(root, 5); 
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 1);

    root = insert(root, 4);
    print(root);

// Дерево: 5 с левым поддеревом (3, 1) и правым (7) 
}