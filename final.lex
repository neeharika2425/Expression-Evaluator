%{
	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
	float stack[1000];
	int sp = -1;
	float val;
         FILE *f;
%}
digit [0-9]
%%
[-]?[0-9][0-9]*\.?[0-9]* { 

	sp++;
	stack[sp]=atof(yytext);
         //  printf("%s",stack[sp]);
 while(stack[sp-1]<11000 && sp >= 2 )
{
                    if(stack[sp-2] == 1100001)
				{val = stack[sp-1] + stack[sp];
			        sp-=3;
			        sp++;
				stack[sp] = val;
		         	}
                    else if(stack[sp-2] == 1100002)
				{val = stack[sp-1] - stack[sp];
			        sp-=3;
			        sp++;
				stack[sp]=val;
		         	}
                    else if(stack[sp-2] == 1100003)
				{val = stack[sp-1] * stack[sp];
			        sp-=3;
			        sp++;
				stack[sp] = val;
		         	}
                    else if(stack[sp-2] == 1100004)
				{val = stack[sp-1] / stack[sp];
			        sp-=3;
			        sp++;
				stack[sp]  = val;
		         	}
                  else
                  break;


}
}
[+]			{sp++ ; stack[sp]= 1100001;}
[-]			{sp++ ; stack[sp] = 1100002;}
[*]			{sp++ ; stack[sp] = 1100003;}
[/]			{sp++ ; stack[sp] = 1100004;}
[;]			{fprintf(f,"The value of the expression is : %0.2f\n", stack[0]); sp =-1;}
%%


int yywrap(void)
{
	return 1;
}
int main(int argc , char *argv[])
{
   f = fopen("answers.txt","w");
	yyin = fopen("prefix", "r");
	yylex();

	fclose(yyin);
	return 0;
}
