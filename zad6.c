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
    //Pobieramy obecna sciezke
    char cwd[PATH_MAX];
    getcwd(cwd, sizeof(cwd));
    char *binaryPath = "/bin/ls";

    execl(binaryPath, binaryPath, cwd, NULL);
	
    return 0;
}

int main(int argc, char *argv[])
{
    pid_t cpid;
    if (fork()== 0)
    {
        childFunction();
    }
    else
    {
        wait(NULL);
    }
}

