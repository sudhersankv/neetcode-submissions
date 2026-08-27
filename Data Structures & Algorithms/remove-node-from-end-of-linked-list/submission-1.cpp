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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int size = 0;

        ListNode* current = head;
        ListNode* oldHead = head;
        
        while(current!=nullptr)
        {
            size++;
            current = current->next;
        }

        if(size == n)
        {
            head = head->next;
            return head;
        }
        current = head;

        for(int i = 0; i < size-n-1; i++)
        {
            current = current->next;
        }
        
        current->next = current->next->next;

        return head;


    }
};
