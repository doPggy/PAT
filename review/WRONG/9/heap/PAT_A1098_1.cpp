#include <algorithm>
#include <cstdio>
using namespace std;

int n;
const int N = 110;
// 从 1 开始
int orignal[N];
int changed[N];
int temp[N];

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
        printf("%d%s", temp[i], i != n ? " " : "\n");
}


// 判断是否是插入排序, 一步一步判断是否变成一样的
bool is_insert_sort()
{
    bool is = false;
    for(int i = 2; i <= n; i++)
    {
        if(i != 2 && is_same_array(temp, changed))
            is = true;
        // 用 sort 来做插入排序
        //? sort(temp + 1, temp + i + 1);
        sort(temp, temp + i + 1);
        if(is) return true;
    }
}


void down_adjust(int low, int high)
{
    int i = low;
    int j = i * 2;

    while(j <= high)
    {
        if(j + 1 <= high && temp[j] < temp[j + 1])
            j = j + 1;
        if(temp[i] < temp[j])
        {
            swap(temp[i], temp[j]);
            i = j; // 被操作对象位置下坠
            j = i * 2;
        }
        else break;
    }
}

void create_heap()
{
    for(int i = n / 2; i > 0; i++)
        down_adjust(i, n);
}

// 不是 insert ，就是 heap sort
void heap_sort()
{
    bool is = false;
    create_heap();
    for(int i = n; i > 1; i--)
    {
        if(i != n && is_same_array(temp, changed))
            is = true;
        swap(temp[1], temp[i]); 
        down_adjust(1, i - 1);
        if(is) return;
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
        scanf("%d", changed + i);
    if(is_insert_sort())
    {
        printf("Insertion Sort\n");
        show();

    }
    else
    {
        for(int i = 1; i <= n; i++)
            temp[i] = orignal[i];
        heap_sort();
        printf("Heap Sort\n");
        show();
    }
}