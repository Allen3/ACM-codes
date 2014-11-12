#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

struct node
{
    int x , y;
};  //node

struct board
{
    int u , l;
};  //board

int  n , m , x1 , y1 , x2 , y2;
int  box[1010];
node toys[1010];
board card[1010];

bool cmp(board a , board b)
{
    return (a.u < b.u);
}   //cmp

int  calc(int toy_x , int card_x)
{
    return ((toys[toy_x].x - card[card_x].l) * (y1 - y2) -
            (toys[toy_x].y - y2) * (card[card_x].u - card[card_x].l));
}   //calc

void solve()
{
    memset(box , 0 , sizeof(box));
    sort(card , card + n , cmp);
    for (int i = 0;i < m;i ++)
    {
        int l = 0 , r = n - 1 , mid;
        while (l < r)
        {
            mid = (l + r) >> 1;
            if (calc(i , mid) < 0)
                r = mid;
            else
                l = mid + 1;
        }   //while
        if (calc(i , l) > 0)
            box[n] ++;
        else
            box[l] ++;
    }   //for i _ m

    sort(box , box + n + 1);

    int tmp = box[0] , cnt = 1;
    box[n + 1] = -1;
    printf("Box\n");
    for (int i = 1;i <= n + 1;i ++)
    {
        if (box[i] != tmp)
        {
            if (tmp)
                printf("%d: %d\n" , tmp , cnt);
            tmp = box[i];
            cnt = 1;
        }
        else
            cnt ++;
    }
}   //solve

int main()
{
    while (scanf("%d" , &n) && n)
    {
        scanf("%d%d%d%d%d" , &m , &x1 , &y1 , &x2 , &y2);
        for (int i = 0;i < n;i ++)
        {
            scanf("%d%d" , &card[i].u , &card[i].l);
        }   //
        for (int i = 0;i < m;i ++)
        {
            scanf("%d%d" , &toys[i].x , &toys[i].y);
        }   //
        solve();
    }   //



    return 0;
}   //main
