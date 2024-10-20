#include <iostream>
#include <fstream>
using namespace std;


class matrix
{
   private:
      char** C;
      
   public:   
      matrix(){
         C=new char* [13];
         for(int i=0; i<13 ; i++){
            C[i]=new char [13];}
         }
      void make2();
      void make3();
      void make4();
      int up(char );
      int down( char );
      int right( char );
      int left( char );
      void wall( char , char);
      void makefile();
      void readfile();
};


void matrix::make2()
{
    for(int i=0 ; i<13 ; i++){
      for(int j=0 ; j<13 ; j++){
          C[i][0]='#';
          if(i==0 || i==12){
             C[i][j]='#';}
          else{
             C[i][j]='.';}
          }
      C[i][12]='#';
      }
    C[1][1]='1';
    C[1][11]='2';
}

void matrix::make3()
{
   for(int i=0 ; i<13 ; i++){
      for(int j=0 ; j<13 ; j++){
          C[i][0]='#';
          if(i==0 || i==12){
             C[i][j]='#';}
          else{
             C[i][j]='.';}
          }
      C[i][12]='#';
      }
   C[1][1]='1';
   C[1][11]='2';
   C[11][1]='3';
}
   
void matrix::make4()
{
   for(int i=0 ; i<13 ; i++){
      for(int j=0 ; j<13 ; j++){
          C[i][0]='#';
          if(i==0 || i==12){
             C[i][j]='#';}
          else{
             C[i][j]='.';}
          }
      C[i][12]='#';
      }
   C[1][1]='1';
   C[1][11]='2';
   C[11][1]='3';
   C[11][11]='4';
}

int matrix::up(char d)
{
   for(int i=0 ; i<13 ; i++){
      for(int j=0 ; j<13 ; j++){
          if(C[i][j]==d){
             if(C[i-1][j]=='.'){
                C[i-1][j]=d;
                C[i][j]='.';}
             else{
                return 2;}
             }
      }
   }   
   for(int i=0 ; i<13 ; i++){
      for(int j=0 ; j<13 ; j++){
         if(C[i][j]==d && i==6 && j==6){
             return 1;}
         }
     }   
   return 0;
}

int matrix::down(char d)
{
   bool f=false;
   for(int i=0 ; i<12 ; i++){
      for(int j=0 ; j<13 ; j++){
          if(C[i][j]==d){
             if(C[i+1][j]=='.'){
                C[i+1][j]=d;
                C[i][j]='.';
                f=true;}

             else{
                f=true;
                return 2;}
             
             break;}
          }
      if(f==true) break;
   }      
   for(int i=0 ; i<13 ; i++){
      for(int j=0 ; j<13 ; j++){
         if(C[i][j]==d && i==6 && j==6){
             return 1;}
         }
     }
    
    return 0;
}

int matrix::right(char d)
{
   bool f=false;
   for(int i=0 ; i<13 ; i++){
      for(int j=0 ; j<13 ; j++){
          if(C[i][j]==d){
             if(C[i][j+1]=='.'){
                C[i][j+1]=d;
                C[i][j]='.';
                f=true;}
             else{
                f=true;
                return 2;}
             
             break;} 
           }
      if(f==true) break;
      }
  for(int i=0 ; i<13 ; i++){
      for(int j=0 ; j<13 ; j++){
         if(C[i][j]==d && i==6 && j==6){
             return 1;}
         }
     } 
   
   return 0;
}

int matrix::left(char d)
{
   for(int i=0 ; i<13 ; i++){
      for(int j=0 ; j<13 ; j++){
          if(C[i][j]==d){
             if(C[i][j-1]=='.'){
                C[i][j-1]=d;
                C[i][j]='.';}
             else{
                return 2;}
             }
          }
      }
   for(int i=0 ; i<13 ; i++){
      for(int j=0 ; j<13 ; j++){
         if(C[i][j]==d && i==6 && j==6){
             return 1;}
         }
     }
    
    return 0;
}

void matrix::wall(char d,char x)
{   
    bool f=false;
    for(int i=0 ; i<13 ; i++){
       for( int j=0 ; j<13 ; j++){
           if( C[i][j]==d ){
              if( x=='u' ){
                if(C[i-1][j]=='.') C[i-1][j]='*';
                if(C[i-1][j+1]=='.') C[i-1][j+1]='*';
                if(C[i-1][j-1]=='.') C[i-1][j-1]='*';}
              else if( x=='d'){
                if(C[i+1][j]=='.') C[i+1][j]='*';
                if(C[i+1][j+1]=='.') C[i+1][j+1]='*';
                if(C[i+1][j-1]=='.') C[i+1][j-1]='*';}
              else if( x=='l'){
                if(C[i][j-1]=='.') C[i][j-1]='*';
                if(C[i+1][j-1]=='.') C[i+1][j-1]='*';
                if(C[i-1][j-1]=='.') C[i-1][j-1]='*';}
              else if( x=='r'){
                if(C[i][j+1]=='.') C[i][j+1]='*';
                if(C[i+1][j+1]=='.') C[i+1][j+1]='*';
                if(C[i-1][j+1]=='.') C[i-1][j+1]='*';}
              f=true;
              break;}
        }
        if( f==true ) break;}
}  

void matrix::makefile()
{   
    ofstream onground( "ground.dat", ios::trunc );
    int a=0;
    char* b;
    b=new char [13];
    
    while(a<13){
       for(int i=0 ; i<13 ; i++){
             b[i]=C[a][i];}
             
       onground << b << endl ;
       a+=1;}
    delete b;
}  

void matrix::readfile()
{
    ifstream inground( "ground.dat", ios::in );
    int a=0;
    char* b;
    b=new char [13];
    
    while(a<13){
       inground >> b;
       
       for(int i=0 ; i<13 ; i++){
          cout << b[i] ;}
       cout << '\n' ;
          
       a+=1;}
    delete b;
}

