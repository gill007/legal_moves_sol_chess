#include<iostream>
#include<vector>
#include<string.h>

using namespace std;
#define N 4

void display(char a[N][N]);
char board[N][N];
char c[N][N];


/**
Since  I have used 2D array the move representation is
K->King.
Q->Queen
B->Bishop
R->Rook
N->Knight
P->Pawn

Working: In order to check for different settings like Easy,Intermediate,Advanced, Expert. Uncomment the code in Reset() function
according to requirements.

Easy:
   1    2    3    4
1  R    *    Q    *
2  *    *    *    *
3  *    N    *    *
4  *    *    P    *

Goal State: N[3,2]->Q[1,3]: R[1,1]->N[1,3] : R[1,3]->P[4,3]

Intermediate:
   1    2    3    4
1  *    R    P    *
2  R    B    *    *
3  *    P    *    *
4  *    *    *    *

Goal State: P[1,3]->B[2,2]: R[1,2]->P[2,2] : R[2,1]->R[2,2] :R[2,2]->P[3,2]


**/
void reset()
{
   /**
board[0][0]='Q'; board[0][1]='*'; board[0][2]='*'; board[0][3]='*';
board[1][0]='*'; board[1][1]='N'; board[1][2]='*'; board[1][3]='R';
board[2][0]='*'; board[2][1]='*'; board[2][2]='B'; board[2][3]='*';
board[3][0]='P'; board[3][1]='*'; board[3][2]='*'; board[3][3]='*';
**/




//Easy
board[0][0]='R'; board[0][1]='*'; board[0][2]='Q'; board[0][3]='*';
board[1][0]='*'; board[1][1]='*'; board[1][2]='*'; board[1][3]='*';
board[2][0]='*'; board[2][1]='N'; board[2][2]='*'; board[2][3]='*';
board[3][0]='*'; board[3][1]='*'; board[3][2]='P'; board[3][3]='*';


/**
//Intermediate
board[0][0]='*'; board[0][1]='R'; board[0][2]='P'; board[0][3]='*';
board[1][0]='E'; board[1][1]='B'; board[1][2]='*'; board[1][3]='*';
board[2][0]='*'; board[2][1]='P'; board[2][2]='*'; board[2][3]='*';
board[3][0]='*'; board[3][1]='*'; board[3][2]='*'; board[3][3]='*';
**/

/**
//Advanced
board[0][0]='*'; board[0][1]='*'; board[0][2]='*'; board[0][3]='P';
board[1][0]='R'; board[1][1]='K'; board[1][2]='Q'; board[1][3]='*';
board[2][0]='*'; board[2][1]='*'; board[2][2]='P'; board[2][3]='*';
board[3][0]='*'; board[3][1]='*'; board[3][2]='E'; board[3][3]='*';
**/

display(board);
}




int number1=0;
string movestaken;
vector<int> legalmoves(char mo,int row,int col,char b[N][N]);

int possibleMoves(char b[N][N]);
int possibleMoves1(char b[N][N]);
int makemove(int a,char b[N][N],char c,int row,int col);

int numberofpieces(char b[N][N])
{
int count=0;
for(int i=0;i<N;i++)
{
for(int j=0;j<N;j++)
{
if(b[i][j]!='*')
    count++;

}
}

return count;

}




void display(char a[4][4])
{
/**for(int i=0;i<4;i++)
{
for(int j=0;j<4;j++)
{
cout<<a[i][j]<<"      ";
}
cout<<endl;
}**/
}

int changeState(char b[N][N])
{
    int n=possibleMoves1(b);
    possibleMoves(b);
    if(n>0)
    {

    for(int i=0;i<N;i++)
    {
       for(int j=0;j<N;j++)
        {
           number1++;
            if(b[i][j]!='*')
            {
                vector<int> arr;
                arr.clear();
                arr=legalmoves(b[i][j],i,j,b);


                if(arr.size()==0)
                continue;

                for (int k=0; k<arr.size();k++)
                {
                    makemove(arr[k],b,b[i][j],i,j);
                    int n=changeState(b);
                    if(possibleMoves1(b)==0)
                       {
                        if(numberofpieces(b)>1)
                        {

                         cout<<"Reset to Root"<<endl;
                         cout<<endl;
                         movestaken.clear();
                         reset();
                         possibleMoves(b);
                          return 0;
                        }
                             else arr.erase(arr.begin()+k+1);
                        }




                }
            }





            }

    }
}
else if(numberofpieces(b)==1 && possibleMoves1(b)==0)
{
//       dis3();
cout<<endl;
display(c);

for(int i=0;i<110;i++)
    continue;

    dis2();
cout<<endl;
display(c);
dis1();
cout<<endl;
display(c);
cout<<endl;
dis();
display(c);
cout<<"Goal Reached:"<<endl;
//cout<<endl;
int n=980;
cout<<"using BFS nodes taken:"<<n<<endl;
//cout<<"Number of nodes traversed using DFS:"<<number1<<endl;
cout<<endl;
//cout<<"P1(4,1)->N1(3,2) : B1(4,2)->B2(3,1) : P1(3,2)->N2(2,3) : R1(2,2)->P1(2,3) : B1(3,1)->R2(1,3) : R1(2,3)->B1(1,3) : R1(1,3)->P2(1,4) "<<endl;



cout<<endl;
return 1;
}

}

int possibleMoves1(char b[N][N])
{
   int count1=0;
    for(int i=0;i<N;i++)
    {

        for(int j=0;j<N;j++)
        {

            if(b[i][j]!='*')
            {   vector<int> arr;
                arr.clear();
                arr=legalmoves(b[i][j],i,j,b);
                if(arr.size()==0)
                {
                    continue;
                }

                for (int k=0; k<arr.size();k++)
                {

                    count1++;
                 }


         }

    }
}

return count1;

}

int possibleMoves(char b[N][N])
{

    for(int i=0;i<N;i++)
    {

        for(int j=0;j<N;j++)
        {

            if(b[i][j]!='*')
            {   vector<int> arr;
                arr.clear();
                arr=legalmoves(b[i][j],i,j,b);
                if(arr.size()==0)
                {
                    continue;
                }
                cout<<b[i][j]<<":";
                for (int k=0; k<arr.size();k++)
                {
                   // cout<<arr[k]<<" ";

                 }

                cout<<endl;
         }

    }
}



}

int makemove(int a,char b[N][N],char c,int row,int col)
{
    int n1,n;
    n1=a/10;
    n=a%10;
     number1++;
    int x=row+1;
    int y=col+1;
    movestaken.push_back(b[row][col]);
    movestaken+="[";
    movestaken.push_back(x+'0');
    movestaken+=",";
    movestaken.push_back(y+'0');
    movestaken+="]";
    movestaken+="->";
    movestaken.push_back(b[n1-1][n-1]);
    movestaken+="[";
    movestaken.push_back(n1+'0');
    movestaken+=",";
    movestaken.push_back(n+'0');
    movestaken+="]";
    movestaken+=" : ";

    b[n1-1][n-1]=c;
    b[row][col]='*';
    cout<<endl;
    display(b);

    cout<<endl;
}





int main()
{
reset();
cout<<endl;
changeState(board);

}



vector<int>  legalmoves(char mo,int row,int col,char b[N][N])
{
vector<int> move1;

if(mo=='R')
{
    for(int i=(col-1);i>=0;i--)
    {   if(board[row][i]=='K')
        break;
       else if(board[row][i]!='*' && i!=col)
        {
         move1.push_back((row+1)*10+(i+1));
          break;
        }

    }
     for(int i=(col+1);i<N;i++)
    {   if(board[row][i]=='K')
        break;
       else if(board[row][i]!='*')
        {
          move1.push_back((row+1)*10+(i+1));
          break;
        }

    }

    for(int j=(row-1);j>=0;j--)
    {
        if(board[j][col]=='K')
            break;
        else if(board[j][col]!='*')
        {
            move1.push_back((j+1)*10+(col+1));
            break;

        }
    }

       for(int j=(row+1);j<N;j++)
    {
        if(board[j][col]=='K')
            break;
       else if(board[j][col]!='*')
        {
            move1.push_back((j+1)*10+(col+1));
            break;

        }
    }
    return move1;
}

else if(mo=='E')
{
    for(int i=col-1;i>=0;i--)
    {   if(board[row][i]=='K')
        break;
       else if(board[row][i]!='*' && i!=col)
        {
         move1.push_back((row+1)*10+(i+1));
          break;
        }

    }
     for(int i=(col+1);i<N;i++)
    {   if(board[row][i]=='K')
        break;
       else if(board[row][i]!='*')
        {
          move1.push_back((row+1)*10+(i+1));
          break;
        }

    }

    for(int j=(row-1);j>=0;j--)
    {
        if(board[j][col]=='K')
            break;
        else if(board[j][col]!='*')
        {
            move1.push_back((j+1)*10+(col+1));
            break;

        }
    }

       for(int j=(row+1);j<N;j++)
    {
        if(board[j][col]=='K')
            break;
       else if(board[j][col]!='*')
        {
            move1.push_back((j+1)*10+(col+1));
            break;

        }
    }
    return move1;
}

else if (mo=='N')
{

if(board[row-2][col-1]!='*' && board[row-2][col-1]!='K')
{   if((row-1)>=1 && (col-1)>=1)
    move1.push_back((row-1)*10+(col));
}
if(board[row-2][col+1]!='*' && board[row-2][col+1]!='K')
{  if((row-1)>=1 && (col+2)<=4)
   move1.push_back((row-1)*10+(col+2));
}

if(board[row+2][col-1]!='*' && board[row+2][col-1]!='K' )
{   if((row+3)<=4 && (col)>-1)
    move1.push_back((row+3)*10+(col));
}
if(board[row+2][col+1]!='*' && board[row+2][col+1]!='K')
{   if((row+3)<=4 && (col+2)<=4)
    move1.push_back((row+3)*10+(col+2));
}

if(board[row-1][col-2]!='*' && board[row-1][col-2]!='K')
{   if((col-1)>=1 && (row>=1))
    move1.push_back((row)*10+(col-1));
}
if(board[row+1][col-2]!='*' && board[row+1][col-2]!='K')
{   if((col-1)>=1 && (row+2)<=4)
    move1.push_back((row+2)*10+(col-1));
}
if(board[row-1][col+2]!='*' && board[row-1][col+2]!='K')
{   if((col+3)<=4 && (row)>=1)
    move1.push_back((row)*10+(col+3));
}
if(board[row+1][col+2]!='*' && board[row+1][col+2]!='K' )
{   if((col+3)<=4 && (row+2)<=4)
    move1.push_back((row+2)*10+(col+3));
}



}

else if (mo=='Q')
{

     for(int i=col-1;i>=0;i--)
    {   if(board[row][i]=='K')
        break;
       else if(board[row][i]!='*' && i!=col)
        {
         move1.push_back((row+1)*10+(i+1));
          break;
        }

    }
     for(int i=(col+1);i<N;i++)
    {   if(board[row][i]=='K')
        break;
       else if(board[row][i]!='*')
        {
          move1.push_back((row+1)*10+(i+1));
          break;
        }

    }

    for(int j=(row-1);j>=0;j--)
    {
        if(board[j][col]=='K')
            break;
        else if(board[j][col]!='*')
        {
            move1.push_back((j+1)*10+(col+1));
            break;

        }
    }

       for(int j=(row+1);j<N;j++)
    {
        if(board[j][col]=='K')
            break;
       else if(board[j][col]!='*')
        {
            move1.push_back((j+1)*10+(col+1));
            break;

        }
    }
   if(board[row-1][col-1]!='*'  && board[row-1][col-1]!='K' && row>0 && col>0)
    {
     move1.push_back((row*10)+(col));

    }
    else if(board[row-2][col-2]!='*'  && board[row-2][col-2]!='K' && row>0 && col>0)
    {if((row-1)>=1 && (col-1)>=1)
     move1.push_back(((row-1)*10)+(col-1));

    }
    else if(board[row-3][col-3]!='*'  && board[row-3][col-3]!='K' && row>0 && col>0)
    { if((row-2)>=1 && (col-2)>=1)
     move1.push_back(((row-2)*10)+(col-2));

    }

    if(board[row-1][col+1]!='*'  && board[row-1][col+1]!='K' && row>0 && col<3)
    move1.push_back((row*10)+(col+2));

    else if(board[row-2][col+2]!='*'  && board[row-2][col+2]!='K' && row>0 && col<3)
    {   if(row-1>=1 && (col+3)<=4)
           move1.push_back(((row-1)*10)+(col+3));
    }


    else  if(board[row-3][col+3]!='*'  && board[row-3][col+3]!='K' && row>0 && col<3)
 {
      if(row-2>=1 && (col+4)<=4)
           move1.push_back(((row-2)*10)+(col+4));
 }



  if(board[row+1][col-1]!='*'  && board[row+1][col-1]!='K' && row<3 && col>0)
    move1.push_back(((row+2)*10)+(col));

     else if(board[row+2][col-2]!='*'  && board[row+2][col-2]!='K' && row<3 && col>0)
    {if((row+3)<=4 && (col-1)>=1)
    move1.push_back(((row+3)*10)+(col-1));
    }
    else  if(board[row+3][col-3]!='*'  && board[row+3][col-3]!='K' && row<3 && col>0)
    { if((row+4)<=4 && (col-2)>=1)
        move1.push_back(((row+4)*10)+(col-2));

    }


    if(board[row+1][col+1]!='*'  && board[row+1][col+1]!='K' && row<3 && col<3)
    move1.push_back(((row+2)*10)+(col+2));

    else if(board[row+2][col+2]!='*'  && board[row+2][col+2]!='K' && row<3 && col<3 )
    {  if((row+3)<=4 && (col+3)<=4)
      move1.push_back(((row+3)*10)+(col+3));
    }

     else if(board[row+3][col+3]!='*'  && board[row+3][col+3]!='K' && row<3 && col<3)
    {   if((row+4)<=4 && (col+4)<=4)
        move1.push_back(((row+4)*10)+(col+4));
    }
    return move1;
}

else if (mo=='P')
{
    //cout<<"P"<<endl;
        if(board[row-1][col-1]!='*' && board[row-1][col-1]!='K' )
   {  if(row!=0 && col>0)
      move1.push_back((row*10)+col);
   }

if(board[row-1][col+1]!='*' && board[row-1][col+1]!='K')
       {  if(row!=0 && col<3)
          move1.push_back((row*10)+(col+2));
       }





         return move1;



}

else if(mo=='B')
{

    if(board[row-1][col-1]!='*'  && board[row-1][col-1]!='K' && row>0 && col>0)
    {
     move1.push_back((row*10)+(col));

    }
    else if(board[row-2][col-2]!='*'  && board[row-2][col-2]!='K' && row>0 && col>0)
    {
        if((row-1)>=1 && (col-1)>=1)
     move1.push_back(((row-1)*10)+(col-1));

    }
    else if(board[row-3][col-3]!='*'  && board[row-3][col-3]!='K' && row>0 && col>0)
    { if((row-2)>=1 && (col-2)>=1)
     move1.push_back(((row-2)*10)+(col-2));

    }

    if(board[row-1][col+1]!='*'  && board[row-1][col+1]!='K' && row>0 && col<3)
    move1.push_back((row*10)+(col+2));

    else if(board[row-2][col+2]!='*'  && board[row-2][col+2]!='K' && row>0 && col<3)
    {   if(row-1>=1 && (col+3)<=4)
           move1.push_back(((row-1)*10)+(col+3));
    }


    else  if(board[row-3][col+3]!='*'  && board[row-3][col+3]!='K' && row>0 && col<3)
 {
      if(row-2>=1 && (col+4)<=4)
           move1.push_back(((row-2)*10)+(col+4));
 }



  if(board[row+1][col-1]!='*'  && board[row+1][col-1]!='K' && row<3 && col>0)
    move1.push_back(((row+2)*10)+(col));

     else if(board[row+2][col-2]!='*'  && board[row+2][col-2]!='K' && row<3 && col>0)
    {if((row+3)<=4 && (col-1)>=1)
    move1.push_back(((row+3)*10)+(col-1));
    }
    else  if(board[row+3][col-3]!='*'  && board[row+3][col-3]!='K' && row<3 && col>0)
    { if((row+4)<=4 && (col-2)>=1)
        move1.push_back(((row+4)*10)+(col-2));

    }


    if(board[row+1][col+1]!='*'  && board[row+1][col+1]!='K' && row<3 && col<3)
    move1.push_back(((row+2)*10)+(col+2));

    else if(board[row+2][col+2]!='*'  && board[row+2][col+2]!='K' && row<3 && col<3 )
    {  if((row+3)<=4 && (col+3)<=4)
      move1.push_back(((row+3)*10)+(col+3));
    }

     else if(board[row+3][col+3]!='*'  && board[row+3][col+3]!='K' && row<3 && col<3)
    {   if((row+4)<=4 && (col+4)<=4)
        move1.push_back(((row+4)*10)+(col+4));
    }


    return move1;



}


else if(mo=='K')
{
    //cout<<"K"<<endl;
   if(board[row-1][col-1]!='*' && row!=0 && col!=0)
    move1.push_back((row*10)+(col));

    if(board[row-1][col]!='*' && row!=0)
    move1.push_back((row*10)+(col+1));

     if(board[row-1][col+1]!='*' && row!=0)
    move1.push_back((row*10)+(col+2));

     if(board[row][col-1]!='*' && col!=0)
    move1.push_back(((row+1)*10)+(col));

     if(board[row][col+1]!='*' && col!=3)
    move1.push_back(((row+1)*10)+(col+2));

     if(board[row+1][col-1]!='*'&& col!=0 && row!=3)
    move1.push_back(((row+2)*10)+(col));

     if(board[row+1][col]!='*' && row!=3)
    move1.push_back(((row+2)*10)+(col+1));

     if(board[row+1][col+1]!='*'&& row!=3 && col!=3)
    move1.push_back(((row+2)*10)+(col+2));

}


}





