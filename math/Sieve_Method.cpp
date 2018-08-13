#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define maxn 10000005
using namespace std;

int N,M,f[maxn],g[maxn],h[maxn],phi[maxn],u[maxn],p[maxn]; //f[n]Ϊn����С�����ӣ�g[n]=f[n]^k��phi[n]Ϊŷ��������u[n]ΪĪ����˹������h[n]Ϊһ����Ժ��� 

void prime()
{
	u[1]=phi[1]=1,h[1]=(0); //1��ʱ������ 
	for (int i=2; i<=N; i++)
	{
		if (!f[i]) p[++M]=i,f[i]=g[i]=i,phi[i]=i-1,u[i]=-1,h[i]=(0); //������ʱ������ 
		for (int j=1,k; j<=M&&p[j]<=f[i]&&i*p[j]<=N; j++)
		{
			f[k=i*p[j]]=p[j];
			if (p[j]<f[i]) g[k]=p[j],phi[k]=phi[i]*phi[p[j]],u[k]=u[i]*u[p[j]],h[k]=h[i]*h[p[j]];
			else g[k]=g[i]*p[j],phi[k]=phi[i]*p[j],u[k]=0,h[k]=h[i/g[i]]*(0); /*������������*/
			//phi[i*p[j]]=phi[i]*(p[j]<f[i]?phi[p[j]]:p[j]);
			//u[i*p[j]]=u[i]*(p[j]<f[i]?u[p[j]]:0);
		}
		/*phi[i*j]=phi[i]*phi[j] (gcd(i,j)=1)
				   phi[i]*j (j|i)
		  u[i*j]=u[i]*u[j] (gcd(i,j)=1)
		         0 (j|i)
		*/
	}
}

