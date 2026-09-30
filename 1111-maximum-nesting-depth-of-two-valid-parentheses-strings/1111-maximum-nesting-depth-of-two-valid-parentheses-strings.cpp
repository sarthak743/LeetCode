class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int depth = 0, n = seq.size();
        vector<int> res(n,0);

        for(int i=0; i < n; i++){
            if(seq[i] == '('){
                depth++;
                if(depth % 2 != 0)
                    res[i] = 0;
                else
                    res[i] = 1;
            }

            else{
                if(depth % 2 != 0)
                    res[i] = 0;
                else
                    res[i] = 1;
                depth--;
            }
        }

        return res;
    }
};