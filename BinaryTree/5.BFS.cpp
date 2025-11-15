#include <iostream>
#include <queue>

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int val = 0) : data(val), left(nullptr), right(nullptr){}
};

void levelOrder(TreeNode* root){
    if(!root){
        return;
    }
    std::queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* t = q.front();
        q.pop();
        std::cout << t->data << ' ';
        
        if(t->left){
            q.push(t->left);
        }
        if(t->right){
            q.push(t->right);
        }
    } 
    std::cout << '\n';
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    levelOrder(root);
    // Вывод: 1 2 3 4 5
}