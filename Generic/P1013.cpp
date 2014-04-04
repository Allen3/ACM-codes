#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;

#define		input		"input.txt"

struct node
{
	char str1[6] , str2[6] , stt[6];
};	//node

int  T;
node arr[4];

int check(int x)
{
	int flag = 0 , pos;

	for (int i = 0;i < 3;i ++)
	{
		pos = 0;
		for (int j = 0;j < strlen(arr[i].str1);j ++)
		{
			if (arr[i].str1[j] == x + 'A')
			{
				pos = 1;
				break;
			}
		}	//for j _ length

		if (!pos)
			for (int j = 0;j < strlen(arr[i].str2);j ++)
			{
				if (arr[i].str2[j] == x + 'A')
				{
					pos = 2;
					break;
				}
			}	//for j _ length

		if (pos)
		{
			if (strcmp(arr[i].stt , "even") == 0)
				return 0;						
			else if (strcmp(arr[i].stt ,"up") == 0)
			{
				if (!flag)
					flag = 1;
				else if (pos == 1 && flag == 1)
					return 0;
				else if (pos == 2 && flag == 2)
					return 0;
			}	//up
			else
			{
				if (!flag)
					flag = 2;
				else if (pos == 1 && flag == 2)
					return 0;
				else if (pos == 2 && flag == 1)
					return 0;
			}	//down
		}	//flag		
	}	//for i _ 3
	if (flag == 0)
		return 0;
	else if (flag == 1)
		return 1;
	else
		return 2;
}	//check

void solve()
{
	int ans;
	for (int i = 0;i < 12;i ++)
	{
		ans = check(i);
		if (ans == 1)
			printf("%c is the counterfeit coin and it is light.\n" , i + 'A');
		if (ans == 2)
			printf("%c is the counterfeit coin and it is heavy.\n" , i + 'A');
	}	//
}	//solve

int main()
{
	freopen(input , "r" , stdin);

	scanf("%d" , &T);
	while (T --)
	{
		for (int i = 0;i < 3;i ++)
			scanf("%s%s%s" , arr[i].str1 , arr[i].str2 , arr[i].stt);
		solve();
		printf("\n");
	}	//while

	return 0;
}	//main

