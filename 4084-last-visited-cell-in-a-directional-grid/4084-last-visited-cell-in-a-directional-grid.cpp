class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> visit (n, vector<int> (m,0));
        vector<int> ans = {-1, -1};

        int i = 0, j = 0;
        while(i >= 0 && i < n && j >= 0 && j < m && !visit[i][j]){
            ans = {i, j};
            visit[i][j]++;

            if(grid[i][j] == 'L')
                j--;
            else if(grid[i][j] == 'R')
                j++;
            else if(grid[i][j] == 'U')
                i--;
            else
                i++;
        }

        return ans;
    }
};