//exact sma elike combination sum 1 , bus isme unique chayiye toh we first sort the array and second thing we have to bring in our mind that is unique chayiye , so for this we can`t take one index again and aganin in terms of getting sum so and thiord and the main thing if we are nt pickiuping that element that rest of the element is same number like it then we move to number which is different from that number 
//ex 1,2,2,2,2,5 so when we are picking up 2 so we to move to the number which is not 2 or fdiffernet , so we hvae to start again from the different number 
class Solution {
public:
    void f(int ind,vector<vector<int>>& ans,vector<int>& list , vector<int>& candidates,int sum, int n){
        if(sum == 0){
            ans.push_back(list);
            return;
        }
        if(sum <0 || ind == n){
            return;
        }
        // we are taking, at every time naye index pe pauchenge 
        list.push_back(candidates[ind]);
        f(ind+1, ans, list, candidates, sum - candidates[ind],n);
        list.pop_back();
        // if we are not taking, jab we have to start from the new one always , yadi new one hai toh koi dikkat nahi hai , and nahi hai toh hi loop chlayi woh aap new tak paucha dega 
        for(int j = ind+1; j<n; j++){
            if(candidates[j] != candidates[ind]){
                f(j, ans, list, candidates, sum,n);// yadi nahi le rahe sum bhi nahi lenge na 
                break;
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        //sort kare bina hume pta nahi lageaga
        sort(candidates.begin(),candidates.end());
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> list;
        f(0,ans,list, candidates, target, n);
        return ans;
    }
};
