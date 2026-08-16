//more optimal 
//penalty only gets updated when we dont find light greater than remainder

class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int maxi = *max_element(lights.begin(), lights.end());
        int result = 0;

        for(int i = 0; i < arrivalTime.size(); i++){
            int r = arrivalTime[i] % period;

            if(r >= maxi)
                result = max(result, period - r);
        }

        return result;
    }
};