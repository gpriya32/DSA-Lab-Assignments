#include<stdio.h>
#include<math.h>
#define f(i,a,b) for(ll i=a;i<b;i++)
#define ll long long

ll i,j, maxr, maxl, maxu, maxd, ch,count;

void spiralMaker(int n,ll spiral[n][n],ll k)
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

int checkPrime(ll x)
{
	for(ll i=2; i<=sqrt(x) ;i++)
	
		if(x%i==0)
			
			return 0;

	return 1; 
}

int main()
{
	int n; scanf("%d",&n);

	ll spiral[n][n];

	if(n%2!=0)

		i=j=((n+1)/2)-1; 

	else
	{
		i=n/2; j=n/2-1;
	}

	maxr=j+1, maxl=j-1, maxu=i-1, maxd=i+1;

	ch=1,count=0;

	spiralMaker(n,spiral,2);

	spiralMaker(n,spiral,3);

	f(k,1,10000000)
	{
		if(count==n*n) break;

		if(checkPrime(6*k-1)) spiralMaker(n,spiral,6*k-1);
		
		if(count==n*n) break;
		
		if(checkPrime(6*k+1)) spiralMaker(n,spiral,6*k+1);

	}
	
	f(p,0,n)
	{
		f(q,0,n) 

			printf("%8lld ",spiral[p][q]);

		printf("\n");
	}

	return 0;
}
