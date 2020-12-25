#include "rule.h"
#include "animal.h"
#include "cell.h"

bool RuleRiver::Enforce(Cell *c, Animal *a)
{
    return a->Pieces()==MOUSE;
}
