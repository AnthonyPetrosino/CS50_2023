#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Find average
            double total = image[i][j].rgbtRed +  image[i][j].rgbtGreen +  image[i][j].rgbtBlue;
            int c = round((total / 3.0));

            // Apply average to rgb

            image[i][j].rgbtRed = c;
            image[i][j].rgbtGreen = c;
            image[i][j].rgbtBlue = c;
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
            // Find sepia
            double sRed = round((.393 * (double)image[i][j].rgbtRed) + (.769 * (double)image[i][j].rgbtGreen) + (.189 * (double)image[i][j].rgbtBlue));
            double sGreen = round((.349 * (double)image[i][j].rgbtRed) + (.686 * (double)image[i][j].rgbtGreen) + (.168 * (double)image[i][j].rgbtBlue));
            double sBlue = round((.272 * (double)image[i][j].rgbtRed) + (.534 * (double)image[i][j].rgbtGreen) + (.131 * (double)image[i][j].rgbtBlue));

            if (sRed > 255)
            {
                sRed = 255;
            }
            if (sBlue > 255)
            {
                sBlue = 255;
            }
            if (sGreen > 255)
            {
                sGreen = 255;
            }

            if (sRed < 0)
            {
                sRed = 0;
            }
            if (sBlue < 0)
            {
                sBlue = 0;
            }
            if (sGreen < 0)
            {
                sGreen = 0;
            }
            // Apply sepia to rgb

            image[i][j].rgbtRed = sRed;
            image[i][j].rgbtGreen = sGreen;
            image[i][j].rgbtBlue = sBlue;
        }
    }
    return;
}

void clearArray(int *p, int size)
{
    for (int i = 0; i < size; i++)
    {
        p[i] = 0;
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE place = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = place;
        }

    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE place[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            place[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            double thisRed = 0;
            double thisGreen = 0;
            double thisBlue = 0;
            int c = 0;

            for (int a = -1; a < 2; a++)
            {
                for (int b = -1; b < 2; b++)
                {
                    int thisA = i + a;
                    int thisB = j + b;

                    if (thisA < 0 || thisA > (height - 1) || thisB < 0 || thisB > (width - 1))
                    {
                        continue;
                    }

                    thisRed += image[thisA][thisB].rgbtRed;
                    thisGreen += image[thisA][thisB].rgbtGreen;
                    thisBlue += image[thisA][thisB].rgbtBlue;

                    c++;
                }
            }

            place[i][j].rgbtRed = round(thisRed / c);
            place[i][j].rgbtGreen = round(thisGreen / c);
            place[i][j].rgbtBlue = round(thisBlue / c);
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = place[i][j].rgbtRed;
            image[i][j].rgbtGreen = place[i][j].rgbtGreen;
            image[i][j].rgbtBlue = place[i][j].rgbtBlue;
        }
    }
    return;
}
