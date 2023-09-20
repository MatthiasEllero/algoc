#include <stdio.h>
#include "echangeContenu.h"

int main(void)
{
	int a;
	int b;
	scanf("%d",&a);
	scanf("%d",&b);

	printf ("a = %d\tb = %d\n", a, b);

	echangeContenu(&a,&b);

	printf ("a et b echanges \n");
	printf ("a = %d\tb = %d\n", a, b);

	return 0;
}

