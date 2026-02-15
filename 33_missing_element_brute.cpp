// logic - ek sequence khud sochenge chlenge from 1to n and array ke elements se compare krwayenge , jo nahi mila wo hi missing h 
//flag = 1 → number exists in array ❌ (not missing) and flag = 0 → number does NOT exist in array ✅ (this is missing)
// do loop chlengi pheli waali sequence (0 to n) ke liye and second array me chlegi (array ke index ko iterate krwayegi jisse hum jaan paye ki hai ya nahi) , aur sequence ko array ke elemnts se compare krwana hai jo elements arr me nahi hoga wohi missing hai , 
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(); 
        for (int i = 0 ; i<=n; i++){
            int flag = 0;
            for (int j = 0; j<n; j++){
                if (nums[j]==i){
                    flag = 1; 
                    break; // jaise hi eual milega ye sidhaloop khatam kr denge , ex - it doesnt happen +1 i got it , uske baad ki saari statement ruke jayegi
                }
            }
        if (flag==0){
            return i;
        }
        }
    return -1;    
    }
};
