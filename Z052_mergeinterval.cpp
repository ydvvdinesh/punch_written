//approach - iterate kro , jaha overlap ho rhaha hai wah , usko proper merge kro and merge kiye hue ko next ke saath compafe kro , and , mrerge krne ke baad waale ko hum ek array me rakhnge jo last waale se compare ho paye

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        for(int i =0; i<n; i++){
            // back ka last index 
            //intervals[i][0] - i index ka array , us index ka 0 part
            if(ans.empty() || ans.back()[1] < intervals[i][0]){
                ans.push_back(intervals[i]);
            }
            //yadi overlapping ho rahi hai toh lat waala maximum hoga range and and first waala minimum
            else{
                ans.back()[1] = max(intervals[i][1], ans.back()[1]);
            }
        }
        return ans;
    }
};
