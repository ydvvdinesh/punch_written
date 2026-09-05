//start ko har number se multiplekrwaoo  given array waalo se,total multple operation count kro and un teeno ke reult ko aise hi har ek ko multiply krwaoo and dueing this dijstra lgaoo woh khud bta dega minimum no of steps , har mutliple me 1 operation hi badh ta hai 
class Solution{
public:
    int minimumMultiplications(vector<int> &arr, int start, int end) {
          // Base case
        if(start == end) return 0;

        int n = arr.size();
        int mod = 100000; // mod
        queue<pair<int,int>> q; //node , steps / count
        vector<int> dist(mod,1e9);
        // this array will storing the steps we want to reach that node
        //distance or steps storing array array store the shortest path , distance to through that node and jo pichle se chota hota hai wohi queue me jaata hai , yaadi bda hai toh hume phir uski kya hi zaroorat hai
        dist[start] = 0;
        q.push({start,0});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int node = it.first;
            int steps = it.second;

            //
            for(auto ti : arr){
                int num = (ti * node)%mod;
                 if(num == end) return steps+1;
                 if(steps + 1 < dist[num]){
                    dist[num] = steps + 1;
                    q.push({num, dist[num]});
                 }
            }
        }
        return -1;
    }
};
