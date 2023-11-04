#include <stdio.h>

unsigned char *ReadPPM(char *filename, int *cols, int *rows)
{
  int  dummy, size;
  char buff[5000];
  FILE *fp;
  unsigned char *image;
  
  if ((fp = fopen(filename, "rb")) == NULL) 
    {
      printf("Can't read from %s!\n",filename); 
      image = NULL; 
    }
  else
    {
      fread(buff, 2, 1, fp);                             /* check color header*/
      if (buff[0]!='P' || buff[1]!='6') 
    { 
      printf("Color-level file must begin with 'P6'!\n"); 
      fclose(fp); 
      image = NULL; 
    }
      else 
        { 
          fseek(fp, 0, 0);
          fgets(buff, sizeof(buff)-1, fp); 
          do fgets(buff, sizeof(buff)-1, fp); 
          while (buff[0]=='#');
          sscanf(buff, "%d %d", cols, rows);                      /* get size */
          if (cols<=0 || rows<=0)                               /* check size */
        {  
          printf("Negative image size!\n");
          fclose(fp);
          image = NULL; 
        }
          else 
            { 
              fgets(buff, sizeof(buff)-1, fp); 
              sscanf(buff, "%d", &dummy);                         /* get size */
              size = (*cols)*(*rows);
              image = (unsigned char *) calloc(size*3+1, sizeof(unsigned char));
              fread(image, sizeof(unsigned char), size*3, fp);   /* Read file */
            }
        }
    }
  return(image);
}

