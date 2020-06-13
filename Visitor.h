#ifndef VISITOR_H
#define VISITOR_H
class File;
class Directory;

class Visitor{
public:
    Visitor(){};
    virtual ~Visitor(){};
    virtual void VisitFile(File*)=0;
    virtual void VisitDirectory(Directory*)=0;    
};

#endif /* VISITOR_H */

