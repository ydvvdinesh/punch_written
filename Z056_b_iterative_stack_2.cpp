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
 //iterative approach with two stack
 //key idea - sabko stack me daalo ek particular order me and har baar top waale element ko stack 2 me bhejo and uske children ko s1 me laoo in order then repeat karo
 /*
 1.pick first node put it into stack 1 , put that element to stack 2 and then put theiir children to stack 1  in left first and right second in that order , after writing put st1.top  into stack 2  then then put their children to stack 1 move it from there to stack 2 , in stack 1 put there children and repeat this process again and again 
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> s1, s2;
        vector<int> ans; // we store stack 2 order in that array
        if(root == NULL){
            return ans;
        }
        s1.push(root);
        while(!s1.empty()){
            root = s1.top();
            s1.pop();
            s2.push(root);
            //phele left ka aayega 
            if(root->left != NULL){
                s1.push(root->left);
            }
            if(root->right != NULL){
                s1.push(root->right);
            }
        }
        while(!s2.empty()){
            ans.push_back(s2.top()->val);
            s2.pop();
        }
        return ans;
    }
};
