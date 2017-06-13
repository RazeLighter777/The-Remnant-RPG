#include "stdafx.h"
#include "World.h"
#include "Room.h"
#include "Entity.h"
#include <fstream>
#include <iostream>
using namespace rpg;
World::World(std::string pWorldFilename)
{
	worldFilename = pWorldFilename;
	std::ifstream file(worldFilename);
	std::getline(file, worldGameName); // Get the name of the world that appears ingame.
	std::string input, input2;
	Texture* t_ptr;
	//This Portion of code loads all of the textures for ingame usage.
	while (input != "END_TEXTURE_PORTION") {
		file >> input;
		if (input == "END_TEXTURE_PORTION") {
			break;
		}
		file >> input2;
		t_ptr = new Texture();
		t_ptr->loadFromFile(input2);
		worldTextures[input] = t_ptr;
	}
	
	//This Portion of code loads all the entities
	//NOTE: To add a new entity to the save/load, you must add it to this list.
	entityTypes etype;
	while (input != "END_ENTITY_PORTION") {
		file >> input;
		if (input == "END_ENTITY_PORTION") {
			break;
		}
		if (input == "tEntity") {
			spawn(*new Entity(file, worldTextures));
		}
	}
	//This portion of code loads all of the rooms

}


World::~World()
{
}
