#pragma once

#include <string>
#include "Vector.h"
#include "Event.h"

namespace df {

	enum Solidness {

		HARD,
		SOFT,
		SPECTRAL,

	};

	class Object {

	private:
		int m_id;
		std::string m_type;
		Vector m_position;
		int m_altitude;

		Vector m_direction;
		float m_speed;
		Vector m_velocity;

		Solidness m_solid;

	public:
		Object();

		virtual ~Object();

		void setId(int new_id);

		int getId() const;

		void setType(std::string new_type);

		std::string getType() const;

		void setPosition(Vector new_pos);

		Vector getPosition() const;

		virtual int eventHandler(const Event* p_e);

		virtual int draw();

		int setAltitude(int new_altitude);

		int getAltitude();

		void setSpeed(float speed);

		float getSpeed() const;

		void setDirection(Vector new_direction);

		Vector getDirection() const;

		void setVelocity(Vector new_velocity);

		Vector getVelocity() const;

		float getXVelocity() const;

		float getYVelocity() const;

		Vector predictPosition();

		bool isSolid() const;

		int setSolidness(Solidness new_solid);

		Solidness getSolid() const;

		void testObject();
	};

}
