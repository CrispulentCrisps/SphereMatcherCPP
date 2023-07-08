/*
* //////////////////////////////////////////////////////////////////
* / This class is for the bezier control knobs in the level editor /
* //////////////////////////////////////////////////////////////////
*/
#pragma once
#include "Object.h"
class Knob :
    public Object
{
public:
    int CurveFollow;
    
    virtual void UpdateObject(int x, int y);
};