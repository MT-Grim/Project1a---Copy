#include "Manager.h"
#include "WorldManager.h"
#include "EventStep.h"
#include "LogManager.h"

namespace df {

	Manager::Manager() {

		setType("Manager");
		m_is_started = false;

	}

	Manager::~Manager() {



	}

	void Manager::setType(std::string type) {

		m_type = type;

	}

	std::string Manager::getType() const {

		return m_type;

	}

	int Manager::startUp() {

		m_is_started = true;

		if (m_is_started == true) {

			return 0;

		}
		else {

			return -1;

		}

	}

	void Manager::shutDown() {

		m_is_started = false;

	}

	bool Manager::isStarted() const {

		if (m_is_started == false) {

			return false;
		}
		else if (m_is_started == true) {

			return true;

		}
	}

	int Manager::onEvent(const Event* p_event) const {

		int count = 0;

		std::vector<Object*> all_objects = WM.getAllObjects();

		std::vector<Object*>::iterator li = all_objects.begin();

		while (li != all_objects.end()) {

			(*li)->eventHandler(p_event);
			li++;
			count++;
		}

		return count;

	}

}






