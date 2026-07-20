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
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        //queue is used to store the node through which we find the total nodes on that level 
        vector<vector<int>> ans; //stores all level of array
        if(root == NULL){
            return ans;
        }
        q.push(root);
        while(!q.empty()){
        vector<int> level; // this will store the level of array
            //jo queue me first aayo ya present hai , toh woh jaye toh uske left and right dono daalke jayye and jo main nikal jaye toh uske roght and left daalna
            //root har baar nayi bnti jayegu , jaha hume stand krenge woh bnati jayegi
            //jab hum next level pe jayenge usse phele us level ke saare element raverse karne hai 
            int n = q.size();
            // using this loop ek baar me hi queue me sab aajaye and level me bhi order se aaye
            for(int i = 0; i<n; i++){
            TreeNode* node = q.front(); // here we are reserving the node kyuki baad me ht jayegi 
                
            q.pop();
            if(node->left != NULL){
                q.push(node->left);
            }
            if(node->right != NULL){
                q.push(node->right);
            }
            level.push_back(node->val);
            }
            ans.push_back(level);
        } 
        return ans;
    }
};
