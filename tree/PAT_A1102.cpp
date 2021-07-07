//https://pintia.cn/problem-sets/994805342720868352/problems/994805365537882112
#include<cstdio>
#include<stack>
#include<queue>
#include<cstring>
#include<algorithm>

using namespace std;
//! 本题目意思是，第一行为编号为 0 的节点的左右节点编号，第二行为 1 节点的左右子树，不存在用 - 表示
// 本题用静态方式实现方便
const int maxn = 110;

// 无需 data 字段，数组下标代表了他的编号
struct node {
    // 左右节点的数组下标,同时也是节点编号
    int lchild, rchild;
} Nodes[maxn];

// [[l, r],[l, r], [l, r] ....]
//     0      1       2

// 找到根节点

// bool is_root[maxn] = {true}; //! 这个有坑
bool is_not_root[maxn] = { false, };
int n, num = 0; // 用于输出空格


int str_2_num(char c)
{
    if(c == '-') return -1;
    else
    {
        // printf("is not rooot %d\n", c - '0');
        is_not_root[c - '0'] = true;
        return c - '0';
    }
}

// 翻转二叉树，其实就是后序遍历
void invert_tree(int root)
{
    if(root == -1) return;
    invert_tree(Nodes[root].lchild);
    invert_tree(Nodes[root].rchild);
    swap(Nodes[root].lchild, Nodes[root].rchild);
}

int find_root()
{
    for(int i = 0; i < n; i++)
    {
        if(!is_not_root[i])
            return i; 
    }
}

void print(int root)
{
    printf("%d", root);
    num++;
    if(num < n) printf(" ");
    else printf("\n");
}

void BFS(int root)
{
    queue<int> q;
    q.push(root);
    while (!q.empty())
    {
        int r = q.front();
        q.pop();
        print(r);
        if(Nodes[r].lchild != -1) q.push(Nodes[r].lchild);
        if(Nodes[r].rchild != -1) q.push(Nodes[r].rchild);
    }
}

void in_order(int root)
{
    if(root == -1) return;
    in_order(Nodes[root].lchild);
    print(root);
    in_order(Nodes[root].rchild);
}

int main()
{
    // 节点编号 0 - n
    scanf("%d", &n);
    char lchild, rchild;
    for(int i = 0; i < n; i++)
    {
        // %*c 吃接收符
        scanf("%*c%c %c", &lchild, &rchild);
        Nodes[i].lchild = str_2_num(lchild);
        Nodes[i].rchild = str_2_num(rchild);
        //! is_root[i]      = false; 出现的都是子节点, 没出现的才是根节点

    }

    int root = find_root();
    invert_tree(root);
    BFS(root);
    num = 0;
    in_order(root);

    return 0;
}