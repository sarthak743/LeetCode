//question similar to AGGRESSIVE COWS
//lowest minimum value is 1 
//largest minimum value is n = (maxi - mini)
//so we would search in 1 to n 
//and for a value if we could place those many cows (balls here) then we take the value and move forward
//to optimize we use binary search instead of linear search

class Solution {
public:
    //arr -> array, d -> distance, c -> number of cows
    bool isPossible(vector<int>& arr, int d, int c){
        int cnt = 1;       //to count the number of cows placed
        int last = arr[0];      //to memorize the position of recently placed cow

        for(int i = 1; i < arr.size(); i++){
            if(arr[i] - last >= d){
                cnt++;      //cow is placed so we move forward to place next cow 
                last = arr[i];      //updating the position of recently placed cow
            }

            if(cnt >= c)    return true;       //once we placed all cows no need to search more and we return true
        }

        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        //binary search cant be done w/o sorted array
        sort(position.begin(), position.end());
        int n = position.size() - 1;
        int low = 1, high = position[n] - position[0];

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(isPossible(position, mid, m))    low = mid + 1;  //if at mid its possible then all values lesser than mid is possible so we skip them
            else high = mid - 1;        //opposite above
        }

        return high;
    }
};