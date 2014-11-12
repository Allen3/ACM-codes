/*
 *  ID:     Allen_3
 *  Prob:   Lazy Girl
 *  LANG:   C++
*/
#include<cstdio>
using namespace std;

int main()
{
    int T;
    scanf("%d" , &T);
    for (int i = 0;i < T;i ++)
    {
        int a , b , t , t1;
        scanf("%d%d%d%d" , &a , &b , &t , &t1);
        if (t1 <= a)
            printf("0.0000\n");
        else if (t1 - t >= a)
        {
            if (t1 <= b)
                printf("%.4f\n" , (double)t / (double)(b - a));
            else
            {
                if (t1 - t >= b)
                    printf("0.0000\n");
                else
                    printf("%.4f\n" , (double)(b + t - t1) / (double)(b - a));
            }
        }
        else
        {
            if (t1 <= b)
                printf("%.4f\n" , (double)(t1 - a) / (double)(b - a));
            else
                printf("1.0000\n");
        }
    }   //for i

    return 0;
}   //main
