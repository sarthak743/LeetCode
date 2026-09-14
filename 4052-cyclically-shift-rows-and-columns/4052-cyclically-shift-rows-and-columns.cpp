//k times left/upward shift == reverse k times 
//cant reverse column elements normally so we make separate func for that

class Solution {
public:
    //l --> start index of column
    //r --> end index of column
    //col --> column index 
    void revcol(vector<vector<int>>& mat, int col, int l, int r){
        while(l < r){
            swap(mat[l][col], mat[r][col]);
            l++;
            r--;
        }
    }

    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
        for(int i=0; i<n; i++){
            int k = rowShift[i] % n;

            reverse(grid[i].begin(), grid[i].begin() + k);
            reverse(grid[i].begin() + k, grid[i].end());
            reverse(grid[i].begin(), grid[i].end());
        }

        for(int i=0; i<n; i++){
            int k = colShift[i] % n;

            revcol(grid, i, 0, k-1);
            revcol(grid, i, k, n-1);
            revcol(grid, i, 0, n-1);
        }

        return grid;
    }
};