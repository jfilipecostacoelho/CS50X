#include "helpers.h"
#include <math.h>
#include <cs50.h>
#include <string.h>

int neighbor_sum(int col, int row, int height, int width, RGBTRIPLE image[height][width], string color);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int color;
            
            // For each pixel get the average of its RGB value and redefine it with the new value
            color = round(((float)image[i][j].rgbtBlue + (float)image[i][j].rgbtGreen + (float)image[i][j].rgbtRed) / 3);

            image[i][j].rgbtBlue = color;
            image[i][j].rgbtGreen = color;
            image[i][j].rgbtRed = color;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red;
            int green;
            int blue;
        
            // Calculate the sepia values
            red = round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue);
            green = round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue);
            blue = round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue);

            // The new value is higher than 255? If true, redefine it to 255
            if (blue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = blue;
            }

            if (green > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = green;
            }

            if (red > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = red;
            }

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            // Save the pixel of the left half in a temporary variable
            RGBTRIPLE auximage = image[i][j];
            // Redefine the pixel of the left half with the opposite 'coordinate' of the right half
            image[i][j] = image[i][width - (j + 1)];
            // Redefine the pixel of the right half with the value of the temporary variable
            image[i][width - (j + 1)] = auximage;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of the image that will be used to calculate the blur
    RGBTRIPLE auximage[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            auximage[i][j] = image[i][j];
        }
    }

    // For each pixel RGB value call the function neightbor_sum that will calculate the new RGB blurry value
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = neighbor_sum(i, j, height, width, auximage, "red");
            image[i][j].rgbtBlue = neighbor_sum(i, j, height, width, auximage, "blue");
            image[i][j].rgbtGreen = neighbor_sum(i, j, height, width, auximage, "green");
        }
    }
    return;
}

int neighbor_sum(int col, int row, int height, int width, RGBTRIPLE image[height][width], string color)
{
    // Variable that will hold the new blurry value
    int value = 0;
    
    // Auxiliary variable that will count the number of pixels that were used to calculate the blurry value
    float pixel = 0;

    for (int i = (col - 1); i < (col + 2); i++)
    {
        for (int j = (row - 1); j < (row + 2); j++)
        {
            // Is it out of bounds? If true there is no value to calculate here
            if (i < 0 || j < 0 || i >= height || j >= width)
            {
                continue;
            }
            else if (strcmp(color, "red") == 0)
            {
                value = value + image[i][j].rgbtRed;
            }
            else if (strcmp(color, "blue") == 0)
            {
                value = value + image[i][j].rgbtBlue;
            }
            else
            {
                value = value + image[i][j].rgbtGreen;
            }
            pixel++;
        }

    }

    return round(value / pixel);
}
