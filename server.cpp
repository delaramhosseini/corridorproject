#include <httplib.h>
#include <iostream>
using namespace std;
char** C;

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



int main(void)
{
  using namespace httplib;
  C=new char* [13];
  for(int i=0 ; i<13 ; i++){
      C[i]=new char [13];}

  Server svr;

  svr.Get("/2", [](const Request& req, Response& res) {
    make2(C);
    res.set_content("player NO.2 press u for up , press d for down , press r for right , press l for left , press w for wall" , "text/plain");
  });
  
  svr.Get("/3", [&](const Request& req, Response& res) {
    make3(C);
    res.set_content("", "text/plain");
  });

  svr.Get("/4", [&](const Request& req, Response& res) {
    make4(C);
    res.set_content("", "text/plain");
  });
  
  svr.Get("/up1", [&](const Request& req, Response& res) {
    up(C ,'1');
    res.set_content("", "text/plain");
  });
  
  svr.Get("/up2", [&](const Request& req, Response& res) {
    up(C ,'2');
    res.set_content("", "text/plain");
  });
  
  svr.Get("/up3", [&](const Request& req, Response& res) {
    up(C ,'3');
    res.set_content("", "text/plain");
  });
  
  svr.Get("/up4", [&](const Request& req, Response& res) {
    up(C ,'4');
    res.set_content("", "text/plain");
  });
  
  svr.Get("/down1", [&](const Request& req, Response& res) {
    down(C ,'1');
    res.set_content("", "text/plain");
  });
  
  svr.Get("/down2", [&](const Request& req, Response& res) {
    down(C ,'2');
    res.set_content("", "text/plain");
  });
  
  svr.Get("/down3", [&](const Request& req, Response& res) {
    down(C,'3');
    res.set_content("", "text/plain");
  });
  
  svr.Get("/down4", [&](const Request& req, Response& res) {
    down(C ,'4');
    res.set_content("", "text/plain");
  });
  
  svr.Get("/right1", [&](const Request& req, Response& res) {
    right(C,'1');
    res.set_content("", "text/plain");
  });
  
  svr.Get("/right2", [&](const Request& req, Response& res) {
    right(C,'2');
    res.set_content("", "text/plain");
  });
  
  svr.Get("/right3", [&](const Request& req, Response& res) {
    right(C,'3');
    res.set_content("", "text/plain");
  });
  
  svr.Get("/right4", [&](const Request& req, Response& res) {
    right(C,'4');
    res.set_content("", "text/plain");
  });
  
  svr.Get("/left1", [&](const Request& req, Response& res) {
    left(C,'1');
    res.set_content("", "text/plain");
  });
  
  svr.Get("/left2", [&](const Request& req, Response& res) {
    left(C,'2');
    res.set_content("", "text/plain");
  });
  
  svr.Get("/left3", [&](const Request& req, Response& res) {
    left(C,'3');
    res.set_content("", "text/plain");
  });
  
  svr.Get("/left4", [&](const Request& req, Response& res) {
    left(C,'4');
    res.set_content("", "text/plain");
  });
  
  svr.Get("/wall1", [&](const Request& req, Response& res) {
    wall(C,'1');
    res.set_content("", "text/plain");
  });
  
  svr.Get("/wall2", [&](const Request& req, Response& res) {
    wall(C,'2');
    res.set_content("", "text/plain");
  });
  
  svr.Get("/wall3", [&](const Request& req, Response& res) {
    wall(C,'3');
    res.set_content("", "text/plain");
  });
  
  svr.Get("/wall4", [&](const Request& req, Response& res) {
    wall(C,'4');
    res.set_content("", "text/plain");
  });
  
  svr.listen("localhost", 8080);
}
