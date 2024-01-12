using namespace std;

#include <iostream>

struct Pixel
{
    // ? Member Variables
    int red, blue, green;
};

class Image
{
    // ? Member Variables
    int Row, Col, Depth;
    Pixel ***image;

public:
    // ? Default Constructor
    Image(int d = 1, int r = 1, int c = 1)
    {
        this->Row = r;
        this->Col = c;
        this->Depth = d;

        image = new Pixel **[Depth];
        for (int i = 0; i < Depth; i++)
        {
            image[i] = new Pixel *[Row];
            for (int j = 0; j < Row; j++)
            {
                image[i][j] = new Pixel[Col];
            }
        }
    }

    // ? Copy Constructor
    Image(const Image &img)
    {
        this->Col = img.Col;
        this->Row = img.Row;
        this->Depth = img.Depth;

        // ? Deep Copy
        image = new Pixel **[Depth];
        for (int i = 0; i < Depth; i++)
        {
            image[i] = new Pixel *[Row];
            for (int j = 0; j < Row; j++)
            {
                image[i][j] = new Pixel[Col];
            }
        }
    }

    // Getters and Setters for Member Variables
    int getRow()
    {
        return this->Row;
    }

    void setRow(int x)
    {
        this->Row = x;
    }

    int getCol()
    {
        return this->Col;
    }

    void setCol(int x)
    {
        this->Col = x;
    }

    int getDepth()
    {
        return this->Depth;
    }

    void setDepth(int x)
    {
        this->Depth = x;
    }

    // Returning the specified Object of Struct Image
    Pixel getPixel(int x, int y, int z)
    {
        return image[x][y][z];
    }

    // Setting thespecified Object of Struct Image
    void setPixel(int x, int y, int z, Pixel p)
    {
        image[x][y][z] = p;
    }

    // Filling the whole 3D Array of objects with the same object
    void fill(Pixel p)
    {
        for (int i = 0; i < Depth; i++)
        {
            for (int j = 0; j < Row; j++)
            {
                for (int k = 0; k < Col; k++)
                {
                    image[i][j][k] = p;
                }
            }
        }
    }

    // Assingning the whole 3D Array of objects member variables 0
    void clear()
    {
        for (int i = 0; i < Depth; i++)
        {
            for (int j = 0; j < Row; j++)
            {
                for (int k = 0; k < Col; k++)
                {
                    image[i][j][k].blue = 0;
                    image[i][j][k].red = 0;
                    image[i][j][k].green = 0;
                }
            }
        }
    }

    /*
    Finding the Brightness by adding the Rgb Values and diiving them by 3
    after I find the brightness of each of the pixel I added them and then divided the
    total brightness with the total number of Pixels
    */
    double getAverageBrightness()
    {
        double Brightness = 0;
        for (int i = 0; i < Depth; i++)
        {
            for (int j = 0; j < Row; j++)
            {
                for (int k = 0; k < Col; k++)
                {
                    Brightness += (image[i][j][k].blue + image[i][j][k].red + image[i][j][k].green) / 3;
                }
            }
        }
        int tD = Depth, tR = Row, tC = Col;
        if (tD < 1)
            tD = 1;

        if (tR < 1)
            tR = 1;

        if (tC < 1)
            tC = 1;

        Brightness = Brightness / (tD * tR * tC);

        return Brightness;
    }

     /*
    Finding the Brightness by adding the Rgb Values and diiving them by 3
    after I find the brightness of each of the pixel I lopped through each of them
    to find the Maximum value 
    */
    int getMaximumBrightness(int depth)
    {
        int Brightness = (image[depth][0][0].blue + image[depth][0][0].red + image[depth][0][0].green) / 3;

        for (int j = 0; j < Row; j++)
        {
            for (int k = 1; k < Col; k++)
            {
                int temp = (image[depth][j][k].blue + image[depth][j][k].red + image[depth][j][k].green) / 3;
                if (temp > Brightness)
                {
                    Brightness = temp;
                }
            }
        }

        return Brightness;
    }
    /*
    I Lopped through the whole 3 D array of Objects and checked each object if any of them
    Member Variables i.e Red,Blue,Green have value 255. If yes then I added 1 in my count to
    count them.
    */
    int countBrightPixel()
    {
        int count = 0;
        for (int i = 0; i < Depth; i++)
        {
            for (int j = 0; j < Row; j++)
            {
                for (int k = 0; k < Col; k++)
                {
                    if (image[i][j][k].blue == 255 || image[i][j][k].red == 255 || image[i][j][k].green == 255)
                    {
                        count++;
                    }
                }
            }
        }

        return count;
    }

    /*
    At a specific 2D Array out of all the 2D Arrays I interchanged the rows and columns 
    such that to take a transpose. 
    */
    void transposePixel(int depth)
    {
        for (int j = 0; j < Row; j++)
        {
            for (int k = 0 + 1; k < Col; k++)
            {
                Pixel temp = image[depth][j][k];
                image[depth][j][k] = image[depth][k][j];
                image[depth][k][j] = temp;
            }
        }

        int temp2 = this->Row;
        this->Row = this->Col;
        this->Col = temp2;
    }

    // ! Destructor
    ~Image()
    {
        for (int i = 0; i < Depth; i++)
        {
            for (int j = 0; j < Row; j++)
            {

                delete[] image[i][j];
            }
            delete[] image[i];
        }
        delete[] image;
    }
};

int main()
{
    cout << "\n\n\nHELLO WORLD \n\n\n";
    return 0;
}