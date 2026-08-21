//binary
//at each point check if it satisfies condition
//if yes then update result and high
//else update low

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int low = 0, high = n - 1;
        int result = 0;

        while(low <= high){
            int mid = (low + high) / 2;

            if(citations[mid] >= n - mid){
                high = mid - 1;

                //since we have to return no of such paper
                //and not index
                result = n - mid;
            }

            else low = mid + 1;
        }

        return result;
    }
};