#include <cstdio>
#include <cstring>
#include <algorithm>


using namespace std;


const int maxv = 100;
int heap[maxv]; // 从 1 开始
int n = 40; // n 为节点数
// 大根堆调整
void down_adjust(int low, int high)
{
    int i = low;
    int j = i * 2;
    while(j <= high)
    {
        if(j + 1 <= high && heap[j] < heap[j + 1])
            j = j + 1;
        if(heap[j] > heap[i])
        {
            swap(heap[j], heap[i]);
            i = j;
            j = i * 2;
        }
        else break;
    }
}

void create()
{
    for(int i = n / 2; i > 0; i--)
    {
        down_adjust(i, n);
    }
}

void delete_heap()
{
    heap[1] = heap[n--];
    down_adjust(1, n);
}


// 从 high 到 low 向上调整, 更 down_adjust 反着来
void up_adjust(int low, int high)
{
    int i = high;
    int j = i / 2;
    while(j >= low)
    {
        if(heap[i] > heap[j])
        {
            swap(heap[i], heap[j]);
        }
        else break;
    }
}

void insert_heap(int data)
{
    heap[++n] = data;
    up_adjust(1, n);
}

void heap_sort()
{
    //!
    create();
    for(int i = n; i > 1; i--)
    {
        swap(heap[1], heap[i]);
        down_adjust(1, i - 1);
    }
}

int main()
{

}