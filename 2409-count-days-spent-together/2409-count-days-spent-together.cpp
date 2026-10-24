class Solution {
public:
    int noofdays(int n){
        if(n == 2)
            return 28;
        if(n == 4 || n == 6 || n == 9 || n == 11)
            return 30;
        return 31;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<vector<int>> year(12, vector<int> (32, 0));

        int aam = (arriveAlice[0] - '0') * 10 + (arriveAlice[1] - '0');
        int aad = (arriveAlice[3] - '0') * 10 + (arriveAlice[4] - '0');
        int lam = (leaveAlice[0] - '0') * 10 + (leaveAlice[1] - '0');
        int lad = (leaveAlice[3] - '0') * 10 + (leaveAlice[4] - '0');

        int abm = (arriveBob[0] - '0') * 10 + (arriveBob[1] - '0');
        int abd = (arriveBob[3] - '0') * 10 + (arriveBob[4] - '0');
        int lbm = (leaveBob[0] - '0') * 10 + (leaveBob[1] - '0');
        int lbd = (leaveBob[3] - '0') * 10 + (leaveBob[4] - '0');

        if(aam == lam)
            for(int i=aad; i<=lad; i++)
                year[aam - 1][i]++;

        else{
            for(int i=aad; i<=noofdays(aam); i++)
                year[aam - 1][i]++;
            
            aam++;
            int diff = lam - aam;
            while(diff--){
                for(int i=1; i<=noofdays(aam); i++)
                    year[aam - 1][i]++;

                aam++;
            }

            for(int i=1; i<=lad; i++)
                year[lam - 1][i]++;
        }

        if(abm == lbm)
            for(int i=abd; i<=lbd; i++)
                year[abm - 1][i]++;

        else{
            for(int i=abd; i<=noofdays(abm); i++)
                year[abm - 1][i]++;
            
            abm++;
            int diff = lbm - abm;
            while(diff--){
                for(int i=1; i<=noofdays(abm); i++)
                    year[abm - 1][i]++;

                abm++;
            }

            for(int i=1; i<=lbd; i++)
                year[lbm - 1][i]++;
        }


        int res = 0;
        for(int i=0; i<12; i++){
            for(int j=0; j<=31; j++)
                if(year[i][j] == 2)
                    res++;
        }

        return res;
    }
};