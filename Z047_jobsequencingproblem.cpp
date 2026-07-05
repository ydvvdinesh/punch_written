class Solution {
public:

    static bool comp(vector<int> &a, vector<int> &b){
        return a[2] > b[2];   // sort according to profit
    }

    vector<int> JobScheduling(vector<vector<int>>& Jobs) {

        int n = Jobs.size();

        sort(Jobs.begin(), Jobs.end(), comp);

        int maxDeadline = 0;

        for(int i = 0; i < n; i++){
            maxDeadline = max(maxDeadline, Jobs[i][1]);
        }

        vector<int> slot(maxDeadline + 1, -1);

        int count = 0;
        int profit = 0;

        for(int i = 0; i < n; i++){

            for(int j = Jobs[i][1]; j >= 1; j--){

                if(slot[j] == -1){

                    slot[j] = Jobs[i][0];   // store job id
                    count++;
                    profit += Jobs[i][2];
                    break;
                }
            }
        }

        return {count, profit};
    }
};
