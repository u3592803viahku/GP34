/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;
#include <stdlib.h>
//#include "other.h"
#include <bits/stdc++.h>
#include <fstream>

string convertToString(char* a, int size)
{
    int i;
    string s = "";
    for (i = 0; i < size; i++) {
        if(a[i]!='x'){
            s = s + a[i];
        }
        
    }
    return s;
}

void save(int** arr,string filename){

  ofstream out(filename);
    if (! out) {
        cout << "cantopenfile" << endl; 
        
    }    
    for(int r = 0; r < 5; r++) {  
        for(int c = 0; c < 5; c++){
            out<<arr[r][c]<<" ";
        }
        out << "\n";
    }
    out.close();
}

void read(int** arr,string filename){
    ifstream op(filename);
    if (! op) {
        cout << "cantopenfile" << endl; 

    }    
    for(int row = 0; row < 5; row++) {  // stop loops if nothing to read
        for(int column = 0; column < 5; column++){
            op >>arr[row][column];
            if ( ! op ) {
                cout << "cantopenfile "; 

            }
        }
    }
    op.close();
    for(int i=0; i<5; i++){
        for(int in=0; in<5; in++){
            cout << arr[i][in] << " ";
        }
        cout<<endl;
    }
}
void Init_2D_Array(int*** arr, int x)
{

  *arr = new int*[x]; 
  for (int i=0;i<x;i++)
  {
      (*arr)[i] = new int[x];
  }
}
void Insert_into_2D_Array(int** arr, int x, int y, int size,int value)
{
  if (x < size && y < size) {
    arr[x][y] = value;
  }
}
void getrandonm(int size,int** arr){
    srand (time(NULL));
    int a = rand() % 2;
    for(int i = 0; i<size;i++){
            for(int in = 0; in<size ; in++){
                a = rand() % 2;
                if(a<1){
                    Insert_into_2D_Array(arr, i,in,size,0 ); 
                }
                else{
                    Insert_into_2D_Array(arr, i,in,size,1 ); 
                }
            }
    }
    
}
void MyFunc(int** arr,int size) {
    for(int i = 0; i<size;i++){
            for(int in = 0; in<size ; in++){
                cout <<arr[i][in]<<" ";
            }
            cout <<endl;
    }
    
}
void rowcollum(int** arr,int size,int** attempt){
    int a =size/2+1;
    int rowar[a];
    int columnar[a];
    int rowarrnum =0;
    int colarrnum =0;
    string row[size];
    string column[size];
    for(int integ = 0 ; integ < a ; integ ++ ){
            rowar[integ]=0;
            columnar[integ]=0;
        }
    for(int i =0 ; i<size ; i++){
        rowarrnum =0;
        colarrnum =0;
        for(int in = 0 ; in<size; in++){
                if(arr[i][in]==0){
                    if(in!=0&&arr[i][in-1]==1) {
                        rowarrnum++;

                    }

                }
                else if(arr[i][in]==1){

                    //ctoi = rowar[rowarrnum];
                    //ctoi++;
                    rowar[rowarrnum]++;

                }
                if(arr[in][i]==0){
                    if(in!=0&&arr[in-1][i]==1) {
                        colarrnum++;
                    }

                }
                else if(arr[in][i]==1){

                    //ctoi = columnar[colarrnum];
                    //ctoi++;
                    columnar[colarrnum]++;
                }
        }
        rowarrnum++;
        colarrnum++;
        char sa[colarrnum];
        int intege = 0;
        for(int iinte = 0 ; iinte<=colarrnum ; iinte++){
                if(columnar[iinte]==0){
                    sa[intege]='x';
                    //.print(0);
                }
                else if(columnar[iinte]==1){
                    sa[intege]='1';
                    intege++;
                    //print(1);
                }
                else if(columnar[iinte]==2){
                    sa[intege]='2';
                    intege++;
                    //print(2);
                }
                else if(columnar[iinte]==3){
                    sa[intege]='3';
                    intege++;
                    //print(3);
                }
                else if(columnar[iinte]==4){
                    sa[intege]='4';
                    //print(4);
                    intege++;
                }
                else if(columnar[iinte]==5) {
                    sa[intege] = '5';
                    intege++;
                    //print(5);
                }
        }
        intege = 0;
        string sth = convertToString(sa,colarrnum);
        column[i]=sth;
        char sac[rowarrnum+1];
        int integ = 0;
        for(int iinte = 0 ; iinte<=rowarrnum ; iinte++){
                if(rowar[iinte]==0){
                    sac[iinte]='x';
                    //print(0);
                }
                else if(rowar[iinte]==1){
                    sac[integ]='1';
                    integ++;
                    //print(1);
                }
                else if(rowar[iinte]==2){
                    sac[integ]='2';
                    integ++;
                    //print(2);
                }
                else if(rowar[iinte]==3){
                    sac[integ]='3';
                    integ++;
                    //print(3);
                }
                else if(rowar[iinte]==4){
                    sac[integ]='4';
                    integ++;
                    //print(4);
                }
                else if(rowar[iinte]==5){
                    sac[integ]='5';
                    integ++;
                    //print(5);
                }
            }
        integ = 0;
        string sthc = convertToString(sac,rowarrnum);
        row[i]=sthc;
        std::fill_n(rowar, a, 0);
        std::fill_n(columnar, a, 0);
    }
    cout << setw(11) <<"|";
    for(int i =0 ; i<size;i++){
        cout << setw(4) <<column[i] <<"|";
    }
    cout<<endl;
    cout <<"_______________________________________"<<endl;
    for(int i =0 ; i<size;i++){
        cout<< setw(10)  <<row[i]<<"|";
        for(int in =0 ; in<size;in++){
            cout<< setw(4)  <<attempt[i][in]<<"|";
        }
        cout <<endl;
        cout <<"_______________________________________"<<endl;
    }
    /*
    string rowcolumn[size*2];
    for (int i =0 ; i<size;i++){
        rowcolumn[i]=column[i];
    }
    for (int i =0 ; i<size;i++){
        rowcolumn[i+size]=row[i];
    }*/

}
void printinst(string name){
    fstream newfile;
    newfile.open(name,ios::in);
    string tp;
    while(getline(newfile, tp)){
         cout << tp << endl;
      }
      newfile.close();
}
void printeachattempt(){
    cout<< setw(15)<<"your turn,you may:"<<endl;
    cout<<"1:quit the game by typing q"<<endl;
    cout<<"2:change value in table by typing v"<<endl;
    cout<<"3:view instruction by typing i"<<endl;
    cout<<"4:view answer by typing a"<<endl;
    cout<<"5:check answer by typing c"<<endl;
    cout<<"6:save your progress by typing s"<<endl;
}
string * getrow(int size,int** arrr  ) {
    //static string  r[5];
    string* r = new string[5];
    int a =size/2+1;
    int rowar[a];
    int columnar[a];
    int rowarrnum =0;
    int colarrnum =0;
    string column[size];
    for(int integ = 0 ; integ < a ; integ ++ ){
            rowar[integ]=0;
            columnar[integ]=0;
        }
    for(int i =0 ; i<size ; i++){
        rowarrnum =0;
        colarrnum =0;
        for(int in = 0 ; in<size; in++){
                if(arrr[i][in]==0){
                    if(in!=0&&arrr[i][in-1]==1) {
                        rowarrnum++;

                    }

                }
                else if(arrr[i][in]==1){

                    //ctoi = rowar[rowarrnum];
                    //ctoi++;
                    rowar[rowarrnum]++;

                }
                if(arrr[in][i]==0){
                    if(in!=0&&arrr[in-1][i]==1) {
                        colarrnum++;
                    }

                }
                else if(arrr[in][i]==1){

                    //ctoi = columnar[colarrnum];
                    //ctoi++;
                    columnar[colarrnum]++;
                }
        }
        rowarrnum++;
        colarrnum++;
        char sa[colarrnum];
        int intege = 0;
        for(int iinte = 0 ; iinte<=colarrnum ; iinte++){
                if(columnar[iinte]==0){
                    sa[intege]='x';
                    //.print(0);
                }
                else if(columnar[iinte]==1){
                    sa[intege]='1';
                    intege++;
                    //print(1);
                }
                else if(columnar[iinte]==2){
                    sa[intege]='2';
                    intege++;
                    //print(2);
                }
                else if(columnar[iinte]==3){
                    sa[intege]='3';
                    intege++;
                    //print(3);
                }
                else if(columnar[iinte]==4){
                    sa[intege]='4';
                    //print(4);
                    intege++;
                }
                else if(columnar[iinte]==5) {
                    sa[intege] = '5';
                    intege++;
                    //print(5);
                }
        }
        intege = 0;
        string sth = convertToString(sa,colarrnum);
        column[i]=sth;
        char sac[rowarrnum+1];
        int integ = 0;
        for(int iinte = 0 ; iinte<=rowarrnum ; iinte++){
                if(rowar[iinte]==0){
                    sac[iinte]='x';
                    //print(0);
                }
                else if(rowar[iinte]==1){
                    sac[integ]='1';
                    integ++;
                    //print(1);
                }
                else if(rowar[iinte]==2){
                    sac[integ]='2';
                    integ++;
                    //print(2);
                }
                else if(rowar[iinte]==3){
                    sac[integ]='3';
                    integ++;
                    //print(3);
                }
                else if(rowar[iinte]==4){
                    sac[integ]='4';
                    integ++;
                    //print(4);
                }
                else if(rowar[iinte]==5){
                    sac[integ]='5';
                    integ++;
                    //print(5);
                }
            }
        integ = 0;
        string sthc = convertToString(sac,rowarrnum);
        r[i]=sthc;
        std::fill_n(rowar, a, 0);
        std::fill_n(columnar, a, 0);
    }/*
    cout << setw(11) <<"|";
    for(int i =0 ; i<size;i++){
        cout << setw(4) <<column[i] <<"|";
    }
    cout<<endl;
    /cout <<"_______________________________________"<<endl;
    for(int i =0 ; i<size;i++){
        cout<< setw(10)  <<r[i]<<"*|";
        for(int in =0 ; in<size;in++){
            cout<< setw(4)  <<arrr[i][in]<<"|";
        }
        cout <<endl;
        cout <<"_______________________________________"<<endl;
    }
    for(int i =0 ; i<size;i++){
        cout<< setw(10)  <<r[i]<<"*|";
        cout <<endl;
    }*/
   return r;
}
string * getcolumn(int size,int** arr ) {

    string* c = new string[5];
    int a =size/2+1;
    int rowar[a];
    int columnar[a];
    int rowarrnum =0;
    int colarrnum =0;
    string row[size];
    for(int integ = 0 ; integ < a ; integ ++ ){
            rowar[integ]=0;
            columnar[integ]=0;
        }
    for(int i =0 ; i<size ; i++){
        rowarrnum =0;
        colarrnum =0;
        for(int in = 0 ; in<size; in++){
                if(arr[i][in]==0){
                    if(in!=0&&arr[i][in-1]==1) {
                        rowarrnum++;

                    }

                }
                else if(arr[i][in]==1){

                    //ctoi = rowar[rowarrnum];
                    //ctoi++;
                    rowar[rowarrnum]++;

                }
                if(arr[in][i]==0){
                    if(in!=0&&arr[in-1][i]==1) {
                        colarrnum++;
                    }

                }
                else if(arr[in][i]==1){

                    //ctoi = columnar[colarrnum];
                    //ctoi++;
                    columnar[colarrnum]++;
                }
        }
        rowarrnum++;
        colarrnum++;
        char sa[colarrnum];
        int intege = 0;
        for(int iinte = 0 ; iinte<=colarrnum ; iinte++){
                if(columnar[iinte]==0){
                    sa[intege]='x';
                    //.print(0);
                }
                else if(columnar[iinte]==1){
                    sa[intege]='1';
                    intege++;
                    //print(1);
                }
                else if(columnar[iinte]==2){
                    sa[intege]='2';
                    intege++;
                    //print(2);
                }
                else if(columnar[iinte]==3){
                    sa[intege]='3';
                    intege++;
                    //print(3);
                }
                else if(columnar[iinte]==4){
                    sa[intege]='4';
                    //print(4);
                    intege++;
                }
                else if(columnar[iinte]==5) {
                    sa[intege] = '5';
                    intege++;
                    //print(5);
                }
        }
        intege = 0;
        string sth = convertToString(sa,colarrnum);
        c[i]=sth;
        char sac[rowarrnum+1];
        int integ = 0;
        for(int iinte = 0 ; iinte<=rowarrnum ; iinte++){
                if(rowar[iinte]==0){
                    sac[iinte]='x';
                    //print(0);
                }
                else if(rowar[iinte]==1){
                    sac[integ]='1';
                    integ++;
                    //print(1);
                }
                else if(rowar[iinte]==2){
                    sac[integ]='2';
                    integ++;
                    //print(2);
                }
                else if(rowar[iinte]==3){
                    sac[integ]='3';
                    integ++;
                    //print(3);
                }
                else if(rowar[iinte]==4){
                    sac[integ]='4';
                    integ++;
                    //print(4);
                }
                else if(rowar[iinte]==5){
                    sac[integ]='5';
                    integ++;
                    //print(5);
                }
            }
        integ = 0;
        string sthc = convertToString(sac,rowarrnum);
        row[i]=sthc;
        std::fill_n(rowar, a, 0);
        std::fill_n(columnar, a, 0);
    }
    /*
    cout << setw(11) <<"|";
    for(int i =0 ; i<size;i++){
        cout << setw(4) <<c[i] <<"*|";
    }
    cout<<endl;
    cout <<"_______________________________________"<<endl;
    for(int i =0 ; i<size;i++){
        cout<< setw(10)  <<row[i]<<"|";
        for(int in =0 ; in<size;in++){
            cout<< setw(4)  <<arr[i][in]<<"|";
        }
        cout <<endl;
        cout <<"_______________________________________"<<endl;
    }

    */

   return c;
}

bool check(int** arr,int size,int** attempt){
    string *r;
    int co =1;
    r = getrow(5,arr);
    string *rattempt;
    rattempt =getrow(5,attempt);
    for(int i = 0 ; i<5; i++){
        //cout<<r[i]<<"|"<<rattempt[i]<<endl;
        if(r[i]!=rattempt[i]){
            co= 0;
            //cout <<"false";
        }
    }
    string *c;

    c = getcolumn(5,arr);
    string *cattempt;
    cattempt =getcolumn(5,attempt);
    for(int i = 0 ; i<5; i++){
        //cout<<c[i]<<"|"<<cattempt[i]<<endl;
        if(c[i]!=cattempt[i]){
            co= 0;
            //cout <<"false";
        }
    }
    if(co==0){
        return false;
    }
    else{
        return true;
    }
    
}
int main() {
    cout<<"welcome to nonogram game"<<endl;
    printinst("instruction.txt");
    int** arr=NULL;
    int x =5;
    Init_2D_Array(&arr, x); 
    getrandonm(x,arr);
    //MyFunc(arr,x);
    int** attempt=NULL;
    Init_2D_Array(&attempt, x);
    for(int i = 0; i<x;i++){
        for(int in = 0; in<x ; in++){
            attempt[i][in]=0;
        }
    }
    cout<<"resume game or not(y/n)"<<endl;
    string xx;
    cin>>xx;
    if(xx=="y"){
        read(arr,"answer.txt");
        read(attempt,"try.txt");
    }
    rowcollum(arr,x,attempt);
    string inpu="x";
    while(inpu!="q"){
        printeachattempt();
        cin>>inpu;
        if(inpu=="q"){
            cout<<"byebye";
        }
        else if (inpu=="i"){
            printinst("instruction.txt");
        }
        else if (inpu=="a"){
            MyFunc(arr,x);
        }
        else if (inpu=="c"){
            bool result;
            result=check(attempt,5,arr);
            if(result){
                cout<<"TRUE"<<endl;
                cout<<"congraduations"<<endl;
                break;
            }
            else{
                cout<<"false,please try again"<<endl;
            }
        }
        else if (inpu=="v"){
            cout<<"row?(0-4)"<<endl;
            int ro;
            cin>>ro;
            cout<<"column?(0-4)"<<endl;
            int co;
            cin>>co;
            //cout<<attempt[ro][co]<<endl;
            if(attempt[ro][co]<1){
                attempt[ro][co]=1;
                //cout<<attempt[ro][co]<<endl;
            }
            else{
                attempt[ro][co]=0;
                //cout<<attempt[ro][co]<<endl;

            }
            rowcollum(arr,x,attempt);
        }
        else if(inpu=="s"){
            save(arr,"answer.txt");
            save(attempt,"try.txt");
        }
    }
    
}
