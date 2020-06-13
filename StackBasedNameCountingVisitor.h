#ifndef NAMECOUNTINGVISITOR_H
#define NAMECOUNTINGVISITOR_H
#include "Visitor.h"
#include "Entity.h"
#include <stack>

class StackBasedNameCountingVisitor: public Visitor{
public:
    stack<unsigned int> m_stack;
public:
    StackBasedNameCountingVisitor(){};
    virtual ~StackBasedNameCountingVisitor(){};

    virtual void VisitFile(File* file){
        m_stack.push(file->getName().size());
    }
    
    virtual void VisitDirectory(Directory* dir){
        unsigned int sum = dir->getName().size(); 
        //Visit every children, store state information in m_stack.
        for(int i=0; i< dir->getChildrenSize(); i++){
            dir->getChild(i)->Accept(this);
        }
        //Get state information from m_stack, do calculation.
        for( int i=0; i<dir->getChildrenSize(); i++ ){
            sum += m_stack.top();
            m_stack.pop();
        }		
        //Store state information in m_stack.
        m_stack.push(sum);	
    };
        
    double getValue() {
        unsigned int result =m_stack.top();
        m_stack.pop();
        return result;
    }

private:
    StackBasedNameCountingVisitor(const StackBasedNameCountingVisitor& orig){};
};

#endif /* NAMECOUNTINGVISITOR_H */

