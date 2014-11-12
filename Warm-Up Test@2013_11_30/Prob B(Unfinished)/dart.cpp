#include<cstdio>
using namespace std;

int  k , m , c;
bool flag;

void solve(int num , int cnt)
{
    if (flag) return;
    if (cnt == 1)
    {

    }
    if (cnt == 3)
    {
        solve(num - 2 * m , cnt - 1);
        solve(num - 2 * k , cnt - 1);
    }
    else
    {
        solve(num - 2 * m , cnt - 1);
        solve(num - 3 * k , cnt - 1);
    }
}   //solve

int main()
{
    scanf("%d%d%d" , &k , &m , &c);
    while (!(!k && !m && !c))
    {
        flag = false;
        solve(c , 3);
        if (flag)
            printf("Yes\n");
        else
            printf("No\n");
        scanf("%d%d%d" , &k , &m , &c);
    }   //while
    return 0;
}   //main
