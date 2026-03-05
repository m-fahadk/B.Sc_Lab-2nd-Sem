#include <stdio.h>

struct time
{
    int hour;
    int min;
    int sec;
};
typedef struct time time;

time time_diff(time t1, time t2)
{
    time temp;
    t1.sec = t1.hour * 3600 + t1.min * 60 + t1.sec;
    t2.sec = t2.hour * 3600 + t2.min * 60 + t2.sec;
    if (t1.sec > t2.sec)
    {
        temp.sec = t1.sec - t2.sec;
    }

    else
    {
        temp.sec = t2.sec - t1.sec;
    }

    temp.hour = temp.sec / 3600;
    temp.sec = temp.sec % 3600;

    temp.min = temp.sec / 60;
    temp.sec = temp.sec % 60;

    return temp;
}

int main()
{
    time t1, t2, t3;

    printf("Enter the 1st time(HH/MM/SS) : ");
    scanf("%d%d%d", &t1.hour, &t1.min, &t1.sec);
    printf("Enter the 2nd time(HH/MM/SS) : ");
    scanf("%d%d%d", &t2.hour, &t2.min, &t2.sec);

    t3 = time_diff(t1, t2);
    printf("Time = %d : %d : %d", t3.hour, t3.min, t3.sec);
}
