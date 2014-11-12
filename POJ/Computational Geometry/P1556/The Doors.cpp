#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;

#define     MAXN    100000

class Node
{
    public:
        double x , y;
        Node (double xx = 0 , double yy = 0)
        {
            this->x = xx;
            this->y = yy;
        }   //constructor
        Node  operator - (Node);
        double operator * (Node);
        bool On_segment(Node , Node);
        bool Among_Interval(Node , Node);
};  //Node

int n;
double a[20][6];
double dis[20][6];

Node Node::operator - (Node p)
{
    return Node(x - p.x , y - p.y);
}   //operator -

double Node::operator * (Node p)
{
    return (x * p.y - y * p.x);
}   //cross

bool Node::Among_Interval(Node q1 , Node q2)
{
    if ((x >= min(q1.x , q2.x) && x <= max(q1.x , q2.x)) &&
        (y >= min(q1.y , q2.y) && y <= max(q1.y , q2.y)))
        return true;
    return false;
}   //Among_Interval

bool Node::On_segment(Node q1 , Node q2)
{
    if ((*this) * (q1 - q2) == 0 &&
        Among_Interval(q1 , q2))
        return true;
    return false;
}   //On_segment

double calc(double x1 , double y1 , double x2 , double y2)
{
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}   //calc

bool Segments_Intersect(Node p1 , Node p2 , Node p3 , Node p4)
{
    double d1 = (p3 - p1) * (p2 - p1);
    double d2 = (p4 - p1) * (p2 - p1);
    double d3 = (p1 - p3) * (p4 - p3);
    double d4 = (p2 - p3) * (p4 - p3);
    if (d1 * d2 < 0 && d3 * d4 < 0)
        return true;
    else if (d1 == 0 && p3.On_segment(p1 , p2))
        return true;
    else if (d2 == 0 && p4.On_segment(p1 , p2))
        return true;
    else if (d3 == 0 && p1.On_segment(p3 , p4))
        return true;
    else if (d4 == 0 && p2.On_segment(p3 , p4))
        return true;
    else return false;
}   //Segments_Intersect

bool check(int ii , int kk , int jj , int ll)
{
    Node p(a[jj][0] , a[jj][ll]);
    Node q(a[ii][0] , a[ii][kk]);
    Node pp , qq;


    //printf("%lf %lf %lf %lf\n" , p.x , p.y , q.x , q.y);      //DEBUG
    for (int i = jj + 1;i < ii;i ++)
    {
        pp.x = a[i][0];     pp.y = 0.0;
        qq.x = a[i][0];     qq.y = a[i][1];
        if (Segments_Intersect(p , q , pp , qq))
            return false;
        pp.y = a[i][2];     qq.y = a[i][3];
        //printf("%lf %lf %lf %lf\n" , pp.x , pp.y , qq.x , qq.y);    //DEBUG
        if (Segments_Intersect(p , q , pp , qq))
            return false;
        pp.y = a[i][4];     qq.y = 10.0;
        if (Segments_Intersect(p , q , pp , qq))
            return false;
    }   //for i _ jj -> ii
    return true;
}   //check

void solve()
{
    double tmp;
    for (int i = 1;i <= n + 1;i ++)
        for (int j = 0;j <= 4;j ++)
            dis[i][j] = MAXN;
    for (int j = 0;j <= 4;j ++)
        dis[0][j] = 0;

    for (int i = 1;i <= n + 1;i ++)
        for (int k = 1;k <= 4;k ++)
            for (int j = 0;j < i;j ++)
                for (int l = 1;l <= 4;l ++)
                {
                    if (check(i , k , j , l))
                    {
                        tmp = calc(a[i][0] , a[i][k] , a[j][0] , a[j][l]);
                        //printf("%d %d %d %d %lf\n" , i , k , j , l , tmp);   //DEBUG
                        if (dis[j][l] + tmp < dis[i][k])
                            dis[i][k] = dis[j][l] + tmp;
                    }   //check
                }   //for l
    printf("%.2f\n" , dis[n + 1][1]);
}   //solve

int main()
{
    while (scanf("%d" , &n) && (n >= 0))
    {
        a[0][0] = 0.0;
        a[0][1] = a[0][2] = a[0][3] = a[0][4] = 5.0;
        a[n + 1][0] = 10.0;
        a[n + 1][1] = a[n + 1][2] = a[n + 1][3] = a[n + 1][4] = 5.0;
        for (int i = 1;i <= n;i ++)
        {
            scanf("%lf" , &a[i][0]);
            scanf("%lf%lf%lf%lf" , &a[i][1] , &a[i][2] , &a[i][3] , &a[i][4]);
        }   //for i _ n
        solve();
    }   //while

    return 0;
}   //main
