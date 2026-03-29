//brute approach
class Solution {
public:
    long double minimiseMaxDistance(vector<int> &arr, int k) {
       int n = arr.size();
       vector<int> howmany(n-1,0);
       for (int gas = 1; gas<=k; gas++){//loop for placing the gas statiom 
        int maximumvalue = -1;
        int maximumindex = -1;
        for (int i = 0 ; i<n-1; i++){//loop for finding the section length for every particular section 
        // jiska 
        long double diff = arr[i+1] - arr[i];
        long double sectionlength = diff/(howmany[i]+1); // this is the way to find the section length ye hi toh find karna , toh ye formula hai
        if(maximumvalue < sectionlength){ // sectionlength of that after minimise bhi badi hi toh that we want
        maximumvalue = sectionlength;
        maximumindex = i; //is index pe section length jada hai
        }
        }
        howmany[maximumindex]++;
       }
       // 
       long double maxans = -1;
       for (int i = 0 ; i<n-1; i++){
         long double diff = arr[i+1] - arr[i];
        long double sectionlength = diff/(howmany[i]+1); 
        maxans = max(maxans,sectionlength);
       }
       return maxans;
    }
};
