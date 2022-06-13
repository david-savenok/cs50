#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    typedef uint8_t BYTE;
    const int BLOCKSIZE = 512;
    int jpgN = -1;
    if (argc != 2)
    {
        printf("Usage: ./recover infile.raw");
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Invalid file");
        return 1;
    }
    BYTE *buffer = malloc(BLOCKSIZE);
    if (buffer == NULL)
    {
        return 1;
    }

    while (fread(buffer, sizeof(BYTE), BLOCKSIZE, file) == BLOCKSIZE)
    {
        if (buffer[0] == 0xFF && buffer[1] == 0xd8 && buffer[2] == 0xFF && (buffer[3] & 0xF0) == 0xE0)
        {
            jpgN++;
        }
    }

}