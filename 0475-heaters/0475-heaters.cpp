//AGGRESSIVE COWDS typa approach

class Solution {
public:
    //helper function should check if all heaters 
    //with radius r can cover all the houses
    //will use two pointers for that

    bool isPossible(vector<int>& a, vector<int>& b, int r){
        int i = 0, j = 0;

        while(i < a.size() && j < b.size()){
            //if house is lower than lower bound 
            if(a[i] < b[j] - r) return false;

            //if house is greater than upper bound
            //check with next heater
            else if(a[i] > b[j] + r)    j++;

            //when that house is covered by heater
            else i++;
        }

        return i == a.size();   //if all houses are covered return true
    }

    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int n = houses.size(), m = heaters.size();
        //search space updated
        int low = 0, high = max(abs(houses[0] - heaters[m - 1]), abs(houses[n - 1] - heaters[0]));

        while(low <= high){
            int mid = (low + high) / 2;

            if(isPossible(houses, heaters, mid))    high = mid - 1;
            else low = mid + 1;
        }

        return low;
    }
};