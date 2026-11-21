//we will make two separate buckets so that unique elements goes in separate bucket

//we xor every element
//find its right most set bit 
//its that bit position where unique elements differ first

//do AND of elements with that set bit
//put them into bucket as result

//then return xor of all elements in those buckets

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xOr = 0;
        for(int i=0; i<nums.size(); i++)            //O(N)
            xOr ^= nums[i];

        //get position of right most set bit
        int rightmost = (xOr & (xOr - 1)) ^ xOr;

        int b1 = 0, b2 = 0;     //buckets

        for(int i=0; i<nums.size(); i++){           //O(N)
            if(nums[i] & rightmost)
                b1 ^= nums[i];
            else
                b2 ^= nums[i];
        }

        return {b1, b2};
    }
};

//unique elements in 1st TC  ==>  {14, 4}

//index     3 2 1 0
//14        1 1 1 0
//4         0 1 0 0

//they first differ at index 1
//thus rightmost set bit  =  0 0 1 0

//ex.  {2,2,14,8,8,4}

//2          0 0 1 0
//rightmost  0 0 1 0
//their AND is 0 

//thus 2 goes to b2 even 14 goes there

//8          1 0 0 0
//rightmost  0 1 0 0
//their AND is non zero

//thus 8 goes to b1 even 4

//xor of all elements in each buckets gives unique element