#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int childFunction(char * fileName)
{

	int file;
	//Tworzymy plik do odczytu i zapisu z odopwiednimi prawami (0644)
    file = open(fileName, O_RDWR | O_CREAT, 0644);

    //Jesli deskryptor bedzie mniejszy od 0, nie udalo sie stworzyc lub otworzyc pliku
	if (file < 0)
	{
		printf("Cannot open file");
	}

	int bufferSize = 50;
	for(int i =1 ; i < 11; ++i)
	{
        char text [bufferSize];
        //Kopiujemy do text napis z odpowiednimi wartoscami
        sprintf(text, "Wywolanie nr: %d. Numer procesu: %d.\n", i, getpid());

        //Zapisujemy text do pliku. Strlen zwraca dlugosc tekstu w zmiennej
		write(file, text, strlen(text));
    }
	close(file);
	//Zwracamy status
    return 10;
}

int main(int argc, char *argv[])
{

    char * fileName = argv[1];
    //Tworzymy nowy proces. Jesli fork zwroci 0, proces jest childem.
    if (fork()== 0)
    {
        return(childFunction(fileName));
    }
    else
    {
        //Ret bedzie w sobie przechowywal status, ktory zwroci child
        int ret;
        wait(&ret);
        printf("Program sie zakonczyl. Status z procesu child to = %d\n", WEXITSTATUS(ret));
    }

}
