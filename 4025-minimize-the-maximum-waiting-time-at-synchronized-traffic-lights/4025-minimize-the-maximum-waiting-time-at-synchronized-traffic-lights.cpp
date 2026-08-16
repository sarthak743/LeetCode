//get remainder of every car arrival time
//search if theres a light greater than remainder
//if not found append the (period - rem) else 0
//to optimize search use binary search

class Solution {
public:
    bool isfound(int rem, vector<int>& arr){
        int low = 0, high = arr.size() - 1;

        while(low <= high){
            int mid = low + (high - low) / 2;
            if(arr[mid] > rem)
                return true;
            else 
                low = mid + 1;
        }

        return false;
    }

    
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int rem = 0;
        int waitin = 0;
        sort(lights.begin(), lights.end());
        
        for(int i = 0; i < arrivalTime.size(); i++){
            rem = arrivalTime[i] % period;
            if(!isfound(rem, lights))
                waitin = max(waitin, period - rem);            
        }

        return waitin;
    }
};