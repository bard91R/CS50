#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: recover infile\n");
        return 1;
    }

    char *infile = argv[1];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    //int eof =0;
    char * block;

    block = malloc(64*sizeof(char));

    //block[0] = 1;


     /* ... */
    fread(block, 1, 64, inptr);

    printf(" es  %c", block);








    free(block);

    fclose(inptr);


}