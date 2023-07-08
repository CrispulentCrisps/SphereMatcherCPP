/*
* ///////////////////////////////////
* / This class is for level editing /
* ///////////////////////////////////
*/

#pragma once
#include "SDL.h"
#include "Object.h"
#include "Path.h"

class LevelEditor:
    public Object
{
public:
    bool Editing;
    vector<Path> paths;

    void Editor_Start();
};

