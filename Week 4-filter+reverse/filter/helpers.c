#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // iterate through height dimension
    for (int h = 0; h <= height; h++)
    {
        // iterate through width dimension
        for (int w = 0; w <= width; w++)
        {
            // save original pixel data
            int r = image[h][w].rgbtRed;
            int g = image[h][w].rgbtGreen;
            int b = image[h][w].rgbtBlue;
            // replace pixel data into the image
            image[h][w].rgbtRed = round((r + g + b) / 3.0);
            image[h][w].rgbtGreen = round((r + g + b) / 3.0);
            image[h][w].rgbtBlue = round((r + g + b) / 3.0);
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{

    int sepiar, sepiag, sepiab = 0;
    // iterate through height dimension
    for (int h = 0; h < height; h++)
    {
        // iterate through width dimension
        for (int w = 0; w < width; w++)
        {
            // save original pixel data
            float originalr = image[h][w].rgbtRed;
            float originalg = image[h][w].rgbtGreen;
            float originalb = image[h][w].rgbtBlue;

            // convert to sepia and cap to 255 if conversion result is higher
            sepiar = round(0.393 * originalr + 0.769 * originalg + 0.189 * originalb);
            if (sepiar > 255)
            {
                sepiar = 255;
            }

            sepiag = round(0.349 * originalr + 0.686 * originalg + 0.168 * originalb);
            if (sepiag > 255)
            {
                sepiag = 255;
            }

            sepiab = round(0.272 * originalr + 0.534 * originalg + 0.131 * originalb);
            if (sepiab > 255)
            {
                sepiab = 255;
            }

            // replace pixel data into the image
            image[h][w].rgbtRed = sepiar;
            image[h][w].rgbtGreen = sepiag;
            image[h][w].rgbtBlue = sepiab;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // temporary variable to store each pixel color
    int tempred, tempgreen, tempblue = 0;

    // iterate through height dimension
    for (int h = 0; h <= height; h++)
    {
        // iterate through width dimension until half the array
        for (int w = 0; w <= (width - 1) / 2; w++)
        {
            // save the pixel info in a temp and swap pixels
            // pixel[h][w] goes to the opposite pixel[h][width - w]
            tempred = image[h][w].rgbtRed;
            tempgreen = image[h][w].rgbtGreen;
            tempblue = image[h][w].rgbtBlue;

            image[h][w].rgbtRed = image[h][width - 1 - w].rgbtRed;
            image[h][w].rgbtGreen = image[h][width - 1 - w].rgbtGreen;
            image[h][w].rgbtBlue = image[h][width - 1 - w].rgbtBlue;

            image[h][width - 1 - w].rgbtRed = tempred;
            image[h][width - 1 - w].rgbtGreen = tempgreen;
            image[h][width - 1 - w].rgbtBlue = tempblue;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // temporary array to store original pixel color for each row/column
    RGBTRIPLE temp[height][width];
    float averagered, averagegreen, averageblue = 0;

    // make a copy of the original bitmap
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            // save the pixel info in a temp
            temp[h][w].rgbtRed = image[h][w].rgbtRed;
            temp[h][w].rgbtGreen = image[h][w].rgbtGreen;
            temp[h][w].rgbtBlue = image[h][w].rgbtBlue;
        }
    }
    // apply the blur formula. Average of each row -1, 0 and + 1; and column -1, 0, +1
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            // for the first row, first column (top left corner)
            if (h == 0 && w == 0)
            {
                averagered =
                    (temp[h][w].rgbtRed + temp[h][w + 1].rgbtRed + temp[h + 1][w].rgbtRed + temp[h + 1][w + 1].rgbtRed) / 4.0;
                averagegreen =
                    (temp[h][w].rgbtGreen + temp[h][w + 1].rgbtGreen + temp[h + 1][w].rgbtGreen + temp[h + 1][w + 1].rgbtGreen) /
                    4.0;
                averageblue =
                    (temp[h][w].rgbtBlue + temp[h][w + 1].rgbtBlue + temp[h + 1][w].rgbtBlue + temp[h + 1][w + 1].rgbtBlue) / 4.0;
                image[h][w].rgbtRed = round(averagered);
                image[h][w].rgbtGreen = round(averagegreen);
                image[h][w].rgbtBlue = round(averageblue);
            }
            // for the first row, second column and on (top row)
            else if (h == 0 && w > 0 && w < (width - 1))
            {
                averagered = (temp[h][w - 1].rgbtRed + temp[h][w].rgbtRed + temp[h][w + 1].rgbtRed + temp[h + 1][w - 1].rgbtRed +
                              temp[h + 1][w].rgbtRed + temp[h + 1][w + 1].rgbtRed) /
                             6.0;
                averagegreen = (temp[h][w - 1].rgbtGreen + temp[h][w].rgbtGreen + temp[h][w + 1].rgbtGreen +
                                temp[h + 1][w - 1].rgbtGreen + temp[h + 1][w].rgbtGreen + temp[h + 1][w + 1].rgbtGreen) /
                               6.0;
                averageblue = (temp[h][w - 1].rgbtBlue + temp[h][w].rgbtBlue + temp[h][w + 1].rgbtBlue +
                               temp[h + 1][w - 1].rgbtBlue + temp[h + 1][w].rgbtBlue + temp[h + 1][w + 1].rgbtBlue) /
                              6.0;
                image[h][w].rgbtRed = round(averagered);
                image[h][w].rgbtGreen = round(averagegreen);
                image[h][w].rgbtBlue = round(averageblue);
            }
            // for the first row, last column (top right corner)
            else if (h == 0 && w == (width - 1))
            {
                averagered =
                    (temp[h][w].rgbtRed + temp[h][w - 1].rgbtRed + temp[h + 1][w].rgbtRed + temp[h + 1][w - 1].rgbtRed) / 4.0;
                averagegreen =
                    (temp[h][w].rgbtGreen + temp[h][w - 1].rgbtGreen + temp[h + 1][w].rgbtGreen + temp[h + 1][w - 1].rgbtGreen) /
                    4.0;
                averageblue =
                    (temp[h][w].rgbtBlue + temp[h][w - 1].rgbtBlue + temp[h + 1][w].rgbtBlue + temp[h + 1][w - 1].rgbtBlue) / 4.0;
                image[h][w].rgbtRed = round(averagered);
                image[h][w].rgbtGreen = round(averagegreen);
                image[h][w].rgbtBlue = round(averageblue);
            }
            // for the second row and on, first column (leftmost column)
            else if (h > 0 && h < (height - 1) && w == 0)
            {
                averagered = (temp[h - 1][w].rgbtRed + temp[h - 1][w + 1].rgbtRed + temp[h][w].rgbtRed + temp[h][w + 1].rgbtRed +
                              temp[h + 1][w].rgbtRed + temp[h + 1][w + 1].rgbtRed) /
                             6.0;
                averagegreen = (temp[h - 1][w].rgbtGreen + temp[h - 1][w + 1].rgbtGreen + temp[h][w].rgbtGreen +
                                temp[h][w + 1].rgbtGreen + temp[h + 1][w].rgbtGreen + temp[h + 1][w + 1].rgbtGreen) /
                               6.0;
                averageblue = (temp[h - 1][w].rgbtBlue + temp[h - 1][w + 1].rgbtBlue + temp[h][w].rgbtBlue +
                               temp[h][w + 1].rgbtBlue + temp[h + 1][w].rgbtBlue + temp[h + 1][w + 1].rgbtBlue) /
                              6.0;
                image[h][w].rgbtRed = round(averagered);
                image[h][w].rgbtGreen = round(averagegreen);
                image[h][w].rgbtBlue = round(averageblue);
            }
            // for the second row and on, last column (rightmost column)
            else if (h > 0 && h < (height - 1) && w == (width - 1))
            {
                averagered = (temp[h - 1][w - 1].rgbtRed + temp[h - 1][w].rgbtRed + temp[h][w - 1].rgbtRed + temp[h][w].rgbtRed +
                              temp[h + 1][w - 1].rgbtRed + temp[h + 1][w].rgbtRed) /
                             6.0;
                averagegreen = (temp[h - 1][w - 1].rgbtGreen + temp[h - 1][w].rgbtGreen + temp[h][w - 1].rgbtGreen +
                                temp[h][w].rgbtGreen + temp[h + 1][w - 1].rgbtGreen + temp[h + 1][w].rgbtGreen) /
                               6.0;
                averageblue = (temp[h - 1][w - 1].rgbtBlue + temp[h - 1][w].rgbtBlue + temp[h][w - 1].rgbtBlue +
                               temp[h][w].rgbtBlue + temp[h + 1][w - 1].rgbtBlue + temp[h + 1][w].rgbtBlue) /
                              6.0;
                image[h][w].rgbtRed = round(averagered);
                image[h][w].rgbtGreen = round(averagegreen);
                image[h][w].rgbtBlue = round(averageblue);
            }
            // for the last row, first column (bottom left corner)
            else if (h == (height - 1) && w == 0)
            {
                averagered =
                    (temp[h - 1][w].rgbtRed + temp[h - 1][w + 1].rgbtRed + temp[h][w].rgbtRed + temp[h][w + 1].rgbtRed) / 4.0;
                averagegreen =
                    (temp[h - 1][w].rgbtGreen + temp[h - 1][w + 1].rgbtGreen + temp[h][w].rgbtGreen + temp[h][w + 1].rgbtGreen) /
                    4.0;
                averageblue =
                    (temp[h - 1][w].rgbtBlue + temp[h - 1][w + 1].rgbtBlue + temp[h][w].rgbtBlue + temp[h][w + 1].rgbtBlue) / 4.0;
                image[h][w].rgbtRed = round(averagered);
                image[h][w].rgbtGreen = round(averagegreen);
                image[h][w].rgbtBlue = round(averageblue);
            }
            // for the last row, second column and on (bottom row)
            else if (h == (height - 1) && w > 0 && w < (width - 1))
            {
                averagered = (temp[h - 1][w - 1].rgbtRed + temp[h - 1][w].rgbtRed + temp[h - 1][w + 1].rgbtRed +
                              temp[h][w - 1].rgbtRed + temp[h][w].rgbtRed + temp[h][w + 1].rgbtRed) /
                             6.0;
                averagegreen = (temp[h - 1][w - 1].rgbtGreen + temp[h - 1][w].rgbtGreen + temp[h - 1][w + 1].rgbtGreen +
                                temp[h][w - 1].rgbtGreen + temp[h][w].rgbtGreen + temp[h][w + 1].rgbtGreen) /
                               6.0;
                averageblue = (temp[h - 1][w - 1].rgbtBlue + temp[h - 1][w].rgbtBlue + temp[h - 1][w + 1].rgbtBlue +
                               temp[h][w - 1].rgbtBlue + temp[h][w].rgbtBlue + temp[h][w + 1].rgbtBlue) /
                              6.0;
                image[h][w].rgbtRed = round(averagered);
                image[h][w].rgbtGreen = round(averagegreen);
                image[h][w].rgbtBlue = round(averageblue);
            }
            // for the last row, last column (bottom right corner)
            else if (h == (height - 1) && w == (width - 1))
            {
                averagered =
                    (temp[h][w].rgbtRed + temp[h][w - 1].rgbtRed + temp[h - 1][w].rgbtRed + temp[h - 1][w - 1].rgbtRed) / 4.0;
                averagegreen =
                    (temp[h][w].rgbtGreen + temp[h][w - 1].rgbtGreen + temp[h - 1][w].rgbtGreen + temp[h - 1][w - 1].rgbtGreen) /
                    4.0;
                averageblue =
                    (temp[h][w].rgbtBlue + temp[h][w - 1].rgbtBlue + temp[h - 1][w].rgbtBlue + temp[h - 1][w - 1].rgbtBlue) / 4.0;
                image[h][w].rgbtRed = round(averagered);
                image[h][w].rgbtGreen = round(averagegreen);
                image[h][w].rgbtBlue = round(averageblue);
            }
            // for the rest of the grid, with no borders (filler pixels)
            else if (h > 0 && h < (height - 1) && w > 0 && w < (width - 1))
            {
                averagered = (temp[h - 1][w - 1].rgbtRed + temp[h - 1][w].rgbtRed + temp[h - 1][w + 1].rgbtRed +
                              temp[h][w - 1].rgbtRed + temp[h][w].rgbtRed + temp[h][w + 1].rgbtRed + temp[h + 1][w - 1].rgbtRed +
                              temp[h + 1][w].rgbtRed + temp[h + 1][w + 1].rgbtRed) /
                             9.0;
                averagegreen = (temp[h - 1][w - 1].rgbtGreen + temp[h - 1][w].rgbtGreen + temp[h - 1][w + 1].rgbtGreen +
                                temp[h][w - 1].rgbtGreen + temp[h][w].rgbtGreen + temp[h][w + 1].rgbtGreen +
                                temp[h + 1][w - 1].rgbtGreen + temp[h + 1][w].rgbtGreen + temp[h + 1][w + 1].rgbtGreen) /
                               9.0;
                averageblue = (temp[h - 1][w - 1].rgbtBlue + temp[h - 1][w].rgbtBlue + temp[h - 1][w + 1].rgbtBlue +
                               temp[h][w - 1].rgbtBlue + temp[h][w].rgbtBlue + temp[h][w + 1].rgbtBlue +
                               temp[h + 1][w - 1].rgbtBlue + temp[h + 1][w].rgbtBlue + temp[h + 1][w + 1].rgbtBlue) /
                              9.0;
                image[h][w].rgbtRed = round(averagered);
                image[h][w].rgbtGreen = round(averagegreen);
                image[h][w].rgbtBlue = round(averageblue);
            }
        }
    }
    return;
}
