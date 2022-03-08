#include<cstdio>
#include<stack>
#include<queue>
#include<algorithm>

using namespace std;


struct Node
{
    int data;
    Node * lchild;
    Node * rchild;
};

const int maxn = 50;
int n;
int post[maxn];
int in[maxn];


Node * create(int post_l, int post_r, int in_l, int in_r)
{
    if(post_l > post_r) return NULL;
    Node * root = new Node;
    int root_v  = post[post_r];
    root->data  = root_v;
    int k = 0;
    for(k = in_l; k <= in_r; k++)
        if(in[k] == root_v) break;
    int num_left = k - in_l; // 左子树的节点个数
    //! 多想想两个序列的划分实例
    root->lchild = create(post_l, post_l + num_left - 1, in_l, k - 1);
    root->rchild = create(post_l + num_left, post_r - 1, k + 1, in_r);
    return root;//! 忘记
}

void BFS(Node *root)
{
    queue<Node *> q;
    q.push(root);
    int num = 0;

    while(!q.empty())
    {
        Node *p = q.front();
        q.pop();
        num++;
        // 二叉
        if(p->lchild) q.push(p->lchild);
        if(p->rchild) q.push(p->rchild);

        printf("%d%s", p->data, (num < n) ? " " : "\n");
    }
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", post + i);
    for(int i = 0; i < n; i++)
        scanf("%d", in + i);
    Node * root = create(0, n - 1, 0, n - 1);
    BFS(root);
}