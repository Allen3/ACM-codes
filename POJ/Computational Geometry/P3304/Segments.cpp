#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;

#define     eps     1e-8

class Node
{
    public:
        double x , y;
        Node (double xx = 0 , double yy = 0)
        {
            this->x = xx;   this->y = yy;
        }   //  Constructor
        Node operator - (Node p)
        {
            return Node(x - p.x , y - p.y);
        }   //  operator -
        double operator * (Node p)
        {
            return (x * p.y - y * p.x);
        }   //  operator *
};  //Node

struct Line
{
    Node p , q;
};  //Line

int T , n , cnt;
Node pts[210];
Line a[110];

inline double dis(Node p , Node q)
{
    return sqrt((p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y));
}   //dis

inline int calc(double xx)
{
    if (fabs(xx) < eps) return 0;
    else if (xx < 0) return -1;
    return 1;
}   //calc

void solve()
{
    if (n == 1 || n == 2)
    {
        printf("Yes!\n");
        return;
    }
    for (int i = 0;i < cnt;i ++)
        for (int j = i + 1;j < cnt;j ++)
        {
            if (dis(pts[i] , pts[j]) < eps) continue;

            bool flag = true;
            for (int k = 0;k < n;k ++)
            {
                int d1 = calc((a[k].p - pts[j]) * (pts[i] - pts[j]));
                int d2 = calc((a[k].q - pts[j]) * (pts[i] - pts[j]));
                if (d1 * d2 > 0)
                {
                    flag = false;
                    break;
                }
            }   //for k _ n
            if (flag)
            {
                printf("Yes!\n");
                return ;
            }
        }   //for i & j _ cnt
    printf("No!\n");
}   //solve

int main()
{
    scanf("%d" , &T);
    for (int i = 0;i < T;i ++)
    {
        memset(pts , 0 , sizeof(pts));
        memset(a , 0 , sizeof(a));
        cnt = 0;
        scanf("%d" , &n);
        for (int i = 0;i < n;i ++)
        {
            scanf("%lf%lf%lf%lf" , &a[i].p.x , &a[i].p.y , &a[i].q.x , &a[i].q.y);
            pts[cnt].x = a[i].p.x;    pts[cnt ++].y = a[i].p.y;
            pts[cnt].x = a[i].q.x;    pts[cnt ++].y = a[i].q.y;
        }   //for i _ n
        solve();
    }   //for i _ T

    return 0;
}   //main
