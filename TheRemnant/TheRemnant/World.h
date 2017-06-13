#pragma once
#include <string>
#include <vector>
#include <map>
#define MAPSIZE 128
namespace rpg {
	class Room;
	class Entity;
	class World
	{
	public:
		friend class EventHandler;
		World(std::string pWorldFilename);
		~World();
		std::map<std::string, Texture*> worldTextures;
	protected:
		bool isValid(int px, int py);
		std::vector<Entity*> allEntitiesAtPosition(int px, int py);
		std::vector<Entity*> allEntitiesWithinRadius(int px, int py, int radius);
		Entity* entityWithId(int id);
		void spawn(Entity& newEntity);
		std::string worldFilename;
		std::string worldGameName;
	private:
		std::vector<Entity*> entitiesInWorld;
		Room* worldRooms[MAPSIZE][MAPSIZE];
		
	};
}
