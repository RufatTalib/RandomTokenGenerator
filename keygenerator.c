/*

	@author:kochrufet
	@created-on:12-06-2022
	@purpose:key generation
	@update-big:25-04-2023


	Copyright
	All rights reserved.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int help()
{
	printf("Invalid option !\nUsage:\n\t-s\t for key size\n\t--size\t for key size\n");
	return 0;
}

int len(const char* p)
{
	int count = 0;
	while(*p++)count++;

	return count;
}

int main(int argc, char const *argv[])
{
	if(argc < 3)
		return help();

	char* cmd = (char*)argv[1];

	char* opt1 = (char*)"-s";
	char* opt2 = (char*)"--size";

	unsigned char found = 1;

	int length = len(cmd);

	switch(length)
	{
	case 2:
		for (int i = 0; i < 2; i++)
		{
			if(*cmd != *opt1)
			{
				found = 0;
				break;
			}

			opt1++;
			cmd++;
		}
		if(found)
			break;
	case 6:
		cmd = (char*)argv[1];
		for (int i = 0; i < 6; i++)
		{
			if(*cmd != *opt2)
			{
				found = 0;
				return help();
			}

			opt2++;
			cmd++;
		}
		break;
	default:
		return help();
	}

	int n = 32;
	
	int k = 0;
	int res = 0;
	while('0' <= argv[2][k] && argv[2][k] <= '9')
	{
		res = res*10 + (argv[2][k]-48);
		k++;
	}
	if(!res)
	{
		printf("Zero sized key cannot generated\n");
		return 0;
	}

			n = res;

	char* key = (char*) malloc(sizeof(char)*(n+1));
	char  a[]= "abcde456fmnopq03rSTUYWVZXstuv$^&wxyz0123789AB2ghijklCDEFGHI65JKLMNOQ2PR!@#*?1895";
	int j;
	int keyelmsz = strlen(a);

	srand((unsigned int)(time(NULL)));

	for(int i=0; i<n; i++)
	{
		j = rand()%(keyelmsz);
		key[i] = a[j];
	}
	key[n] = 0;
	

	printf("%s\n",key);
	free(key);
 	
	return 0;
}