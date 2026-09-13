//MAP == 
//1 -->  {0, 2, 4}      <--special
//8 -->  {1, 6}
//5 -->  {3, 5, 7}      <--special

class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        //map will have element and as values itll hv all indices it appears on
        unordered_map<int, vector<int>> mpp;
        int res = 0;

        for(int i = 0; i < nums.size(); i++)
            mpp[nums[i]].push_back(i);

        //iterate map
        for(auto x : mpp){
            //number is special only if it occurs thrice
            if(x.second.size() == 3){
                //res++ if that element is special
                if(x.second[2] - x.second[1] == x.second[1] - x.second[0])
                    res++;
            }
        }

        return res;
    }
};