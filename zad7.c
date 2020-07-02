#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <signal.h>

void sigusr1Handler(int signum)
{
    if (signum == SIGUSR1)
    {
         FILE * dst;
        dst = fopen("pid.txt", "a");
        if (!dst)
        {
            printf("Cannot open file");
            return 1;
        }
        fprintf(dst, " PPID: %d", getppid());

        fclose(dst);
        exit(0);
    }
}

void sigusr2Handler(int signum)
{
    if (signum == SIGUSR2)
    {
        FILE * dst;
		//Otworzenie pliku w trybie write automatycznie czyści plik
        dst = fopen("pid.txt", "w");
        fclose(dst);

        exit(0);
    }
}

int main(int argc, char *argv[])
{
    //Rejestrujemy sie na sygnaly
    signal(SIGUSR1, sigusr1Handler);
    signal(SIGUSR2, sigusr2Handler);

    FILE * dst;
	dst = fopen("pid.txt", "w");
	if (!dst)
	{
		printf("Cannot open file");
		return 1;
	}
    fprintf(dst, "PID: %d", getpid());

    fclose(dst);

    //Tak mozna przetestowac sygnaly
    //kill(getpid(), SIGUSR2);
    //kill(getpid(), SIGUSR1);
}

