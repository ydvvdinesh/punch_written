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
 //approach here we have to check the everynode , if every node is same and have same value that means it is equal
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //this statement check if both tree are null
        if(p == NULL || q == NULL){
            return (p==q);
        }
        //preorder 
        //first condition checking the node value after traversal , if same then then baaki ki dono condition check karo otherwise mat karo
        // second will take us to left 
        // third will take us to right
        return (p->val == q->val) 
        && isSameTree(p->left, q->left)
        && isSameTree(p->right, q->right);
    }
};
