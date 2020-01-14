
#include "TestObject.h"
#include "LogManager.h"
#include "WorldManager.h"
#include "EventStep.h"
#include "DisplayManager.h"
#include "KeyboardEvent.h"
#include "InputManager.h"
#include "GameManager.h"
#include "EventMouse.h"
#include <stdlib.h>

TestObject::TestObject() {

	setType("TestObject");

	// random starting location
	float x = rand() % 10 + 1;
	float y = rand() % 10 + 1;

	df::Vector v;
	v.setXY(x, y);

	m_pos = v;

	self = '.';

};

int TestObject::eventHandler(const df::Event* p_e) {

	if (p_e->getType() == df::UNDEFINED_EVENT) {

		LM.writeLog("UndefinedEvent test");
		
	}

	if (p_e->getType() == df::STEP_EVENT) {

		//Used to test if it can actually "move" things on screen. 
		/*
		df::Vector v = getPos();

		setPos(v);

		setPos(getPos().getX() + 1, getPos().getY());
		*/
		
		LM.writeLog("TestObject Step Event");

	}

	
	if (p_e->getType() == df::KEYBOARD_EVENT) {
		
		const df::EventKeyboard* p_keyboard_event = dynamic_cast <const df::EventKeyboard*> (p_e);
		kbd(p_keyboard_event);
		return 1;

	}

	if (p_e->getType() == df::MSE_EVENT) {
		const df::EventMouse* p_mouse_e = dynamic_cast <const df::EventMouse*> (p_e);
		mouse(p_mouse_e);
	}
	return 0;
}

void TestObject::mouse(const df::EventMouse* p_mouse_event){
	if ((p_mouse_event->getMouseAction() == df::CLICKED) && (p_mouse_event->getMouseButton() == df::Mouse::LEFT)) {

		setPos(getPos().getX(), getPos().getY() + 1);

	}

}


void TestObject::kbd(const df::EventKeyboard* p_keyboard_event) {

	switch (p_keyboard_event->getKey()) {
	case df::Keyboard::A:
		if (p_keyboard_event->getKeyboardAction() == df::KEY_PRESSED || p_keyboard_event->getKeyboardAction() == df::KEY_DOWN) {
			setPos(getPos().getX() - 1, getPos().getY());
		}
		break;
	case df::Keyboard::D:
		
		if (p_keyboard_event->getKeyboardAction() == df::KEY_PRESSED || p_keyboard_event->getKeyboardAction() == df::KEY_DOWN) {
			setPos(getPos().getX() + 1, getPos().getY());
		}
		break;
	case df::Keyboard::S:

		if (p_keyboard_event->getKeyboardAction() == df::KEY_PRESSED || p_keyboard_event->getKeyboardAction() == df::KEY_DOWN) {
			setPos(getPos().getX(), getPos().getY() + 1);
		}
		break;
	case df::Keyboard::W:

		if (p_keyboard_event->getKeyboardAction() == df::KEY_PRESSED || p_keyboard_event->getKeyboardAction() == df::KEY_DOWN) {
			setPos(getPos().getX(), getPos().getY() - 1);
		}
		break;
	case df::Keyboard::Q:

		if (p_keyboard_event->getKeyboardAction() == df::KEY_PRESSED) {
			GM.setGameOver(true);
		}
		break;
	default:
		LM.writeLog("End of kdb switch. key not fount.");
	}
	

}

void TestObject::setPos(df::Vector v) {

	m_pos = v;

}

void TestObject::setPos(int X, int Y) {

	df::Vector v;
	v.setXY(X, Y);

	m_pos = v;

}

df::Vector TestObject::getPos() const {

	return m_pos;

}

int TestObject::draw() {

	//LM.writeLog("TestObject self: %c", getCharacter());

	DM.drawCh(m_pos, self, df::RED);

	return 0;

}

void TestObject::setCharacter(char character) {

	self = character;

}

char TestObject::getCharacter() const{

	return self;

}