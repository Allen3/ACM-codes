#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

class Node
{
public:
    double x , y;
    Node (double xx = 0 , double yy = 0)
    {
        this->x = xx;
        this->y = yy;
    }   //Constructor
    Node operator - (Node p)
    {
        return Node(x - p.x , y - p.y);
    }   //  operator -
    double operator * (Node p)
    {
        return x * p.y - y * p.x;
    }   //  operator *
    bool Among_Interval(Node p , Node q)
    {
        return ((x >= min(p.x , q.x)) && (x <= max(p.x , q.x)) &&
                (y >= min(p.y , q.y)) && (y <= max(p.y , q.y)));
    }   //Among_Interval
    bool On_segment(Node p , Node q)
    {
        return (((*this - q) * (p - q) == 0) && (this->Among_Interval(p , q)));
    }   //On_segment
};  //Node

bool Segments_Intersect(Node p1 , Node q1 , Node p2 , Node q2)
{
    double d1 = (p2 - q1) * (p1 - q1);
    double d2 = (q2 - q1) * (p1 - q1);
    double d3 = (p1 - q2) * (p2 - q2);
    double d4 = (q1 - q2) * (p2 - q2);
    if (d1 * d2 < 0 && d3 * d4 < 0)
        return true;
    else if (d1 == 0 && p2.On_segment(p1 , q1))
        return true;
    else if (d2 == 0 && q2.On_segment(p1 , q1))
        return true;
    else if (d3 == 0 && p1.On_segment(p2 , q2))
        return true;
    else if (d4 == 0 && q1.On_segment(p2 , q2))
        return true;
    return false;
}   //Segments_Intersect

int n;
Node a[100010] , b[100010];
bool tag[100010];

void solve()
{
    memset(tag , 0 , sizeof(tag));
    tag[n - 1] == true;
    int cnt = 1;

    for (int i = n - 2;i >= 0;i --)
    {
        bool flag = true;
        for (int j = i + 1;j < n;j ++)
        {
            if (Segments_Intersect(a[i] , b[i] , a[j] , b[j]))
            {
                flag = false;
                break;
            }   //if
        }   //for j _ i
        if (flag)
        {
            tag[i] = true;
            cnt ++;
        }
        if (cnt >= 1000)
            break;
    }   //for i _ n

    printf("Top sticks:");
    for (int i = 0;i < n - 1;i ++)
        if (tag[i])
            printf(" %d," , i + 1);
    printf(" %d.\n" , n);
}   //solve

int main()
{
    while (scanf("%d" , &n) && n)
    {
        for (int i = 0;i < n;i ++)
            scanf("%lf%lf%lf%lf" , &a[i].x , &a[i].y , &b[i].x , &b[i].y);
        solve();
    }   //while

    return 0;
}   //main
