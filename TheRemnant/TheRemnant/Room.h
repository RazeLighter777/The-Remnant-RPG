#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>
using namespace sf;
namespace rpg {
	enum roomTypes {
		tDefaultRoom,
		tKillRoom,
		tWallRoom
	};
	class RoomType;
	class Entity;
	class Room
	{
	public:
		Room(std::ifstream& i);
		~Room();
		void draw(RenderWindow& w);
		void applyEffects(std::vector<Entity*> entities);
		bool isSolid();
	protected:
		Sprite roomSprite;
		int x, y;
		bool solid = 0;
	};
}
