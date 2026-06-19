//stock span problem - maximum xonsecutive days inn which the stock price will be lower or equal to current day, index representing day and vakue is representing the stock price
//brute force approach- add element to array and back traverse karke count kro kitne jo smaller hai and consecutive waale
class StockSpanner {
public:
    vector<int> arr;
    StockSpanner() {
        vector<int> arr;
    }
    
    int next(int price) {
        arr.push_back(price);
        int maxi =0;
        int count =1;
        for(int i = arr.size()-2 ; i>=0; i--){
            if(arr[i] <= price) count++;
            else{
                break;
            }
            //maxi = max(maxi,count); //no need of maxi because count har baar increase hi horha hai jaha , count automatically answer stiore kar rha hai by our using break
        }
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
