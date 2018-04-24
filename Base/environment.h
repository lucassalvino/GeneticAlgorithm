#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H
#include <iostream>
#include <stdio.h>
#include "../MineJsonSuport/jsonobject.h"

class Environment{
private:
    double rateChange;
    double rateCrossOver;
public:
    Environment()
    {
        rateChange = -1;
        rateCrossOver = -1;
    }

    double GetChangeRate()
    {
        if(rateChange < 0)
            throw "the change rate is not set";
        return rateChange;
    }

    double GetCrossOverRate()
    {
        if(rateCrossOver<0)
            throw "The crossOver rate is not set";
        return rateCrossOver;
    }

    void SetChangeRate(double value)
    {
        if(value > 1.0) printf("[WARNING] The change rate is bigger of 100%c.",'%');
        rateChange = value;
        rateCrossOver = 1 - rateChange;
    }

    void SetCrossOverRate(double value)
    {
        if(value > 1.0) printf("[WARNING] The CrossOver rate is bigger of 100%c.",'%');
        rateCrossOver = value;
        rateChange = 1 - rateCrossOver;
    }

    std::string ToStringJson(){
        JsonObject json(std::string("Environment"));
        json.AddDoubleValue("rateChange",rateChange);
        json.AddDoubleValue("rateCrossOver",rateCrossOver);
        return json.GetJsonObject();
    }
};

#endif // ENVIRONMENT_H
