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
 //recursive approach solution - we are going with the reverse preorder traversal, right, left, root 
//approach - sab kuch right me aayega and left har node ka khaali rhega 
class Solution {
public:
    
    TreeNode* prev = NULL;

    void flatten(TreeNode* root) {
        TreeNode* node = root;
        if(node == NULL){
            return ;
        }
        //move to right
        flatten(node->right);
        //move to left
        flatten(node->left);
        //because prev carry all right part 
        node->right = prev;
        //left point to null
        node->left = NULL;
        //now prev variable is storing the current node where everin tight part 
        prev = node; 
    }
};
