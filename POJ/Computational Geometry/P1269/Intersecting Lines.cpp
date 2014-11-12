#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;

#define     eps     1e-3

struct Node
{
    int x , y;
    Node (int xx = 0 , int yy = 0)
    {
        this->x = xx;
        this->y = yy;
    }   //Constructor
    Node operator - (Node p)
    {
        return Node(x - p.x , y - p.y);
    }   //Operator -
    int operator * (Node p)
    {
        return (x * p.y - y * p.x);
    }   //Operator *
};  //Node

struct Line
{
    Node p , q;
};  //Line

int n;
Line a[30];
Line b[30];

inline int cmp(double xx , double yy)
{
    if (fabs((xx - yy)) < eps)  return 0;
    else if (xx > yy) return 1;
    return -1;
}   //cmp

void solve()
{
    printf("INTERSECTING LINES OUTPUT\n");
    for (int i = 0;i < n;i ++)
    {
        Node v1 = a[i].q - a[i].p;
        Node v2 = b[i].q - b[i].p;
        int cross = v1 * v2;
        if (cross == 0)
        {
            if ((b[i].q - a[i].p) * (a[i].q - a[i].p) == 0)
                printf("LINE\n");
            else
                printf("NONE\n");
        }   //  Parallel or Collineation
        else
        {
            if (v1.x == 0)
            {
                double k2 = (double)(b[i].q.y - b[i].p.y) / (double)(b[i].q.x - b[i].p.x);
                double b2 = (double)(b[i].q.y) - (double)(b[i].q.x) * k2;
                printf("POINT %d.00 %.2lf\n" , a[i].p.x , b2);
            }   //  line1 is verticle
            else if (v2.x == 0)
            {
                double k1 = (double)(a[i].q.y - a[i].p.y) / (double)(a[i].q.x - a[i].p.x);
                double b1 = (double)(a[i].q.y) - (double)(a[i].q.x) * k1;
                printf("POINT %d.00 %.2lf\n" , b[i].p.x , b1);
            }   //  line2 is verticle
            else
            {
                double k1 = (double)(a[i].q.y - a[i].p.y) / (double)(a[i].q.x - a[i].p.x);
                double k2 = (double)(b[i].q.y - b[i].p.y) / (double)(b[i].q.x - b[i].p.x);
                double b1 = (double)(a[i].q.y) - (double)(a[i].q.x) * k1;
                double b2 = (double)(b[i].q.y) - (double)(b[i].q.x) * k2;
                double xx = (b2 - b1) / (k1 - k2);
                double yy = k1 * xx + b1;
                printf("POINT %.2lf %.2lf\n" , xx , yy);
            }
        }   //  Intersect
    }   //for i _ n
    printf("END OF OUTPUT\n");
}   //solve

int main()
{
    scanf("%d" , &n);
    for (int i = 0;i < n;i ++)
    {
        scanf("%d%d%d%d" , &a[i].p.x , &a[i].p.y , &a[i].q.x , &a[i].q.y);
        scanf("%d%d%d%d" , &b[i].p.x , &b[i].p.y , &b[i].q.x , &b[i].q.y);
    }   //for i _ n
    solve();

    return 0;
}   //main
