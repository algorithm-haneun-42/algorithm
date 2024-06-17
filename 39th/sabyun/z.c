#include <stdio.h>
#include <math.h>

int ret;
void position(int n, int r, int c, int rs, int re)
{
	if(n == 0)
	{
		ret = rs;
		return;
	}
	int len = pow(2,n);
	int tlen = (pow(2,n) * pow(2,n)) ;
	int rside = 0;
	int cside = 0;
	if((len/2) -1 < r)
		rside = 1;
	if(((len/2) -1< c))
		cside = 1;
	if(rside == 0 && cside == 0)
		position(n-1, len/2 < r ? r-(len/2): r,len/2 < c ? c-(len/2): c, rs,((rs+re)/4) -1);
	else if(rside == 1 && cside == 0)
		position(n-1, len/2 < r ? r-(len/2): r,len/2 < c ? c-(len/2): c, (rs+re)/4,((rs+re)/4 + (rs+re)/4)-1);
	else if(rside == 0 && cside == 1)
		position(n-1, len/2 < r ? r-(len/2): r,len/2 < c ? c-(len/2): c, ((rs+re)/4 + (rs+re)/4), (rs+re - (rs+re)/4) -1);
	else
		position(n-1, len/2 < r ? r-(len/2): r,len/2 < c ? c-(len/2): c, (rs+re - (rs+re)/4) -1,re);
}
int main()
{
	int n ,r ,c;
	int arr[16][16] = {};
	scanf("%d %d %d", &n, &r, &c);
	position(n,c,r,0,pow(2,n) * pow(2,n));
	printf("%d\n",ret);
	return 0;
}