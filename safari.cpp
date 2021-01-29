#include "safari.h"

Safari::Safari(QWidget *par)
    :Game(par)
{

}

void Safari::Load()
{
    Animal *Zoo[16];
    for (int i = 0; i < 16; i++)
    {
        Zoo[i] = new Animal(i, parent);
    }

    int n = 0;
    for (int i = 0; i < 2; i++)
    {
        grass[n++] = new CellGrass(0+68*i, 0, parent);
    }
    for (int i = 0; i < 2; i++)
    {
        grass[n++] = new CellGrass(340+68*i, 0, parent);
    }
    for (int i = 0; i < 3; i++)
    {
        grass[n++] = new CellGrass(0+68*i, 68, parent);
    }
    for (int i = 0; i < 3; i++)
    {
        grass[n++] = new CellGrass(272+68*i, 68, parent);
    }
    for (int i = 0; i < 7; i++)
    {
        grass[n++] = new CellGrass(0+68*i, 136, parent);
    }
    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 3; i++)
        {
            grass[n++] = new CellGrass(0+204*i, 204+68*j, parent);
        }
    }
    for (int i = 0; i < 7; i++)
    {
        grass[n++] = new CellGrass(0+68*i, 408, parent);
    }
    for (int i = 0; i < 3; i++)
    {
        grass[n++] = new CellGrass(0+68*i, 476, parent);
    }
    for (int i = 0; i < 3; i++)
    {
        grass[n++] = new CellGrass(272+68*i, 476, parent);
    }
    for (int i = 0; i < 2; i++)
    {
        grass[n++] = new CellGrass(0+68*i, 544, parent);
    }
    for (int i = 0; i < 2; i++)
    {
        grass[n++] = new CellGrass(340+68*i, 544, parent);
    }

    grass[0]->AddDropRules(1, new RuleGrass());

    int m = 0;
    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 2; i++)
        {
            river[m++] = new CellRiver(68+68*i, 204+68*j, parent);
        }
    }

    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 2; i++)
        {
            river[m++] = new CellRiver(272+68*i, 204+68*j, parent);
        }
    }

    river[0]->AddDropRules(1, new RuleRiver());

    int o = 0;
    red_trap[o++] = new CellRedTrap(136, 0, parent);
    red_trap[o++] = new CellRedTrap(272, 0, parent);
    red_trap[o++] = new CellRedTrap(204, 68, parent);

    red_trap[0]->AddDropRules(1, new RuleRedTrap());

    int p = 0;

    blue_trap[p++] = new CellBlueTrap(204, 476, parent);
    blue_trap[p++] = new CellBlueTrap(136, 544, parent);
    blue_trap[p++] = new CellBlueTrap(272, 544, parent);

    blue_trap[0]->AddDropRules(1, new RuleBlueTrap());

    red_base = new CellRedBase(204, 0, parent);

    red_base->AddDropRules(1, new RuleRedBase());

    blue_base = new CellBlueBase(204, 544, parent);

    blue_base->AddDropRules(1, new RuleBlueBase());

    Zoo[0]->Move(grass[10]);
    Zoo[1]->Move(grass[8]);
    Zoo[2]->Move(grass[5]);
    Zoo[3]->Move(grass[14]);
    Zoo[4]->Move(grass[12]);
    Zoo[5]->Move(grass[3]);
    Zoo[6]->Move(grass[0]);
    Zoo[7]->Move(grass[16]);
    Zoo[8]->Move(grass[32]);
    Zoo[9]->Move(grass[34]);
    Zoo[10]->Move(grass[37]);
    Zoo[11]->Move(grass[28]);
    Zoo[12]->Move(grass[30]);
    Zoo[13]->Move(grass[39]);
    Zoo[14]->Move(grass[42]);
    Zoo[15]->Move(grass[26]);
}
