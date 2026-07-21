class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> map(51, 0);
        int count = 0;

        for(int i = 0; i < A.size(); i++){
            map[A[i]]++;
            map[B[i]]++;

            count = 0;
            for(int i = 1; i <= A.size(); i++){
                if(map[i] == 2) count++;
            }

            A[i] = count;
        }

        return A;
    }
};