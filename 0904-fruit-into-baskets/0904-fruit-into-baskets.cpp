//map worked as set
//sliding window
//after having 3 distinct fruits
//move left and decrement map

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mpp;
        int l = 0, r = 0;
        int res = 0;

        while(r < fruits.size()){
            mpp[fruits[r]]++;

            if(mpp.size() > 2){
                while(mpp.size() > 2){
                    mpp[fruits[l]]--;

                    //js like in set we delete the key
                    //once its value becomes 0
                    if(mpp[fruits[l]] == 0)
                        mpp.erase(fruits[l]);

                    l++;
                } 
            }

            res = max(res, r - l + 1);
            r++;
        }

        return res;
    }
};