class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int i = 1;

        //increasing part
        while(i < n && nums[i-1] < nums[i]) i++;
        if(i == 1)  return false;       //if i doesnt move that means there isnt increasing phase at start
        int peak = i;   //the moment the i stops updating we hv reached peak

        //decreasing part
        while(i < n && nums[i - 1] > nums[i])   i++;
        if(i == peak)   return false;       //if i is still at peak meaning there isnt downhill ahead but a plateau
        int valley  = i;

        //increasing part
        while(i < n && nums[i - 1] < nums[i])   i++;        //same as above js third increasing part
        if(i == valley)     return false;

        return i == n;        //after all these if i reaches end then array is trionic      
    }
};