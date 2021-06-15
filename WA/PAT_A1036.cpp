#include <cstdio>
#include <math.h>

struct student
{
    char name[11];
    char id[11];
    // char gender = 0;
    int score;
} temp, male, female;


int main()
{
    int n = 0;
    scanf("%d", &n);
    male.score = 101;
    female.score = -1;
    char gender;
    while(n--)
    {
        //! 这里的输入是大坑，一定要加入空格去吸收
        scanf("%s %c %s %d", temp.name, &gender, temp.id, &temp.score);
        if(gender == 'M' and temp.score <= male.score)
            male = temp;
        if(gender == 'F' and temp.score >= female.score)
            female = temp;
        gender = 0;
    }

    if(female.score == -1)
        printf("Absent\n");
    else
        printf("%s %s\n", female.name, female.id);
    if(male.score == 101)
        printf("Absent\n");
    else
        printf("%s %s\n", male.name, male.id);

    // ! 之间的差应该可以是负数
    // int diff = abs(female.score - male.score);
    int diff = (female.score - male.score);
    if(male.score == 101 || female.score == -1)
        printf("NA\n");
    else
        printf("%d\n", female.score - male.score);
}
