//GEOMETRICAL MATH QUE
//check video for graph of all car 

//sort position and make changes in speed likewise
//traverse position from end
//get exact time taken by closest car to target to reach target = prevtime
//traverse rest and get exact time taken by them 
//while traversing if we find car taking lesser or equal to prevtime then theyll make fleet
//if we find car taking higher time than prevtime then new fleet will form 
//and we cnt++ and update prevtime with it

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> cars;
        for(int i = 0; i < n; i++)
            cars.push_back({position[i], speed[i]});

        //sorts the pair vector with first element (position)
        sort(cars.begin(), cars.end());

        double prevtime = (double)(target - cars[n-1].first) / cars[n-1].second;
        int cnt = 1;
        
        for(int i = n-2; i >= 0; i--){
            //get very exact time (decimal matters)
            double time = (double)(target - cars[i].first) / cars[i].second;
            if(time > prevtime){
                prevtime = time;
                cnt++;
            }  
        }

        return cnt;
    }
};