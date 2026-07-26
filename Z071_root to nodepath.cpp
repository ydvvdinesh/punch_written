/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution{
	public:

    consider krenge , yadi dono false hai toh nahi krenge consider 
    bool getpath(TreeNode* root, vector<int> &ans, int x){
        if(root == NULL){
            return false;
        }
        // yadi root hi khaali hai toh hum jis doond rahe hai woh milegi hi nahi
        // jispe pe hum reach krenge usko array me daalenge , yadi dono traf false milta hai toh nikal denge 
        ans.push_back(root->val);
        // and yadi jo cheyiye woh milgayi toh true
        if(root-> val == x) return true;
        //abhi ye main hai traversal dono side 
        //ye hi traversal krenge and ye hi find krke denge true hai ya false 
        //tadi dono me se ek bhi true hai toh done hai mamla , jo true hai hum uske raste pe jayenge
        if ( getpath(root->left, ans,x)|| 
        getpath(root->right, ans,x))
         return true;
        //otherwise , mtlb false hai 
        ans.pop_back();
        return false;
    }

		vector<vector<int>> allRootToLeaf(TreeNode* root) {
        vector<int> ans;
        if(root == NULL){
           return ans;
        }
      int x = root->val;
        getpath(root, ans, x);
        return ans;
		}
};
