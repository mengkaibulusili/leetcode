
// 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
// 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
// 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

// 示例：
// 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
// 输出：7 -> 0 -> 8
// 原因：342 + 465 = 807

// Definition for singly-linked list.
struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
//虽然写的略微啰嗦，但是 没有去用 除法或者 取余运算

  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
  {
    ListNode *hd = new ListNode(0);
    int carry = 0;
    ListNode *l11 = l1;
    ListNode *l21 = l2;
    ListNode *curr = hd;
    int sum = 0;
    while (1)
    {
      int v1 = 0, v2 = 0;
      if (l11 != nullptr)
      {
        v1 = l11->val;
        l11 = l11->next;
      }
      if (l21 != nullptr)
      {
        v2 = l21->val;
        l21 = l21->next;
      }
      sum = v1 + v2 + carry;
      if (sum > 9)
      {
        carry = 1;
        curr->next = new ListNode(sum - 10);
      }
      else
      {
        carry = 0;
        curr->next = new ListNode(sum);
      }
      curr = curr->next;
      if (l11 == nullptr && l21 == nullptr)
      {
        if (carry != 0)
        {
          curr->next = new ListNode(carry);
        }
        break;
      }
    }
    return hd->next;
  }
};