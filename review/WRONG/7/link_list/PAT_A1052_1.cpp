#include <cstdio>
#include <algorithm>

using namespace std;
//sort the structures according to their key values in increasing order.
//用 sort 把有效节点左边填充，并且排序

const int maxn = 100010;
struct Node
{
    int data;
    int next;
    int addr; //如果需要利用 sort 将有效节点填充，需要记录本身地址
    bool is_valid; // 是否是有效节点，而非孤点
}nodes[maxn];


bool cmp(Node a, Node b)
{
    if(!a.is_valid || !b.is_valid) return a.is_valid > b.is_valid; // true > false ,有效优先
    else
        return a.data < b.data;
    // else if(a.data != b.data) return a.data < b.data;

}

int main()
{
    int head, n;
    scanf("%d%d", &n, &head);
    int addr, data, next;
    // 把节点都搞了
    for(int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &addr, &data, &next);
        nodes[addr].addr = addr;
        nodes[addr].data = data;
        nodes[addr].next = next;
    }

    // 遍历，标记整条链表
    int p = head;
    int num = 0;
    while(p != -1)
    {
        nodes[p].is_valid = true;
        num++;
        p = nodes[p].next;
    }
    if(num == 0)
    {
        printf("0 -1");
    }
    else
    {
        //! sort(nodes, nodes + num, cmp); 这里不是 num 是全部都要排序，因为地址是分散的
        //! 同时 num == 0 要分开
        sort(nodes, nodes + maxn, cmp); //这里不是 num 是全部都要排序，因为地址是分散的
        printf("%d %05d\n", num, nodes[0].addr);
        int i = 0;
        for(i = 0; i < num - 1; i++)
        {
            //! printf("%05d %d %05d\n", nodes[i].addr, nodes[i].data, nodes[i].next);
            printf("%05d %d %05d\n", nodes[i].addr, nodes[i].data, nodes[i + 1].addr);
        }
        printf("%05d %d -1", nodes[i].addr, nodes[i].data);
    }
}