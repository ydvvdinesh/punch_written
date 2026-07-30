/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // 3 things 1. parent pointer , iske karan hum upward traf ki side bhi move kar skate hai warna tree me hum sirf neeche move kar skate hai 
 //create parent pointer
 //kon vist huwa aur kon , mtlb sab direction me ek saath move karna hai
class Solution {
public:
//function to create the parent pointer 
    void markparent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent_track, TreeNode* target){
        //use level order 
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left != NULL){
                //node ke left ka father node hi hogi 
                parent_track[node->left] = node;
                q.push(node->left);
            }
            if(node->right != NULL){
                parent_track[node->right] = node;
                q.push(node->right);
            }
        }

    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent_track;
        markparent(root,parent_track, target);
        //till now we called a function which is stored all parent , like who is father of whom
        //now second point we have to move radially till we not reached the distance k 
        unordered_map<TreeNode*, bool> visited;
        //we are taking a record on which till we reached
        queue<TreeNode*> q;
        q.push(target);
        //target jaha se hunme baaki doondni hai 
        visited[target] = true;
        int dist = 0;
        //jaise hi distance k barber ho jaygi vaise hum  ruk jayenge
        while(!q.empty()){
            int n = q.size();
            if(dist == k){
                break;
            }
            dist++;
            // radilaly move karne hai so we are using the loop here 
            for(int i =0; i<n; i++){
                TreeNode* node = q.front();
                q.pop();
                //yadi null nahi hai and ab tak visted nahi kiya hai toh vist kro
                if(node-> left != NULL && visited[node->left] == false){
                    q.push(node->left);
                    visited[node->left] = true;
                }
                if(node-> right != NULL && visited[node->right] == false){
                    q.push(node->right);
                    visited[node->right] = true;
                }
                if(parent_track.find(node) != parent_track.end() &&
                   visited[parent_track[node]] == false){

                    q.push(parent_track[node]);
                    visited[parent_track[node]] = true;
                }
            }
        }
            vector<int> result;
            while(!q.empty()){
                TreeNode* node = q.front();
                q.pop();
                result.push_back(node->val);
        }
        return result;
    }
};
