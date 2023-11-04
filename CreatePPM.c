#include <stdlib.h>
unsigned char *CreatePPM(int cols, int rows)
{
  unsigned char *image;

  image = (unsigned char *) calloc(cols*rows*3, sizeof(unsigned char));
  return(image);
}
