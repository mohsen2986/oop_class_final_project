#ifndef UNTITLED21_NODE_H

#include <iostream>

using namespace std;
class Node{
private:
    int id;
    int port;
    string ip_src;
    string ip_des;
public:
    Node();
    Node(int id,int port,string ip_src ,string ip_des);

    //getters
    int getId ();
    int getPort();
    string getIp_src();
    string getIP_des();
    //setters
    void setId(int id);
    void setPort(int port);
    void setIp_src(string src);
    void setIp_des(string des);
    //virtual
    virtual void print();

};
#define UNTITLED21_NODE_H

#endif //UNTITLED21_NODE_H
