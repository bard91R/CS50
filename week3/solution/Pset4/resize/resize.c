#include <stdio.h>
#include <stdlib.h>

#include <math.h>
#include "bmp.h"
//#include "matrix.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: copy factor[0-100] infile outfile\n");
        return 1;
    }

    float factor;
    sscanf(argv[1], "%f", &factor); //put first value into float variable

    char *infile = argv[2];
    char *outfile = argv[3];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    /////////////

    //Multiple the number of pixels by the factor

    BITMAPFILEHEADER newFilebf = bf;
    BITMAPINFOHEADER newFilebi = bi;

    newFilebi.biWidth = factor*bi.biWidth;
    newFilebi.biHeight = factor*bi.biHeight;

    float convFactor = 1/factor;            //factor used to multiply the position number of resized to determine from which pixel the data should be pulled

    //int originalColumns[bi.biWidth];
    //int originalRows[bi.biHeight];
    RGBTRIPLE originalMatrix[abs(bi.biWidth)][abs(bi.biHeight)];    //for some reason returns a negative value



//    struct matrix* newImage = malloc(sizeof(struct dyn_array) + newFilebi.biWidth *sizeof(int), sizeof(struct dyn_array) + newFilebi.biHeight *sizeof(int));

    /////////////



    // write outfile's BITMAPFILEHEADER
    fwrite(&newFilebf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&newFilebi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // determine padding for scanlines
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;



    ///////////////////////////////////////////////////////
        //the idea in here is to iterate over the matrix of the resized image and multiple them by the appropriate factor to determine from which pixel to pull the data


        for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        // iterate over pixels in scanline
        for (int j = 0; j < bi.biWidth; j++)
        {
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            originalMatrix[j][i] = triple;   //we obtain the original matrix

            // write RGB triple to outfile
            //fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
        }

        // skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);

        // then add it back (to demonstrate how)
        for (int k = 0; k < padding; k++)
        {
            fputc(0x00, outptr);
        }
    }



    padding = (4 - (newFilebi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

        for (int i = 0, biHeight = abs(newFilebi.biHeight); i < biHeight; i++)
    {
        // iterate over pixels in scanline
        for (int j = 0; j < newFilebi.biWidth; j++)
        {

            int posX = floor(convFactor*j);
            int posY = floor(convFactor*i);

            RGBTRIPLE triple = originalMatrix[posX][posY];

            fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);

        }

        // skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);

        // then add it back (to demonstrate how)
        for (int k = 0; k < padding; k++)
        {
            fputc(0x00, outptr);
        }

    }



    //////////////////////////////////////////////////////////




/*
    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        // iterate over pixels in scanline
        for (int j = 0; j < bi.biWidth; j++)
        {
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            // write RGB triple to outfile
            fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
        }

        // skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);

        // then add it back (to demonstrate how)
        for (int k = 0; k < padding; k++)
        {
            fputc(0x00, outptr);
        }
    }
*/


    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);


    //free(newImage);
    // success
    return 0;




}