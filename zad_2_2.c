#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int fd = open(argv[1], O_RDONLY);
    int value;
    for (int i = 0; i < 10; i++)
    {
        read(fd, &value, sizeof(8));
        printf("%d * 3 = %d\n", value, value * 3);
    }

    return 0;
}
