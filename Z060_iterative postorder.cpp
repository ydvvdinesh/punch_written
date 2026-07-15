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
 //iterative approach - put all left first into stack then start puting right , and , there is a specfic condition which we have to add it to stack, so learn that while block of code
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* curr = root;
        while(curr != NULL || !st.empty()){
        if(curr != NULL){
            st.push(curr);
            curr = curr->left;
        }
        else{
            TreeNode* temp = st.top()->right; // ye current node ke right me nahi hai , jo just push ki uski side me hai
            if(temp == NULL){ // yadi right me bhi nahi becoz left me toh nahi hai pehel se isliye hi toh abhi stack me nahi bhega
            temp = st.top();
            st.pop();
            ans.push_back(temp->val);
            //learn this one , understood but hetic one
            while(!st.empty() && temp == st.top()->right){
                temp = st.top();
                st.pop();
                ans.push_back(temp->val);
        }
            }
            else{
                curr = temp;
            }
        }
    }
        return ans;
    }
};
