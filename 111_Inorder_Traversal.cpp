#include <bits/stdc++.h> 
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
vector<int> v1;
void moveroot(TreeNode *root){
    if(!root)
        return;
    moveroot(root->left);
    v1.push_back(root->data);
    moveroot(root->right);
}
vector<int> getInOrderTraversal(TreeNode *root)
{   
    moveroot(root);
    vector<int> v2= v1;
    v1.clear();
    return v2;
}