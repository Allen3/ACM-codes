#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;

#define     MAXN    110

const double EPS = 1e-8;
/*====================================basic functions================================*/
inline double fix_double(double x)
{
    return (fabs(x) < EPS? 0.0 : x);
}   //fix_double

inline int sign(double x)
{
    return (x < -EPS? -1 : x > EPS);
}   //sign
/*===================================class Declaration===============================*/
class Point
{
public:
    double x , y;
    Point (){}
    Point (double _x , double _y)
    {
        x = _x;
        y = _y;
    }   //Constructor
    bool operator == (const Point B)
    {
        return (sign(x - B.x) == 0 && sign(y - B.y) == 0);
    }   //Operator ==
    Point operator - (const Point B)
    {
        return Point(x - B.x , y - B.y);
    }   //Operator -
};  //Point

class Segment
{
public:
    Point a , b;
    Segment(){}
    Segment (Point _a , Point _b)
    {
        a = _a;
        b = _b;
    }   //Constructor
};  //Segment
/*========================================auxiliary tools===================================*/
inline double dot(Point O , Point A , Point B)
{
    Point OA = A - O;
    Point OB = B - O;
    return (OA.x * OB.x + OA.y * OB.y);
}   //dot

inline double cross(Point O , Point A , Point B)
{
    Point OA = A - O;
    Point OB = B - O;
    return (OA.x * OB.y - OA.y * OB.x);
}   //cross
/*=======================================Functional Functions===============================*/
//0: Nope           1:Among the segment line      2: On one endpoint
int inSegment(Point pt , Segment seg)
{
    if (sign(cross(pt , seg.a , seg.b))) return 0;
    int ans = sign(dot(pt , seg.a , seg.b));
    return (ans == 0? 2 : ans < 0);
}   //inSegment

//0: No Intersection    1: Standard Intersection    2: Endpoint Intersection    3: Coinside Part Exists
int across(Segment AB , Segment CD)
{
    if (max(AB.a.x , AB.b.x) < min(CD.a.x , CD.b.x) || max(AB.a.y , AB.b.y) < min(CD.a.y , CD.b.y)
      ||max(CD.a.x , CD.b.x) < min(AB.a.x , AB.b.x) || max(CD.a.y , CD.b.y) < min(AB.a.y , AB.b.y))
        return 0;
    int AB_CD = sign(cross(AB.a , AB.b , CD.a)) * sign(cross(AB.a , AB.b , CD.b));
    int CD_AB = sign(cross(CD.a , CD.b , AB.a)) * sign(cross(CD.a , CD.b , AB.b));

    if (AB_CD == 0 && CD_AB == 0 && (inSegment(AB.a , CD) == 1 || inSegment(AB.b , CD) == 1)) return 3;

    if (AB_CD < 0)
        return CD_AB == 0? 2 : CD_AB < 0;
    else if (AB_CD == 0)
        return CD_AB <= 0? 2 : 0;
    return 0;
//What if two segments are end to end?Expecially for the Case 3?
}   //across

//
int n;
Segment seg[MAXN];
Point treasure , pt[MAXN * 10];

inline double dist(Point A , Point B)
{
    return sqrt((B.x - A.x) * (B.x - A.x) + (B.y - A.y) * (B.y - A.y));
}   //double

bool cmp(const Point &A , const Point &B)
{
    Point O = Point(-1.0 , -1.0);
    int ans = sign(cross(O , A , B));
    if (fix_double(A.y) == 0 && fix_double(B.y) == 0)
        return dist(O , A) + EPS < dist(O , B);
    else if (fix_double(A.x) == 0 && fix_double(B.x) == 0)
        return dist(O , A) + EPS > dist(O , B);
    else
        return ans > 0;
}   //cmp

int solve()
{
    int ans = n + 1 , cnt = 0;
    for (int i = 0;i < n;i ++)
    {
        pt[cnt ++] = seg[i].a;
        pt[cnt ++] = seg[i].b;
    }   //for i _ n
    pt[cnt ++] = Point(0 , 0);
    pt[cnt ++] = Point(100 , 100);
    pt[cnt ++] = Point(100 , 0);
    pt[cnt ++] = Point(0 , 100);

    sort(pt , pt + cnt , cmp);
    for (int i = 0;i < cnt;i ++)
        printf("%lf %lf\n" , pt[i].x , pt[i].y);

    for (int i = 1;i < cnt;i ++)
    {
        Point center((pt[i].x + pt[i - 1].x) / 2 , (pt[i].y + pt[i - 1].y) / 2);
        Segment link(treasure , center);
        int tot = 0;
        for (int j = 0;j < n;j ++)
        {
            if (across(link , seg[j]))
                tot ++;
        }
        if (tot < ans)
            ans = tot;
    }   //for i _ cnt
    return ans + 1;
}   //solve

int main()
{
    scanf("%d" , &n);
    for (int i = 0;i < n;i ++)
    {
        scanf("%lf%lf%lf%lf" , &seg[i].a.x , &seg[i].a.y , &seg[i].b.x , &seg[i].b.y);
    }   //for i
    scanf("%lf%lf" , &treasure.x , &treasure.y);
    printf("Number of doors = %d\n" , solve());
    return 0;
}   //main
