//interval ko ek correct order se lgana hai and remeber this non overlapping nature ka woh hoga , toh jo overlap krega unke sab ke first ka minimum and last ka maximum leke ek range bnda denge usme cover ho jayenge and usko push krdenge
//easy we disrtibute question in 3 parts  left right middle , middle jaha over lapping ho rahi usko proper range me laake add krdenge and baaki ko direct entry 
// left and right me sahi hai unko directly new aaray me dalte raho
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size(); //m ki jaroort hai nahi size 2 hi hai interval ka
        vector<vector<int>> res; //hum naye array me ye saari value daalenge
        int i = 0; //for traversal 
        //purane ka last and new ka first
        while(i<n && intervals[i][1] < newInterval[0]){
            res.push_back(intervals[i]); // jo sahi hai unko daalo new array me
            i++;
        }
        // middle 
        // purane waale first and naye waale ka last
        while(i<n && intervals[i][0] <= newInterval[1]){
            //minimum in first ones
            //maximum in last
            newInterval[0] = min(intervals[i][0],newInterval[0]);
            newInterval[1] = max(intervals[i][1],newInterval[1]);
            i++;
        }
            res.push_back(newInterval);
        //right
        while(i<n){
            res.push_back(intervals[i]);
            i++;
        }
        return res;
    }
};
