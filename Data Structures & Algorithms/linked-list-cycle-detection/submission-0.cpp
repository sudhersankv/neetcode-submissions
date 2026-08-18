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
    bool hasCycle(ListNode* head) {

        std::unordered_set<ListNode*> seen;

        ListNode* current = head;
        // nextnode = nullptr;
        while(current != nullptr)
        {
            if(seen.find(current) == seen.end())
            {
                seen.insert(current);
            }
            else
            {
                return true;
            }

            current = current->next;
        }

        return false;
        
    }
};
