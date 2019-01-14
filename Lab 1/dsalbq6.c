#include<stdio.h>
#include<math.h>

#define ll long long
#define f(i,a,b) for(ll i=a;i<b;i++)

int main()
{
	ll a,b; scanf("%lld%lld",&a,&b);

	if(a>b)
	{ 
		printf("Invalid Input!\n");

		return 0;

	}

	ll arr[b+1]; 

	arr[0]=arr[1]=0;

	f(i,2,b+1) arr[i]=1;

	f(i,2,sqrt(b))

		if(arr[i]==1)

			for(ll j=i*2;j<b+1;j+=i)

				arr[j]=0;

	printf("Prime numbers between a and b (included) are:\n");

	f(i,a,b+1)

		if(arr[i]!=0) printf("%lld ",i);

	printf("\n");

	return 0;
}
