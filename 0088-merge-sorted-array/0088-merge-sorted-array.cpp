//this is a bit optimal solution
//this dont take extra space
//and time complexity is better too



class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        if(!nums2.size()) return;
        if(nums1.size() == nums2.size()){
            for(int i = 0; i < nums2.size(); i++){
                nums1[i] = nums2[i];
            }  
            return;
        }

        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while(i >= 0 && j >= 0){
            if(nums1[i] > nums2[j]){
                nums1[k] = nums1[i];
                k--;
                i--;
            }
            
            else{
                nums1[k] = nums2[j];
                k--;
                j--;
            }
        }            

        while (j >= 0){
            nums1[k] = nums2[j];
            k--;
            j--;
        }
            
    }
};