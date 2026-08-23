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
 //simple ha couple of node jinki value k equal yadi hai toh true otherwise false
 //find out the inorder , which is sorted for the bst and then go with two pointer
class Solution {
public:
    //function to get inorder
    void inorder(TreeNode* node, vector<int>& elements){
        if(node == NULL){
            return;
        }
        //left node right
        inorder(node->left, elements);
        elements.push_back(node->val);
        inorder(node->right, elements);
    }
    //now using a function to return that vector
    vector<int> inordervec(TreeNode* node){
        vector<int> ans;
        inorder(node, ans);
        return ans;
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> ls = inordervec(root);
        //now two pointer
        int n = ls.size();
        int left = 0;
        int right = n-1;
        while(left < right){
            int sum = ls[left] + ls[right];
            if(sum == k){
                return true;
            }
            else if(sum >k){
                right--;
            }
            else{
                left++;
            }
        }
        return false;
    }
};
