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
 //using stack - go to the root and push  to stack and removal of thaat from add after that add both children ek saath , but first put right children then left and then repeat the process we will the get the pre order traversal
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        st.push(root);
        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();
            ans.push_back(node->val);
            //right one first 
            if(node->right != NULL){
                st.push(node->right);
            }
            if(node->left != NULL){
                st.push(node->left);
            }
        }
        return ans;
    }
};
