class Solution {
    public:
        double averageWaitingTime(vector<vector<int>>& customers){
            long long totalWaitingTime = 0;
            long long currentTime = 0;
            
            for (const auto& customer : customers) {
                int arrival = customer[0];
                int time = customer[1];
                
                currentTime = max(currentTime, (long long)arrival) + time;
                totalWaitingTime += (currentTime - arrival);
            }
            
            return (double)totalWaitingTime / customers.size();
        }
};