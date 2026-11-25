class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int no_of_subsets = 1 << nums.size();
        vector<vector<int>> res;

        for(int i=0; i<no_of_subsets; i++){
            vector<int> temp;

            for(int j=0; j<nums.size(); j++){
                //if set bit then take it
                if(i & (1 << j))
                    temp.push_back(nums[j]);
            }

            res.push_back(temp);
        }

        return res;
    }
};

//for ex. input {1, 2}

//0  ==>  0  0
//1  ==>  0  1
//2  ==>  1  0
//3  ==>  1  1

//0 in binary means dont take element at that index
//1 in binary means take element at that index

//0  0      {}
//0  1      {1}
//1  0      {2}
//1  1      {1, 2}