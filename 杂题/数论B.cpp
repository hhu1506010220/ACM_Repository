#include <cstdio>

int main()
{
   int R1=5544,R2=14421,R3=1288,R=21252;
   int a,b,c,day,cas=0;
   getchar();
   while (scanf("%d%d%d%d",&a,&b,&c,&day)!=EOF&&a!=-1) {
      int res=(R1*a+R2*b+R3*c-day)%R;
      res=(res+R-1)%R+1;
      printf("Case %d: the next triple peak occurs in %d days.\n",++cas,res);
   }
   return 0;
}
