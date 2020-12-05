#include "Data.h"

Data::Data():Node() {
    ttl=0;
    protocol="TCP";
    priority=1;
}
Data::Data(int tll, int priority, string protocol, int id, int port, string ip_src, string ip_des) :Node(id,port,ip_src,ip_des){
    setTll(tll);
    setPriority(priority);
    setProtcol(protocol);
}
int Data::getTll() { return ttl;}
int Data::getPriority() {return priority;}
string Data::getProtocol() {return protocol;}
void Data::setTll(int tll) {this->ttl=(tll>0&&tll<129)? tll : 0 ;}
void Data::setPriority(int priority) {this->priority=(priority>0&&priority<4)? priority :1;}
void Data::setProtcol(string protcol) {this->protocol=(protcol=="")? "TCP" :protcol;}
void Data::print() {
    cout<<"ttl:"<<ttl<<endl;
    cout<<"priority:"<<priority<<endl;
    cout<<"protocol:"<<protocol<<endl;
    Node::print();
}
void Data::alert(vector<Data> data) {
    cout<<"dosent suport!!!"<<endl;
}