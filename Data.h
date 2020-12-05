#ifndef UNTITLED21_DATA_H
#include <vector>
#include "Node.h"
class Data : public Node{
private:
    int ttl;
    int priority;
    string protocol;

public:
    Data();
    Data(int tll,int priority, string protocol, int id, int port,string ip_src,string ip_des);

    //getters
    int getTll();
    int getPriority();
    string getProtocol();
    //setters
    void setTll(int tll);
    void setPriority(int  priority);
    void setProtcol(string protcol);

    void print();

    //virtual
    virtual  void alert(vector <Data> datas);
};
#define UNTITLED21_DATA_H

#endif //UNTITLED21_DATA_H
