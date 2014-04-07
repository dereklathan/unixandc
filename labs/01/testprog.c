#include <stdio.h>

int main(){
	int c;
	c = (getchar()!=EOF);
	putchar(c);
	printf("\n%d\n",c);
}
