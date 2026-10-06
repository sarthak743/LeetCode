//not optimal since it take map 
//multiple recursion call 

//we will have map of size of nums
//get an element mark it as visit then explore whole array
//take not visited element and do recursion call
//do it for all elements 

class Solution {
public:
    void recursion(vector<int> arr, vector<vector<int>>& res, vector<int>& curr, vector<int> f){
        //when all are visited meaning all elements is in curr
        //so if size of curr and size of arr must be same
        if(curr.size() == arr.size()){
            res.push_back(curr);
            return;
        }
        for(int i=0; i<arr.size(); i++){
            //if visited skip it
            if(f[i])
                continue;

            curr.push_back(arr[i]);
            f[i]++;         //mark it as visited
            recursion(arr, res, curr, f);

            //backtracking
            curr.pop_back();
            f[i]--;         //mark it as unvisited and go for further element
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> a;
        vector<int> freq(nums.size(), 0);

        recursion(nums, res, a, freq);

        return res;
    }
};