#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

#define     input       "test.in"
#define     output      "test.out"
#define EPS     1e-8

double fix_double(double x)
{
    return fabs(x) < EPS? 0.0 : x;
}   //fix_double

int sign(double x)
{
    return x < -EPS? -1 : x > EPS;
}   //sign

class Point
{
    public:
        double x , y;
        Point(){}
        Point(double _x , double _y)
        {
            x = _x;     y = _y;
        }   //Constructor
        bool operator == (Point p)
        {
            return ((sign(x - p.x) == 0) && (sign(y - p.y) == 0));
        }   //Operator ==
        Point operator - (Point p)
        {
            return Point(x - p.x , y - p.y);
        }   //Operator -
};  //Point

class Segment
{
    public:
        Point a , b;
        Segment(){}
        Segment(Point _a , Point _b)
        {
            a = _a;     b = _b;
        }   //Constructor
};  //Segment

class Poly
{
    public:
        Point pt[10];
};  //Poly

double dot(Point O , Point A , Point B)
{
    Point OA = A - O;
    Point OB = B - O;
    return (OA.x * OB.x + OA.y * OB.y);
}   //dot

double cross(Point O , Point A , Point B)
{
    Point OA = A - O;
    Point OB = B - O;
    return (OA.x * OB.y - OA.y * OB.x);
}   //cross

//0 : Nope      1: In the segment       2: On one endpoint
int inSegment(Point pt , Segment seg)
{
    if (sign(cross(pt , seg.a , seg.b))) return 0;
    int ans = sign(dot(pt , seg.a , seg.b));
    return ans == 0? 2 : ans < 0;
}   //inSegment

//0 : Nope      1: Standard     2: Endpoint     3: Coinside
int across(Segment AB , Segment CD)
{
    if (max(AB.a.x , AB.b.x) < min(CD.a.x , CD.b.x) || max(AB.a.y , AB.b.y) < min(CD.a.y , CD.b.y)
     || max(CD.a.x , CD.b.x) < min(AB.a.x , AB.b.x) || max(CD.a.y , CD.b.y) < min(AB.a.y , AB.b.y))
        return 0;

    int AB_CD = sign(cross(AB.a , AB.b , CD.a)) * sign(cross(AB.a , AB.b , CD.b));
    int CD_AB = sign(cross(CD.a , CD.b , AB.a)) * sign(cross(CD.a , CD.b , AB.b));

    if (AB_CD == 0 && CD_AB == 0 && (inSegment(AB.a , CD) || inSegment(AB.b , CD))) return 3;

    if (AB_CD < 0)
        return CD_AB == 0? 2 : CD_AB < 0;
    else if (AB_CD == 0)
        return CD_AB <  0? 2 : 0;
    return 0;
}   //across

int n;
Segment seg;
Poly    rec;
Point p , q;

void solve()
{
    for (int i = 1;i <= 4;i ++)
    {
        Segment link(rec.pt[i % 4] , rec.pt[(i - 1) % 4]);

        if (across(link , seg))
        {
            printf("T\n");
            return;
        }
    }   //for i _ 0

    if (seg.a.x >= min(p.x , q.x) && seg.a.x <= max(p.x , q.x) &&
        seg.a.y >= min(p.y , q.y) && seg.a.y <= max(p.y , q.y) &&
        seg.b.x >= min(p.x , q.x) && seg.b.x <= max(p.x , q.x) &&
        seg.b.y >= min(p.y , q.y) && seg.b.y <= max(p.y , q.y))
    {
        printf("T\n");
        return;
    }
    printf("F\n");
}   //solve

int main()
{
    //freopen(input  , "r" , stdin);
    //freopen(output , "w" , stdout);

    scanf("%d" , &n);
    for (int i = 0;i < n;i ++)
    {
        scanf("%lf%lf%lf%lf" , &seg.a.x , &seg.a.y , &seg.b.x , &seg.b.y);
        scanf("%lf%lf%lf%lf" , &p.x , &p.y , &q.x , &q.y);

        if (p.x > q.x)
            swap(p.x , q.x);
        if (p.y > q.y)
            swap(p.y , q.y);

        rec.pt[0].x = p.x;      rec.pt[0].y = p.y;
        rec.pt[1].x = q.x;      rec.pt[1].y = p.y;
        rec.pt[2].x = q.x;      rec.pt[2].y = q.y;
        rec.pt[3].x = p.x;      rec.pt[3].y = q.y;
        solve();
    }   //for i _ n

    //fclose(stdin);
    //fclose(stdout);

    return 0;
}   //main
