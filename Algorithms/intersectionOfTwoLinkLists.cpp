/*
 *
 *Write a program to find the node at which the intersection of two singly linked lists begins.
 *
 */

#include<iostream>

struct ListNode
{   
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};


class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *curA = headA;
        ListNode *curB = headB;

        while(curA != curB)
        {
            curA = curA ? curA->next : headB;
            curB = curB ? curB->next : headA;
        }
        
        return curA;
    }
};

int main()
{
    ListNode *headA = new ListNode(3);
    ListNode *heada = new ListNode(2);
    ListNode *headb = new ListNode(4);

    headA->next = heada;
    heada->next = headb;

    ListNode *headB = new ListNode(0);
    ListNode *head1 = new ListNode(9);
    ListNode *head2 = new ListNode(1);
    ListNode *head3 = new ListNode(2);
    ListNode *head4 = new ListNode(4);
    headB->next = head1;
    head1->next = head2;
    head2->next = head3;
    head3->next = head4;

    Solution s;
    ListNode *result = s.getIntersectionNode(headA, headB);

    std::cout << "The intersection Node is: " << result->val << std::endl;

    ListNode *curA = headA;
    while(curA != NULL)
    {
        delete curA;
    }

    ListNode *curB = headB;
    while(curB != NULL)
    {
        delete curB;
    }

    return 0;
}
