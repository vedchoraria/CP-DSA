/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(ptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int i =1;
        vector<int>dis;
        ListNode* temp = head;
        while(temp->next->next != nullptr){
            int a = temp->val;
            int b = temp->next->val;
            int c = temp->next->next->val;

            if((b>a && b>c) or (b<a && b<c)){
                dis.push_back(i);
            }
            i++;
            temp = temp->next;
        }

        int mi = INT_MAX, ma = -1;
        if(dis.size() >=2){
            ma = dis[dis.size()-1] - dis[0];
        }
        for(int i =1;i<dis.size();i++){
            mi = min(dis[i] - dis[i-1], mi);
        }

        mi = (mi == INT_MAX) ? -1 : mi ;
        return {mi,ma};
    }
};