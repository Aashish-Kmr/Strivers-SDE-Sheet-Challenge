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
vector<int> ans1;
void pre(TreeNode *root){
    if(!root){
        return;
    }
    ans1.push_back(root->data);
    pre(root->left);
    pre(root->right);
}
vector<int> getPreOrderTraversal(TreeNode *root)
{
    pre(root);
    vector<int> v = ans1;
    ans1.clear();
    return v;
}