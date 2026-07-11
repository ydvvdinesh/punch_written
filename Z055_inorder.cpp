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
.// we created a function 
 //APPROACH - left root 
 void inorder(TreeNode* root, vector<int> &store){
    if(root == NULL){
        return; // it will help to return at node during coming back into recursion
    }
    // go to left first 
    inorder(root->left, store);
    //write the node into the storeing data structre whoc is array
    store.push_back(root->val);
    //go to right node 
    inorder(root->right, store);
 }
// we just call the function
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }
};
