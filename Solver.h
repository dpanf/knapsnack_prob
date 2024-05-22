#ifndef SOLVER_H
#define SOLVER_H

#include "Parser.h"
#include <iostream>
#include<algorithm>
#include<vector>

class Solver
{
    public:
        Solver(Parser *parser,int n=100);
        ~Solver();
        vector<vector<int>> X,Y;
        int select(Parser* parser,int i,int j)
        void mutate(Parser* parser,vector<int> arr)
        void cross(Parser* parser,int x,int y)
        int fit(Parser* parser,vector<int> ar)

    protected:

    private:
        Parser *parser;
};

#endif // SOLVER_H
