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
 //approach - symmetric mtln left side ki mirror image hum yadi rigth side pe impose kare toh exactly impose ho jaye with the same node 
 // in left part we move in preorder traversal root left right and in right part we move like reverse preorder traversal root right left
class Solution {
public:
    //devide the two part from the main root , one is leftpart and another is rightpart
    bool checking(TreeNode* leftboss, TreeNode* rightboss){
        //leftboss is the root of left part or left subtree
        //rightboss is the root of right part or right subtree
        if(leftboss == NULL || rightboss == NULL){
            return leftboss == rightboss;
        }
        //yadi ek null hai toh uspe jo impose hogi yadi wo null hai toh true otherwise false
        //now yadi null nahihai toh check their value
        if(leftboss->val != rightboss->val) return false;
        //now check this for everyone, but remeber dono part simaltaneously chlenge 
        // note yadu hum left part ke left me chal rahe hai toh usme hum right ke right me chalne chayiye and yadi left ke right mr chal rahe hai toh dusre me right ke left me chlane chayiye, tabhi impose waali condition aayegi 
        return checking(leftboss->left, rightboss->right) && checking(leftboss->right, rightboss-> left);
    } 
    bool isSymmetric(TreeNode* root) {
        if(root == NULL){
            return false;
        }
        return checking(root->left, root->right);
    }
};
