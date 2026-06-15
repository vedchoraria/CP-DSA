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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode*prev = new ListNode();
        if(head->next == nullptr){
            return nullptr;
        }
        while(fast->next != nullptr && fast->next->next != nullptr){
            prev = slow;
            slow = slow -> next;
            fast = fast->next->next;
        }
        if(fast->next != nullptr){
            prev= slow;slow = slow->next;
        }
        prev->next = slow->next;


        return head;
    }
};