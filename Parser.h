#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

class Parser
{
    public:
        Parser(string str);
        ~Parser();
        vector<int> v, w;
        int get_N();
        int get_max_weight();
        vector<int> get_v();
        vector<int> get_w();
        void Parse();

    protected:

    private:
        string filename;
        fstream f_in;
        int N=0;
        int max_weight;
};

#endif // PARSER_H
