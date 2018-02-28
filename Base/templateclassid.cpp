#include "templateclassid.h"
TemplateClassId::TemplateClassId()
{
    ID = -1;
    AlreadySetId = 0;
}

TemplateClassId::TemplateClassId(int Id){
    updateId(Id);
}

int TemplateClassId::GetId(){
    return ID;
}

void TemplateClassId::SetId(int Id){
    if(AlreadySetId)
        throw "ID already set";
    updateId(Id);
}

void TemplateClassId::updateId(int Id){
    if(validateId(Id)){
        this->ID = Id;
        AlreadySetId = true;
    }else{
        throw "ID is not valid";
    }
}

bool TemplateClassId::validateId(int Id){
    return (Id>=0);
}
