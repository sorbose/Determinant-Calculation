#include<stdio.h>
double b[10][10];
void fundel (double a[][10], int n, int c )//del col-c
{
	int i,j=1,k=1;
	for(i=1+1;i<=n;i++)
		for(j=1,k=1;j<=n;j++,k++)
		{
			if(j==c) k++;
			b[i-1][j]=a[i][k];
		}
		return;}

//void revokedel (int a[][10],int c[][10], int n, int c)//revokedel col-c
//{
//}

int flag (int i,int j)
{
	if ((i+j)%2==0) return 1;
	return -1;
}

double det (double a[][10],int n)
{
	if (n==2) return b[1][1]*b[2][2]-b[1][2]*b[2][1];
	int i=1,j=1,ii,jj;
	double t,sum=0,tt[10][10];
	
	for(j=1;j<=n;j++)
	{   
		t=b[1][j];
		for (ii=1;ii<=n;ii++)
			for(jj=1;jj<=n;jj++)
				tt[ii][jj]=b[ii][jj];
			fundel(b,n,j);
			sum=sum+flag(i,j)*t*det(b,n-1);
			for (ii=1;ii<=n;ii++)
				for(jj=1;jj<=n;jj++)
					b[ii][jj]=tt[ii][jj];}
	return sum;
	
	
}

int main()
{
	int i,j,n;
	double D,a[10][10];
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{scanf("%d",&a[i][j]); b[i][j]=a[i][j];}
		
		D=det(a,n);
		printf("%lf",D);
		
		
		return 0;}