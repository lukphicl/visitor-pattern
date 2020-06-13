#ifndef ENTITY_H
#define ENTITY_H
#include <string>
#include "Visitor.h"

class Entity{
protected:
    string m_name;
    unsigned int m_size;
    Entity(string name, unsigned int size): m_name(name),m_size(size){}
public:
    virtual ~Entity(){};
    
    virtual string getName() const{
        return m_name;
    }
    
    virtual unsigned int getSize() const{
        return m_size;
    }
    
    virtual void print() const=0;
    
    virtual void Accept(Visitor*) = 0;
};

#endif /* ENTITY_H */