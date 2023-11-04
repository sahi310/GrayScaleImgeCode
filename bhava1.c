/* Programming Assignment - 1
Name : Sahithi Priya Bhavanam
euid : sb1923 *
compiler used : Tiny C*/

#define FILENAME_LEN 20
//#define G_MASK_SIZE 100
#define IMAGE_SIZE 400
#define mask_size 1

#include "PPMTools.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void main()
{
  unsigned char *image;
  // declaring variables for gray scale, desaturate, decompose
  unsigned char *image1, *sahithi_gray,*sahithi_desc, *sahithi_deco;
  int cols, rows, i, j;
  int red,blue,green;
  char filename[FILENAME_LEN];
  // declaring minimum , maximum temparory variables
  int sahithi_mintemp,sahihti_mintemp;
  
  printf("Enter image file name:");
  scanf("%s", filename);

  image = ReadPPM(filename,&cols, &rows);
  sahithi_gray = CreatePPM(cols, rows);
  sahithi_desc = CreatePPM(cols, rows);
  sahithi_deco = CreatePPM(cols, rows);
 
  for (i = 0; i < rows; i++) {
      for (j = 0; j < cols; j++) {
          PutRPixel(sahithi_gray, cols, j, i, 255);
          PutGPixel(sahithi_gray, cols, j, i, 255);
          PutBPixel(sahithi_gray, cols, j, i, 255);
		  
		  PutRPixel(sahithi_desc, cols, j, i, 255);
          PutGPixel(sahithi_desc, cols, j, i, 255);
          PutBPixel(sahithi_desc, cols, j, i, 255);
		  
		  PutRPixel(sahithi_deco, cols, j, i, 255);
          PutGPixel(sahithi_deco, cols, j, i, 255);
          PutBPixel(sahithi_deco, cols, j, i, 255);
      }
  }
 
  for (i=0;i<rows;i++) {
      for(j=0;j<cols;j++) {
          red=(int)GetRPixel(image,cols,j,i);
          green=(int)GetGPixel(image, cols,j,i);
		  blue=(int)GetBPixel(image, cols,j,i);
		  
		  //if (red < 205) {red =  (red +50 );}
		  //if (green < 205) {green = (green +50 );}
		  //if (blue < 205) {blue = (blue +50 ); }
		  
		  // declaring grayvalue function
	      unsigned char sahithi_grayValue = (unsigned char)(0.3*red + 0.59 * green + 0.11 * blue);
		  
          PutRPixel(sahithi_gray, cols, j, i, sahithi_grayValue);
          PutGPixel(sahithi_gray, cols, j, i, sahithi_grayValue);
          PutBPixel(sahithi_gray, cols, j, i, sahithi_grayValue);
		  
		  // Logic to find out maximum function which can be used to find Desaturated and decompose value
		  int sahithi_maxtemp = red;
		  if (sahithi_maxtemp < green)
			  sahithi_maxtemp = green;
		  if (sahithi_maxtemp < blue)
			  sahithi_maxtemp=blue;
		  
		  // Logic to find out minimum function which can be used to find desaturated value
		  if(red < green && red < blue)
			  sahithi_mintemp = red;
		  else if(green<red && green < blue)
			  sahihti_mintemp = green;
		  else
			  sahithi_mintemp = blue;
	
	      unsigned char sahithi_desaturatedValue = (unsigned char)(0.5 * (sahithi_maxtemp + sahithi_mintemp));	

	      PutRPixel(sahithi_desc, cols, j, i, sahithi_desaturatedValue);
          PutGPixel(sahithi_desc, cols, j, i, sahithi_desaturatedValue);
          PutBPixel(sahithi_desc, cols, j, i, sahithi_desaturatedValue);
		  
		  unsigned char sahithi_decomposeValue = (unsigned char)(sahithi_maxtemp);	

	      PutRPixel(sahithi_deco, cols, j, i, sahithi_decomposeValue);
          PutGPixel(sahithi_deco, cols, j, i, sahithi_decomposeValue);
          PutBPixel(sahithi_deco, cols, j, i, sahithi_decomposeValue);
	
      }
  }
  
  // WritePPM("out.ppm", image, rows, cols);
  // output for gray scale image
  WritePPM("gray.ppm", sahithi_gray, rows, cols);
  // output for desaturate image
  WritePPM("desa.ppm", sahithi_desc, rows, cols);
  // output for decompose image
  WritePPM("deco.ppm", sahithi_deco, rows, cols);

}
