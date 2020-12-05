#include "ADSOne.h"
void swap(vector<int> &v, int x, int y) {
    int temp = v[x];
    v[x] = v[y];
    v[y] = temp;
}
void swap(vector<Data> &v , int x,int y){
    Data temp = v[x];
    v[x] = v[y];
    v[y] = temp;
}
void quicksort(vector<int> &vec,vector<Data> &ip, int L, int R) {
    int i, j, mid, piv;
    i = L;
    j = R;
    mid = L + (R - L) / 2;
    piv = vec[mid];
    Data ip_piv=ip[mid];

    while (i<R || j>L) {
        while (vec[i] < piv)
            i++;
        while (vec[j] > piv)
            j--;

        if (i <= j) {
            swap(vec, i, j);
            swap(ip , i, j);
            i++;
            j--;
        }
        else {
            if (i < R)
                quicksort(vec, ip, i, R);
            if (j > L)
                quicksort(vec, ip, L, j);
            return;
        }
    }
}
void ipSrc(vector <Data> datas){
    vector<Data> ips;
    vector<int> ipSrcCounter;


    bool exist=true;
    for (int i = 0; i < datas.size(); ++i) {
        exist=true;
        for (int j = 0; j < ips.size(); ++j) {
            if (ips.at(j).getIp_src() == datas.at(i).getIp_src()) {
                ipSrcCounter.at(j)++;
                exist = false;
            }
        }
        if (exist){
            ips.push_back(datas.at(i));
            ipSrcCounter.push_back(1);
        }
    }
    quicksort(ipSrcCounter,ips,0,ipSrcCounter.size()-1);
    for (int k = 0; k < ipSrcCounter.size(); ++k) {
        cout<<"counter ============>" << ipSrcCounter.at(k)<<endl;
        ips.at(k).print();
    }
}
void ipDesCounter(vector <Data> datas){
    vector<Data> des;
    vector<int> ipDesCounter;
    bool exist=true;
    for (int i = 0; i < datas.size(); ++i) {
        exist=true;
        for (int j = 0; j < des.size(); ++j) {
            if (des.at(j).getIp_src() == datas.at(i).getIp_src()) {
                ipDesCounter.at(j)++;
                exist = false;
            }
        }
        if (exist){
            des.push_back(datas.at(i));
            ipDesCounter.push_back(1);
        }
    }
    quicksort(ipDesCounter,des,0,ipDesCounter.size()-1);
    for (int k = 0; k < ipDesCounter.size(); ++k) {
        cout<<"counter ============>"<<ipDesCounter.at(k)<<endl;
        des.at(k).print();
    }
}
bool searchIp(string s,vector<Data> datas){
    for(int i=0;i<datas.size() ;i++)
        if(datas.at(i).getIp_src() == s) return true;
    return false;
}
void ADSOne::alert(vector<Data> datas) {

    int choosse=1;
    string ip;
    int m;
    while(choosse) {
        cout<<"enter the option  "<<endl;
        cout<<"1_ipSrc    2_ipDes"<<endl;
        cout<<"3_searchIp 4_exit "<<endl;
        cin >> choosse;
        switch (choosse) {
            case 1:
                ipSrc(datas);
                break;
            case 2:
                ipDesCounter(datas);
                break;
            case 3:
                cout << "enter the ip number";
                cin >> ip;
                if(searchIp(ip,datas))
                    cout<<"exist !!!"<<endl;
                else
                    cout<<"Dosent exist :("<<endl;
                break;
            case 4:
                choosse = 0;
                cout << "exiting....." << endl;
                break;
            default:
                cout << "enter the right choose!!!!" << endl;
                break;
        }
    }

}