class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        vector<int> res;
        int n = matrix.size();
        
        for(int i=0; i < n; i++){
            int sum = 0;
            for(int j = 0; j < n; j++)
                sum += matrix[i][j];
            res.push_back(sum);
        }

        return res;
    }
};