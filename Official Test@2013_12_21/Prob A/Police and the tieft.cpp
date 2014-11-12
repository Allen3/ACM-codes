/*
 *  ID:     Allen_3
 *  Prob:   Police and the thief
 *  LANG:   C++
*/
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

const char THIEF[6] = "thief";

int T , n , m;
int xp , yp , xt , yt;
char str[20];

int main()
{
    scanf("%d" , &T);
    for (int i = 0;i < T;i ++)
    {
        scanf("%d%d" , &n , &m);
        scanf("%d%d%d%d" , &xp , &yp , &xt , &yt);
        scanf("%s" , str);
        int delta = abs(xp - xt) + abs(yp - yt);

        if ((xp == xt) && (yp == yt))
        {
            printf("YES\n");
            continue;
        }

        if (n == 1 || m == 1)
        {
            //if (delta % 2 == 0)
                printf("YES\n");
            /*
            else
                printf("NO\n");
            */
            continue;
        }

        if (strcmp(str , THIEF) == 0)
        {
            if (delta % 2 == 0)
                printf("YES\n");
            else
                printf("NO\n");
        }
        else
        {
            if (delta % 2 == 0)
                printf("NO\n");
            else
                printf("YES\n");
        }
    }   //for i _ T

    return 0;
}   //main
