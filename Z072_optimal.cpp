/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //lca is the deepest node which common in the path of two nodes from the root 
 //bruteforce appproach - we find the path for both nodes and put them into array ans in last check it 
 //optimal approach - use dfs/inorder + backtracking traversal , and we have to look for the node for which we have to find the lca 
 //first go to left then left until you can`t find that node or null, if you find the node then no need to go , more on left or further , if we get null then return null this the same conceot used in right and in every node look for right and left if both null then return null , if one is number then it return number and when you get number on both side left and right then you find the lca , we get in process because kyuki lca dono me aata hai yadi dono traf se number hi that`s means dono ke paath tha
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q){
            return root;
        }
        //yadi root null toh null hi return krega and yadi value hogi toh value return hogi 
        TreeNode* leftnode = lowestCommonAncestor(root->left,p,q);
        TreeNode* rightnode = lowestCommonAncestor(root->right,p,q);
        //ye traversal kregi and in return null ya node(number) leki aayegi jiske base pe lca decide hoga
        //dono kaam kregi ttraverse bhi and return result bhi aayegi and woh store hoga leftnode and rightnode me 
        // jab left khaali hai toh right ko consider krenge
        if(leftnode == NULL){
            return rightnode;
        }
        else if(rightnode == NULL){
            return leftnode;
        }
        //yadi dono null hai toh root return krenge
        else{
            return root;
        }
        return NULL;
    }
};
