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
 //easy hai - main root me ek graph bna do x axis and y axis ka and , x axis pe vertical naam rakho and zero point humare give node mtlb root ka hoga uske right me +1 and left me -1  according to maths, and level waale axis ko root pe 0 and 1 then 2 then 3 assign kardo , and hume vertical moove karna hai that`s means left ki first node / first vertical ko pakde then second vertical ko pakde and aise hi move krte rahe and map me store karte rahe
class Solution {
public:

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        //queue and map and vector declaration dekh lena thoda hard hai baaki easy hai
        vector<vector<int>> ans;
        map<int, map<int, multiset<int>>> nodes;
        //queue me pair me node , vertical , leaf aayege
        queue <pair<TreeNode* , pair<int, int>>> q;
        //root ko zero vertical aur zero level pe daal diya
        q.push({root,{0,0}});
        while(!q.empty()){
            //pair then uske aandar nodes and sab
            auto p = q.front(); // p is the complete pair 
            //auto will decide kya aayega that thing
            q.pop();
            TreeNode* node = p.first;
            int vertical = p.second.first;
            int level = p.second.second;
            //push the every node into map that storing the value
            nodes[vertical][level].insert(node->val);
            // left children toh level niche jayega and acc to maths -1 increase hoga left me 
            if(node->left != NULL){
                q.push({node->left,{vertical-1, level+1}});
            }
            if(node->right != NULL){
                q.push({node->right,{vertical+1, level+1}});
            }
        }
        // till now while loop saara ko map me store kar legi 
        //now we have to add in the answer 
        for(auto p : nodes){
            vector<int> col;
            for(auto z : p.second){
                col.insert(col.end(), z.second.begin(), z.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};
