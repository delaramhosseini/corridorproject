#include <httplib.h>
#include <iostream>
#include <matrix>
using namespace std;


int main(void)
{
  using namespace httplib;
  matrix C;
  
  int r=0;
  Server svr;

  svr.Get("/2", [&](const Request& req, Response& res) {
    C.make2();
    C.read();
    res.set_content("", "text/plain");
  });
  
  svr.Get("/3", [&](const Request& req, Response& res) {
    C.make3();
    C.read();
    res.set_content("", "text/plain");
  });

  svr.Get("/4", [&](const Request& req, Response& res) {
    C.make4();
    C.read();
    res.set_content("", "text/plain");
  });
  
  svr.Get("/up1", [&](const Request& req, Response& res) {
    r=C.up('1');
    C.read();
    if(r==1) res.set_content("the player number 1 win", "text/plain");
    else res.set_content("", "text/plain");
  });
  
  svr.Get("/up2", [&](const Request& req, Response& res) {
    r=C.up('2');
    C.read();
    if(r==1) res.set_content("the player number 2 win", "text/plain");
    else res.set_content("", "text/plain");
  });
  
  svr.Get("/up3", [&](const Request& req, Response& res) {
    r=C.up('3');
    C.read();
    if(r==1) res.set_content("the player number 3 win", "text/plain");
    else res.set_content("", "text/plain");
  });
  
  svr.Get("/up4", [&](const Request& req, Response& res) {
    r=C.up('4');
    C.read();
    if(r==1) res.set_content("the player number 4 win", "text/plain");
    else res.set_content("", "text/plain");
  });
  
  svr.Get("/down1", [&](const Request& req, Response& res) {
    r=C.down('1');
    C.read();
    if(r==1) res.set_content("the player number 1 win", "text/plain");
    else res.set_content("", "text/plain");
  });
  
  svr.Get("/down2", [&](const Request& req, Response& res) {
    r=C.down('2');
    C.read();
    if(r==1) res.set_content("the player number 2 win", "text/plain");
    else res.set_content("", "text/plain");
  });
  
  svr.Get("/down3", [&](const Request& req, Response& res) {
    r=C.down('3');
    C.read();
    if(r==1) res.set_content("the player number 3 win", "text/plain");
    else res.set_content("", "text/plain");
  });
  
  svr.Get("/down4", [&](const Request& req, Response& res) {
    r=C.down('4');
    C.read();
    if(r==1) res.set_content("the player number 4 win", "text/plain");
    else res.set_content("", "text/plain");
  });
  
  svr.Get("/right1", [&](const Request& req, Response& res) {
    r=C.right('1');
    C.read();
    if(r==1) res.set_content("the player number 1 win", "text/plain");
    else res.set_content("", "text/plain");
  });
  
  svr.Get("/right2", [&](const Request& req, Response& res) {
    r=C.right('2');
    C.read();
    if(r==1) res.set_content("the player number 2 win", "text/plain");
    else res.set_content("", "text/plain");
  });
  
  svr.Get("/right3", [&](const Request& req, Response& res) {
    r=C.right('3');
    C.read();
    if(r==1) res.set_content("the player number 3 win", "text/plain");
    else res.set_content("", "text/plain");
  });
  
  svr.Get("/right4", [&](const Request& req, Response& res) {
    r=C.right('4');
    C.read();
    if(r==1) res.set_content("the player number 4 win", "text/plain");
    else res.set_content("", "text/plain");
  });
  
  svr.Get("/left1", [&](const Request& req, Response& res) {
    r=C.left('1');
    C.read();
    if(r==1) res.set_content("the player number 1 win", "text/plain");
    else res.set_content("", "text/plain");
  });
  
  svr.Get("/left2", [&](const Request& req, Response& res) {
    r=C.left('2');
    C.read();
    if(r==1) res.set_content("the player number 2 win", "text/plain");
    else res.set_content("", "text/plain");
  });
  
  svr.Get("/left3", [&](const Request& req, Response& res) {
    r=C.left('3');
    C.read();
    if(r==1) res.set_content("the player number 3 win", "text/plain");
    else res.set_content("", "text/plain");
  });
  
  svr.Get("/left4", [&](const Request& req, Response& res) {
    r=C.left('4');
    C.read();
    if(r==1) res.set_content("the player number 4 win", "text/plain");
    else res.set_content("", "text/plain");
  });
  
  svr.Get("/wall1", [&](const Request& req, Response& res) {
    C.wall('1');
    res.set_content("", "text/plain");
  });
  
  svr.Get("/wall2", [&](const Request& req, Response& res) {
    C.wall('2');
    res.set_content("", "text/plain");
  });
  
  svr.Get("/wall3", [&](const Request& req, Response& res) {
    C.wall('3');
    res.set_content("", "text/plain");
  });
  
  svr.Get("/wall4", [&](const Request& req, Response& res) {
    C.wall('4');
    res.set_content("", "text/plain");
  });
  
  
  svr.listen("localhost", 8080);
}
