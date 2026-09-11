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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* output = new ListNode(0);
        int carry = 0;
        int l1val = 0;
        int l2val = 0;
        ListNode* current = output;

        while(l1!= nullptr || l2!=nullptr || carry!=0)
        {

        if(l1 == nullptr)
        {
            l1val = 0;
        }
        else
        {
            l1val = l1->val;
        }

        if(l2 == nullptr)
        {
            l2val = 0;
        }
        else
        {
            l2val = l2->val;
        }
        if(l1val+l2val+carry < 10)
        {
            current->next = new ListNode(l1val+l2val+carry);
            current = current->next;
            carry = 0;
        }
        else
        {
            current->next = new ListNode((l1val+l2val+carry) % 10);    
            current = current->next;
            carry = (l1val+l2val+carry) / 10;

        }
        if (l1 != nullptr) l1 = l1->next;
        if (l2 != nullptr) l2 = l2->next;
        }

        return output->next;
        
    }
};
