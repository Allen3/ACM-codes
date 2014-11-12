/*
 *  ID:     Allen_3
 *  Prob:   The Heros
 *  LANG:   C++
*/
#include<cstdio>
#include<cstring>
using namespace std;

struct node
{
    char str[52];
};  //node

node temp[12];

int main()
{
    int n , m;
    scanf("%d" , &n);
    for (int i = 0;i < n;i ++)
        scanf("%s" , temp[i].str);
    scanf("%d" , &m);
    for (int i = 0;i < m;i ++)
    {
        bool flag = false;
        char str[52];
        scanf("%s" , str);
        for (int i = 0;i < n;i ++)
            if (strstr(str , temp[i].str) != NULL)
            {
                printf("A new hero discovered\n");
                flag = true;
                break;
            }
        if (!flag)
            printf("Just an ordinary person\n");
    }   //

    return 0;
}   //main
