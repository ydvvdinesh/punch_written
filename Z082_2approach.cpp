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
 //using stack method - top waale toh right waale ko connect kro , phele right jayega then left , and aise chalta rhega
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == NULL){
            return;
        }
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();
            if(node->right != NULL){
                st.push(node->right);
            }
            if(node->left != NULL){
                st.push(node->left);
            }
            //important step
            if(!st.empty()){
                node->right = st.top();
            }
            node->left = NULL;
        }
    }
};
