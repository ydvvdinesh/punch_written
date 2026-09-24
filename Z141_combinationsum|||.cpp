//bahut easy hai , isme bhi sab subsequence generate karne hai jinka size k ho , sum n ho 
//hume maximum possible way nikalne hai toh hum recursion se jayenge 
//iss baar sab take hi karne hai like 1 element me gaye toh use baaki element elements ke saath pair bnaoo then phit se aisa kro toh saare subsequence gneerate ho jayenge , unique bnane hai toh har baar index bdhate jaana 
// 2nd element pe gaye toh ab uske pass third elemet se last elemtntak ke saare possible case lene hai , yadi do eleement hai element hai toh , last elelemnt ke aage se shuru karna hai 
//and target ko todke zero oe laooo
//isme sab we are taking hi chlega 
class Solution {
public:

    void f(int sum, vector<vector<int>>& ans, vector<int>& list, int k){
        if(sum == 0 && list.size() == k){
            ans.push_back(list);
        }
        
        if(sum <0 || list.size()>k){
            return;
        }
        //jaha se next subsequence start karke last tak jaana hai 
        int element = list.empty()?1:list.back()+1;
        // har ke pass 9 element ke pass jaane ke raaste hai, 1 to 9 tak jaaana hai 
        for(int i = element; i<=9; i++){
            if(i<=sum){
            list.push_back(i);
            f(sum-i,ans,list,k);
            list.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
    	vector<vector<int>> ans; 
        vector<int> list;
        f(n,ans,list,k);
        return ans;
    }
};
