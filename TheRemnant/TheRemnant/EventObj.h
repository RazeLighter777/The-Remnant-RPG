#pragma once
#include <string>
#include <sstream>
#include <vector>
namespace rpg {
	class Entity;
	enum eventType {
		eAttacke, //Entity attacks entity
		eIsAt, //Specifies the position of an entity
		eTalk, //Specifies that an entity talks
		eInteracte //Entity interacts with entity
	};
	class EventObj
	{
	public:
		EventObj(int senderId, int pEventType);
		~EventObj();
		eventType getType();
		std::vector<int> getTargetInstanceNumbers();
		void addTarget(Entity& newTarget);
		void addTarget(int newTargetId);
		std::stringstream eventData;
	protected:
		eventType type;
		std::vector<int> targetInstanceNumbers;
		
	};

}