#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100010;

// 定义静态链表
struct Node
{
    int addr;
    int data;
    bool is_valid;// 是否为有效节点，如在链表上
    int next;
}nodes[maxn];

bool cmp(Node a, Node b)
{
    //! if(a.is_valid != b.is_valid) 忽略了两者都 false
    if(!a.is_valid || !b.is_valid) return a.is_valid > b.is_valid; // true > false (1 > 0)
    else if(a.data != b.data) return a.data < b.data;
}

int main()
{
    int n, head_addr;
    scanf("%d%d", &n, &head_addr);
    int addr;
    int data;
    int next;
    // 建表
    for(int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &addr, &data, &next);
        nodes[addr].data = data;
        nodes[addr].next = next;
        nodes[addr].addr = addr; // 后头有用
    }

    // 遍历链表
    int p     = head_addr;
    int count = 0;
    for(; p != -1; p = nodes[p].next)
    {
        nodes[p].is_valid = true;
        count++;//头结点就有数据
    }
    //! 特别判断
    if(count == 0)
    {
        printf("0 -1");
    }
    else
    {
        //!有效节点全部左移， 但其实破坏了链表的next，只能通过相邻下标获取
        sort(nodes, nodes + maxn, cmp);
        printf("%d %05d\n", count, nodes[0].addr);
        int i = 0;
        for(i = 0; i < count - 1; i++)
        {
            printf("%05d %d %05d\n", nodes[i].addr, nodes[i].data, nodes[i + 1].addr);
        }
        printf("%05d %d -1", nodes[i].addr, nodes[i].data);

    }

}
