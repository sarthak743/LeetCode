class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //row wise
        for(int i=0; i<=8; i++){
            vector<int> hash(10,0);
            for(int j=0; j<=8; j++){
                if(board[i][j] != '.'){
                    hash[board[i][j] - '0']++;
                    if(hash[board[i][j] - '0'] > 1)
                        return false;
                }
            }
        }

        //column wise
        for(int i=0; i<=8; i++){
            vector<int> hash(10,0);
            for(int j=0; j<=8; j++){
                if(board[j][i] != '.'){
                    hash[board[j][i] - '0']++;
                    if(hash[board[j][i] - '0'] > 1)
                        return false;
                }
            }
        }

        //for 3x3 boxes
        //box number ==>
        //0    3    6
        //1    4    7
        //2    5    8

        vector<vector<int>> box(9, vector<int> (10,0));
        int sum = 0;        
        for(int j=0; j<=8; j++){
            for(int i=0; i<=8; i++){
                sum = (j/3) * 3 + (i/3);        //helps find in which box ele belongs
                if(board[i][j] != '.'){
                    box[sum][board[i][j] - '0']++;
                    if(box[sum][board[i][j] - '0'] > 1)
                        return false;
                }
            }
        }

        return true;
    }
};