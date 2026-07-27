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
 //width - number of nodes in a level between leftmost node and the rightmost node but remeber one thing left most and rightmost dono ek hi level me milenge 
 //approach - we are going with index based approach - we assign index no to every node using a formula for left node  - index = 2*oldindex + 1 and for right - index = 2*oldindex + 2 these formuka are for zero based indexing , 1 based ke liye bhi same hi hai but ek change hai woh gopgle kar lena now next thing ye indexing overflow ho jaati hai when skew tree aaye tab , tab iss index ka koi rok hi nahi , so to prevernt overflo we comes up with a solution
 // new index = index - index minimum at that particular level 
 //due to this hume jo indexing hai woh ek aprticuar me milegi like 0,1 se start in a level
 //here we are using the level order traversal left to right sab daalo queue me usse baad aage bado
//width formula oif we know index of first and last then , = last-first+1;
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0; // why 0 not null because they are asking in int form
        }
        queue<pair<TreeNode*, long long>> q;
        // q is storing the node and the index at which index the node is 
        q.push({root,0});
        int ans = 0;
        //pushing the first node into q then now daal na hi hai 
        while(!q.empty()){
            int n = q.size();
            long long minimum = q.front().second;
            //jo bhi q.front hoga uska index minimum hoga uss particular level , because in level orderhum left se start karte hai toh waah sabse chota hoga
            long long first , last;
            // these index will the index of first of the level and last of level
            //ek iteration me ek level queue ke aandr
            for(int i =0; i<n;i++){
                // we have to intilize the index and remenber we have to prevent it from overflow 
                long long curr_index = q.front().second-minimum; // i
//don`t confuse in simole to prevent overflow
                //now hume lag raha same me se same minus kar diya but realityis different, this line is for after o index when the left and right increase the index , after doing minus it will fix up , minimum will store the last / previous 
                TreeNode* node = q.front().first;
                q.pop();
                if(i == 0){
                    first = curr_index;
                }
                if(i == (n-1)){
                    last = curr_index;
                }
                //now move to leftand right with formula 
                if(node-> left != NULL){
                    q.push({node->left, curr_index*2+1});
                }
                if(node-> right != NULL){
                    q.push({node->right, curr_index*2+2});
                }
            }
            ans = max(ans, (int)(last-first+1));
        }
        return ans;
    }
};
