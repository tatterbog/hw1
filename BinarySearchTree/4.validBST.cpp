#include <iostream>
#include <queue>

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data = 0) : data(data), left(nullptr), right(nullptr) {}
};

bool isValidBST(TreeNode* root){
    if(!root){
        return true;
    }

    std::queue<TreeNode*> q;
    std::queue<int> mins;
    std::queue<int> maxs;

    q.push(root);
    mins.push(INT_MIN);
    maxs.push(INT_MAX);
    while(!q.empty()){
        TreeNode* tmp = q.front();
        q.pop();

        int min = mins.front();
        mins.pop();

        int max = maxs.front();
        maxs.pop();
        if(!tmp){
            continue;
        }

        if(min >= tmp->data || max <= tmp->data){
            return false;
        }

        if(tmp->left){
            q.push(tmp->left);
            mins.push(min);
            maxs.push(tmp->data);
        }

        if(tmp->right){
            q.push(tmp->left);
            mins.push(tmp->data);
            maxs.push(max);
        }
    }
    return true;
}


int main(){
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);

    bool valid = isValidBST(root);  // valid = true

    TreeNode* invalid = new TreeNode(5);
    invalid->left = new TreeNode(7);  // нарушение свойства BST
    invalid->right = new TreeNode(3);

    bool notValid = isValidBST(invalid);  // notValid = false

    std::cout << valid << notValid;
}