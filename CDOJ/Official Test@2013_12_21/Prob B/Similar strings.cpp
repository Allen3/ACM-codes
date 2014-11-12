/*
 *  ID:     Allen_3
 *  Prob:   Similar strings
 *  LANG:   C++
*/
#include<cstdio>
#include<cstring>
using namespace std;

int T;
int len_a , len_b;
char stra[100010] , strb[100010];
int arra[100010] , arrb[100010];
int hash[200];

int main()
{
    scanf("%d" , &T);
    for (int i = 0;i < T;i ++)
    {
        scanf("%s" , stra);
        scanf("%s" , strb);
        len_a = strlen(stra);   len_b = strlen(strb);
        if (len_a == len_b)
        {
            int tmpa = 0 , tmpb = 0;
            memset(hash , -1 , sizeof(hash));
            for (int i = 0;i < len_a;i ++)
            {
                if (hash[stra[i]] == -1)
                    hash[stra[i]] = tmpa ++;
                arra[i] = hash[stra[i]];
            }
            memset(hash , -1 , sizeof(hash));
            for (int i = 0;i < len_b;i ++)
            {
                if (hash[strb[i]] == -1)
                    hash[strb[i]] = tmpb ++;
                arrb[i] = hash[strb[i]];
            }
            bool flag = true;
            for (int i = 0;i < len_a;i ++)
                if (arra[i] != arrb[i])
                {
                    flag = false;
                    break;
                }
            if (flag)
                printf("YES\n");
            else
                printf("NO\n");
        }   //len_a == len_b
        else
            printf("NO\n");


    }   //for i _ T

    return 0;
}   //main
