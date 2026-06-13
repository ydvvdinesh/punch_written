//optimal appeoach - sum of subarray maximum - sum of subarray minimun
class Solution {
public:

    vector<int> prevSmaller(vector<int>& nums){
        int n = nums.size();
        vector<int> pse(n);
        stack<int> st;

        for(int i = 0; i < n; i++){
            while(!st.empty() && nums[st.top()] > nums[i]){
                st.pop();
            }

            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return pse;
    }

    vector<int> nextSmaller(vector<int>& nums){
        int n = nums.size();
        vector<int> nse(n);
        stack<int> st;

        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }

            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return nse;
    }

    vector<int> prevGreater(vector<int>& nums){
        int n = nums.size();
        vector<int> pge(n);
        stack<int> st;

        for(int i = 0; i < n; i++){
            while(!st.empty() && nums[st.top()] < nums[i]){
                st.pop();
            }

            pge[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return pge;
    }

    vector<int> nextGreater(vector<int>& nums){
        int n = nums.size();
        vector<int> nge(n);
        stack<int> st;

        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && nums[st.top()] <= nums[i]){
                st.pop();
            }

            nge[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return nge;
    }

    long long subArrayRanges(vector<int>& nums) {

        int n = nums.size();

        vector<int> pse = prevSmaller(nums);
        vector<int> nse = nextSmaller(nums);

        vector<int> pge = prevGreater(nums);
        vector<int> nge = nextGreater(nums);

        long long minSum = 0;
        long long maxSum = 0;

        for(int i = 0; i < n; i++){

            long long leftMin = i - pse[i];
            long long rightMin = nse[i] - i;

            minSum += 1LL * nums[i] * leftMin * rightMin;

            long long leftMax = i - pge[i];
            long long rightMax = nge[i] - i;

            maxSum += 1LL * nums[i] * leftMax * rightMax;
        }

        return maxSum - minSum;
    }
};
