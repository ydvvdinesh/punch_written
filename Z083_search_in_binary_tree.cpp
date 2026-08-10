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
 //binary tree and binary search tree me ek hi difference hai that is left waala node se chota hota hai and right waala node se bda hoga hai, time complexity logn rheti hai
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        //do condition hai yaha toh jo doond rahe hai woh na mil jaye ya null na nikle itne chalte raho, remeber the word chalte raho , this make sense of using while jab tak condition galat na ho itne chalt raho 
        while(root != NULL && root->val != val){
            if(root-> val > val){
                root = root->left; // toh right me move krenge
            }
            else if(root->val < val){
                root = root->right; //choti hai toh left me move krenge
            }
        }
        return root;
    }
};
