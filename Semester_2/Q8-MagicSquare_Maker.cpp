#include <iostream>

using namespace std;

int ** thearrayallocator(int n)
{
    
    int ** thearr=new int *[n];

    for(int i=0; i<n; i++)
    {
        thearr[i]=new int [n];   
    }

    return thearr;
}

void TheAlgorithmmaker(int ** array,int n)
{
    
// * Allocating all values to 0 to avoid repetetion 
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            array[i][j]=0;
        }
    }
    
// ! The Main Loop to make the magic square    
        for(int j=0; j<n*n; j++)
        {
            static int pos1,pos2;
            if( j==0 )
            {
                array[n/2][n-1]=1;
                pos1=n/2,pos2=n-1;
            }
            else
            {

            pos1--,pos2++;

            if(pos1==-1 && pos2==n)
            {
                pos1=0;
                pos2=n-2;
            }

            if(pos1==-1)
            {
                pos1=n-1;
            }

            if(pos2==n)
            {
                pos2=0;
            }

     if(array[pos1][pos2]==0)
         {
                array[pos1][pos2]=j+1;

        }
 else{
                pos1++,pos2=pos2-2;
                array[pos1][pos2]=j+1;
    }
            }
}

// ? PRINTING THE MAGIC SQUARE 

for(int i=0; i<n; i++)
{
    for(int j=0; j<n; j++)
    {
        cout<<array[i][j]<<"\t";
    }
    cout<<endl;
}

// ! UNALLOCATING THE MEMEORY 
for(int i=0; i<n; i++)
{
    delete []array[i];
}

delete []array;
array=NULL;
    

}

int main()
{
    int size;

    cout<< "Enter the size of the magic square you want to build "<<endl;
    cin>>size;
    cout<<"\n\n";

  int ** TheMagicsquare=thearrayallocator(size);

  TheAlgorithmmaker(TheMagicsquare,size);

  TheMagicsquare=NULL;

  return 0;
}