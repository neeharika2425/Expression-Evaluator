#include<stdio.h>
#include<string.h>
char stack[100][100];
char out[100][100];
int sp=-1;
int ot=0;
FILE *f;
FILE *f1;
int prece(char * str)
{
	if( strcmp(str,"(")==0 || strcmp(str,")")==0)
		return 0;
	if( strcmp(str,"/")==0 || strcmp(str,"*")==0)
		return 2;
	if( strcmp(str,"+")==0 || strcmp(str,"-")==0)
		return 1;
}
int main()
{
	f = fopen("prefix","w");
	f1 = fopen("infixStrings.txt","r");
	char string[100][100],ch;
	int num=0,c,k=0,n=0,l,j,i;
	char str[100];

	while(fscanf(f1,"%[^\n]",str)!=EOF)
	{
		//printf("%s\n",string);
		strcpy(string[k++],str);
		char dump;
		fscanf(f1,"%c",&dump);
	}
//printf("%d---\n",k);
	for(l=0;l<k;l++)
	{

		char * pch;
		char words[100][100];
		pch = strtok (string[l]," ");
		sp = -1;
		ot = 0;
		c = 0;

		while(pch!=NULL)
		{
			strcpy(words[c],pch);
			c++;
			//			printf("%s",pch);
			pch = strtok (NULL, " ");
		}

		for(i=c-1;i>=0;i--)
		{  
			//                   printf("%s ",words[i]);
			if((strcmp(words[i],"+")==0  || strcmp(words[i],"-")==0 || strcmp(words[i],"*")==0 || strcmp(words[i],"/")==0 ) && sp == -1 )
			{
				sp++;
				strcpy(stack[sp],words[i]);
			}
			else if ((strcmp(words[i],"+")==0  || strcmp(words[i],"-")==0 || strcmp(words[i],"*")==0 || strcmp(words[i],"/")==0) && sp != -1 )
			{
				if (prece(words[i]) >= prece (stack[sp]))
				{
					sp++;
					strcpy(stack[sp],words[i]);

				}
				else
				{
					for(j=sp;j>=0;j--)
					{
						if(prece (words[i]) >= prece(stack[sp]))
						{
							//		sp++;
							//		strcpy(stack[sp],words[i]);
							break;
						}
						else
						{
							strcpy(out[ot],stack[j]);
							ot++; 
							sp--;
						}
					}
					sp++;
					strcpy(stack[sp],words[i]);

				}


			}
			else if(strcmp(words[i],")")==0   )
			{
				sp++;
				strcpy(stack[sp],words[i]);
			}  
			else if(strcmp(words[i],"(")==0   )
			{  
				for(j=sp;j>=0;j--)
				{
					if(strcmp(stack[j],")")==0)
					{
						sp--;
						break;
					}
					else
					{
						strcpy(out[ot],stack[j]);
						ot++;  
						sp--; 
					}
				}


			}


			else
			{
				strcpy(out[ot],words[i]);
				ot++; 


			}

		}
		for(i=sp;i>=0;i--)
		{
			//	printf("%s",stack[i]);
			strcpy(out[ot],stack[i]);
			ot++;
		}
		for(i=ot-1;i>=0;i--)
		{
			if(i!=0)
				fprintf(f,"%s ",out[i]);
			else
			{
				fprintf(f,"%s ",out[i]);
				fprintf(f,";");
			}           
		}
	}
	return 0;
}

