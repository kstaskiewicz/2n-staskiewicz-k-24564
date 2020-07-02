#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define SIZE 1
int main(int argc, char *argv[])
{
    //Czytamy jeden znak na raz
	char buf[SIZE];
	int src, dst;
	size_t nread;
	char * fileName = argv[1];
	
    if(fileName == "")
    {
        printf("No file provided in program arguments");
    }
	
	//Alokujemy pamieć na nową nazwę pliku
	char * outFile = malloc(strlen(fileName) + strlen(".red") + 1);
	strcpy(outFile, fileName);
	//Dodajemy na koniec .red
	strcat(outFile, ".red");
	
	src = open(fileName,  O_RDONLY, "r");
	dst = open(outFile, O_WRONLY | O_CREAT, "w");

	if (src < 0 || dst < 0)
	{
		printf("Cannot open file");
		exit(1);
	}

	int i = 1;

    while ((nread = read(src, &buf, SIZE)) > 0)
	{
			write(buf, SIZE, stdout);

		if( i% 3 ==0)
		{
			write(dst, buf, SIZE);
		}
		i++;
	}
	    close(src);
	    close(dst);

}

