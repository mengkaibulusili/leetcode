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
  ListNode *swapPairs(ListNode *head)
  {
    ListNode *res = new ListNode(0);
    ListNode *tmp = head;
    ListNode *now = res;
    int flag=0;
    while (tmp != NULL && tmp->next != NULL)
    {
      flag=1;
      ListNode *next2Node = tmp->next->next;
      now->next = tmp->next;
      now->next->next = tmp;
      now = now->next->next;
      tmp = next2Node;
    }
    now->next = tmp;
    if(flag==0){
        res->next=head;
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
  h1 = solu.swapPairs(h1);
  reShowList(h1);
}