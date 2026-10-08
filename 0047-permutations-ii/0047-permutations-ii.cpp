//js like optimal of part 1
//need to handle duplicate 

//as we alter given array at every step 
//they dont remain sorted at each call

//so instead of checking adjacent we check if element exists in map or not
//and skip likewise

class Solution {
public:
    void recursion(int i, vector<int>&arr, vector<vector<int>>&r){
        if(i == arr.size()){
            r.push_back(arr);
            return;
        }

        unordered_map<int, int> mpp;
        for(int j=i; j<arr.size(); j++){
            //handling duplicates
            if(mpp[arr[j]])
                continue;
            mpp[arr[j]]++;            
            
            swap(arr[i], arr[j]);
            recursion(i+1, arr, r);
            swap(arr[i], arr[j]);            
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        recursion(0, nums, res);
        return res;
    }
};