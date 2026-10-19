class Solution {
public:
    void recursion(int i, int a, int b, vector<vector<int>>&c, vector<int>d){
        if(d.size() == b){
            c.push_back(d);
            return;
        }

        for(int j=i+1; j<=a; j++){
            d.push_back(j);
            recursion(j, a, b, c, d);
            d.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        if(n == 1)
            return {{1}};

        vector<vector<int>> res;
        vector<int> arr;

        for(int i=1; i<=n; i++)  
            recursion(i, n, k, res, {i});

        return res;
    }
};