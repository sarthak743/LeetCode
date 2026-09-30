//at each position we got two options
//either we take element append and reduce target by it
//or skip that element and move ahead

class Solution {
public:
    void recursion(int i, vector<int> a, vector<int>&b, vector<vector<int>>&c, int t){
        //since given array has positives only
        //so if target get reduced to negative we should stop 
        if(t < 0)
            return;

        //when some sequence satisfies target
        //target get reduced to 0 and we append it 
        if(!t){
            c.push_back(b);
            return;
        }

        //take curr element
        //and reduce target with that element
        if(i < a.size()){
            b.push_back(a[i]);
            recursion(i, a, b, c, t - a[i]);
        }

        //dont take curr element and move ahead
        if(i < a.size()){
            b.pop_back();
            recursion(i+1, a, b, c, t);
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> def;
        recursion(0, candidates, def, res, target);

        return res;
    }
};