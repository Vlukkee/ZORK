#pragma once
#include "Entity.h"

enum class ItemType { DEF, KEY, WEAPON, ACHIVEMENT, BULLET };

class Item : public Entity 
{

public:
	Item(string name, string description, ItemType itemType = ItemType::DEF) 
		: Entity(EntityType::ITEM, name, description)
	{
		this->itemType = itemType;
	}
	ItemType GetItemType() const;

private:
	ItemType itemType;
};
