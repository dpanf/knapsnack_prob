#include "Parser.cpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include "Solver.h"
#include "Parser.h"

using namespace std;

void Solver::mutate(Parser* parser,vector<int> arr){
    int N=parser.get_N();
    int i=rand()%N;
    arr[i]=0;
    return;
}

int Solver::select(Parser* parser,int i,int j){
    int N=parser.get_N();
    if(X[i][N]<=X[j][N])
        return j;
    return i;
}

int Solver::fit(Parser* parser,vector<int> ar){
    int i,val=0,weight=0,N=parser.get_N(),mw=parser.get_max_weight();
    for(i=0;i<N;i++)
        weight=weight+(parser.get_w())[i]*arr[i];
    if (weight<=mw){
        for(i=0;i<N;i++)
            val=val+(parser.get_v())[i]*arr[i];
        return val;
    }
    return 0;
}

void Solver::cross(Parser* parser,int x,int y) {
    vector<int> arr1, arr2;
    int N=parser.get_N(),i;
    for(int i=0;i<N;i++) {
        arr1.push_back(X[x][i]);
        arr2.push_back(X[y][i]);
    }
    mutate(parser,arr1);
    mutate(parser,arr2);
    Y.push_back(arr1.push_back(fit(parser,arr1)));
    Y.push_back(arr2.push_back(fit(parser,arr2)));
    return;
}

Solver::Solver(Parser* parser,int n){
    int r,i,j,d,N=parser.get_N(),x,y,a,b,maxx=0,l=0,mw=parser.get_max_weight();
    for(r=0;r<10000;r++){
        srand(time(0));
        for(i=0;i<n;i++){
            vector<int> arr; d=0;
            for(j=0;j<N;j++){
                d=rand()%100;
                if(d>25)
                    arr.push_back(0);
                else arr.push_back(1);
            }
            X.push_back(arr.push_back(fit(parser,arr)));
        }
        for(i=0;i<n/2;i++){
            x=y=0;
            while(x==y){
                x=rand()%n;
                y=rand()%n;
            }
            a=select(parser,x,y);
            x=y=0;
            while(x==y){
                x=rand()%n;
                y=rand()%n;
            }
            b=select(parser,x,y);
            cross(parser,a,b);
        }
        for(i=0;i<n;i++)
            for(j=0;j<=N;j++)
                X[i][j]=Y[i][j];
    }
    for(i=1;i<n;i++)
        if(X[maxx][N]<X[i][N])
            maxx=i;
    for(i=0;i<N;i++)
        l=l+X[maxx][i]*((parser.get_w)[i]);
    cout<<X[maxx][N]<<" "<<mw-l<<endl;
    for(i=0;i<N;i++)
        cout<<X[maxx][i]<<" ";
}

Solver::~Solver(){
    X.clear();
    Y.clear();
}
