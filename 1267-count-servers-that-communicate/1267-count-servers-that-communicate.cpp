class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        vector<vector<int>> temp = grid;
        int sum = 0, res = 0, n = grid.size(), m = grid[0].size();

        for(int i=0; i<n; i++){
            sum = accumulate(grid[i].begin(), grid[i].end(), 0);
            if(sum < 2)
                continue;
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    temp[i][j] = -1;
                    res++;
                }
            }
        }


        for(int i=0; i<m; i++){
            sum = 0;
            for(int j=0; j<n; j++){
                sum += grid[j][i];
            }

            if(sum < 2)
                continue;

            for(int j=0; j<n; j++){
                if(temp[j][i] == 1)
                    res++;
            }
        }

        return res;
    }
};