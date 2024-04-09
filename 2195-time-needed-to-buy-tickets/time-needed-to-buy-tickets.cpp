class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
    int total_time = 0;
    while (any_of(tickets.begin(), tickets.end(), [](int ticket) { return ticket > 0; })) {
      for (int i = 0; i < tickets.size(); ++i) {
        if (tickets[i] > 0) {
          tickets[i]--;
          total_time++;
          
          if (i == k && tickets[i] == 0) {
            return total_time;
          }
        }
      }
    }
    return total_time;
  }
};