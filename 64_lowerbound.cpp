//lowerbound is the smallest index(i) which satisy this conditon arr[i] >= target, target se jo value badi hai woh , yadi equal nahi h toh equal to hai toh woh khud
class Solution {
  public:
    int lowerBound(vector<int>& arr, int target) {
    int n = arr.size();
    int ans = n;
    int left = 0;
    int high = n-1;
    while (left <= high){
        int mid = left + high;
        if(arr[mid]>=target){
            ans = mid;
        high = mid -1; /*
             what if target same huwa toh then hume value toh doodni hai but uske 
             hume smallest index bhi doondna hai hai jo iss condition find kre
            */
        }
        else{
            ans = mid;
            left = mid-1; // jab llop baar baar chlwgi toh khud value ajayegi first statement se
        }
    }
    return ans;
    }
};
