class Solution {
public:
    int findGCD(vector<int>& nums) 
    {
        int n = nums.size();
        int min = nums[0];
        int max = nums[1];
        int gcd = 0;

        for(int i=0; i<n; i++)
        {
            if(nums[i] < min)
            {
                min = nums[i];
            }

            else if(nums[i] > max)
            {
                max = nums[i];
            }
        }        

        for(int i=1; i<=min; i++)
        {
            if(min % i == 0 && max % i == 0 )
            {
                if(i > gcd)
                {
                    gcd = i;
                }
            }
        }

        return gcd;
    }
};