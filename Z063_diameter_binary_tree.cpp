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
 //key idea= longest distance betn any two nodes, 
 //formula = find lh +rh everytime that gives us
 //brute approach find the for every
class Solution {
public:
//this function gives us the height foir a node , you want for that 
    int maxdepth(TreeNode* root){
        TreeNode* node = root;
        if(node == NULL){
            return 0;
        }
        //recursive way of traversal
        int lh = maxdepth(node->left);
        int rh = maxdepth(node->right);
        return (1+max(lh,rh));
    }

    //for finding diameter we will find distance for every node 
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi =0;
        TreeNode* node = root;
        if(node == NULL){
            return 0;
        }
        int lh = maxdepth(node->left);
        int rh = maxdepth(node->right);
        maxi = max(maxi, lh+rh);
        //till now we find the height
        //we using recursive traversal ,
        diameterOfBinaryTree(node->left);
        diameterOfBinaryTree(node->right);
        return maxi;
    }
};
