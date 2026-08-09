class Solution {
    public double minPrice(int[] prices, int[] discounts) {
        double ans = 0;
        int n = discounts.length;
        int m = prices.length;
        Arrays.sort(prices);
        Arrays.sort(discounts);
        int idx = n-1;
        for(int i = m-1;i>=0;i--){
            if(idx >=0){
                double p = prices[i];
                double d = discounts[idx];
                double v = (p*(100-d))/100.0;
                ans += v;
            } else{
                ans += prices[i];
            }
            idx--;
        }
        return ans;
    }
}