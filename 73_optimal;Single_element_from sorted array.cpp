//simple logic if even,odd ye index hai pair ka jo duplicate h toh hum left part me hume elminate kro , element dusre me hai
/* Standing index dekho even ya odd index , yadi even h toh pair check kro yadi element same hai ya duplicate hai toh iska mtlb hum left part me 
for left part duplicates will stay in order of even,odd inde
for rightpart duplicates will stay in order of odd, even 
toh hum ek ke hisab se chelenge 
1.find the part and elinate our same ,
even hai toh right waale check krenge , yadi hume odd mila toh even check krenge jisme stand krenege ussse dusra check krenge 
aur yadi element mila toh toh orf=der ke hisab se part ho jayega
 */
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 1;// kyuki isse phele koi nahi hai
        int high = n-2; //kyuki iske baad koi nahi hai
        if (n==1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[n-1] != nums[n-2]) return nums[n-1];
        while (low <= high){
            int mid = (low + high)/2;
            if (nums[mid] != nums[mid+1] && nums[mid] != nums[mid-1]){
                return nums[mid];
            }
            // hum code dono part ke liye likhte because we don`t know the which question coming
            // left part - pair duplicates index = even, odd  
            // of omdex is odd that means we have to check the left part
            //or
            // if index is even then in left part we have to check the next one is which is odd
            if((mid%2 ==1 && nums[mid] == nums[mid-1]) || 
            (mid%2 == 0 && nums[mid] == nums[mid+1])){ 
                //eliminate the part jisme me hum hai 
                low = mid +1;
            }
            else{
                high = mid - 1;
            }
        }
        return -1;
    }
};
