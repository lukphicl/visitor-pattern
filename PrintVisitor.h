#ifndef PRINTVISITOR_H
#define PRINTVISITOR_H
#include "Visitor.h"
#include "File.h"
#include "Directory.h"

class PrintVisitor: public Visitor{
public:
    PrintVisitor(){};
    
    virtual ~PrintVisitor(){};
    
    virtual void VisitFile(File* file){
        cout<<"(file name="<<file->getName()<<", file size="<<file->getSize()<<"); ";
    }
    
    virtual void VisitDirectory(Directory* dir){
        cout<<"Directory "<<dir->getName()<<" contains: (";
        for(int i=0; i<dir->getChildrenSize(); i++){
            dir->getChild(i)->Accept(this);
        }
        cout<<"); ";
    }
    
};
#endif /* PRINTVISITOR_H */

