
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
 };


class Solution {
public:


//  @param p TreeNode类 
//  @param q TreeNode类 
//  @return bool布尔型

    bool isSameTree(TreeNode *p, TreeNode *q) {
        if(p==nullptr && q==nullptr)
            return true;
        if(p==nullptr || q==nullptr)
            return false;
        if(p->val == q->val)
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        else
            return false;
    }
};


class solution {
    bool isSameTree(TreeNode * p , TreeNode * q){
        if (p==nullptr && q==nullptr)return true;
        if(p==nullptr)return false;
        if(q==nullptr)return false;
        if (p->val == q->val )
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
        else return false;
        
    }
};