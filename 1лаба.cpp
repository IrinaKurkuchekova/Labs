// 1лаба.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include "transport.h"
using namespace std;
namespace simple_transport {
    // Сигнатуры требуемых внешних функций
    void Init(container& c);
    void Clear(container& c);
    void In(container& c, ifstream& ifst);
    void Out(container& c, ofstream& ofst);
}
using namespace simple_transport;

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "incorrect command line! "
            "Waited: command infile outfile" << endl;
        exit(1);
    }
    ifstream ifst(argv[1]);
    ofstream ofst(argv[2]);
    cout << "Start" << endl;
    container c;
    Init(c);
    In(c, ifst);
    ofst << "Filled container. " << endl;
    Out(c, ofst);
    Clear(c);
    ofst << "Empty container. " << endl;
    Out(c, ofst);
    cout << "Stop" << endl;
    return 0;
}
