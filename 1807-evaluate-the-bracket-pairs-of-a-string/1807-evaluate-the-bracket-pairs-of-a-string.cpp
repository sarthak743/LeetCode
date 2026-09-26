class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mpp;
        int n = s.size();
        string res = "";

        for(int i=0; i < knowledge.size(); i++)
            mpp[knowledge[i][0]] = knowledge[i][1];

        int i=0;
        while(i<n){
            if(s[i] != '(')
                res += s[i];

            if(s[i] == '('){
                i++;
                string a = "";
                while(s[i] != ')'){
                    a += s[i];
                    i++;
                }

                if(mpp.find(a) != mpp.end())
                    res += mpp[a];
                else
                    res += '?';
            }

            i++;
        }

        return res;
    }
};