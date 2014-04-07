/*CSCI3100 Lab #1

1. A. both programs output with putchar() whatever characters are entered with getchar() until getchar()==EOF
   B. the first program assigns character to char c and then checks if c==EOF. the second makes the assignment
      and checks it in the while parameter. the second also has an error on line 15.
   C. #include <stdio.h>

	int main(){
		int c;
		while(c = getchar()!=EOF){
		putchar(c);
		printf("\n%d\n",c);}
	}

	#include <stdio.h>

	int main(){
		int c;
		c = (getchar()!=EOF);
		putchar(c);
		printf("\n%d\n",c);
	}

	in the two progs above c can only equal a 1 if getchar()!=EOF or a 0 if getchar()==EOF
2. A. counts number of characters entered until end of file then prints nc.
   B. program 3 uses the long for counting while program 4 uses double.
      program 3 uses a while loop and program 4 uses a for loop.
      program 3 outputs as long double program 4 outputs as floating point with 0 decimal places.
   C. no the second control expression gets the character and then checks to see if its end of file

3. A. program 5 counts number of lines until getchar()==EOF
      program 6 counts lines, words, and characters.
   B. if state==OUT, the previous character was either a space, newline, or tab and a word is counted

^D sends EOF */

#include <stdio.h>

int main()
{
	char c;

	while((c = getchar())!=EOF)
	{
		if(c==' '||c=='\t'||c=='\n')
			putchar('\n');
		else
			putchar(c);
	}
}
