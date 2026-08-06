//we do binary search on first row
//then on whatever column the mid lies we find the max element in it
//since adjacents are not equal
//so if we find max in column that element is larger than its up and down element
//thus we compare that element with its left and right
//if left is greater then we take the left one otherwise right one

//TC - O(N * logM)

class Solution {
public:
    // helper function to tell index of max element in column
    int maxInCol(vector<vector<int>>& arr, int mid) {
        int n = arr.size();
        int m = arr[0].size();
        int maxi = INT_MIN, idx = -1;

        for (int i = 0; i < n; i++)
            if (arr[i][mid] > maxi){
                maxi = arr[i][mid];
                idx = i;
            }
                

        return idx;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int low = 0, high = m - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            int row = maxInCol(mat, mid);
            
            //to check if mid is at extreme end
            //if mid is at extreme then one of them will be -1
            int left = (mid - 1 >= 0) ? mat[row][mid - 1] : -1;
            int right = (mid + 1 < m) ? mat[row][mid + 1] : -1;

            if(left < mat[row][mid] && mat[row][mid] > right)   return {row, mid};
            if(left > mat[row][mid])    high = mid - 1;
            else low = mid + 1;
        }

        return {-1, -1};
    }
};