//Binary Search
//update the mini with minimum of sorted half
//then take the other half and do the same

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1, mini = INT_MAX;
        
        while(low <= high){
            int mid = (low + high) / 2;

            //when search space is already sorted
            //then no need to do binary search anymore at that point
            //cause nums[low] will be minimum in that search space  
            if(nums[low] <= nums[high]){
                mini = min(mini, nums[low]);
                break;
            }

            if(nums[mid] >= nums[low]){
                mini = min(mini, nums[low]);
                low = mid + 1;                
            }
            else{
                mini = min(mini, nums[mid]);
                high = mid - 1;
            }
        }   

        return mini;
    }
};