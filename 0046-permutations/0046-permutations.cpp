//optimal
//w/o freq map

//refer video cant explain here

class Solution {
public:
    void recursion(int i, vector<int> arr, vector<vector<int>>& res){
        if(i == arr.size()){
            res.push_back(arr);
            return;
        }

        for(int j=i; j<arr.size(); j++){
            swap(arr[j], arr[i]);

            recursion(i+1, arr, res);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;

        recursion(0, nums, res);

        return res;
    }
};