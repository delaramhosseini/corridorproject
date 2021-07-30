#include <httplib.h>
#include <iostream>
#include <matrix>
using namespace std;
using namespace httplib;

int main(void)
{
  matrix C;
  Client cli("localhost", 8080);
  int a;
  cout << "chosse your membership(2,3,4):" << ' ' ;
  cin >> a;
  switch(a){  
      case 2:
          if (auto res = cli.Get("/2")) {
             if (res->status == 200) {
               cout << res->body << endl;}
          }
          break;
      case 3:
          if (auto res = cli.Get("/3")) {
             if (res->status == 200) {
               cout << res->body << endl;}
          }
          break;
      case 4:
          if (auto res = cli.Get("/4")) {
             if (res->status == 200) {
               cout << res->body << endl;}
          }
          break;
  }
  C.readfile();
  while(true){
      int b=1;
      char d;
      int r=0;
      while(b<=a){
         cout << "player NO." << b << ':' << '\n';
         cout << "press u for up" << '\n' << "press d for down" << '\n' << "press r for right" << '\n' << "press l for left" << '\n' << "press w for wall" << '\n';
         cin >> d;
         switch(d){
             case 'u':
                 if(b==1){ 
                   if (auto res = cli.Get("/up1")) {
                      if (res->status == 200) {
                         cout << res->body << endl;}
                   
                      if( res->body== "the player number 1 win" ) r=1;}
                   }
                 else if(b==2){
                     if (auto res = cli.Get("/up2")) {
                        if (res->status == 200) {
                           cout << res->body << endl;}
                        
                        if( res->body== "the player number 2 win" ) r=1;}
                     }
                 else if(b==3){
                     if (auto res = cli.Get("/up3")) {
                        if (res->status == 200) {
                           cout << res->body << endl;}
                        
                        if( res->body== "the player number 3 win" ) r=1;}
                     }
                 else if(b==4){
                     if (auto res = cli.Get("/up4")) {
                        if (res->status == 200) {
                           cout << res->body << endl;}
                        
                        if( res->body== "the player number 4 win" ) r=1;}
                     }                 
                 break;
             case 'd':
                 if(b==1){
                     if (auto res = cli.Get("/down1")) {
                        if (res->status == 200) {
                           cout << res->body << endl;}
                           
                        if( res->body== "the player number 1 win" ) r=1;}
                     }
                 else if(b==2){
                     if (auto res = cli.Get("/down2")) {
                        if (res->status == 200) {
                           cout << res->body << endl;}
                        
                        if( res->body== "the player number 2 win" ) r=1;}
                     }
                 else if(b==3){ 
                     if (auto res = cli.Get("/down3")) {
                        if (res->status == 200) {
                           cout << res->body << endl;}
                        
                        if( res->body== "the player number 3 win" ) r=1;}
                     }
                 else if(b==4){
                     if (auto res = cli.Get("/down4")) {
                        if (res->status == 200) {
                           cout << res->body << endl;}
                        
                        if( res->body== "the player number 4 win" ) r=1;}
                     }
                 break;
             case 'r':
                 if(b==1){
                     if (auto res = cli.Get("/right1")) {
                        if (res->status == 200) {
                           cout << res->body << endl;}
                        
                        if( res->body== "the player number 1 win" ) r=1;}
                     }
                 else if(b==2){
                     if (auto res = cli.Get("/right2")) {
                        if (res->status == 200) {
                           cout << res->body << endl;}
                         
                        if( res->body== "the player number 2 win" ) r=1;}
                     }
                 else if(b==3){
                     if (auto res = cli.Get("/right3")) {
                        if (res->status == 200) {
                           cout << res->body << endl;}
                        
                        if( res->body== "the player number 3 win" ) r=1;}
                     }
                 else if(b==4){
                     if (auto res = cli.Get("/right4")) {
                        if (res->status == 200) {
                           cout << res->body << endl;}
                        
                        if( res->body== "the player number 4 win" ) r=1;}
                     }
                 break;
             case 'l':
                 if(b==1){
                     if (auto res = cli.Get("/left1")) {
                        if (res->status == 200) {
                           cout << res->body << endl;}
                           
                        if( res->body== "the player number 1 win" ) r=1;}
                     }
                 else if(b==2){
                     if (auto res = cli.Get("/left2")) {
                        if (res->status == 200) {
                           cout << res->body << endl;}
                         
                        if( res->body== "the player number 2 win" ) r=1;}
                     }
                 else if(b==3){
                     if (auto res = cli.Get("/left3")) {
                        if (res->status == 200) {
                           cout << res->body << endl;}
                        
                        if( res->body== "the player number 3 win" ) r=1;}
                     }
                 else if(b==4){
                     if (auto res = cli.Get("/left4")) {
                        if (res->status == 200) {
                           cout << res->body << endl;}
                        
                        if( res->body== "the player number 4 win" ) r=1;}
                     }
                 break;
             case 'w':
                 int e;
                 char x;
                 cout << "chosse a player: " << '\n' ;
                 cin >> e;
                 cout << "press u for up " << '\n' << "press d for down" << '\n' << "press r for right" << '\n' << "press l for left" << '\n' << "press w for wall" << '\n' ;
                 cin >> x;
                 if(e==1){
                    switch(x){
                       case 'u':
                         cli.Get("/wall1u");
                         break;
                       case 'd':
                         cli.Get("/wall1d");
                         break;
                       case 'l':
                         cli.Get("/wall1l");
                         break;
                       case 'r':
                         cli.Get("/wall1r");
                         break;
                       }
                   }
                 else if(e==2){
                     switch(x){
                       case 'u':
                         cli.Get("/wall2u");
                         break;
                       case 'd':
                         cli.Get("/wall2d");
                         break;
                       case 'l':
                         cli.Get("/wall2l");
                         break;
                       case 'r':
                         cli.Get("/wall2r");
                         break;
                       }
                    }
                 else if(e==3){
                     switch(x){
                       case 'u':
                         cli.Get("/wall3u");
                         break;
                       case 'd':
                         cli.Get("/wall3d");
                         break;
                       case 'l':
                         cli.Get("/wall3l");
                         break;
                       case 'r':
                         cli.Get("wall3r");
                         break;
                       }
                    }
                 else if(e==4){
                     switch(x){
                       case 'u':
                         cli.Get("/wall4u");
                         break;
                       case 'd':
                         cli.Get("/wall4d");
                         break;
                       case 'l':
                         cli.Get("/wall4l");
                         break;
                       case 'r':
                         cli.Get("/wall4r");
                         break;
                       }
                    }
         }
         C.readfile();
         if( r==1 ) break;
         b+=1;}
     if( r==1 ) break;
     }
}

