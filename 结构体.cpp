#include "stdio.h"
typedef struct{
	int a;
	int b;
}AB;
typedef struct{
	int a;
	int b;
}*pAB;

main(){
	AB ab;
	ab.a=5;
	ab.b=12;
	printf("%d %d",ab.a,ab.b);
	pAB pab;
	pab->a=14;
	pab->b=5;
	printf("%d %d",pab->a,pab->b);
}
