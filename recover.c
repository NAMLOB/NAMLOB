#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define BLOCK 512

int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // Open the memory card
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Couldn't access memory. program exited");
        return 1;
    }

    // Create a buffer for a block of data
    uint8_t buffer[BLOCK];

    char image[9];
    int count = 0;
    FILE *img = NULL;
    // While there's still data left to read from the memory card
    while (fread(buffer, 1, BLOCK, card) == BLOCK)
    {
        // Check memory for JPEG header
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            // Create JPEGs from the data
            // If first JPEG
            if (count == 0)
            {
                sprintf(image, "%03i.jpg", count);
                img = fopen(image, "w");
                fwrite(buffer, 1, BLOCK, img);
                count++;
            }
            // If next JPEG
            else
            {
                fclose(img);
                sprintf(image, "%03i.jpg", count);
                img = fopen(image, "w");
                fwrite(buffer, 1, BLOCK, img);
                count++;
            }
        }
        // Continue writing if no new JPEG is identified
        else if (img != NULL)
        {
            fwrite(buffer, 1, BLOCK, img);
        }
    }
    fclose(card);
    fclose(img);
}
