//very brute naive
//never try ts

class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> arr(n,1);
        int cnt = n, i = 0;

        while(cnt != 1){ 
            int a = k;
            for(int j=1; j<a; ){
                i = (i+1) % n;
                if(arr[i] != 0)
                    j++;
            }

            arr[i] = 0;
            cnt--;

            //skip the deads
            while(arr[i] == 0) {
                i = (i + 1) % n;
            }
        }

        for(int i =0; i<n; i++)
            if(arr[i])
                return i+1;
        return -1;
    }
};