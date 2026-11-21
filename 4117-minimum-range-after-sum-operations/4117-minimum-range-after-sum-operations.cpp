class Solution {
public:
    int minRange(int a, int b, int c) {
        vector<int> arr;
        arr.push_back(a);
        arr.push_back(b);
        arr.push_back(c);

        sort(arr.begin(), arr.end());

        return min(arr[2] - arr[0], arr[1]);
    }
};