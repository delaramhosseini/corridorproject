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
  while(true){
      int b=1;
      char d;
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
                   }
                   }
                 else if(b==2){
                     if (auto res = cli.Get("/up2")) {
                        if (res->status == 200) {
                           cout << res->body << endl;}
                     }
                     }
                 else if(b==3){
                     if (auto res = cli.Get("/up3")) {
                        if (res->status == 200) {
                           cout << res->body << endl;}
                     }
                     }
                 else if(b==4){
                     if (auto res = cli.Get("/up4")) {
                        if (res->status == 200) {
                           cout << res->body << endl;}
                     }
                     }                 
                 break;
             case 'd':
                 if(b==1){
                     if (auto res = cli.Get("/down1")) {
                        if (res->status == 200) {
                           cout << res->body << endl;}
                     }
                     }
                 else if(b==2){
                     if (auto res = cli.Get("/down2")) {
                        if (res->status == 200) {
                           cout << res->body << endl;}
                     }
                     }
                 else if(b==3){ 
                     if (auto res = cli.Get("/down3")) {
                        if (res->status == 200) {
                           cout << res->body << endl;}
                     }
                     }
                 else if(b==4){
                     if (auto res = cli.Get("/down4")) {
                        if (res->status == 200) {
                           cout << res->body << endl;}
                     }
                     }
                 break;
             case 'r':
                 if(b==1){
                     if (auto res = cli.Get("/right1")) {
                        if (res->status == 200) {
                           cout << res->body << endl;}
                     }
                     }
                 else if(b==2){
                     if (auto res = cli.Get("/right2")) {
                        if (res->status == 200) {
                           cout << res->body << endl;}
                     }
                     }
                 else if(b==3){
                     if (auto res = cli.Get("/right3")) {
                        if (res->status == 200) {
                           cout << res->body << endl;}
                     }
                     }
                 else if(b==4){
                     if (auto res = cli.Get("/right4")) {
                        if (res->status == 200) {
                           cout << res->body << endl;}
                     }
                     }
                 break;
             case 'l':
                 if(b==1){
                     if (auto res = cli.Get("/left1")) {
                        if (res->status == 200) {
                           cout << res->body << endl;}
                     }
                     }
                 else if(b==2){
                     if (auto res = cli.Get("/left2")) {
                        if (res->status == 200) {
                           cout << res->body << endl;}
                     }
                     }
                 else if(b==3){
                     if (auto res = cli.Get("/left3")) {
                        if (res->status == 200) {
                           cout << res->body << endl;}
                     }
                     }
                 else if(b==4){
                     if (auto res = cli.Get("/left4")) {
                        if (res->status == 200) {
                           cout << res->body << endl;}
                     }
                     }
                 break;
             case 'w':
                 if(b==1){
                     if (auto res = cli.Get("/wall1")) {
                        if (res->status == 200) {
                           cout << res->body << endl;}
                     }
                     }
                 else if(b==2){
                     if (auto res = cli.Get("/wall2")) {
                        if (res->status == 200) {
                           cout << res->body << endl;}
                     }
                     }
                 else if(b==3){
                     if (auto res = cli.Get("/wall3")) {
                        if (res->status == 200) {
                           cout << res->body << endl;}
                     }
                     }
                 else if(b==4){
                     if (auto res = cli.Get("/wall4")) {
                        if (res->status == 200) {
                           cout << res->body << endl;}
                     }
                     }
                 break;
         }
         b+=1;}
     }
      
}
