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
 // same like bfs , bas isme one level left to right and another level right to left and same repeating everytime
//so we use a flag method , yadi true toh left se right and yadi 1 toh right se left 
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL){
            return result;
        }
        //yadi node null h toh as exsit return kardo
        queue<TreeNode*> q;
        q.push(root);
        //till now we created the queue and the push the first element , kyuki queue me se tabhi front remove karna hai jab uske saare bache , yaha woh complete level queue me 
        bool lefttoright = true;
        //create flag jis humko pta rhega konsi side se element bhejne hai
        //queue me sab element level ayyenge yadi woh khaaali that`s means usne traverse kar diya hai
        while(!q.empty()){
            int n = q.size();
            vector<int> level(n);
            for(int i=0; i<n; i++){
                TreeNode* node = q.front();
                //ye hume node reserve ki kyuki iske hi children lene hai and isko remove karna hai, jab children lene hai toh parent remove hoga
                q.pop();
                //now dekhna pdega kis order me ek vector store krne hai 
                int index = (lefttoright)?i:(n-1-i); 
                level[index] = node->val;
                //storing the value 
                if(node->left != NULL){
                    q.push(node->left);
                }
                if(node->right != NULL){
                    q.push(node->right);
                }
            }
            //har level me flag ki value true or false jayegi like phele flag pe true toh then dusre pe false like aise
            lefttoright = !lefttoright;
            result.push_back(level);
            //after pushing everything we have to return result 
        }
        return result;
    }
};
