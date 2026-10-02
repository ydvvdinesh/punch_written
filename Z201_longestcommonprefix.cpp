//common prefix btana hai 
//we go with a logic sort krenge , then hum first ko pakdenge and last waala un dono do common hai woh return kar denge kyuki middle waala toh hunke beeche hi ie krenge
//comparsion kreng ejo alag nikla usko store kren lenge 
class Solution{	
	public:
		string longestCommonPrefix(vector<string>& str){
			int n = str.size();
            sort(str.begin(), str.end());
            string ans;
            string first = str[0];
            string last = str[n-1];
            int m = min(first.size(),last.size());
            for(int i =0; i<m; i++){
                if(first[i] != last[i]){
                    break;
                }
                    ans += first[i];
            }
            return ans;
		}
};
