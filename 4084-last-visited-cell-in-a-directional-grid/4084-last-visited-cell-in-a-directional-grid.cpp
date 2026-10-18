//optimized space

class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> ans = {-1, -1};

        int i = 0, j = 0;
        while(i >= 0 && i < n && j >= 0 && j < m && grid[i][j] != '0'){
            ans = {i, j};
            char c = grid[i][j];
            grid[i][j] = '0';

            if(c == 'L')
                j--;
            else if(c == 'R')
                j++;
            else if(c == 'U')
                i--;
            else
                i++;            
        }

        return ans;
    }
};