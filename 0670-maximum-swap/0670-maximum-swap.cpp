class Solution {
public:
    int maximumSwap(int num) {
        string a = to_string(num);

        for(int i=0; i<a.size(); i++){
            int maxi = -1, maxInd = -1;
            for(int j=i+1; j<a.size(); j++){
                if(a[j] > a[i] && (a[j] - '0') >= maxi){
                    maxi = max(maxi, a[j] - '0');
                    maxInd = j;
                }
            }

            if(maxInd != -1){
                swap(a[i], a[maxInd]);
                return stoi(a);
            }
        }

        return stoi(a);
    }
};