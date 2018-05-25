//
// Created by lerest_m on 14/06/17.
//

#include "Debug.hpp"

bool Debug::debug = false;

void Debug::setDebug(bool debugValue)
{
    debug = debugValue;
}

bool &Debug::isDebug()
{
    return (debug);
}
