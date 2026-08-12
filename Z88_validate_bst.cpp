/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 //bst ki fundamental confition hai left < node < right
 //isme hum range bnake chlege , in left me move krenge toh children ki range ki max value parent ki value hogi and in right me move krenge toh children ki value range ki min value parent ki hogi 
class Solution {
public:

    bool isValidBST(TreeNode* root) {
        return bst(root, LLONG_MIN, LLONG_MAX);
    }

    bool bst(TreeNode* root, long long minval, long long maxval){
        if(root == NULL){
            return true;
        }
        //yadi null hai toh true hi hai saara
        //yadi root ki value , range me nahi hai jo humne bnayii hai toh woh false ho jayegi
        //in left , chilren maximum is parent value
        //in right, children minimmum is parent value 
        if(root->val <= minval || root->val >= maxval) return false;
        //yadi mini value se chota hai and maximum value se badi toh error degi
        // bas recurisve method use kro an har ek cheeze check kar ro
        return bst(root->left,minval, root->val) && bst(root->right, root->val,maxval);
    }
};
