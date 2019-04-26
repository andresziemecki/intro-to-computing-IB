#include <stdio.h>

int main(void)
	{
		int c, pausa = 0;
		while((c = getchar()) != EOF)
		{
			if ( c == '(')
			pausa = 1;
			if ( pausa == 0 )
			putchar (c);
			if ( c == ')')
			pausa = 0;
		}
	return 0;
	}
