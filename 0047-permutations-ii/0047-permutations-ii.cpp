//js like optimal of part 1
//need to handle duplicate 

//similar to better soln of part 1 and optimal soln of combination 2

//sort array
//get freq map to mark element as taken or not
//to handle duplicates check adjacent elements
//if prev is equal to current element 
//and prev one is not used then skip
//else take the current element and do further recursion

class Solution {
public:
    void recursion(vector<int>&arr, vector<vector<int>>&r, vector<int>&curr, vector<int>&f){
        if(curr.size() == arr.size()){
            r.push_back(curr);
            return;
        }

        for(int j=0; j<arr.size(); j++){
            if(f[j])
                continue;

            if(j>0 && arr[j] == arr[j-1] && f[j-1] == 0)
                continue;

            curr.push_back(arr[j]);
            f[j]++;
            recursion(arr, r, curr, f);
            curr.pop_back();
            f[j]--;     
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> a;
        vector<int> freq(nums.size(), 0);

        recursion(nums, res, a, freq);
        return res;
    }
};