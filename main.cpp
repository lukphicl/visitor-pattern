#include <cstdlib>
using namespace std;
#include <iostream>
#include "File.h"
#include "Directory.h"
#include "PrintVisitor.h"
#include "StackBasedNameCountingVisitor.h"
#include "NonStackBasedNameCountingVisitor.h"

//What does this project do again? I forgot already

int main(int argc, char** argv) {
    File f1("f1.txt", 100);
    File f2("f2.txt", 80);
    Directory d1("d1");
    d1.addEntity(&f1);
    d1.addEntity(&f2);
  
    File f3("f3.txt", 20);
    File f4("f4.txt", 30);
    File f5("f5.txt", 40);
    Directory d2("d2");
    d2.addEntity(&f3);
    d2.addEntity(&f4);
    d2.addEntity(&f5);
    
    Directory d3("d3");
    d3.addEntity(&d1);
    d3.addEntity(&d2);
    
    cout<<"Print Operation: ==================="<<endl;
    d3.print();
    
    cout<<endl<<"Print Visitor: ==================="<<endl;
    PrintVisitor pv;
    d3.Accept(&pv);
    
    cout<<endl<<"Stack Based Name Counting Visitor: ==================="<<endl;
    StackBasedNameCountingVisitor sbncv;
    d3.Accept(&sbncv);
    cout<<sbncv.getValue()<<endl;
    
    cout<<endl<<"Non-Stack Based Name Counting Visitor: ==================="<<endl;
    NonStackBasedNameCountingVisitor nsbncv;
    d3.Accept(&nsbncv);
    cout<<nsbncv.getValue()<<endl;
    
    return 0;
}

