#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
    ofstream outfile("example.txt");
    if (outfile.is_open()){
        outfile<<"hello,file!"<<endl;
        outfile<<"this is line 2."<<endl;
        outfile<<"c++ file handling is easy!"<<endl;
        outfile.close();    
        cout<<"file written successfully!."<<endl;
    }else{
        cout<<"error: could not open file for writing!"<<endl;
    }
    ifstream infile("example.txt");
    if (infile.is_open()){
        string line;
        cout<<"\nfile contents:"<<endl;
        while(getline(infile,line)){
            cout<<line<<endl;
        }
        infile.close();
    }else{
        cout<<"error: could not open file for reading!"<<endl;
    }   
    return 0;
}
