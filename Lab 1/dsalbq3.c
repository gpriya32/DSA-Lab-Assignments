#include<stdio.h>
#include<math.h>
#define f(i,a,b) for(int i=a;i<b;i++)

int main()
{
	int n; scanf("%i",&n);

	int spiral[n][n];

	int prime[8000];
		
	f(i,2,8000) prime[i]=1;

	f(i,2,sqrt(8000))
	
		if(prime[i]==1)

			for(int j=i*2;j<8000;j+=i)	prime[j]=0;

	int i,j;

	if(n%2!=0)

		i=j=((n+1)/2)-1; 

	else
	{
		i=n/2; j=n/2-1;
	}

	int maxr=j+1, maxl=j-1, maxu=i-1, maxd=i+1;

	int ch=1,count=0;

	f(k,2,8000)
	{
		if(count==n*n) break;

		if(prime[k]==1)	
		{	
			count++;
			
			spiral[i][j]=k;
	
			if(j==maxl && i==maxd)
			{
				maxr+=1; maxl-=1; maxu-=1; maxd+=1;
			}
	
			switch(ch)
			{
	
				case 1: if(j+1<=maxr) ++j;
		
					if(j==maxr) ch=2;
	
					break;
	
				case 2: if(i-1>=maxu) --i;
			
					if(i==maxu) ch=3;
		
					break;
		
				case 3: if(j-1>=maxl) --j;
	
					if(j==maxl) ch=4;
	
					break;
	
				case 4: if (i+1<=maxd) ++i;
				
					if(i==maxd) ch=1;
	
			}	
			
		}

	}
	
	f(p,0,n)
	{
		f(q,0,n) 

			printf("%i   ",spiral[p][q]);

		printf("\n");
	}

	return 0;
}
