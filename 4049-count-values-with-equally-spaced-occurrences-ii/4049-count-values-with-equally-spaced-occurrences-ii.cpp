//similar to 4048
//js element should occur atleast thrice

class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, vector<int>> mpp;
        int res = 0;

        for(int i=0; i <nums.size(); i++)
            mpp[nums[i]].push_back(i);      //most imp line to remember

        for(auto x : mpp){
            //take element which appear atleast thrice
            if(x.second.size() > 2){
                int diff = x.second[1] - x.second[0];
                bool found = false;

                for(int i=2; i<x.second.size(); i++){
                    //if not equally spaced take other element
                    if(x.second[i] - x.second[i-1] != diff){
                        found = true;
                        break;
                    }
                }

                if(!found)
                    res++;
            }
        }

        return res;
    }
};