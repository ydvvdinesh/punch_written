//logic - consecutive doondo and jo bhi consecutive sequence me include hone layak hai uske liye count 1 increase krdo
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n==0){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int count =0; // track the count of the element which can bhe happened in sequence
        int lastsmaller = INT_MIN; // lastsmaller is the variable tracking the every last appearence of element in the array when move to next element of array
        int longest =1; // longest is the variable tracking the sabse jada kisi count raha
        for (int i = 0; i<n; i++){
            if (nums[i] - 1 == lastsmaller){ // yadi nums ki value me se ek ghatya toh lastnumber hi milega or aage vale ki value se one decrease toh last number hi milega , 
            //yaha pe nums[i]-1 count krnege , lastsmaller toh khud milta jayega yaadi toh same hai iska mtalb lastsmaller +  1 = next number toh consecutive ho gaye na 
            count = count +1;
            lastsmaller = nums[i]; // jab aage badhenge toh toh present number past me jaake lastsmaller ho jayegaa 
            }
            else if(nums[i] == lastsmaller){ // yadi dono same hai toh next element pe chle jayenge 
                continue;
            }
            // ye condition hai yadi 4 se sidha 100 ka element aajaye
            //we always start the count from 1 because khud ka khud me hoga if the last smaller is not equal to new number or not lesser than 1
            else if (lastsmaller != nums[i]){
                count = 1; // naya sequence se kaam shuru
                lastsmaller = nums[i];
            }
            longest = max(count , longest);
        }
        return longest;
    }
};
