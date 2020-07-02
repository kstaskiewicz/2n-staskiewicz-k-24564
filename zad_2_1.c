#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{

    int rand_nums[10];
    int fd = open(argv[1], O_CREAT | O_WRONLY);
    time_t t;

    srand((unsigned)time(&t));

    for (int i = 0; i < 10; i++)
    {
        rand_nums[i] = rand() % 100;
        printf("%d, ", rand_nums[i]);
    }

    write(fd, rand_nums, sizeof(rand_nums));
    return 0;
}