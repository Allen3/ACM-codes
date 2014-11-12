#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;

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

    if (AB_CD == 0 && CD_AB == 0 && (inSegment(AB.a , CD) || inSegment(AB.b , CD) )) return 3;

    if (AB_CD < 0)
        return CD_AB == 0? 2 : CD_AB < 0;
    else if (AB_CD == 0)
        return CD_AB <= 0? 2 : 0;
    return 0;
//What if two segments share a same endpoint and are collinear?
//Expecially for the Case 3?
//Now it is modified , but still need to be varified.
}   //across

int N;
Point pts[10010];
Segment seg[10010];
Point target;

void solve(){
    pts[N].x = pts[0].x;    pts[N].y = pts[0].y;

    int pt1_index = 0 , pt2_index = N;
    for (int i = 1;i < N;i ++){
        if (cross(target , pts[i - 1] , pts[i]) < 0){
            pt1_index = i - 1;
            break;
        }
    }   //for i _ N

    for (int i = N - 1;i > 0;i --){
        if (cross(target , pts[i + 1] , pts[i]) > 0){
            pt2_index = i + 1;
            break;
        }
    }   //for i _ N

    //Test Info
    //printf("pt1_index = %d  pt2_index = %d\n" , pt1_index , pt2_index);

    double ans = 0;
    if (cross(pts[pt1_index] , pts[pt2_index] , target) > 0){
        if (pt1_index != 0)
            for (int i = 1;i <= pt1_index;i ++)
                ans += sqrt((pts[i].x - pts[i - 1].x) * (pts[i].x - pts[i -1 ].x) +
                            (pts[i].y - pts[i - 1].y) * (pts[i].y - pts[i - 1].y));
        if (pt2_index != N)
            for (int i = N - 1;i >= pt2_index;i --)
                ans += sqrt((pts[i + 1].x - pts[i].x) * (pts[i + 1].x - pts[i].x) +
                            (pts[i + 1].y - pts[i].y) * (pts[i + 1].y - pts[i].y));
    }   //
    else{
        for (int i = pt1_index + 1;i <= pt2_index;i ++)
            ans += sqrt((pts[i].x - pts[i - 1].x) * (pts[i].x - pts[i - 1].x) +
                        (pts[i].y - pts[i - 1].y) * (pts[i].y - pts[i - 1].y));

    }   //else
    printf("%.3lf\n" , ans);
}   //solve

int main(){
    scanf("%d" , &N);
    for (int i = 0;i < N;i ++)
        scanf("%lf%lf" , &pts[i].x , &pts[i].y);
    scanf("%lf%lf" , &target.x , &target.y);
    solve();

    return 0;
}   //main
