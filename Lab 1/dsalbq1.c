#include<stdio.h>
#define ll long long
#define f(i,a,b) for(ll i=a;i<b;i++)

int main()
{
	ll n; scanf("%lld",&n);

	ll matrix[n][n];

	ll cmax[n];

	f(i,0,n) cmax[i]=-1000000007;

	f(i,0,n)
	{
		ll rminval=1000000007;

		ll rmincol;

		f(j,0,n) 
		{
			scanf("%lld",&matrix[i][j]);

			if(rminval>= matrix[i][j])
			{
				rmincol = j;

				rminval=matrix[i][j];
			}
		}

		if(cmax[rmincol]<=rminval)

			cmax[rmincol]=rminval;

	}

	f(i,0,n)

		if(cmax[i]!=-1000000007)

			f(j,0,n)

				if(cmax[i]<matrix[j][i])
				{
					cmax[i]=-1000000007;
		
					break;
				}

	int temp=0;
		
	f(i,0,n)
		
		if(cmax[i]!=-1000000007)
		{
			printf("%lld\n",cmax[i]);

			temp=1;
		}

	if(temp==0)

		printf("No saddle point present!\n");

	return 0;
}
