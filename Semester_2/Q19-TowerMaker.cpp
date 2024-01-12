// !  Tayyab_Kamran_Sami_22i_2505

#include <iostream>

using namespace std;

class Block
{
    // ? Data members of Class Block
protected:
    string Type;
    string color;

public:
    // * Constructors
    Block(string Type = "", string C = "")
    {
        this->color = C;
        this->Type = Type;
    }

    //? Getter
    string GetType()
    {
        return this->Type;
    }

    string GetColor()
    {
        return this->color;
    }

    // ! Display method of class Block
    ostream &display(ostream &out) const
    {
        if (this->color != "" && this->Type != "")
        {
            out << "(" << this->Type << ", " << this->color << ")"
                << "  ";
        }
        else if (this->color == "" && this->Type != "")
        {
            out << "(" << this->Type << ")"
                << "  ";
        }
        else
        {
            cout << " "
                 << " ";
        }

        return out;
    }
};

//* Operator overloading  for class Block
ostream &operator<<(ostream &print, Block &obj)
{
    obj.display(print);
    cout << endl;
    return print;
}

class Build; //? Forward Declaration

//? Prototype for  Operator overloading for class Build
ostream &operator<<(ostream &print, Build);

class Build
{
protected:
    Block ***Content;
    int Height, Width, Depth;

public:
    //* Parameteried Constructor
    Build(Block obj1 = Block())
    {
        this->Height = 1, this->Width = 1, this->Depth = 1;
        Content = new Block **[Height];

        for (int i = 0; i < Height; i++)
        {
            this->Content[i] = new Block *[Depth];

            for (int j = 0; j < Depth; j++)
            {
                this->Content[i][j] = new Block[Width];
            }
        }
        Content[0][0][0] = obj1;
    }

    // ! Copy Constructor
    Build(const Build &other)
    {
        Height = other.Height;
        Width = other.Width;
        Depth = other.Depth;

        Content = new Block **[Height];
        for (int i = 0; i < Height; i++)
        {
            Content[i] = new Block *[Depth];
            for (int j = 0; j < Depth; j++)
            {
                Content[i][j] = new Block[Width];
            }
        }

        for (int i = 0; i < Height; i++)
        {
            for (int j = 0; j < Depth; j++)
            {
                for (int k = 0; k < Width; k++)
                {
                    Content[i][j][k] = other.Content[i][j][k];
                }
            }
        }
    }

    //* Allocates the Content Array for an Object of Required Size
    void Allocator(int H, int D, int W, Build &obj)
    {
        Block Mobj("", "");

        obj.Content = new Block **[H];

        for (int i = 0; i < H; i++)
        {
            obj.Content[i] = new Block *[D];

            for (int k = 0; k < D; k++)
            {
                obj.Content[i][k] = new Block[W];
            }
        }

        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < D; j++)
            {
                for (int k = 0; k < W; k++)
                {
                    obj.Content[i][j][k] = Mobj;
                }
            }
        }
    }

    //? Copies a specific object into the calling object.
    void Equalizer(Build obj)
    {
        this->Depth = obj.Depth;
        this->Height = obj.Height;
        this->Width = obj.Width;

        this->Content = new Block **[Height];

        for (int i = 0; i < Height; i++)
        {
            this->Content[i] = new Block *[Depth];

            for (int k = 0; k < Depth; k++)
            {
                this->Content[i][k] = new Block[Width];
            }
        }
        for (int i = 0; i < Height; i++)
        {
            for (int j = 0; j < Depth; j++)
            {
                for (int k = 0; k < Width; k++)
                {
                    this->Content[i][j][k] = obj.Content[i][j][k];
                }
            }
        }
        return;
    }

    //* Overloading = Operator
    Build &operator=(Build obj)
    {
        this->Depth = obj.Depth;
        this->Height = obj.Height;
        this->Width = obj.Width;

        this->Content = new Block **[Height];

        for (int i = 0; i < Height; i++)
        {
            this->Content[i] = new Block *[Depth];

            for (int k = 0; k < Depth; k++)
            {
                this->Content[i][k] = new Block[Width];
            }
        }

        for (int i = 0; i < Height; i++)
        {
            for (int j = 0; j < Depth; j++)
            {
                for (int k = 0; k < Width; k++)
                {
                    this->Content[i][j][k] = obj.Content[i][j][k];
                }
            }
        }
        return *this;
    }

    // * Display method for Build to display the Tower
    ostream &display(ostream &out) const
    {
        for (int i = Height - 1; i > -1; i--)
        {
            cout << "Layer " << i << ":" << endl;
            for (int j = 0; j < Depth; j++)
            {
                for (int k = 0; k < Width; k++)
                {
                    Content[i][j][k].display(out);
                }
                cout << endl;
            }
            cout << endl;
        }
        return out;
    }

    //*  Operator to add a Block object and update the object
    Build &operator^=(Block &obj)
    {
        Build temp1;

        int H = this->Height + 1;
        int W = this->Width;
        int D = this->Depth;

        Allocator(H, D, W, temp1);

        for (int i = 0; i < this->Height; i++)
        {
            for (int j = 0; j < this->Depth; j++)
            {
                for (int k = 0; k < this->Width; k++)
                {
                    temp1.Content[i][j][k] = this->Content[i][j][k];
                }
            }
        }

        temp1.Content[H - 1][0][0] = obj;

        temp1.Depth = D, temp1.Height = H, temp1.Width = W;

        Equalizer(temp1);

        return *this;
    }

    //*  Operator to add the object and return the updated object
    Build operator^(Build &obj)
    {
        Build temp;

        int H = obj.Height + this->Height;

        int W = this->Width;

        if (this->Width < obj.Width)
        {
            W = obj.Width;
        }

        int D = this->Depth;

        if (this->Depth < obj.Depth)
        {
            D = obj.Depth;
        }

        temp.Depth = D, temp.Height = H, temp.Width = W;

        Allocator(H, D, W, temp);

        for (int i = 0; i < this->Height; i++)
        {
            for (int j = 0; j < this->Depth; j++)
            {
                for (int k = 0; k < this->Width; k++)
                {
                    temp.Content[i][j][k] = this->Content[i][j][k];
                }
            }
        }

        for (int i = 0; i < obj.Height; i++)
        {
            for (int j = 0; j < obj.Depth; j++)
            {
                for (int k = 0; k < obj.Width; k++)
                {
                    temp.Content[i + this->Height][j][k] = obj.Content[i][j][k];
                }
            }
        }

        return temp;
    }

    //*  Operator to add a Build object
    Build operator^=(Build &obj)
    {
        Build temp;

        int H = obj.Height + this->Height;

        int W = this->Width;

        if (this->Width < obj.Width)
        {
            W = obj.Width;
        }

        int D = this->Depth;

        if (this->Depth < obj.Depth)
        {
            D = obj.Depth;
        }

        temp.Depth = D, temp.Height = H, temp.Width = W;

        Allocator(H, D, W, temp);

        for (int i = 0; i < this->Height; i++)
        {
            for (int j = 0; j < this->Depth; j++)
            {
                for (int k = 0; k < this->Width; k++)
                {
                    temp.Content[i][j][k] = this->Content[i][j][k];
                }
            }
        }

        for (int i = 0; i < obj.Height; i++)
        {
            for (int j = 0; j < obj.Depth; j++)
            {
                for (int k = 0; k < obj.Width; k++)
                {
                    temp.Content[i + this->Height][j][k] = obj.Content[i][j][k];
                }
            }
        }

        Equalizer(temp);

        return *this;
    }

    //*  Operator adds block behind and update the calling object
    Build operator-=(Block &obj)
    {
        Build temp1;
        int H, W, D;

        H = this->Height;
        W = this->Width;
        D = this->Depth + 1;

        Allocator(H, D, W, temp1);

        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < this->Depth; j++)
            {
                for (int k = 0; k < W; k++)
                {
                    temp1.Content[i][j][k] = this->Content[i][j][k];
                }
            }
        }

        temp1.Content[0][D - 1][0] = obj;

        temp1.Depth = D, temp1.Height = H, temp1.Width = W;

        Equalizer(temp1);

        return temp1;
    }

    //*  Operator adds build behind and update the calling object
    Build operator-=(Build &obj)
    {
        Build temp;
        int H, W, D;

        W = this->Width;

        if (this->Width < obj.Width)
        {
            W = obj.Width;
        }

        if (this->Height > obj.Height)
        {
            return *this;
        }

        if (this->Height <= obj.Height)
        {
            H = this->Height;
            D = this->Depth + obj.Depth;

            temp.Depth = D, temp.Height = H, temp.Width = W;

            Allocator(H, D, W, temp);

            for (int i = 0; i < H; i++)
            {
                for (int j = 0; j < this->Depth; j++)
                {
                    for (int k = 0; k < this->Width; k++)
                    {
                        temp.Content[i][j][k] = this->Content[i][j][k];
                    }
                }
            }
            for (int i = 0; i < H; i++)
            {
                for (int j = 0; j < D; j++)
                {
                    for (int k = 0; k < W; k++)
                    {
                        if (j == D - 1)
                        {
                            temp.Content[i][j][k] = obj.Content[i][j - (D - 1)][k];
                        }
                    }
                }
            }

            Equalizer(temp);
        }

        return *this;
    }

    //* Operator adds Build behind and return the updated object
    Build operator-(Build &obj)
    {
        Build temp;
        int H, W, D;

        W = this->Width;

        if (this->Width < obj.Width)
        {
            W = obj.Width;
        }

        if (this->Height > obj.Height)
        {
            return *this;
        }

        if (this->Height <= obj.Height)
        {
            H = this->Height;
            D = this->Depth + obj.Depth;

            temp.Depth = D, temp.Height = H, temp.Width = W;

            Allocator(H, D, W, temp);

            for (int i = 0; i < H; i++)
            {
                for (int j = 0; j < this->Depth; j++)
                {
                    for (int k = 0; k < this->Width; k++)
                    {
                        temp.Content[i][j][k] = this->Content[i][j][k];
                    }
                }
            }
            for (int i = 0; i < H; i++)
            {
                for (int j = 0; j < D; j++)
                {
                    for (int k = 0; k < W; k++)
                    {
                        if (j == D - 1)
                        {
                            temp.Content[i][j][k] = obj.Content[i][j - (D - 1)][k];
                        }
                    }
                }
            }
        }

        return temp;
    }

    //*  Operator adds block right front and update the calling object 
    Build operator+=(Block &obj)
    {
        Build temp;
        int H, W, D;

        H = this->Height;
        W = this->Width + 1;
        D = this->Depth;

        Allocator(H, D, W, temp);

        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < this->Depth; j++)
            {
                for (int k = 0; k < this->Width; k++)
                {
                    temp.Content[i][j][k] = this->Content[i][j][k];
                }
            }
        }

        temp.Content[0][0][W - 1] = obj;

        temp.Depth = D, temp.Height = H, temp.Width = W;

        Equalizer(temp);

        return temp;
    }

    //*  Operator adds build  right front and update the calling object 
    Build operator+=(Build &obj)
    {
        Build temp;
        int H, W, D;

        if (this->Height > obj.Height || this->Depth > obj.Depth)
        {
            return *this;
        }

        if (this->Height <= obj.Height || this->Depth <= obj.Depth)
        {
            H = this->Height;
            W = this->Width + obj.Width;
            D = this->Depth;

            temp.Depth = D, temp.Height = H, temp.Width = W;

            Allocator(H, D, W, temp);

            for (int i = 0; i < H; i++)
            {
                for (int j = 0; j < D; j++)
                {
                    for (int k = 0; k < this->Width; k++)
                    {
                        temp.Content[i][j][k] = this->Content[i][j][k];
                    }
                }
            }

            for (int i = 0; i < H; i++)
            {
                for (int j = 0; j < D; j++)
                {
                    for (int k = 0; k < W; k++)
                    {
                        if (k == W - 1)
                        {
                            temp.Content[i][j][k] = obj.Content[i][j][k - (W - 1)];
                        }
                    }
                }
            }
            Equalizer(temp);
        }
        return *this;
    }

    //* Operator adds build right front and return the updated object 
    Build operator+(Build &obj)
    {
        Build temp;
        int H, W, D;

        if (this->Height > obj.Height || this->Depth > obj.Depth)
        {
            return *this;
        }

        if (this->Height <= obj.Height || this->Depth <= obj.Depth)
        {
            H = this->Height;
            W = this->Width + obj.Width;
            D = this->Depth;

            temp.Depth = D, temp.Height = H, temp.Width = W;

            Allocator(H, D, W, temp);

            for (int i = 0; i < H; i++)
            {
                for (int j = 0; j < D; j++)
                {
                    for (int k = 0; k < this->Width; k++)
                    {
                        temp.Content[i][j][k] = this->Content[i][j][k];
                    }
                }
            }

            for (int i = 0; i < H; i++)
            {
                for (int j = 0; j < D; j++)
                {
                    for (int k = 0; k < W; k++)
                    {
                        if (k == W - 1)
                        {
                            temp.Content[i][j][k] = obj.Content[i][j][k - (W - 1)];
                        }
                    }
                }
            }
        }
        return temp;
    }

    //* Q5a Operator* use the +=operator n times
    friend Build operator*(unsigned int n, Build const &obj)
    {
        Build temp;
        Build temp2;

        temp.Equalizer(obj);
        temp2.Equalizer(obj);

        for (int i = 1; i < n; i++)
        {
            temp += temp2;
        }

        return temp;
    }

    //* Q5b Operator/ use the ^= operator n times
    friend Build operator/(unsigned int n, Build const &obj)
    {
        Build temp;
        Build temp2;

        temp.Equalizer(obj);
        temp2.Equalizer(obj);

        for (int i = 1; i < n; i++)
        {
            temp ^= temp2;
        }

        return temp;
    }

    //* Q5c Operator% use the -= operator n times
    friend Build operator%(unsigned int n, Build const &obj)
    {
        Build temp;
        Build temp2;

        temp.Equalizer(obj);
        temp2.Equalizer(obj);

        for (int i = 1; i < n; i++)
        {
            temp -= temp2;
        }

        return temp;
    }

    // ! Destructor
    ~Build()
    {
        for (int i = 0; i < this->Height; i++)
        {
            for (int j = 0; j < this->Depth; j++)
            {
                delete[] Content[i][j];
            }
            delete[] Content[i];
        }
        delete[] Content;
    }
};

//* Operator to display the tower
ostream &operator<<(ostream &print, Build obj)
{
    obj.display(print);

    return print;
}

int main()
{
    // Basic Types of Block
    Block Bobj1("ObliqueL", "red");
    Block Bobj2("ObliquedR", "red");
    Block Bobj3("Simple", "red");
    Block Bobj4("Simple", "white");

    // Building Build objects from Blocks
    Build ObligueL(Bobj1);
    Build simpleR(Bobj3);
    Build ObligueR(Bobj2);
    Build SimpleW(Bobj4);

    // Layer 4
    Build Layer4(Bobj1);
    Layer4 += ObligueR;
    Layer4 = 3 % Layer4;

    // Layer 3
    Build Layer3(ObligueL);
    Layer3 += simpleR;
    Layer3 += simpleR;
    Layer3 += ObligueR;
    Layer3 = 3 % Layer3;

    // Layer 2
    Build Layer2(SimpleW);
    Layer2 = 4 * Layer2;
    Layer2 = 3 % Layer2;

    // Layer 1
    Build Layer1(Layer2);

    // The Final Tower
    Build Tower(Layer2);

    Tower ^= Layer1;
    Tower ^= Layer2;
    Tower ^= Layer3;
    Tower ^= Layer4;

    cout << Tower;

    return 0;
}