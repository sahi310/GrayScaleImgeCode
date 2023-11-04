void PutBPixel(unsigned char *image, int cols, int x, int y, unsigned char val)
{
  image[y*cols*3+x*3+2] = val;
}
