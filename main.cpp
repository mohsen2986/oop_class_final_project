#include <iostream>
#include <vector>
#include "Data.h"
#include "ADSOne.h"
#include "ADSTwo.h"
#include <fstream>
#include <regex>


using namespace std;

vector<Data> datas;

void read(bool showData){
    fstream f("../alert_sample",fstream::in);
    if (f)
        cout<<"file opened"<<endl;
    else
        cout<<"file not opened"<<endl;

    Data data;
    int dataCount=0;
    string string="";

    struct found{
        bool f_priority=true;
        bool f_ipSource=true;
        bool f_ipDes=true;
        bool f_ttl=true;
        bool f_protcol=true;
        bool f_port=true;
        bool f_id=true;
    };
    found found1;

    while (!f.eof())
    {
        getline(f,string);

        regex priorityRegex("Priority: [1-3]");
        sregex_iterator priority(string.begin(), string.end(), priorityRegex);

        regex ipSourceRegex(" [\\d]+.[\\d]+.[\\d]+.[\\d]+");
        sregex_iterator ipSrc(string.begin(),string.end(),ipSourceRegex);

        regex ipDesRegex("-> [\\d]+.[\\d]+.[\\d]+.[\\d]+");
        sregex_iterator ipDes(string.begin(),string.end(),ipDesRegex);

        regex ttlRegex("TTL:[\\d]+");
        sregex_iterator ttl(string.begin(),string.end(),ttlRegex);

        regex protcolRegex("^[A-Z]{3}");
        sregex_iterator protocol(string.begin(),string.end(),protcolRegex);


        regex portRegex("[\\d]:[0-9]{0,5}$");
        sregex_iterator port(string.begin(),string.end(),portRegex);

        regex idRegex("ID:[\\d]+");
        sregex_iterator id(string.begin(),string.end(),idRegex);

        sregex_iterator end;



        if(priority!=end&&found1.f_priority){
            smatch smatch=*priority;
            int digits=atoi(smatch.str().substr(smatch.str().find(':')+1).c_str());
            if(showData) cout<<digits<<endl;
            data.setPriority(digits);
            found1.f_priority=false;
        }
        if (ipSrc!=end&&found1.f_ipSource){
            smatch smatch=*ipSrc;
            string=smatch.str().erase(0,1);
            if(showData) cout<<string<<endl;
            data.setIp_src(string);
            found1.f_ipSource=false;
        }
        if(ipDes!=end&&found1.f_ipDes){
            smatch smatch=*ipDes;
            string=smatch.str().erase(0,3);
            if(showData) cout<<string<<endl;
            data.setIp_des(string);
            found1.f_ipDes=false;
        }
        if (port!=end&&found1.f_port){
            smatch smatch=*port;
            int digits=atoi(smatch.str().erase(0,2).c_str());
            if(showData) cout<<digits<<endl;
            data.setPort(digits);
            found1.f_port=false;
        }
        if (id!=end&&found1.f_id) {
            smatch smatch = *id;
            int digits = atoi(smatch.str().substr(smatch.str().find(':') + 1).c_str());
            if(showData) cout << digits << endl;
            data.setId(digits);
            found1.f_id=false;
        }
        if (ttl!=end&&found1.f_ttl) {
            smatch smatch = *ttl;
            int digits = atoi(smatch.str().substr(smatch.str().find(':') + 1).c_str());
            if(showData) cout << digits << endl;
            data.setTll(digits);
            found1.f_ttl=false;
        }
        if (protocol!=end&&found1.f_protcol) {
            smatch smatch = *protocol;
            string = smatch.str();
            if(showData) cout << string << endl;
            data.setProtcol(string);
            found1.f_protcol=false;
        }
        if (string==""){
            datas.push_back(data);

            data = Data();
            dataCount++;
            cout<<"Read Node   ===>"<<dataCount<<endl;

            found1.f_ipDes=true;
            found1.f_port=true;
            found1.f_id=true;
            found1.f_ipSource=true;
            found1.f_priority=true;
            found1.f_ttl=true;
            found1.f_protcol=true;
        }
    }
}

void start(){
    int choose=1;
    while (choose){

        cout<<"1_ADS ONE   2_ADS TWO"<<endl;
        cout<<"3_exit               "<<endl;
        cin>>choose;
        switch(choose){
            case 1:
                ADSOne one;
                one.alert(datas);
                break;
            case 2:
                ADSTwo two;
                two.alert(datas);
                break;
            case 3:
                choose=0;
                break;
            default:
                cout<<"enter the right option!!!"<<endl;
                break;
        }
    }

}

int main() {
    read(true);
    start();

    return 0;
}
