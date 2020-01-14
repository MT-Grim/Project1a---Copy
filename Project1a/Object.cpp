
#include "Object.h"
#include "LogManager.h"
#include "WorldManager.h"

namespace df {

	

	Object::Object() {

		setType("Object");
		
		static int newestId = 0;

		newestId++;

		m_id = newestId;

		m_altitude == WM.MAX_ALTITUDE / 2;

		WM.insertObject(this);

	}

	Object::~Object() {

		WM.removeObject(this);

	}

	void Object::setId(int new_id) {

		m_id = new_id;

	}

	int Object::getId() const {

		return m_id;

	}

	void Object::setType(std::string new_type) {

		m_type = new_type;

	}

	std::string Object::getType() const {

		return m_type;

	}

	void Object::setPosition(Vector new_pos){

		m_position = new_pos;

	}

	Vector Object::getPosition() const {

		return m_position;

	}

	int Object::eventHandler(const Event* p_e) {

		return 0;

	}

	int Object::draw() {

		return 0;

	}

	int Object::setAltitude(int new_altitude) {

		if (new_altitude <= 4) {
			m_altitude = new_altitude;
			return 0;
			
		}
		else {
			return -1;
		}
		
	}

	int Object::getAltitude() {

		return m_altitude;

	}

	void Object::setSpeed(float speed) {

		m_speed = speed;
	}

	float Object::getSpeed() const {

		return m_speed;

	}

	void Object::setDirection(Vector new_direction) {

		m_direction = new_direction;

	}

	Vector Object::getDirection() const {

		return m_direction;

	}

	void Object::setVelocity(Vector new_velocity) {

		m_velocity = new_velocity;

	}

	Vector Object::getVelocity() const {

		return m_velocity;

	}

	float Object::getXVelocity() const {

		LM.writeLog("ERROR ERROR GETXVELOCITY() NOT DEFINED");
		return m_velocity.getX();

	}

	float Object::getYVelocity() const {

		LM.writeLog("ERROR ERROR GETYVELOCITY() NOT DEFINED");
		return m_velocity.getY();

	}

	Vector Object::predictPosition() {

		Vector new_pos = m_position + getVelocity();

		return new_pos;

	}

	bool Object::isSolid() const {

		if (getSolid() == HARD || getSolid() == SOFT) {

			return true;

		}
		else {
			return false;
		}

	}

	int Object::setSolidness(Solidness new_solid) {

		if (new_solid == HARD || new_solid == SOFT || new_solid == SPECTRAL) {

			m_solid = new_solid;
			return 0;

		}
		else {
			return -1;
		}
	

	}

	Solidness Object::getSolid() const {

		return m_solid;

	}

	void Object::testObject() {
		
		LM.writeLog("Start Object Tests");

		LM.writeLog("");

		///tests

		Object o;

		o.setId(2);

		if (o.getId() == 2) {

			LM.writeLog("getId() and setId() tests passed");

		}
		else {
			LM.writeLog("getId() and setId() tests failed");
		}

		o.setType("test");

		if (o.getType() == "test") {

			LM.writeLog("getType() and setType() tests passed");

		}
		else {

			LM.writeLog("getType() and setType() tests failed");

		}

		Vector v;

		v.setXY(1.0, 1.0);

		o.setPosition(v);

		if (o.getPosition().getX() == 1.0 && o.getPosition().getY() == 1.0) {

			LM.writeLog("getPosition() and setPosition() tests passed");

		}
		else {

			LM.writeLog("getPosition() and setPosition() tests failed");

		}

		Object t;

		LM.writeLog("t Id: %d", t.getId());

		Object c;

		LM.writeLog("c Id: %d", c.getId());

		Object z;

		LM.writeLog("z Id: %d", z.getId());

		if (t.getId() == 3 && c.getId() == 4 && z.getId() == 5) {

			LM.writeLog("ID incrementation test passed");

		}
		else {

			LM.writeLog("ID incrementation test failed");

		}

		LM.writeLog("");
		
		LM.writeLog("End Object Tests");

		LM.writeLog("*******");
		
	}
}