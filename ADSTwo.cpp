#include "ADSTwo.h"
void sortPriority(vector<Data> datas){
    vector <Data> p1;
    vector <Data> p2;
    vector <Data> p3;
    for (int i = 0; i < datas.size(); ++i) {
        if      (datas.at(i).getPriority() == 1)
            p1.push_back(datas.at(i));
        else if (datas.at(i).getPriority() == 2)
            p2.push_back(datas.at(i));
        else
            p3.push_back(datas.at(i));
    }
    for (int l = 0; l < p3.size(); ++l)
        p3.at(l).print();

    for (int k = 0; k < p2.size(); ++k)
        p2.at(k).print();

    for (int j = 0; j < p1.size(); ++j)
        p1.at(j).print();

}
bool searchPort(int port,vector <Data> datas){
    for (int i = 0; i < datas.size(); ++i)
        if (datas.at(i).getPort() == port) return true;

    return false;
}
void swap1(vector<int> &v, int x, int y) {
    int temp = v[x];
    v[x] = v[y];
    v[y] = temp;
}
void swap1(vector<Data> &v , int x,int y){
    Data temp = v[x];
    v[x] = v[y];
    v[y] = temp;
}
void quicksort1(vector<int> &vec,vector<Data> &port, int L, int R) {
    int i, j, mid, piv;
    i = L;
    j = R;
    mid = L + (R - L) / 2;
    piv = vec[mid];
    Data ip_piv=port[mid];

    while (i<R || j>L) {
        while (vec[i] < piv)
            i++;
        while (vec[j] > piv)
            j--;

        if (i <= j) {
            swap1(vec, i, j);
            swap1(port , i, j);
            i++;
            j--;
        }
        else {
            if (i < R)
                quicksort1(vec, port, i, R);
            if (j > L)
                quicksort1(vec, port, L, j);
            return;
        }
    }
}
void port(vector <Data> datas){
    vector<Data> ports;
    vector<int> poetSrcCounter;
    bool exist=true;
    for (int i = 0; i < datas.size(); ++i) {
        exist=true;
        for (int j = 0; j < ports.size(); ++j) {
            if (ports.at(j).getPort() == datas.at(i).getPort()) {
                poetSrcCounter.at(j)++;
                exist = false;
            }
        }
        if (exist){
            ports.push_back(datas.at(i));
            poetSrcCounter.push_back(1);
        }
    }
    quicksort1(poetSrcCounter,ports,0,poetSrcCounter.size()-1);
    for (int k = 0; k < poetSrcCounter.size(); ++k) {
        cout<<"counter ============>" << poetSrcCounter.at(k)<<endl;
        ports.at(k).print();
    }
}
void ADSTwo::alert(vector<Data> datas) {

    int choosse=1;
    string ports;
    int m;
    while(choosse) {
        cout<<"enter the option   "<<endl;
        cout<<"1_port 2_searchPort"<<endl;
        cout<<"3_priority 4_exit  "<<endl;
        cin>>choosse;
        switch (choosse){
            case 1:
                port(datas);
                break;
            case 2:
                cout << "enter the port number";
                cin >> m;
                if(searchPort(m,datas))
                    cout<<"exist !!!"<<endl;
                else
                    cout<<"Dosent exist :("<<endl;
                break;
            case 3:
                sortPriority(datas);
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