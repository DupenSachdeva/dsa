#include<bits/stdc++.h>

using namespace std;

class TreeNode{
    public:
    int data;
    TreeNode * left;
    TreeNode * right;
};
int find(TreeNode * root , map<TreeNode * , int> &dp){
     
    if(root == nullptr){
        dp[nullptr] = 0;
        return;
    }

     if(!root->left && !root->right)
     dp[root] = root->data == 1 ? 1 : 0;
     
     find(root->left,dp);
     find(root->right,dp);


     dp[root] = dp[root->left] + dp[root->right];

     if(root->data==1){

        if(root->left && root->left->data && root->right && root->right->data)
        dp[root] -= 1;

        if(root->left && root->right && !root->left->data && !root->right->data)
        dp[root] += 1;

        if(!root->left && !root->right->data)
        dp[root] += 1;

        if(!root->right && !root->left->data)
        dp[root] += 1;
     }



}
int main(){
    
    
    TreeNode * root;
    map<TreeNode* , int > dp;
    cout<<"ans is "<<find(root,dp);
    return 0;
}