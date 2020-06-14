#include <stdio.h>
#include <afxtempl.h>
int main()
{  int  a = 0, b = 1;
   char c = 'A';
   int *pa = &a, *pb = &b; 
   char *pc = &c;            
   *pa=9;
   printf("a is %d, &a is %p, pa is %p, *pa is %d\n", a, &a, pa, *pa);		// a 是数 ， &a 是地址 ，pa 是地址 ， *pa 是数字 
   printf("b is %d, &b is %p, pb is %p, *pb is %d\n", b, &b, pb, *pb);
   printf("c is %c, &c is %p, pc is %p, *pc is %c\n", c, &c, pc, *pc);
   
   int *pd=new int;
   pd = 11;
   printf("%d",pd);
   
   
   
   return 0;
}

