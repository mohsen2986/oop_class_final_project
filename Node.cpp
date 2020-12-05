#include "Node.h"
Node::Node(){
    id=0;
    port=0;
    ip_src="0.0.0.0";
    ip_des="0.0.0.0";
}
Node::Node(int id,int port, string ip_src,string ip_des){
    setId(id);
    setPort(port);
    setIp_src(ip_src);
    setIp_des(ip_des);
}
bool validIp(string ip){
    bool valid=true;
    int a = 0;
    for (int i = 0; i < ip.length() && valid; i++) {
        if (ip.at(i) != '.') {
            char t = ip.at(i);
            a *= 10;
            a += t - 48;
        } else {
            if (a < 255 && a >=
            0) { valid = true; }
            else { valid = false; }
            a = 0;
        }
    }return valid;
}
int Node::getId() {return id;}
int Node::getPort() {return port;}
string Node::getIP_des() {return ip_des;}
string Node::getIp_src() {return ip_src;}
void Node::setId(int id) {this->id=(id>9999&&id<100000)? id :0;}
void Node::setPort(int port) {this->port=(0<port&&65535>port)? port :0;}
void Node::setIp_des(string des) {this->ip_des=(des!="" && validIp(des))? des :"0.0.0.0";}
void Node::setIp_src(string src) {this->ip_src=(src!="" && validIp(src))? src :"0.0.0.0";}
void Node::print(){
    cout<<"id :"<<id<<endl;
    cout<<"port :"<<port<<endl;
    cout<<"ip src:"<<ip_src<<endl;
    cout<<"ip des"<<ip_des<<endl;
}
