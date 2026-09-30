//house robber || similar hai but is cyclic hai , hosue robber 1 ek dum same hai maximum sum of no adjscent element 
//so exact same hai maximum non adjacent sum element ke , bus ek catch hai isme last and first connected hai so, ek baar first ko chode ke sab ki beech maximum sum of non adacent nikalenge and ek baar hum last ko chhod ke 
class Solution {
public:
    int func(vector<int>& money){
        int n = money.size();
        int prev = money[0]; 
        int prev2 = 0;
        for(int i = 1; i<n; i++){
            int pick = money[i];
            if(i>1){
                pick = money[i] + prev2;
            }
            int nonpick = 0 + prev;
            int curr = max(pick, nonpick);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }

    int houseRobber(vector<int>& money) {
        int n = money.size();
        vector<int> temp_leavefirstone;
        vector<int> temp_leavelastone;
        // Only one house 
        if(n == 1) return money[0];
        for(int i = 0; i<n; i++){
            if(i != 0){
                temp_leavefirstone.push_back(money[i]);
            }
            if(i != n-1){
                temp_leavelastone.push_back(money[i]);
            }
        }
        int first = func(temp_leavefirstone);
        int second = func(temp_leavelastone);
        return max(first, second);
    }
};
