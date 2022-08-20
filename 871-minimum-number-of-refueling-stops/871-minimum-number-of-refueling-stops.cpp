class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int stops = 0;
        int prev = 0, fuel = startFuel;
        int i = 0;
        stations.push_back({target, 0});
        int n = stations.size();
        while(i < n){
            int nextCanBeReached = prev + fuel;
            int nextPosToReach = stations[i][0];
            if(nextCanBeReached < nextPosToReach){
                while(!pq.empty() and ((prev+fuel) < nextPosToReach)){
                    fuel += pq.top(); pq.pop();
                    stops++;
                }
                if(prev+fuel < nextPosToReach) return -1;
            }else{
                fuel -= (nextPosToReach - prev);
                prev = nextPosToReach;
                pq.push(stations[i][1]);
                i++;
            }
        }
        return stops;
    }
};