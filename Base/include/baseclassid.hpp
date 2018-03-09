#ifndef BASECLASSID_HPP
#define BASECLASSID_HPP
class BaseClassId
{
public:
    BaseClassId();
    BaseClassId(int Id);
    int GetId();
    void SetId(int Id);
protected:
    int ID;
    bool validateId(int Id);
private:
    bool AlreadySetId;
    void updateId(int id);
};
#endif // BASECLASSID_HPP
