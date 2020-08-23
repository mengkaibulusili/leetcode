#include <iostream>

using namespace std;
struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
  {
    if (l1 == nullptr && l2 == nullptr)
    {
      return nullptr;
    }
    else if (l1 == nullptr)
    {
      return l2;
    }
    else if (l2 == nullptr)
    {
      return l1;
    }
    ListNode *l3 = new ListNode(0);
    ListNode *t1 = l1;
    ListNode *t2 = l2;
    ListNode *t3 = l3;
    while (t1 != nullptr && t2 != nullptr)
    {
      if (t1->val > t2->val)
      {
        t3->next = t2;
        t2 = t2->next;
      }
      else
      {
        t3->next = t1;
        t1 = t1->next;
      }
      t3 = t3->next;
    }

    if (t1 != nullptr)
    {
      t3->next = t1;
    }
    if (t2 != nullptr)
    {
      t3->next = t2;
    }

    return l3->next;
  }
};

// 非递归展示
void showList(ListNode *head)
{
  ListNode *temp = head;
  while (temp->next != nullptr)
  {
    cout << temp->val << " --> ";
    temp = temp->next;
  }
  cout << temp->val << endl;
}

// 递归展示
void reShowList(ListNode *head)
{
  ListNode *temp = head;
  cout << temp->val;
  if (temp->next != nullptr)
  {
    cout << " --> ";
    reShowList(temp->next);
  }
  else
    cout << endl;
}

int main()
{
  ListNode *head1 = new ListNode(1);
  ListNode *temp = head1;
  temp->next = new ListNode(2);
  temp = temp->next;
  temp->next = new ListNode(4);
  temp = temp->next;

  ListNode *head2 = new ListNode(1);
  temp = head2;
  temp->next = new ListNode(3);
  temp = temp->next;
  temp->next = new ListNode(4);
  temp = temp->next;

  showList(head1);

  Solution solu;
  ListNode *head3 = solu.mergeTwoLists(head1, head2);

  showList(head3);
}