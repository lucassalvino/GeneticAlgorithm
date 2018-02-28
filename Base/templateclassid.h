#ifndef TEMPLATECLASSID_H
#define TEMPLATECLASSID_H
class TemplateClassId
{
public:
    TemplateClassId();
    TemplateClassId(int Id);
    int GetId();
    void SetId(int Id);
protected:
    int ID;
    bool validateId(int Id);
private:
    bool AlreadySetId;
    void updateId(int id);
};
#endif // TEMPLATECLASSID_H
