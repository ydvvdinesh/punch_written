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
//approach hume  level ki last node se ulta raversal krenge toh hume right veiw mil jayega 
//we are doing reverse preorder transversal - root left right , but here we are doing root right left 
class Solution {
public:

    vector<int> recursion(TreeNode* root, int level, vector<int> &res){
         //for storing the result
        if(root == NULL){
            return res;
        }
        //if(level == size ) toh hume woh node ki value leni hai woh hogi khud se automatically
        if(level == res.size()){
            res.push_back(root->val);
        }
        recursion(root->right, level+1,res);
        recursion(root->left, level+1,res);
        return res;
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        recursion(root, 0 , ans);
        return ans;
    }
};
