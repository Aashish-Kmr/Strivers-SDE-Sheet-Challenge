#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    
    vector<int> ans;
    if(!root){
        return ans;
    }
    bool flagltr=true;
    queue<BinaryTreeNode<int>*> q1;
    q1.push(root);
    while(!q1.empty()){
        stack<int>s1;
        int size1 = q1.size();
        for(int i=0; i< size1; i++){
            BinaryTreeNode<int> *t = q1.front();
            q1.pop();
            if(flagltr){
                ans.push_back(t->data);
            }
            else{
                s1.push(t->data);
            }
            if(t->left){
                q1.push(t->left);
            }
            if(t->right){
                q1.push(t->right);
            }
        }
        while(!s1.empty()){
                ans.push_back(s1.top());
                s1.pop();
            }
        flagltr=!flagltr;
    }
    return ans;
}
