#include <cstdio>


struct Student
{
    long long id;// 准考证 16 位数字
    int seat_id;
} students[1001];

int main()
{
    int n = 0;
    scanf("%d", &n);
    long long id;
    int seat_id;
    int try_seat_id;
    //* 用试座位号，坐下标，相当于 dict
    for(int i = 0; i < n; i++)
    {
        scanf("%lld%d%d", &id, &try_seat_id, &seat_id);
        students[try_seat_id].id      = id;
        students[try_seat_id].seat_id = seat_id;
    }
    int m = 0;
    scanf("%d", &m);
    while (m--)
    {
        scanf("%d", &try_seat_id);
        printf("%lld %d\n", students[try_seat_id].id, students[try_seat_id].seat_id);
    }
    
}