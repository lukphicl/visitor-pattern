#ifndef STACKBASEDNAMECOUNTINGVISITOR_H
#define STACKBASEDNAMECOUNTINGVISITOR_H
#include "Visitor.h"
#include "Entity.h"

class NonStackBasedNameCountingVisitor: public Visitor{
protected:
    unsigned int sum;
public:
    NonStackBasedNameCountingVisitor(){
        sum=0;
    };
    virtual ~NonStackBasedNameCountingVisitor(){};
    
    virtual void VisitFile(File* file){
        sum+=file->getName().size();
    }
    
    virtual void VisitDirectory(Directory* dir){
        sum += dir->getName().size(); 
        //Visit every children, store state information in m_stack.
        for(int i=0; i< dir->getChildrenSize(); i++){
            dir->getChild(i)->Accept(this);
        }	
    };
        
    double getValue() {
        unsigned int result =sum;
        sum=0;
        return result;
    }
    
private:
    NonStackBasedNameCountingVisitor(const NonStackBasedNameCountingVisitor& orig){};
};

#endif /* STACKBASEDNAMECOUNTINGVISITOR_H */