#include <iostream>
#include <cstddef>

using namespace std;

// Definition for singly-linked list.
struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
  ListNode *removeNthFromEnd(ListNode *head, int n)
  {
    ListNode *temp = head;
    ListNode *needRm = new ListNode{0};
    needRm->next = temp;
    head = needRm;
    int js = n;
    int lLen = 1;
    while (temp->next != NULL)
    {
      lLen++;
      if (js > 0)
        js--;
      if (js == 0)
      {
        needRm = needRm->next;
      }
      temp = temp->next;
    }
    if (lLen > 1)
    {
      needRm->next = needRm->next->next;
    }
    if (lLen == 1)
    {
      head->next = NULL;
    }
    head = head->next;
    return head;
  }
};

void showList(ListNode *head)
{
  ListNode *temp = head;
  while (temp->next != NULL)
  {
    cout << temp->val << " --> ";
    temp = temp->next;
  }
  cout << temp->val << " --> \n";
}

int main()
{
  Solution solu;

  ListNode head = {1};
  ListNode *now = &head;
  int idx = 2;
  while (idx < 6)
  {
    now->next = new ListNode(idx);
    now = now->next;
    idx++;
  }

  showList(&head);

  solu.removeNthFromEnd(&head, 2);
  showList(&head);
}