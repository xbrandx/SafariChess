#include "rule.h"

bool RuleRiver::Enforce(Cell *c, Animal *a)
{
    return a->Pieces()==MOUSE;
}
