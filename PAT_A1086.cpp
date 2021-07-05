#include<cstdio>
#include<stack>
#include<cstring>
#include<algorithm>

using namespace std;
//https://pintia.cn/problem-sets/994805342720868352/problems/994805380754817024
//! 其实题目绕来绕去，通过样例分析可以发现 push 是先序遍历，pop 是后序遍历 -> 利用两个遍历构造二叉树
//! 画遍历图就方便理解
struct node
{
    int data;
    struct node* lchild;
    struct node* rchild;
};

const int maxn = 50;
int pre[maxn], in[maxn];
int n = 0;

//! 用先序中序构造出二叉树, 递归方式，相当于一个先序
// 先序序列第一个必是根
node *create(int preL, int preR, int inL, int inR)
{
    if(preL > preR)
        return NULL;
    node * root = new node;
    int k = 0;
    //! for(k = 0; k < n; k++)
    // 应该是当前序列
    for(k = inL; k <= inR; k++)
        if(in[k] == pre[preL]) break;
    int num_left = k - inL;
    root->data   = pre[preL];//!新节点就是当前序列的根节点
    root->lchild = create(preL + 1, preL + num_left, inL, k - 1);
    root->rchild = create(preL + num_left + 1, preR, k + 1, inR);
    return root;
}

int num = 0;
void post_order(node * root)
{
    if(root == NULL)
        return;
    post_order(root->lchild);
    post_order(root->rchild);
    printf("%d", root->data);
    num++; //!
    if(num < n) printf(" "); 
}


int main()
{
    // int n = 0;
    scanf("%d", &n);
    stack<int> s;
    char input[6];
    int pre_index = 0;
    int in_index  = 0;
    int val       = 0;
    for(int i = 0; i < 2 * n; i++)
    {
        scanf("%s", input);
        if(strcmp(input, "Push") == 0)
        {
            scanf("%d", &val);
            pre[pre_index++] = val;
            s.push(val);
        }
        else
        {
            //! 怎么会有这个东西？ scanf("%d", &val);
            in[in_index++] = s.top(); //! 题中就说了利用栈
            s.pop();
        }
    }

    node * root = create(0, n - 1, 0, n - 1);
    post_order(root);
    printf("\n");


    return 0;
}