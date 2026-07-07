//same concept like n meetings in the room 
// we have to return the minimum number count  of the uinterval to remove so all overlapping went delete
//ans = total - which is possible(without overlapping)
//which is possible(without overlapping) - n meting waala concept ;ga denge one time 

//ascending order rakhna hai
    static bool comp(vector<int>& a, vector<int>& b){
        return a[1]< b[1];
    }

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        //sort according to end time 
        sort(intervals.begin(), intervals.end(), comp);
        int count = 1; //First interval is already selected
        int lastendtime  = intervals[0][1];
        //meeting tabhi assign kar skte hai jab pheli khatam ho that means nextstarttime > lasttime
        for(int i =0; i<n; i++){
            if(intervals[i][0] >= lastendtime){ // equal to only for this question
                count++;
                lastendtime = intervals[i][1]; // lastendtime will assgin next to the thing
            }
        }
        return (n-count);
    }
};
