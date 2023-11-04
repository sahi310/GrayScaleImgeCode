unsigned char GetRPixel(unsigned char *image, int cols, int x, int y)
{
  return(image[y*cols*3+x*3]);
}
