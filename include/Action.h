#ifndef ACTION_H
#define ACTION_H

// Forward declarations instead of includes
class Engine;
class Entity;

/**
 * Action class
 *
 * base class that handles the different possible actions
 */
class Action {
	public:
		//! pure virtual destructor
		virtual ~Action() = 0;
		//! virtual function for handling movement
		virtual void perform(Engine engine, Entity& entity) = 0;
};
#endif
