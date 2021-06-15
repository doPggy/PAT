#include <cstdio>
#include <algorithm>

using namespace std;

int loc_max_index(double a[], int i1, int i2)
{
    return a[i1] > a[i2] ? i1 : i2;
}

int main()
{
    char result[4] = {'W', 'T', 'L'};
    double w, t, l;
    int max_index[3] = {0};
    double profit = 1.0;
    double input[3];
    for(int i = 0; i < 3; i++)
    {
        // w t l 0 1 2
        scanf("%lf%lf%lf", input, input + 1, input + 2);
        // max_index[第几次 game] = w t l 哪个赔率高
        max_index[i] = loc_max_index(input, loc_max_index(input, 0, 1), 2);
        profit *= input[max_index[i]];
    }
    for(int i = 0; i < 3; i++)
    {
        printf("%c ", result[max_index[i]]);
    }
    printf("%.2f\n", (profit * 0.65 - 1) * 2);
}