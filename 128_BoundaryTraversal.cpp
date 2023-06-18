#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
vector<int> ans;
bool isleaf(TreeNode<int>* root){
    if(!root->left && !root->right){
        return true;
    }
    else return false;
}
void inorder(TreeNode<int> *root) {
  if (!root)
    return;
  inorder(root->left);
  if (isleaf(root))
    ans.push_back(root->data);
  inorder(root->right);
}
void bound_traverse(TreeNode<int> *root){
    ans.push_back(root->data);

    // for the left side of the tree traversal : ) 
    TreeNode<int> *cur = root->left;
    while(cur){
      if (!isleaf(cur)) {
        ans.push_back(cur->data);
      }
        if(cur->left){
            cur = cur->left; 
        }
        else cur= cur->right;
    }

    // for the leaf elements -> inorder traversal /// any would do
    cur= root;
    inorder(cur);

    //for the right side tree traversal
    cur= root->right;
    stack<int>v1;
    while(cur){
        if(!isleaf(cur)){
            v1.push(cur->data);
        }
        if(cur->right)
            cur=cur->right;
        else cur = cur->left;
    }
    while (!v1.empty()) {
      ans.push_back(v1.top());
      v1.pop();
    }
}

vector<int> traverseBoundary(TreeNode<int>* root){
  if (!root) {
    vector<int> v = ans;
    ans.clear();
    return v;
  }
    if (isleaf(root)) {
      ans.push_back(root->data);
      vector<int> v=ans;
    ans.clear();
    return v;
    }
    else 
        bound_traverse(root);
    vector<int> v=ans;
    ans.clear();
    return v;
}