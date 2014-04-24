#include<cstdio>
#include<cstdlib>

int main()
{
	int T,x,y,t,i,u,d,r,l,A;
	char z;
	scanf("%d",&T);
	for(A=0;A<T;A++)
	{
		scanf("%d%d%d",&x,&y,&t);
		u=d=r=l=0;
		for(i=0;i<t;i++)
		{
			z=getchar();
			switch(z)
			{
			case 'U': u++;break;
			case 'D': d++;break;
			case 'R': r++;break;
			case 'L': l++;
			}
			if((y>=0&&y<=u||y<0&&-y==d)&&(x>=0&&x<=r||x<0&&-x==l))
			{
				printf("%d\n",i+1);
				break;
			}
		}   //for i
		if((y>=0&&y<=u||y<0&&-y==d)&&(x>=0&&x<=r||x<0&&-x==l));
		else
			printf("-1\n");
	}   //for A
	system("pause");
	return 0;
}
