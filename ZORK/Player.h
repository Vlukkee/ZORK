#include "Global.h"
#include "Creature.h"
#include "Exit.h"
#include "Enemy.h"
#include "Achievements.h"
#include "Item.h"

class Player : public Creature 
{

public:
	Player(string name, string description, Room* location) 
		: Creature(EntityType::PLAYER, name, description, location) 
	{ 
		this->holdingItem = nullptr;
	}

	void DescribePath();
	void Inventory();
	Item* GetHoldingItem() const;
	void SetHoldingItem(Item* item);
	void Look(const string& str);
	void Go(const string& str);
	void Take(const string& str);
	void Drop(const string& str);
	void Equip(const string& str);
	void Unequip(const string& str);
	bool Attack(const string& str);
	void InsertItem(const string& str, const string& str2);
	void Unlock(const string& str);
	void GetAchievement();
	void ShowAchievements();

private:
	Exit* ExitPath(const Path& dir) const;
	Exit* ExitPath(const string& str) const;
	template <class T>
	T* GetEntityName(const string& name, const list<Entity*>& entities, const EntityType type) const;
	Item* GetTypeItem(ItemType type) const;
	Enemy* GetEnemyFromCurrentRoom() const;
	Item* holdingItem;
};
