#include <iostream>

using namespace std;

// * It checks if anyone has won the Match or not 
void thewinnerdeclare(int count,bool turn )
{
   if(count==3)
  {
    if(!turn)
    {
      cout<<"Player 1 WINS "<<endl;
      exit(0);
    }

    if(turn)
    {
      cout<<"Player 2 WINS "<<endl;
      exit(0);
    }
  }
}

// ? This check if any four consecutive entries are same or not 
void  thewinnerchecker(char** ptr,int row,int col,int pr,int pc,bool &turn)
{
  int countw=0;

  // ! row checker front 
  for(int i=1; i<4; i++)
  {
    if(pr+i<row)
    {
      if(ptr[pr][pc]==ptr[pr+i][pc])
      {
        countw++;
      }
    }
  }

  thewinnerdeclare(countw,turn);

  countw=0;

// ! Row Checker back
   for(int i=1; i<4; i++)
  {
    if(pr-i>-1)
    {
      if(ptr[pr][pc]==ptr[pr-i][pc])
      {
        countw++;
      }
    }
  }

  thewinnerdeclare(countw,turn);

  countw=0;

  // ! Column Checker front  
  for(int i=1; i<4; i++)
  {
    if(pc+i<col)
    {
      if(ptr[pr][pc]==ptr[pr][pc+i])
      {
        countw++;
      }
    }
  }

  thewinnerdeclare(countw,turn);

  countw=0;

   // ! Column Checker back  
  for(int i=1; i<4; i++)
  {
    if(pc-i>-1)
    {
      if(ptr[pr][pc]==ptr[pr][pc-i])
      {
        countw++;
      }
    }
  }

  thewinnerdeclare(countw,turn);

  countw=0; 

   // ! Diagonal check front P   
  for(int i=1; i<4; i++)
  {
    if(pc+i<col && pr+i<row)
    {
      if(ptr[pr][pc]==ptr[pr+i][pc+i])
      {
        countw++;
      }
    }
  }

  thewinnerdeclare(countw,turn);

  countw=0; 

   // ! Diagonal check back P  
  for(int i=1; i<4; i++)
  {
    if(pc-i>-1 && pr-i>-1)
    {
      if(ptr[pr][pc]==ptr[pr-i][pc-i])
      {
        countw++;
      }
    }
  }

  thewinnerdeclare(countw,turn);

  countw=0; 

   // ! Diagonal check front  
  for(int i=1; i<4; i++)
  {
    if(pc+i<col && pr-i>-1)
    {
      if(ptr[pr][pc]==ptr[pr-i][pc+i])
      {
        countw++;
      }
    }
  }

  thewinnerdeclare(countw,turn);

  countw=0;   

   // ! Diagonal check back  
  for(int i=1; i<4; i++)
  {
    if(pc-i>-1 && pr+i<row)
    {
      if(ptr[pr][pc]==ptr[pr+i][pc-i])
      {
        countw++;
      }
    }
  }

  thewinnerdeclare(countw,turn);

  countw=0;      
}

// * It checks if the input is not overflowing 
void Validator(int input,int col)
{
  if(input>col)
  {
    cout<<"You are crossing the bounds of the table "<<endl;
    exit(0);
  }
}

// ? It changes turn manages them and also implemt the logic that the entries fall down and
// ? stack over each of them 
void theturnmaker(bool* turn,char**ptr,int row,int col)
{
  static int func=0;    // one time use 
 static int * const counter2=new int [col];
   static int* const counter= new int [col];

  if(func==0)
  {
    for(int i=0; i<col; i++)
    {
      counter[i]=-1;
    }
    for(int i=0; i<col; i++)
    {
      counter2[i]=row-1;
    }
    func++;
  }

  int input;
if(*turn){
  cout<<"Player 1 Turn \n";
  cout<<"Enter the column you want to drop the token"<<endl;
  cin>>input;
}

if(!*turn){
  cout<<"Player 2 Turn \n";
  cout<<"Enter the column you want to drop the token"<<endl;
  cin>>input;
}


  Validator(input,col);

  counter[input-1]++;

  if(counter2[input-1]<0)
  {
    cout<<"This column has no more space "<<endl;
    exit(0);
  }
if(*turn==true){
  ptr[counter2[input-1]][input-1]='+';
  *turn=false;
}

else{
   ptr[counter2[input-1]][input-1]='x';
   *turn=true;
}
int pr=counter2[input-1],pc=input-1;

  for(int i=0; i<row; i++)
  {
    for(int j=0; j<col; j++)
    {
      cout<<ptr[i][j]<<" ";
    }
    cout<<"\n";
  }
  counter2[input-1]--;

  thewinnerchecker(ptr,row,col,pr,pc,*turn);

}

void thelogicmaker(char **ptr, int row ,int col)
{
  // General Information 
  cout<<"+ stands for Player 1 "<<endl;
  cout<<"x stands for Player 2"<<endl;
  bool player=true;

// TODO : This Loop again and again call the turns until the whole table is full 
  for(int i=0; i<row*col; i++)
  {
    theturnmaker(&player,ptr,row,col);
  }
  cout<<"The Match is tied nobody won :D"<<endl;
  exit(0);
}

int main()
{
  cout<<"Welcome to the Game of Connect 4 "<<endl<<endl;

  // * Taking The number of Rows and Column of the board 
  int row,col;
  
  cout<<"Enter the rows of the board "<<endl;
  cin>>row;
  cout<<"Enter the columns of the board "<<endl;
  cin>>col;
  cout<<endl;

  if(row<4 && col<4)
  {
    cout<<"The Size should be at least 4 "<<endl;
    exit(0);
  }

// ? Making a 2D Character Array 
  char**ptr=new char*[row];
  for(int i=0; i<row; i++)
  {
    ptr[i]=new char[col];
     for(int j=0; j<col; j++)
    {
        ptr[i][j]='_';    
    }   
  }

// ! Calling the function to implement the logic
  thelogicmaker(ptr,row,col);
  

  for(int i=0; i<row; i++)
  {
    delete[]ptr[i];
  }
  delete[]ptr;

  ptr=NULL;
  return 0;
}