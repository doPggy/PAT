#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 110;
int orignal[N];
int temp[N];
int changed[N];
int n;

bool is_same_array(int a[], int b[])
{
    for(int i = 1; i <= n; i++)
    {
        if(a[i] != b[i]) return false;
    }
    return true;
}

void show()
{
    for(int i = 1; i <= n; i++)
    {
        if(i != n)
            printf("%d ", temp[i]);
        else
            printf("%d\n", temp[i]);
    }

}

//!
bool is_insert_sort()
{
    bool flag = false; // 记录中间步骤是否和插入一致
    //! 从 1 编号
    for(int i = 2; i <= n; i++) //! 插入排序不熟悉
    {
        // 非初始序列且某一次排序结果相同
        if(i != 2 && is_same_array(temp, changed))
            flag = true;
        //! 先进行下一步排序，因为如果是一致的，题目要求
        sort(temp, temp + i + 1); //! i + 1，因为要下一趟的排序了 插入排序用 sort 简化
        if(flag) return true; // 已经达到一致
    }
    return false;
}


// 一次向下调整
void down_adjust(int low, int high)
{
    int i = low;
    int j = i * 2;
    while(j <= high)
    {
        if(j + 1 <= high && temp[j + 1] > temp[j])
            j = j + 1;
        if(temp[i] < temp[j])
        {
            swap(temp[i], temp[j]);
            i = j; //被操作对象换了，下标下坠了
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

// bool heap_sort()
//! 不是插入就是堆，堆就不用判断了
// 注意要一步一步地排序
void heap_sort()
{
    bool flag = false;
    create(); //建堆
    //! 堆排序 从后往前, 然后调整 1~i-1
    for(int i = n; i > 1; i--)
    {
        if(i != n && is_same_array(temp, changed))
            flag = true;
        //! 要先排序后return
        swap(temp[1], temp[i]); //! 核心
        down_adjust(1, i - 1); //! 核心
        if(flag)
        {
            return;
        }
    }
}


int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", orignal + i);
        temp[i] = orignal[i];
    }
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", changed + i);
    }

    if(is_insert_sort())
    {
        printf("Insertion Sort\n");
        show();
    }
    else
    {
        // 从 1 开始编号
        for(int i = 1; i <= n; i++)
            temp[i] = orignal[i];
        heap_sort();
        printf("Heap Sort\n");
        show();
    }
}