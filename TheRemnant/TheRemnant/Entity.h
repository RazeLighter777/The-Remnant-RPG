#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <fstream>
using namespace sf;
class EventHandler;
class EventObj;
namespace rpg {
	enum entityTypes {
		tEntity,
		tBasicFootMob,
		tEntitySpawner,
		tPlayer,
		tNpc
	};
	class Entity
	{
	public:
		Entity();
		Entity(std::ifstream& f, std::vector<Texture*>& textures) {}; //This loads the entity from a file.
		Entity(std::string pName, int pInstanceNum, EventHandler& e, std::vector<Texture*>& textures, int px, int py);
		std::string getName();
		void save(std::ofstream& o); //This saves the entity to the world
		void draw(RenderWindow& w);
		int getInstanceNum();
		int getX();
		int getY();
		void passEvent(EventObj&);
		~Entity();
	protected:
		entityTypes type;
		std::string entityName;
		int x, y;
		int instanceNum;
		EventHandler* handler;
		Sprite entitySprite;
	};

}