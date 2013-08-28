#ifndef _ITEM_FACTORY_H_
#define _ITEM_FACTORY_H_

#include "game.h"
#include "item.h"

class item_factory
{
public:
    item_factory();
    void init();
    void init(game* main_game);
};

#endif
