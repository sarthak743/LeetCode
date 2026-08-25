class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        map<int, int> map;
        for(int i = 0; i < nums.size(); i++)
            map[nums[i]]++;

        int i = k;
        while(map[i]){
            i = i + k;
        }

        return i;
    }
};