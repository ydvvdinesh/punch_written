//hume total paani btana hai jo store huwa 
//brute force - pani wahi rukega jaha depth hogi , and depth un buliding pe hogi jinke left and right waali badi buliding hai 
//ek bulding ke baaju me do buliding hogi jinke beech paani bherga and , un dono me jiski height kaam hogi uss level tak paani bherga , otherwise woh streets me float kr jayega
//total = answer hai
//har bulding ke upper jitna paani hoga after left and rightwaali buliding ki constrant ke baad usko hume jodete jayenge 
//formula - min(leftmax,rightmax) - arr[i]
//minimum waale ke level me paani aayega , fir us postion waali hieght ko hta do toh water store bch jayega
//leftmax woh buliding jo left me bdi hai uss specific position se 
//rightmax woh buliding jo left me bdi hai uss specific position se 
//for finding leftmax we use prefix sum 
//for finding rightmax we use concept of suffix sum
class Solution {
public:
//prefix sum - these function return a array of left max at that specifc position
vector<int> prefixsum(vector<int>& height){
    int n = height.size();
    vector<int> prefix(n,-1);
    prefix[0] = height[0];
    for(int i = 1 ; i<n; i++){
        prefix[i] = max(height[i], prefix[i-1]); // prefix is the array storing the leftmax for every particular position
    }
    return prefix;
}
//suffix sum
vector<int> suffixsum(vector<int>& height){
    int n = height.size();
    vector<int> suffix(n,-1);
    suffix[n-1] = height[n-1];
    for(int i = n-2 ; i>=0; i--){
        suffix[i] = max(height[i], suffix[i+1]); // prefix is the array storing the leftmax for every particular position
    }
    return suffix;
}
    int trap(vector<int>& height) {
        //now we store a array of prefix,
        vector<int> prefix = prefixsum(height);
        vector<int> suffix = suffixsum(height);

        int n = height.size();
        int total =0;
        for(int i =0; i<n; i++){
            int leftmax = prefix[i];
            int rightmax = suffix[i];
            total = total + min(leftmax,rightmax) - height[i];
        }
        return total;
    }
};
