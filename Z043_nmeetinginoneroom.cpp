// we created a own data structure to store this
struct meeting{
    int start, end, pos;
};

//ascending order 
bool comp(const meeting &a, const meeting &b){
    return a.end < b.end;
}

class Solution{
    public:
    int maxMeetings(vector<int>& start, vector<int>& end){
        int n = start.size();
         vector<meeting> ds(n); // list created  , we can ds is array
        //put data into data structure
        for(int i =0;i<n;i++){
            ds[i].start = start[i];
            ds[i].end = end[i];
            ds[i].pos = i+1;
        }
        // now use comp method 
        sort(ds.begin(), ds.end(), comp);

        //we have to count 
        int count =1;
        int freetime = ds[0].end;
        for(int i =1; i<n;i++){
            if(ds[i].start > freetime){
                count++;
                freetime = ds[i].end;
            }
        }
        return count;
    }
};
