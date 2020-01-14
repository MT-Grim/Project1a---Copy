#pragma once

#include "Event.h"
#include <string>

namespace df {

	class Manager {

	private:
		std::string m_type;
		bool m_is_started;
		
	protected:
		void setType(std::string tpye);

	public:
		Manager();

		virtual ~Manager();

		std::string getType() const;
		
		virtual int startUp();

		virtual void shutDown();

		bool isStarted() const;

		int onEvent(const Event* p_event) const;

	};

}