//recursively

class Solution {
public:
    void rev(vector<char>& a, int l, int h){
        if(l > h)
            return;

        swap(a[l], a[h]);
        return rev(a, l+1, h-1);
    }

    void reverseString(vector<char>& s) {
        return rev(s, 0, s.size()-1);   
    }
};