#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

int T , xx , yy , t;
char str[100010];

int solve()
{
    int x = 0 , y = 0 , time = 0;
    while (!(x == xx && y == yy))
    {
        if (time >= t) return -1;
        if (xx > x && str[time] == 'R')
            x ++;
        if (xx < x && str[time] == 'L')
            x --;
        if (yy > y && str[time] == 'U')
            y ++;
        if (yy < y && str[time] == 'D')
            y --;
        time ++;
    }   //while
    return time;
}   //solve

int main()
{
    //freopen(output , "w" , stdout);
    scanf("%d" , &T);
    for (int i = 0;i < T;i ++)
    {
        char ch;
        scanf("%d%d%d%c" , &xx , &yy , &t , &ch);
        scanf("%s" , str);
        printf("%d\n" , solve());
    }   //for i _ T

    return 0;
}   //main
