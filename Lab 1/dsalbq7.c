#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void reverse(char *string)
{
	char ch;

	for(int i=0,j=strlen(string)-1;i<strlen(string) && i<j; i++,j--)
	{
		ch= string[i];

		string[i]=string[j];

		string[j]=ch;
	}
}

void encodeString(){

	printf("Enter the string:\n");
	
	char *string=NULL, *word=NULL;

	char *ch = (char *)malloc(sizeof(char));

	int i=0;

	do{
		*ch=getchar();

		if(*ch!=' ' && *ch!='\n')
		{
			if((i+1)%2!=0)
			{
				*ch+=3;	

				if(*ch>122)  *ch = *ch-122+96; 

				if(*ch>90 && *ch<94) *ch = *ch-90+64;
			}

			if(word==NULL)
			
				word = (char *)malloc(sizeof(char));

			else
				word = realloc(word,sizeof(word)+sizeof(char));

			strcat(word,ch);
		
			i++;

		}

		if(*ch==' ' || *ch=='\n')
		{
			reverse(word);	

			if(string == NULL)		

				string = (char *)malloc(sizeof(word)+sizeof(char));

			else
			
				string = realloc(string,sizeof(string)+sizeof(word)+sizeof(char));


			strcat(string,word);

			strcat(string," ");

			word=NULL;

		}
		
	}while(*ch!='\n');

	printf("Encoded string:\n%s\n",string);

	free(string);

	free(ch);
	
	free(word);
}

void decodeString()
{
	printf("Enter the string:\n");
	
	char *string=NULL, *word=NULL;

	char *ch = (char *)malloc(sizeof(char));

	long long i=0,alphaCnt=0; 

	do{
		*ch=getchar();

		if(*ch!=' ' && *ch!='\n')
		{
			if(word==NULL)
			
				word = (char *)malloc(sizeof(char));

			else
				word = realloc(word,sizeof(word)+sizeof(char));

			strcat(word,ch);

		}

		if(*ch==' ' || *ch=='\n')
		{
			reverse(word);

			alphaCnt+=strlen(word);

			long long j=0;

			for(;i<alphaCnt;i++)
			{
				if((i+1)%2!=0)
				{
					word[j]-=3;

					if(word[j]<97 && word[j]> 93) word[j] = word[j]-97+123;

					if(word[j]<65) word[j] = word[j]-65+91;
				}

				j++;	
			}

			if(string == NULL)		

				string = (char *)malloc(sizeof(word)+sizeof(char));

			else
			
				string = realloc(string,sizeof(string)+sizeof(word)+sizeof(char));


			strcat(string,word);

			strcat(string," ");

			word=NULL;

		}
		
	}while(*ch!='\n');

	printf("Decoded string:\n%s\n",string);

	free(string);

	free(ch);
	
	free(word);
}

int main()
{
	int opt;

	printf("Press 1 to Encode and 2 to Decode:\n");

	scanf("%i",&opt);
	
	getchar();

	(opt==1)?encodeString():decodeString();

	return 0;
	
}
