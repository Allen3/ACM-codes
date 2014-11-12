#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

class node
{
    public:
        int x , y;
        node (int xx = 0 , int yy = 0)
        {
            this->x = xx;
            this->y = yy;
        }
        node operator +(node p) { return node(x + p.x , y + p.y); }
        node operator -(node p) { return node(x - p.x , y - p.y); }
        int  operator *(node p) { return     (x * p.y - y * p.x); }
};  //node

class board
{
    public:
        node u , l;
};  //board

int n , m , x1 , y1 , x2 , y2;
board card[5010];
node toy[5010];
bool hash[5010];

bool check(node q , node p1 , node p2)
{
    if ((q - p2) * (p1 - p2) < 0)
        return true;
    return false;
}   //check

void solve()
{
    int sum = 0;
    memset(hash , 0 , sizeof(hash));
    for (int i = 0;i < n;i ++)
    {
        int cnt = 0;
        for (int j = 0;j < m;j ++)
        {
            if (!hash[j] && check(toy[j] , card[i].u , card[i].l))
            {
                hash[j] = 1;
                cnt ++; sum ++;
            }
        }
        printf("%d: %d\n" , i , cnt);
    }   //for i _ n
    printf("%d: %d\n" , n , m - sum);
    printf("\n");
}   //solve

int main()
{
    while (scanf("%d" , &n) && n)
    {
        scanf("%d%d%d%d%d" , &m , &x1 , &y1 , &x2 , &y2);
        for (int i = 0;i < n;i ++)
        {
            scanf("%d" , &card[i].u.x); card[i].u.y = y1;
            scanf("%d" , &card[i].l.x); card[i].l.y = y2;
        }   //
        for (int i = 0;i < m;i ++)
        {
            scanf("%d%d" , &toy[i].x , &toy[i].y);
        }   //
        solve();
    }   //while

    return 0;
}   //main
