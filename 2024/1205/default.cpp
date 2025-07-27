#include<fstream>
#include<iostream>
#include<random>
#include<ctime>
#include<cstring>
#include<vector>
#include<utility>
#include<set>
using namespace std;
const int N = 15;
#define ll long long

void open_input(ofstream &fout, int t_case) {
    string dir_path = "../data/secret/";
    string file_name = to_string(t_case) + ".in";
    string input_path = dir_path + file_name;
    fout.open(input_path, ios::out | ios::trunc);
    if(!fout) {
        cerr << "cannot open file" << input_path << endl;
        exit(1);
    }
}

default_random_engine gen(time(NULL));
uniform_int_distribution<int> unif(0, 2147483647);

void make_input(ofstream &fout, int t_case) {
    int n;
    if(t_case == 1){
        fout << "500000 500000\n";
        for(int i = 1; i <= 499900; i++){
            fout << i << " ";
        }
        for(int i = 499901; i <= 500000; i++){
            fout << 1;
            if(i != 500000) fout << " ";
        }
        fout << "\n";
    }
    else{
        int n = unif(gen) % 500000;
        int q = unif(gen) % n + 1;
        fout << n << " " << q << "\n";
        for(int i = 0; i < n; i++){
            int k = unif(gen) % 1000000000 + 1;
            fout << k;
            if(i != n - 1) fout << " ";
        }
        fout << "\n";
    }
}
void close_input(ofstream &fout, int t_case) {
    fout.close();
}
int main() {
    for(int i = 1; i <= N; i++) {
        ofstream fout;
        open_input(fout, i);
        make_input(fout, i);
        close_input(fout, i);
    }
    return 0;
}