#include <stdio.h>

/*outputs an RGB image as PPM.
  Top is an optional image displayed at the top of the image.*/

void WritePPM(char *filename, unsigned char *image, int rows, int cols)
{

    FILE *fp;
  
  if ((fp = fopen(filename, "wb")) == NULL) 
    { 
      printf("Can't write to %s!\n", filename); 
      exit(1);
    }

  else
    {
      fprintf(fp, "P6\n%d %d\n255\n",cols, rows);
      fwrite(image, sizeof(unsigned char), 3*rows*cols, fp);
      fclose(fp);
    }
}

