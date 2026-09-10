class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int i = rowIndex + 1;
        long long ans = 1;
        vector<int> row;
        row.push_back(1);

        for(int j=1; j<i; j++)
        {
            ans = ans * (i - j);
            ans = ans / j;
            row.push_back(ans);
        }

        return row;
    }
};