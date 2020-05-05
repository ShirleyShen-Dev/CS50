#include "helpers.h"
#include "stdio.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // For each pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Get average of RGB colors
            float fsum = (float) image[i][j].rgbtBlue + (float) image[i][j].rgbtGreen + (float) image[i][j].rgbtRed;

            int iavg;

            if (round(fsum / 3) > 255)
            {
                iavg = 255;
            }
            else
            {
                iavg = round(fsum / 3);
            }

            image[i][j].rgbtBlue = iavg;
            image[i][j].rgbtGreen = iavg;
            image[i][j].rgbtRed = iavg;
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // For each pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Use sepia algorithm
            float fRed = 0.393 * (float) image[i][j].rgbtRed + 0.769 * (float) image[i][j].rgbtGreen + 0.189 * (float) image[i][j].rgbtBlue;
            float fGreen = 0.349 * (float) image[i][j].rgbtRed + 0.686 * (float) image[i][j].rgbtGreen + 0.168 * (float) image[i][j].rgbtBlue;
            float fBlue = 0.272 * (float) image[i][j].rgbtRed + 0.534 * (float) image[i][j].rgbtGreen + 0.131 * (float) image[i][j].rgbtBlue;

            // Check to make sure color value is between 0 and 255
            if (fRed > 255)
            {
                fRed = 255;
            }
            if (fGreen > 255)
            {
                fGreen = 255;
            }
            if (fBlue > 255)
            {
                fBlue = 255;
            }

            // Apply new color values
            image[i][j].rgbtBlue = round(fBlue);
            image[i][j].rgbtGreen = round(fGreen);
            image[i][j].rgbtRed = round(fRed);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0, h = height; i < h; i++)
    {
        for (int j = 0, w = width; j < w / 2; j++)
        {
            //Swap values
            RGBTRIPLE tmp = image[i][j];
            // Reflect pixel to that in opposite end. Adjust width for zero index
            image[i][j] = image[i][w - 1 - j];
            image[i][w - 1 - j] = tmp;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{


// Declare a copy of image called tmp
    RGBTRIPLE tmp[height][width];

    // Declare variables for average calculation


    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            // Set border of blur box

            int box_hmin = i - 1;
            int box_hmax = i + 1;
            int box_wmin = j - 1;
            int box_wmax = j + 1;
            
            // Addressing edge cases
            
            if (box_hmin < 0)
            {
                box_hmin = 0;
            }
            if (box_hmax > height - 1)
            {
                box_hmax = height - 1;
            }
            if (box_wmin < 0) 
            {
                box_wmin = 0;
            }
            if (box_wmax > width - 1)
            {
                box_wmax = width - 1;
            }

            float fsum_R = 0.0;
            float fsum_G = 0.0;
            float fsum_B = 0.0;
    
            float pixel_count = 0.0;
            
            // Iterate over blur box to capture sum of RGB values of each pixel in box
            for (int x = box_hmin ; x <= box_hmax; x++)
            {
                for (int y = box_wmin; y <= box_wmax; y++)
                {
                    fsum_R = fsum_R + image[x][y].rgbtRed;
                    fsum_G = fsum_G + image[x][y].rgbtGreen;
                    fsum_B = fsum_B + image[x][y].rgbtBlue;
                    pixel_count++;
                }
                
            }
            
            tmp[i][j].rgbtRed = round(fsum_R / pixel_count);
            tmp[i][j].rgbtGreen = round(fsum_G / pixel_count);
            tmp[i][j].rgbtBlue = round(fsum_B / pixel_count);           
            

        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = tmp[i][j].rgbtRed ;
            image[i][j].rgbtGreen = tmp[i][j].rgbtGreen ;
            image[i][j].rgbtBlue = tmp[i][j].rgbtBlue ;
        }
    }
    

    return;
}
