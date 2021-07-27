#include <iostream>
#include "./httplib.h"
using namespace std;
using namespace httplib;

   
void make2(char** C)
{
   for(int i=0 ; i<13 ; i++){
      for(int j=0 ; j<13 ; j++){
          C[i][0]='#';
          if(i==0 || i==12){
             C[i][j]='#';}
          else{
             C[i][j]=' ';}
          }
      C[i][12]='#';
      }
   C[1][1]='1';
   C[1][11]='2';
   for(int i=0 ; i<13 ; i++){
      for(int j=0 ; j<13 ; j++){
          cout << C[i][j] ;}
      cout << '\n';}
}

void make3(char** C)
{
   for(int i=0 ; i<13 ; i++){
      for(int j=0 ; j<13 ; j++){
          C[i][0]='#';
          if(i==0 || i==12){
             C[i][j]='#';}
          else{
             C[i][j]=' ';}
          }
      C[i][12]='#';
      }
   C[1][1]='1';
   C[1][11]='2';
   C[11][1]='3';
   for(int i=0 ; i<13 ; i++){
      for(int j=0 ; j<13 ; j++){
          cout << C[i][j] ;}
      cout << '\n';}
}

void make4(char** C)
{
   for(int i=0 ; i<13 ; i++){
      for(int j=0 ; j<13 ; j++){
          C[i][0]='#';
          if(i==0 || i==12){
             C[i][j]='#';}
          else{
             C[i][j]=' ';}
          }
      C[i][12]='#';
      }
   C[1][1]='1';
   C[1][11]='2';
   C[11][1]='3';
   C[11][11]='4';
   for(int i=0 ; i<13 ; i++){
      for(int j=0 ; j<13 ; j++){
          cout << C[i][j] ;}
      cout << '\n';}
}

           
int up(char** C, char d)
{
   for(int i=0 ; i<13 ; i++){
      for(int j=0 ; j<13 ; j++){
          if(C[i][j]==d){
             if(C[i-1][j]==' '){
                C[i-1][j]=d;
                C[i][j]=' ';}
             else{
                cout << "error"<< '\n' ;}
             }
      }
   }
      
   
   for(int i=0 ; i<13 ; i++){
      for(int j=0 ; j<13 ; j++){
          cout << C[i][j] ;}
      cout << '\n';}
   
   for(int i=0 ; i<13 ; i++){
      for(int j=0 ; j<13 ; j++){
         if(C[i][j]==d && i==6 && j==6){
             cout << "the player number " << d << " win" << '\n';
             return 1;}
         }
     }   
   return 0;
}

int down(char** C, char d)
{
   bool f=false;
   for(int i=0 ; i<12 ; i++){
      for(int j=0 ; j<13 ; j++){
          if(C[i][j]==d){
             if(C[i+1][j]==' '){
                C[i+1][j]=d;
                C[i][j]=' ';
                f=true;
                break;}
             else{
                cout << "error" << '\n' ;
                f=true;
                break;}
             }
          }
      if(f==true) break;
      }
    
    for(int i=0 ; i<13 ; i++){
      for(int j=0 ; j<13 ; j++){
          cout << C[i][j] ;}
      cout << '\n';}
      
   for(int i=0 ; i<13 ; i++){
      for(int j=0 ; j<13 ; j++){
         if(C[i][j]==d && i==6 && j==6){
             cout << "the player number " << d << " win" << '\n';
             return 1;}
         }
     }
    
    return 0;
}

int right(char** C , char d)
{
   bool f=false;
   for(int i=0 ; i<13 ; i++){
      for(int j=0 ; j<13 ; j++){
          if(C[i][j]==d){
             if(C[i][j+1]==' '){
                C[i][j+1]=d;
                C[i][j]=' ';
                f=true;
                break;}
             else{
                cout << "error" << '\n' ;
                f=true;
                break;} 
             }
          }
      if(f==true) break;
      }
  
   for(int i=0 ; i<13 ; i++){
      for(int j=0 ; j<13 ; j++){
          cout << C[i][j] ;}
      cout << '\n';}
  
  for(int i=0 ; i<13 ; i++){
      for(int j=0 ; j<13 ; j++){
         if(C[i][j]==d && i==6 && j==7){
             cout << "the player number " << d << " win" << '\n';
             return 1;}
         }
     } 
   
   return 0;
}

int left(char** C , char d)
{
   for(int i=0 ; i<13 ; i++){
      for(int j=0 ; j<13 ; j++){
          if(C[i][j]==d){
             if(C[i][j-1]==' '){
                C[i][j-1]=d;
                C[i][j]=' ';}
             else{
                cout << "error" << '\n' ;}
             }
          }
      }
    for(int i=0 ; i<13 ; i++){
      for(int j=0 ; j<13 ; j++){
          cout << C[i][j] ;}
      cout << '\n';}
      
   for(int i=0 ; i<13 ; i++){
      for(int j=0 ; j<13 ; j++){
         if(C[i][j]==d && i==6 && j==5){
             cout << "the player number " << d << " win" << '\n';
             return 1;}
         }
     }
    
    return 0;
}

void wall(char** C , char d)
{
    int x;
    cout << "chosse one of the players: " ;
    cin >> x;
}    

int main() {
   char** C;
   C=new char* [13];
   for(int i=0 ; i<13 ; i++){
       C[i]=new char [13];}
   Client cli("localhost,8080");
   int a;
   cout << "chosse your membership(2,3,4):" << ' ' ;
   cin >> a;
   switch(a){  
      case 2:
         make2(C);
         break;
      case 3:
         make3(C);
         break;
      case 4:
         make4(C);
         break;
     }
   
   while(true){
      int b=1;
      int r=0;
      char d;
      while(b<=a){
         cout << "player NO." << b << ':' << '\n';
         cout << "press u for up" << '\n' << "press d for down" << '\n' << "press r for right" << '\n' << "press l for left" << '\n' << "press w for wall" << '\n';
         cin >> d;
         switch(d){
             case 'u':
                 if(b==1) r=up(C,'1');
                 else if(b==2) r=up(C,'2');
                 else if(b==3) r=up(C,'3');
                 else if(b==4) r=up(C,'4');
                 break;
             case 'd':
                 if(b==1) r=down(C,'1');
                 else if(b==2) r=down(C,'2');
                 else if(b==3) r=down(C,'3');
                 else if(b==4) r=down(C,'4');
                 break;
             case 'r':
                 if(b==1) r=right(C,'1');
                 else if(b==2) r=right(C,'2');
                 else if(b==3) r=right(C,'3');
                 else if(b==4) r=right(C,'4');
                 break;
             case 'l':
                 if(b==1) r=left(C,'1');
                 else if(b==2) r=left(C,'2');
                 else if(b==3) r=left(C,'3');
                 else if(b==4) r=left(C,'4');
                 break;
             case 'w':
                 if(b==1) wall(C,'1');
                 else if(b==2) wall(C,'2');
                 else if(b==3) wall(C,'3');
                 else if(b==4) wall(C,'4');
                 break;
         }
         if(r==1) break;
         b+=1;}
     if(r==1) break;
     }
      
   return 0;
}

