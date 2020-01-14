#include "WorldManager.h"
#include "LogManager.h"
#include "Object.h"
#include "EventCollision.h"
#include "EventOut.h"
#include "DisplayManager.h"

#include <vector>

namespace df {

	WorldManager::WorldManager() {

		setType("WorldManager");

	}

	WorldManager& WorldManager::getInstance() {

		static WorldManager instance;
		return instance;

	}

	int WorldManager::startUp() {

		if (Manager::startUp() == 0) {
			return 0;
		}
		else {
			return -1;
		}

	}

	void WorldManager::shutDown() {

		std::vector<Object*> ol = m_updates;
		std::vector<Object*>::iterator li;

		for (li = ol.begin(); li != ol.end(); li++) {

			delete (*li);

		}

	}

	int WorldManager::insertObject(Object* p_o) {

		int prev_list_size = m_updates.size();

		m_updates.insert(m_updates.end(), p_o);

		int after_list_size = m_updates.size();

		//check if the object at the end of the list has the same type
		//as the object put into the function
		//also check if the size is 1 bigger than before insert
		//
		if(prev_list_size + 1 == after_list_size && m_updates.size() + 1 == prev_list_size) {

			return 0;
			
		}
		else {
			return -1;
			
		}
		
	}

	int WorldManager::removeObject(Object* p_o) {

		for (std::vector<Object*>::iterator li = m_updates.begin(); li != m_updates.end(); li++) {

			if (*li == p_o) {

				m_updates.erase(li);

				return 0;
			}

		}

		return -1;

	}

	std::vector<Object*> WorldManager::getAllObjects() const {

		return m_updates;

	}

	std::vector<Object*> WorldManager::objectsOfType(std::string type) const {

		std::vector<Object*> m_u = m_updates;
		std::vector<Object*> ol;
		std::vector<Object*>::iterator li = m_u.begin();


		for (li; li != m_u.end(); li++) {


			if ((*li)->getType() == type) {

				//       (position, value)
				ol.insert(ol.end(), *li);

			}

		}

		return ol;

	}

	void WorldManager::update() {

		std::vector<Object*>::iterator ll = m_updates.begin();

		while (ll != m_updates.end()) {

			Vector new_pos = (*ll)->predictPosition();

			if (new_pos.getX() != (*ll)->getPosition().getX() && new_pos.getY() != (*ll)->getPosition().getY()) {

				LM.writeLog("moving object");
				moveObject(*ll, new_pos);

			}

			ll++;

		}



		std::vector<Object*>::iterator li = m_deletions.begin();
		while (li != m_deletions.end()) {

			delete (*li);

			li++;

		}

		m_deletions.clear();

	}

	int WorldManager::markForDelete(Object* p_o) {

		std::vector<Object*>::iterator li = m_deletions.begin();

		while (li != m_deletions.end()) {

			if (*li == p_o) {
				return 0;
			}

			li++;

		}

		m_deletions.insert(m_deletions.end(), p_o);

		return 0;
	}

	void WorldManager::draw() {

		std::vector<Object*>::iterator li = m_updates.begin();

		for (int alt = 0; alt <= MAX_ALTITUDE; alt++) {
	
			while (li != m_updates.end()) {

				if ((*li)->getAltitude() < alt) {
					Object *p_temp_o = *li;
					//LM.writeLog("object type: %s", (p_temp_o->getType()).c_str());
					p_temp_o->draw();
					li++;
				}
			}
		}	
	}



	std::vector<Object*> WorldManager::getCollisions(Object* p_o, Vector where) const {

		std::vector<Object*> ol;

		std::vector<Object*> ul = m_updates;

		std::vector<Object*>::iterator li = ul.begin();

		while (li != m_updates.end()) {

			Object* p_temp_o = *li;

			if (&p_temp_o != &p_o) {

				if (positionsIntersect(p_temp_o->getPosition(), where)) {

					ol.insert(ol.end(), p_temp_o);

				}


			}

			li++;


		}

		return ol;

	}

	int WorldManager::moveObject(Object* p_o, Vector where) {

		if (p_o->isSolid() == true) {

			std::vector<Object*> list = getCollisions(p_o, where);

			if (list.size() != 0) {

				bool do_move = true;

				std::vector<Object*>::iterator li = list.begin();

				while (li != list.end()) {

					Object* p_temp_o = *li;

					EventCollision c(p_o, p_temp_o, where);

					p_o->eventHandler(&c);
					p_temp_o->eventHandler(&c);

					if (p_o->getSolid() == HARD && p_temp_o->getSolid() == HARD) {

						do_move = false;

					}

					li++;

				}

				if (do_move == false) {

					return -1;

				}



			}

		}

		p_o->setPosition(where);

		if (p_o->getPosition().getX() > DM.getHorzontal() || p_o->getPosition().getX() < 0
			|| p_o->getPosition().getY() < 0 || p_o->getPosition().getY() > DM.getVertical()) {

			EventOut c;
			p_o->eventHandler(&c);

		}

		return 0;

	}

	bool positionsIntersect(Vector p1, Vector p2) {

		if (abs(p1.getX() - p2.getX()) <= 1 && abs(p1.getY() - p2.getY()) <= 1) {

			return true;

		}
		else {

			return false;

		}

	}





	void WorldManager::testWorldManager() {
		
		LM.writeLog("Start WorldManager Tests");

		LM.writeLog("");

		Object c;

		c.setType("WMTest");

		//find better way to test insertObject(). It gets called when the obj is created. 

		if (m_updates.back()->getType() == "WMTest") {
			LM.writeLog("insertObject() test passed");
		}
		else {
			LM.writeLog("insertObject() test failed");
		}

		if (WM.objectsOfType("WMTest").size() == 1) {
			LM.writeLog("objectsOfType() test passed");
		}
		else {
			LM.writeLog("objectsOfType() test failed");
		}

		if (markForDelete(&c) == 0) {
			LM.writeLog("markForDelete() test passed");
		}
		else {
			LM.writeLog("markForDelete() test failed");
		}

		LM.writeLog("");

		LM.writeLog("End WorldManager Tests");

		LM.writeLog("*******");
		
	}
}