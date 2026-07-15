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
 //approach - iterative
 //node - on which we are looking for 
 //left me gaye yadi node null hai toh stack se usko bahar nikal do and otherwise tack me daalo and left , root , right ke order me chalo we directly get our answer
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* node = root;
        stack<TreeNode*> st;
        vector<int> ans;
        while(node != NULL || !st.empty()){ //only syack empty me kya pta chle hi nah, because starting me toh empty hi rhega 
            if(node != NULL){
                st.push(node);
                node = node->left;
            }
            else{//if it is null
            if(st.empty()) break;
            node = st.top();
            st.pop();
            ans.push_back(node->val);
            node = node->right;
            }
        }
        return ans;
    }
};
