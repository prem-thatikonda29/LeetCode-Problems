/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(!head || head->next == nullptr || head->next->next == nullptr){
            return {-1, -1};
        }

        vector<int> criticalPositions;
        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* next = curr->next;
        int position = 1;

        int maxDist = INT_MIN;
        int minDist = INT_MAX;

        while(next != nullptr){
            if((curr->val < prev->val && curr->val < next->val) || (curr->val > prev->val && curr->val > next->val)){
                criticalPositions.push_back(position);
            }

            prev = curr;
            curr = next;
            next = next->next;
            position++;
        }

        if(criticalPositions.size() < 2){
            return {-1, -1};
        }

        for(int i = 1; i < criticalPositions.size(); i++){
            minDist = min(minDist, criticalPositions[i] - criticalPositions[i-1]);
        }

        maxDist = criticalPositions.back() - criticalPositions.front();

        return {minDist, maxDist};
    }
};
