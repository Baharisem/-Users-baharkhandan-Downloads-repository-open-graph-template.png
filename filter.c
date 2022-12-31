#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale (int height, int width, RGBTRIPLE image [height][width])
{
    // Comb through each row
    for (int i = 0; i < height; i++)
    {
        // Comb through each column
        for (int j = 0; j < width; j++)
    }
    //convert pixels to float
    float Red = image [i][j].rgbtRed;
    float Green = image[i][j].rgbtGreen;
    float Blue = image[i][j].rgbtblue;

    // find the average value
    int average = round ((Red + Green + Blue) / 3)
    image[i][j].rgbtRed = image [i][j].rgbtGreen = image[i][j].rgbtBlue = average;
       }
     }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image [height][width])
{
   //comb through each row
   for(int i = 0; i < height; i++)
   {
       //comb through each column
       for(int j = 0; j < width; j++)
       {
           //convert pixels to float
           float originalRed = image[i][j].rgbtRed;
           float originalGreen = image[i][j].rgbtGreen;
           float originalBlue = image[i][j].rgbtBlue;

           //find the updated pixel value
           int sepiaRed = round (0.393 * originalRed + 0.769 * original Green + 0.189 * original Blue);
           int sepiaGreen = round (0.349 * originalRed + 0.686 * original Green + 0.168 * original Blue);
           int sepiaBlue = round (0.272 * originalRed + 0.534 * original Green + 0.131 * original Blue);

           //update the pixel value if sepiaRed, sepiaGreen or sepiaBlue exceeds 255
           if (sepiaRed > 255)
           {
               sepiaRed = 255;
           }
           if(sepiaGreen > 255)
           {
               sepiaGreen = 255;
           }
           if (sepiaBlue > 255)
           {
               sepiaBlue =255;
           }

           //update final pixel values
           image[i][j].rgbtRed = sepiaRed;
           image[i][j].rgbtGreen = sepiaGreen;
           image[i][j].rgbtBlue = sepiaBlue;
       }
   }
  return;
}

//reflect image horizontally
void reflect (int height, int width, RGBTRIPLE image [height][width] )
{
    //comb through each row
    for (int i = 0; i < height; i++)
    {
        //comb through each column
        for ( int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp = image [i][j];
            image [i][j] = image [i][width - (j + 1)];
            image [i][width - (j + 1)] = temp;
        }
    }
    return;
}

\\blur image
void blur(int height, int width, RGBTRIPLE image [height][width])
{
    //creat a copy of the image
    RGBTRIPLE temp [height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++ )
        {
            temp[i][j]= image[i][j];
        }
    }

    for(int i = 0; i < height; i++)
    {
        for (int j = 0 < width; j++)
        {
            int totalRed, totalBlue, totalGreen;
            totalRed = totalBlue = totalGreen = 0;
            float counter = 0.00;

            //get neighbouring pixels
            for (int x = -1; x < 2; x++)
            {
                for( int y = -1; y < 2; y++)
                {
                    int currentX = i + x;
                    int currentY = j + y;

                    //check if neighbouring pixel is valid
                    if (currentY < 0 || currentX > (height - 1) || currentY < 0 || currentY > (width - 1))
                    {
                        continue;
                    }

                    //get image value
                    totalRed += image [currentX][currentY].rgbtRed;
                    totalGreen += image [currentX][currentY].rgbtGreen;
                    totalBlue += image [currentX][currentY].rgbtBlue;

                    counter++;
                }

                //calculate average of neighbouring pixels
                temp[i][j].rgbtRed = round (totalRed / counter);
                temp[i][j].rgbtGreen = round (totalGreen / counter);
                temp[i][j].rgbtBlue = round (totalBlue / counter);
            }
        }
    }

    //copy new pixels into original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
             image[i][j].rgbtRed = temp [i][j].rgbtRed;
            image[i][j].rgbtGreen = temp [i][j].rgbtGreen;
             image[i][j].rgbtBlue = temp [i][j].rgbtBlue;
        }
    }
     return;
}