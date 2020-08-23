#include <iostream>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
  bool JudgeKNull(ListNode *head, int k)
  {
    ListNode *temp = head;
    while (k > 0)
    {
      if (temp != nullptr)
        temp = temp->next;
      else
        return false;
      k--;
    }
    return true;
  }

  ListNode *reverseKGroup(ListNode *head, int k)
  {
    ListNode *res = new ListNode(0);
    ListNode *tmp = head;
    ListNode *now = res;
    int flag = 0;
    while (JudgeKNull(tmp, k))
    {
      flag = 1;
      ListNode *next2Node = tmp;
      ListNode *reverse = new ListNode(0);

      ListNode *lastNext2Node = nullptr;
      for (int i = 0; i < k; i++)
      {
        if (i == 0)
          lastNext2Node = next2Node;
        ListNode *p = next2Node;
        next2Node = next2Node->next;
        p->next = reverse->next;
        reverse->next = p;
      }
      now->next = reverse->next;
      now = lastNext2Node;
      tmp = next2Node;
    }
    now->next = tmp;
    if (flag == 0)
    {
      res->next = head;
    }
    return res->next;
  }
};

void reShowList(ListNode *h)
{
  ListNode *t = h;
  if (t != nullptr)
  {
    cout << t->val;
    if (t->next != nullptr)
      cout << " --> ";
    else
      cout << endl;
    reShowList(t->next);
  }
}

int main()
{
  ListNode *h1 = new ListNode(0);
  ListNode *tmp = h1;
  tmp->next = new ListNode(1);
  tmp = tmp->next;
  tmp->next = new ListNode(2);
  tmp = tmp->next;
  tmp->next = new ListNode(3);
  tmp = tmp->next;
  tmp->next = new ListNode(4);
  h1 = h1->next;

  reShowList(h1);
  Solution solu;
  // cout << solu.JudgeKNull(h1, 4) << endl;
  // cout << solu.JudgeKNull(h1, 3) << endl;
  h1 = solu.reverseKGroup(h1, 3);
  reShowList(h1);
}