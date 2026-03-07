class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        vector<vector<int>> ans;
        for (int i = 0; i<n; i++){
            //back() returns the last element of the vector. and ans.back()[1] - Now we access the second element of that last interval.
            if (ans.empty() || ans.back()[1]< intervals[i][0]){ //conditoon - if 2nd ofprevious is lesser then 1st of new one
            ans.push_back(intervals[i]);
            }
            else{
                // fir toh bad value update krni hai new end ki
                ans.back()[1] = max( ans.back()[1], intervals[i][1]); //arr[i][1] - new end ki value 
                // ye jo purane end ki chalti aarahi thi woh
            }
        }
        return ans;
    }
};
