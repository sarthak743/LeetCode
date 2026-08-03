//used hashing
//then check each number we they are present or not iteratively

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int maxi = *max_element(arr.begin(), arr.end());
        vector<int> mpp(maxi + 1, 0);
        int count = 0;

        for(int i = 0; i < arr.size(); i++)     mpp[arr[i]]++;

        for(int i = 1; i <= maxi; i++){
            if(mpp[i] == 0){
                count++;
                if(count == k) return i;
            }
        }

        return maxi + (k - count);      //when the desire number is out of array
    }
};