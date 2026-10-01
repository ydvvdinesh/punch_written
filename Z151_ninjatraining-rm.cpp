// thoda sa bada not hard hai , ye dhayn rakhna hai jo last time acticity ki thi usse alag hi karni hai 
class Solution {
public:
    // for which we are looking , which task i performed in the last, the given matrix
    int func(int day, int last, vector<vector<int>>& matrix, vector<vector<int>>& dp ){
        int n = matrix.size(); // rows, because task toh 3 hi hai , task 0, task 1, task 2 , it means it 3 hi column honge 
        // base condition , where it gonna stop, it days on last what are we getting or the guy is doing what ccording to we get answer
        if(day == 0){
            int maxi = 0; // storing the maximum merit point , after trying out all the activity, which activity is giving us the maximum thing we get that one 
            for(int task =0; task<3; task++){
                if(task != last){ // alag hi chayiye 
                    maxi = max(maxi, matrix[day][task]); // har task ke through jaana hai phir maximum waali store krenge
                }
            }
            return maxi;
        }

        //ye toh base case ka ho gaya and now har day ke liye fo cheeze karne kanri, last day konsi perform ki , kyuki jo karli woh next day nahi krenge toh hmare pass 2 possible way honge , jo hum select kar skte hai , unn dono mai se maximum lenge 

        if(dp[day][last] != -1){
            return dp[day][last];
        }
        //uss day jo maximum liya hai , jo piche se maximum lete aarhe hai and jod rahe hai that`s give us the maximum answer 
        int maxi = 0;
        for(int task = 0; task<3; task++){
            if(task != last){ // the task we are performing right now, it is not equal to last one we performed , so then we move ahead
            //the day on we are trying for other remaining task which is not performed + cumulatuve jo piche se chalta aarha hai 
                int points = matrix[day][task] + func(day-1, task, matrix, dp);
                // we have to pick activity which have maximum point , till now we are only trying 
                maxi = max(points, maxi);
            }
        }
        return dp[day][last] = maxi;
    }

    int ninjaTraining(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(4,-1));
        return func(n-1, 3, matrix, dp);
    }
};
