#include "include/baseclassid.hpp"
BaseClassId::BaseClassId()
{
    ID = -1;
    AlreadySetId = 0;
}

BaseClassId::BaseClassId(int Id){
    updateId(Id);
}

int BaseClassId::GetId(){
    return ID;
}

void BaseClassId::SetId(int Id){
    if(AlreadySetId)
        throw "ID already set";
    updateId(Id);
}

void BaseClassId::updateId(int Id){
    if(validateId(Id)){
        this->ID = Id;
        AlreadySetId = true;
    }else{
        throw "ID is not valid";
    }
}

bool BaseClassId::validateId(int Id){
    return (Id>=0);
}
