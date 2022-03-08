#include<cstdio>
#include<stack>
#include<queue>
#include<algorithm>

using namespace std;

const int maxn = 50;

struct Node
{
    int data;
    Node * lchild;
    Node * rchild;
};


int pre[maxn];
int post[maxn];
int in[maxn];//中序序列

int n;

Node * create(int post_l, int post_r, int in_l, int in_r)
{
    if(post_l > post_r) // 后序序列长度小于 0
        return NULL;
    Node * new_p = new Node;
    new_p->data  = post[post_r]; //根节点的值
    // 找根节点
    int i = 0;
    for(i = in_l; i <= in_r; i++)
    {
        if(in[i] == post[post_r]) break;
    }
    int num_left = i - in_l; // 求出左子树节点个数
    //! new_p->lchild = create(post_l, post_l + num_left, in_l, in_l + num_left);
    new_p->lchild = create(post_l, post_l + num_left - 1, in_l, i - 1); // post_l + num_left 会包含右子树的第一个节点
    //! new_p->rchild = create(post_l + num_left, post_r, i + 1, in_r);
    new_p->rchild = create(post_l + num_left, post_r - 1, i + 1, in_r); // post_r - 1 ，post_r 已经是根节点了
    return new_p; //! 递归结果没写返回值
}

int num;
void BFS(Node * root)
{
    queue<Node *> q;
    q.push(root);
    while(!q.empty())
    {
        Node * p = q.front();
        q.pop();
        printf("%d", p->data);
        num++;//控制空格
        if(num < n) printf(" ");
        if(p->lchild) q.push(p->lchild);
        if(p->rchild) q.push(p->rchild);
    }
}




int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", post + i);
    for(int i = 0; i < n; i++)
        scanf("%d", in + i);
    Node* root = create(0, n - 1, 0, n - 1);
    BFS(root);
    printf("\n");
}