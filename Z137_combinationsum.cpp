// ek dum simpmilar hai powerset and subsequence walli problem ke bus ek difference , have in subsequence hum saare ko saath leke chlte the jis se hum ek element ko ek baar hi le skte the but yaha hum ek element ko kitni baar leke skte hai hum sequence chayiye
//approach - take it or not take 
//yadi take it hai , iska maltab hum usse lenge and tab tak lenge jab tak base condition reach na ho jaye kyuki kya pta baar baar lene se answer mil jaye and not take it , iska mtlb hai waha se answer nahi mila toh hum aage badh jayenge next index me aayehe phir usse ye dekheneg take or not it 
// f(in,list,ans,summ) = ind - the index we have to process , aagla index ye process krenge iska element lenge 
//ex- f(0,list,ans,sum) = next index jispe hum kaam krenge owh zero hoga 
//sum - jab bhi hum sequence me value add krnege toh woh sum mai se minus krenge, jaise hi zero hoga mtlb woh subsequmece ka sum taregt ke equal hai 
//hum ulta chlte hai jode nahi tod ke answer nikal rahe hai 
class Solution {
public:
    
    void f(int ind,vector<vector<int>>&ans, vector<int>& list, vector<int>& candidates , int sum, int n){
        if(sum == 0){
            ans.push_back(list);
            return;
        }
        // yadi next jo processkarne ko bole utne ho hi nah toh 
        if(sum < 0 || ind == n){ 
            return;
        }
        //now we take, yadi le rahe toh next bhi usse hi lenenge until woh galat nah ho , toh usse index ko baar baar process karnege
        list.push_back(candidates[ind]);
        f(ind,ans,list,candidates,sum-candidates[ind],n);
        list.pop_back();

        //if we are not taking that index toh agle pe badh jaoo, jab liya hi nahu toh sum goh utna hi rhega na 
        f(ind+1, ans, list, candidates, sum,n);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
         int n = candidates.size();
         vector<vector<int>> ans;
         vector<int> list;
         f(0,ans,list,candidates, target, n);
         return ans;
    }
};
