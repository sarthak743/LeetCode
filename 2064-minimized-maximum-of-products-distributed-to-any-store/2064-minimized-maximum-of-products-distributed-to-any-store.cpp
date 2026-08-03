//AGGRESSIVE COWS 
//in helper function we will get the numbers of stores that can be distributed with a amount of products
//to find that we take ceil of number of products of that type with amount of prod to be distributed
//if that number is greater than given number of stores then its possible
//while binary searching if at some value its possible to distribute all the products 
//then its possible too for values larger than it

class Solution {
public:
    //a -> amount of product given, p -> product array, n -> number of retail stores
    bool isPossible(int a, vector<int>& p, int n){
        int total_stores = 0;

        for(int i = 0; i < p.size(); i++){
            total_stores += (p[i] + a - 1) / a;     //math trick to find ceil
        }

        if(total_stores <= n)    return true;
        return false;
    }   

    int minimizedMaximum(int n, vector<int>& quantities) {
        int low = 1, high = *max_element(quantities.begin(), quantities.end());

        while(low <= high){
            int mid = (low + high) / 2;

            if(isPossible(mid, quantities, n))  high = mid - 1;     //if for mid its possible then values larger than it is possible so we skip them
            else low = mid + 1;     //otherwise
        }

        return low;
    }
};