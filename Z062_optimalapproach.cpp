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
 //two approach hai - har me jaoo and check kro condition and another one 2 function add kro maximum height wale funtion me
 //condition through which we can find the tree is balanced or not.
 //height of left - height of right children >1 toh balanced binary tree nahi hai and 1 ya o hai toh hai 

 
class Solution {
public:

int maxDepth(TreeNode* root) {
        TreeNode* node = root;
        if(node == NULL){
            return 0;
        }
        int leftheight = maxDepth(node->left);
        if(leftheight == -1) return -1;
        int rightheight = maxDepth(node->right);
        if(rightheight == -1) return -1;
        if(abs((leftheight - rightheight)>1)) return -1;
        return (1+ max(leftheight, rightheight));
    }

    bool isBalanced(TreeNode* root) {
        return maxDepth(root) != -1;
    }
};
