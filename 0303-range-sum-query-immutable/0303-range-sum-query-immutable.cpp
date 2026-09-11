class NumArray {
public:
    vector<int> presum;
    NumArray(vector<int>& arr){        
        int sum = 0;

        for(int i=0; i<arr.size(); i++){
            sum += arr[i];
            presum.push_back(sum);
        }
    }
    
    int sumRange(int left, int right){
        if(!left)
            return presum[right];

        return presum[right] - presum[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */