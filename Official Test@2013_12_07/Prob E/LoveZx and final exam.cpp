#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define     INF         0x3f3f3f3f
#ifdef unix
#define     LL_FMT      "%lld"
#else
#define     LL_FMT      "%I64d"
#endif

int T;
char Zx[100010] , LoveZx[100010];
int Counts[13];

inline int min(int a , int b)
{
    if (a < b)
        return a;
    return b;
}   //min

void solve()
{
    if (strlen(Zx) > strlen(LoveZx))
    {
        printf("Poor LoveZx\n");    return ;
    }
    else if(strlen(Zx) < strlen(LoveZx))
    {
        printf("0\n");  return ;
    }
    else
    {
        int len = strlen(Zx);
        int ans = INF;

        memset(Counts , 0 , sizeof(Counts));

        for (int i = 0;i < len;i ++)
            Counts[LoveZx[i] - '0'] ++;

        int tot = 0;
        int cnt = 0;
        bool flag = false;

        for (int i = 0;i < len;i ++)
        {
            if (tot > ans)
                break;
            while ((cnt < len) && !Counts[LoveZx[cnt] - '0'])
                cnt ++;
            Counts[LoveZx[cnt] - '0'] --;

            if (Zx[i] < LoveZx[cnt])
            {
                ans = min(tot , ans);
                break;
            }   //Zx[i] < LoveZx[i]
            else if(Zx[i] > LoveZx[cnt])
            {
                for (int num = 9;num > Zx[i] - '0';num --)
                {
                    if (Counts[num])
                    {
                        flag = true;
                        ans = min( ++tot , ans);
                        break;
                    }
                }   //      candidate number larger than Zx[i]
                if (flag)
                    break;

                if (!Counts[Zx[i] - '0'])
                {
                    break;
                }   //      candidate number smaller than Zx[i]
                else
                {
                    tot ++;
                    Counts[Zx[i] - '0'] --;
                    Counts[LoveZx[cnt] - '0'] ++;
                }   //      candidate number equals Zx[i]
            }   //Zx[i] > LoveZx[i]
            else
            {
                for (int num = 9;num > Zx[i] - '0';num --)
                {
                    if (Counts[num])
                    {
                        ans = min(ans , tot + 1);
                        break;
                    }
                }   //      candidate number larger than Zx[i]
                cnt ++;
            }   //Zx[i] == LoveZx[i]
        }   //for i _ len
        if (ans != INF)
            printf("%d\n" , ans);
        else
            printf("Poor LoveZx\n");
    }   //
}   //solve

int main()
{
    char ch;
    scanf("%d%c" , &T , &ch);
    for (int i = 0;i < T;i ++)
    {
        scanf("%s%s" , Zx , LoveZx);
        solve();
    }

    return 0;
}   //main
