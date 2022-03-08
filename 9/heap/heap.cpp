#include <cstdio>
#include <cstring>
#include <algorithm>


using namespace std;

const int MAXV = 110; 

int heap[MAXV]; //完全二叉树，用数组直接表示, 编号  1~ n
int n = 100; //节点个数

//大根堆 向下调整 - 建堆用
// [low, high] 范围内向下调整
void down_adjust(int low, int high)
{
    //! int i = low * 2; // 左孩子j
    //! int j = i + 1; // 右孩子
    int i = low; // i 是被操作对象
    int j = i * 2;// 一定是从左孩子开始, j 是被调换对象

    //?
    while(j <= high)
    {
        // 右孩子 更大的话
        if(j + 1 <= high && heap[j + 1] > heap[j])
        {
            j = j + 1;
        }
        // 孩子里有更大的
        if(heap[i] < heap[j])
        {
            swap(heap[i], heap[j]);
            // 被操作对象变化, 孩子上去了，被操作对象就下来了
            i = j;
            j = i * 2;
        }
        else break; // 不需要下坠了，结束了
    }
}

// 建堆
void create_heap()
{
    // 从后往前，从最后一个非叶子节点开始调整
    for(int i = n / 2; i > 0; i--)
    {
        down_adjust(i, n);
    }
}

// 删除堆顶，最后一个放上去，然后根节点向下调整
void delete_top()
{
    heap[1] = heap[n--];
    down_adjust(1, n);
}

// [low, high] high low 之间向上调整
void up_adjust(int low, int high)
{
    int i = high; // i 为被操作对象
    int j = i / 2; // 父节点，被比较对象
    while(j >= low)
    {
        if(heap[j] < heap[i])
        {
            swap(heap[j], heap[i])
            i = j; // 被操作对象换
            j = i / 2;
        }
        else break;
    }
}

// 新增一个，放到尾巴，然后向上调整
//! 因为堆确保了父节点比孩子节点都大，所以就不断向上调整就行 
void insert_heap(int x)
{
    heap[++n] = x;
    up_adjust(1, n);
}

void heap_sort()
{
    //! for(int i = n; i > 0; i--) 剩一个就不用继续了
    for(int i = n; i > 1; i--)
    {
        swap(heap[1], heap[i]);
        down_adjust(1, i - 1);
    }
}

int main()
{
}
