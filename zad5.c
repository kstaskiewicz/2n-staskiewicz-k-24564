#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

int childFunction()
{
	FILE * dst;

	dst = fopen("liczby.txt", "w");

	if (!dst)
	{
		printf("Cannot open file");
		return 1;
	}

	int i = 1;
    int c;

    for(int i =9; i<= 99 ; i++)
	{
        //Liczby podzielne przez 3 bez reszty
		if( i% 3 ==0)
		{
            fprintf(dst, " %d", i);
		}
	}
    fclose(dst);
    return 0;
}

int main(int argc, char *argv[])
{
    pid_t cpid;
    if (fork()== 0)
    {
        exit(childFunction());
    }
    else
    {
        int ret;
		//Czekamy na childa i pobieramy result
        cpid = wait(&ret);
        printf("ret = %d\n", ret);
    }
}

