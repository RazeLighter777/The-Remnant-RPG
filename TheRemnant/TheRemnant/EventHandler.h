#pragma once
namespace rpg {
	class EventObj;
	class World;
	class EventHandler
	{
	public:
		EventHandler(World& handlerWorld);
		void dispatch(EventObj& eventToDispatch);
		~EventHandler();
	protected:
		World* handlerWorld;
	};
}
