/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution{	
	public:
//floor , greater than everyone but smaller than key in that tree
    int floor(TreeNode* root, int key){
        int f = -1;
        while(root != NULL){
            if(root->data == key){
                f = root->data;
                return f;
            }
            if(root->data < key){ //yadi value key se choti hai toh hum hume next value pe jaana chayiye jo badi hai last waali se par choti hai key se
                 f = root->data;
                 // f0r finding big thata`s we go to left
                 root= root->right;
            }
            else{
                // find the smaller one yadi badi ho gaya toh left me jaoo wahi small milega
                root = root->left;
            }
        }
        return f;
    }

    int ceil(TreeNode* root, int key){
        int c = -1;
        while(root != NULL){
            if(root->data == key){
                c = root->data;
                return c;
            }
            if(root->data > key){ // ulkata hai floor ka , sabse me chota but usse se bda
                 c = root->data;
                 root= root->left;
            }
            else{
                // find the smaller one yadi badi ho gaya toh left me jaoo wahi small milega
                root = root->right;
            }
        }
        return c;
    }

		vector<int> floorCeilOfBST(TreeNode* root,int key){
			int a = floor(root,key);
            int b = ceil(root, key);
            vector<int>ans;
            ans.push_back(a);
            ans.push_back(b);
            return ans;
		}
};
