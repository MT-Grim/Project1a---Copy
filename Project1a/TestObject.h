#pragma once

#include "Object.h"
#include "Vector.h"
#include "KeyboardEvent.h"
#include "EventMouse.h"


class TestObject : public df::Object {

public:
	TestObject();
	df::Vector m_pos;
	char self;
	int eventHandler(const df::Event* p_e);
	void setPos(df::Vector v);
	void setPos(int X, int Y);
	df::Vector getPos() const;
	int draw();
	void setCharacter(char c);
	char getCharacter() const;
	void kbd(const df::EventKeyboard* p_keyboard_event);
	void mouse(const df::EventMouse* p_mouse_event);
};

