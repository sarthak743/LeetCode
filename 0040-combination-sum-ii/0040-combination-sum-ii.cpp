//OPTIMAL

//multiple recursion calls

//we will try to make less recursion call
//first sort the array
//at each call explore rest of array and skip duplicate (except the first one from duplicates)
//add element that comes while exploring


class Solution {
public:
    void recursion(int i, vector<int>&arr, vector<vector<int>>&s, vector<int>&curr, int t){            
        if(t == 0){
            s.push_back(curr);
            return;
        }
        
        for(int j=i; j<arr.size(); j++){
            //skip duplicate
            if(j > i && arr[j] == arr[j-1])
                continue;

            //if element found is greater than target 
            //means rest all elements is greater than target
            //so we break
            if(arr[j] > t)
                break;
            
            curr.push_back(arr[j]);
            recursion(j+1, arr, s, curr, t - arr[j]);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> res;
        vector<int> curr;

        recursion(0, candidates, res, curr, target);

        return res;
    }
};