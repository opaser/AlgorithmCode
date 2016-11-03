#include<cstdio>
#include<cmath>
using namespace std;
int T,n;
int a[1000005],b[1000005],ge[1000005];
int gcd(int x,int y)
{
	    if(y>x)
				  return gcd(y,x);
			if(x*y==0) 
					return x+y;
			return gcd(y,x%y);
}
int main()
{
	  int i,j;
		scanf("%d",&T);
		while(T--){
					int hh=0;
					scanf("%d",&n);
					for(i=1;i<=1000000;i++)
					  b[i]=-1,ge[i]=0;
					for(i=1;i<=n;i++)
					{
					   scanf("%d",&a[i]);
					   for(j=1;j<=int(sqrt(a[i]));j++)
					      if(a[i]%j==0)
					       {
										if(b[j]==-1)
										{
											 b[j]=a[i]/j;
										}
										else
											 b[j]=gcd(b[j],a[i]/j);
										if(b[a[i]/j]==-1)
											 b[a[i]/j]=j;
									  else
									     b[a[i]/j]=gcd(b[a[i]/j],j);
									  if(j==a[i]/j)
									     ge[j]++;
									  else
									  {
									     ge[j]++;
									     ge[a[i]/j]++;
									  }
								 }            
				 }
				 for(i=1;i<=1000000;i++)
				 {
				    if(ge[i]>=2&&b[i]==1)
				    {
				      if(hh==0)
				           printf("%d",i);
				      else
					        printf(" %d",i);
					    hh++;
					  }
			  }
				printf("\n");
		}
		return 0;
}
