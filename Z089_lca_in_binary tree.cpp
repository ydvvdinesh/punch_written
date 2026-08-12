/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// lca is the frist common node in path of two nodes from root to that node and , note we are looking from the downward part 
//3 case hai 1. ek node left me ho aur dusri right and , toh unka merge (from down view) or split from (upper view) and , toh wohi lca hoga 
//2. dono left meho ya right me toh woh last me split hoi hi 
//3. koi node khud lca me aaye toh jo pehele node aayi traverse aayi wohi answer hoga 
//we are going with the recursive approach 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return NULL;
        }
        TreeNode* curr = root;
        // go to right if the given value is smaller then the curr node
        //why ek ulta aur sukta , kyu jaise wohi confdition aayi toh split mil jayega 
        if(curr->val < p->val && curr->val < q->val){
            return lowestCommonAncestor(root->right, p, q);
        }
        if(curr->val > p->val && curr->val > q->val){
            return lowestCommonAncestor(root->left, p, q);
        }
        return root;
    }
};
