#include<stdio.h>
#define ll long long
#define f(i,a,b) for(ll i=a;i<b;i++)

int main()
{
	ll n; scanf("%lld",&n);

	ll spiral[n][n];

	ll i,j;

	if(n%2!=0)

		i=j=((n+1)/2)-1; 

	else
	{
		i=n/2; j=n/2-1;
	}

	ll maxr=j+1, maxl=j-1, maxu=i-1, maxd=i+1;

	int ch=1;

	f(k,1,n*n+1)
	{	
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

	f(p,0,n)
	{
		f(q,0,n) 

			printf("%lld   ",spiral[p][q]);

		printf("\n");
	}

	return 0;
}
