#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include "Parser.h"

using namespace std;

Parser::Parser(string str){
    filename=str;
    f_in.open(filename);
    string s;
    getline(f_in,s,' ');
    N=stoi(s);
    getline(f_in,s,'\n');
    max_weight=stoi(s);
    f_in.clear();
}

Parser::~Parser(){
    filename.clear();
    f_in.close();
    N=0;
    max_weight=0;
    v.clear();
    w.clear();
}

vector<int> Parser::get_v() {return v;}
vector<int> Parser::get_w() {return w;}
int Parser::get_N() {return N;}
int Parser::get_max_weight() {return max_weight;}

void Parser::Parse(){
    vector<int> x,y;
    string a,b;
    char div=' ';
    for(int i=0;i<N;i++){
        getline(f_in,a,div);
        getline(f_in,b,'\n');
        x.push_back(stod(a));
        y.push_back(stod(b));
    }
    v=x;
    w=y;
    return;
}
