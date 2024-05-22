#include<iostream>
#include "Parser.h"
#include "Solver.h"

int main(){
    Parser parser("ks_4_0");
    parser.Parse();

    Solver solver(&parser);
    return 0;
}
