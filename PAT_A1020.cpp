#include<cstdio>
#include<stack>
#include<queue>
#include<algorithm>
// https://pintia.cn/problem-sets/994805342720868352/problems/994805485033603072
//! 给后序中序，求出层序遍历，先构造出一个树，再遍历

using namespace std;

const int maxn = 50;

struct node
{
    int data;
    struct node * lchild;
    struct node * rchild;
};

int post[maxn], in[maxn];
int n;

// 递归，也是一种前序
node *create(int postL, int postR, int inL, int inR)
{
    if(postL > postR)
    {
        return NULL;
    }
    node * root = new node();
    root->data  = post[postR];
    int k = 0;
    // 后序的最后一个是根，而在中序找到根
    for(k = 0; k < inR; k++)
    {
        if (post[postR] == in[k]) break;
    }
    // 只有中序知道
    int num_left = k - inL;
    // 左子树
    root->lchild = create(postL, postL + num_left - 1,inL, k - 1);
    // 右子树
    root->rchild = create(postL + num_left, postR - 1, k + 1, inR);
    return root;
}

int num = 0;
void BFS(node *root)
{
    queue<node *> q;
    q.push(root);
    while(!q.empty())
    {
        node * f = q.front();
        printf("%d", f->data);
        q.pop();
        num++;
        if(num < n) printf(" ");
        if(f->lchild)
            q.push(f->lchild);
        if(f->rchild)
            q.push(f->rchild);
    }
    printf("\n");
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", post + i);
    }
    for(int i = 0; i < n; i++)
    {
        scanf("%d", in + i);
    }
    node * root = create(0, n - 1, 0, n - 1);
    BFS(root);
    return 0;
}
