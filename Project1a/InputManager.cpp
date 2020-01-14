
#include "LogManager.h"
#include "InputManager.h"
#include "DisplayManager.h"
#include "EventMouse.h"
#include "KeyboardEvent.h"
#include "WorldManager.h"
#include "EventStep.h"

namespace df {

	InputManager::InputManager() {

		setType("InputManager");

	}

	InputManager& InputManager::getInstance() {

		static InputManager instance;	
		return instance;

	}

	int InputManager::startUp() {

		if (DM.isStarted() == false) {
			LM.writeLog("DisplayManager is not started");
			return -1;
		}

		sf::RenderWindow* m_window = DM.getWindow();

		m_window->setKeyRepeatEnabled(false);

		if (m_window != NULL) {

			Manager::startUp();

		}

	}

	void InputManager::shutDown() {

		sf::RenderWindow* m_window = DM.getWindow();

		m_window->setKeyRepeatEnabled(true);

		Manager::shutDown();

	}

	void InputManager::getInput() {

		sf::Event event;

		sf::RenderWindow* m_window = DM.getWindow();

		while (m_window->pollEvent(event)) {

			if (event.type == sf::Event::KeyPressed) {

				EventKeyboard s;
				s.setKeyboardAction(KEY_PRESSED);
				
				switch(event.key.code){	
					//ABC
					case sf::Keyboard::A:
						s.setKey(Keyboard::A);
						WM.onEvent(&s);
						break;
					case sf::Keyboard::B:
						s.setKey(Keyboard::B);
						WM.onEvent(&s);
						break;
					case sf::Keyboard::C:
						s.setKey(Keyboard::C);
						WM.onEvent(&s);
						break;
					case sf::Keyboard::D:
						s.setKey(Keyboard::D);
						WM.onEvent(&s);
						break;
					case sf::Keyboard::E:
						s.setKey(Keyboard::E);
						WM.onEvent(&s);
						break;
					case sf::Keyboard::F:
						s.setKey(Keyboard::F);
						WM.onEvent(&s);
						break;
					case sf::Keyboard::G:
						s.setKey(Keyboard::G);
						WM.onEvent(&s);
						break;
					case sf::Keyboard::H:
						s.setKey(Keyboard::H);
						WM.onEvent(&s);
						break;
					case sf::Keyboard::I:
						s.setKey(Keyboard::I);
						WM.onEvent(&s);
						break;
					case sf::Keyboard::J:
						s.setKey(Keyboard::J);
						WM.onEvent(&s);
						break;
					case sf::Keyboard::K:
						s.setKey(Keyboard::K);
						WM.onEvent(&s);
						break;
					case sf::Keyboard::L:
						s.setKey(Keyboard::L);
						break;
					case sf::Keyboard::M:
						s.setKey(Keyboard::M);
						WM.onEvent(&s);
						break;
					case sf::Keyboard::N:
						s.setKey(Keyboard::N);
						WM.onEvent(&s);
						break;
					case sf::Keyboard::O:
						s.setKey(Keyboard::O);
						WM.onEvent(&s);
						break;
					case sf::Keyboard::P:
						s.setKey(Keyboard::P);
						WM.onEvent(&s);
						break;
					case sf::Keyboard::Q:
						s.setKey(Keyboard::Q);
						WM.onEvent(&s);
						break;
					case sf::Keyboard::R:
						s.setKey(Keyboard::R);
						WM.onEvent(&s);
						break;
					case sf::Keyboard::S:
						s.setKey(Keyboard::S);
						WM.onEvent(&s);
						break;
					case sf::Keyboard::T:
						s.setKey(Keyboard::T);
						WM.onEvent(&s);
						break;
					case sf::Keyboard::U:
						s.setKey(Keyboard::U);
						WM.onEvent(&s);
						break;
					case sf::Keyboard::V:
						s.setKey(Keyboard::V);
						WM.onEvent(&s);
						break;
					case sf::Keyboard::W:
						s.setKey(Keyboard::W);
						WM.onEvent(&s);
						break;
					case sf::Keyboard::X:
						s.setKey(Keyboard::X);
						WM.onEvent(&s);
						break;
					case sf::Keyboard::Y:
						s.setKey(Keyboard::Y);
						WM.onEvent(&s);
						break;
					case sf::Keyboard::Z:
						s.setKey(Keyboard::Z);
						WM.onEvent(&s);
						break;
					//123
					case sf::Keyboard::Num0:
						s.setKey(Keyboard::NUM0);
						WM.onEvent(&s);
						break;
					case sf::Keyboard::Num1:
						s.setKey(Keyboard::NUM1);
						WM.onEvent(&s);
						break;
					case sf::Keyboard::Num2:
						s.setKey(Keyboard::NUM2);
						WM.onEvent(&s);
						break;
					case sf::Keyboard::Num3:
						s.setKey(Keyboard::NUM3);
						WM.onEvent(&s);
						break;
					case sf::Keyboard::Num4:
						s.setKey(Keyboard::NUM4);
						WM.onEvent(&s);
						break;
					case sf::Keyboard::Num5:
						s.setKey(Keyboard::NUM5);
						WM.onEvent(&s);
						break;
					case sf::Keyboard::Num6:
						s.setKey(Keyboard::NUM6);
						WM.onEvent(&s);
						break;
					case sf::Keyboard::Num7:
						s.setKey(Keyboard::NUM7);
						WM.onEvent(&s);
						break;
					case sf::Keyboard::Num8:
						s.setKey(Keyboard::NUM8);
						WM.onEvent(&s);
						break;
					case sf::Keyboard::Num9:
						s.setKey(Keyboard::NUM9);
						WM.onEvent(&s);
						break;
					//F1F2F3
					case sf::Keyboard::F1:
						s.setKey(Keyboard::F1);
						WM.onEvent(&s);
						break;
					case sf::Keyboard::F2:
						s.setKey(Keyboard::F2);
						WM.onEvent(&s);
						break;
					case sf::Keyboard::F3:
						s.setKey(Keyboard::F3);
						WM.onEvent(&s);
						break;
					case sf::Keyboard::F4:
						s.setKey(Keyboard::F4);
						WM.onEvent(&s);
						break;
					case sf::Keyboard::F5:
						s.setKey(Keyboard::F5);
						WM.onEvent(&s);
						break;
					case sf::Keyboard::F6:
						s.setKey(Keyboard::F6);
						WM.onEvent(&s);
						break;
					case sf::Keyboard::F7:
						s.setKey(Keyboard::F7);
						WM.onEvent(&s);
						break;
					case sf::Keyboard::F8:
						s.setKey(Keyboard::F8);
						WM.onEvent(&s);
						break;
					case sf::Keyboard::F9:
						s.setKey(Keyboard::F9);
						WM.onEvent(&s);
						break;
					case sf::Keyboard::F10:
						s.setKey(Keyboard::F10);
						WM.onEvent(&s);
						break;
					case sf::Keyboard::F11:
						s.setKey(Keyboard::F11);
						WM.onEvent(&s);
						break;
					case sf::Keyboard::F12:
						s.setKey(Keyboard::F12);
						WM.onEvent(&s);
						break;
					//SPACE , RETURN , ESCAPE , TAB , LEFTARROW , RIGHTARROW , UPARROW , DOWNARROW ,
					case sf::Keyboard::Space:
						s.setKey(Keyboard::SPACE);
						WM.onEvent(&s);
						break;
					case sf::Keyboard::Return:
						s.setKey(Keyboard::RETURN);
						WM.onEvent(&s);
						break;
					case sf::Keyboard::Escape:
						s.setKey(Keyboard::ESCAPE);
						WM.onEvent(&s);
						break;
					case sf::Keyboard::Tab:
						s.setKey(Keyboard::TAB);
						WM.onEvent(&s);
						break;
					case sf::Keyboard::Left:
						s.setKey(Keyboard::LEFTARROW);
						WM.onEvent(&s);
						break;
					case sf::Keyboard::Right:
						s.setKey(Keyboard::RIGHTARROW);
						WM.onEvent(&s);
						break;
					case sf::Keyboard::Up:
						s.setKey(Keyboard::UPARROW);
						WM.onEvent(&s);
						break;
					case sf::Keyboard::Down:
						s.setKey(Keyboard::DOWNARROW);
						WM.onEvent(&s);
						break;
					//PAUSE , MINUS , PLUS , TILDE , PERIOD , COMMA , SLASH , LEFTCONTROL
					case sf::Keyboard::Pause:
						s.setKey(Keyboard::PAUSE);
						WM.onEvent(&s);
						break;
					case sf::Keyboard::Dash:
						s.setKey(Keyboard::MINUS);
						WM.onEvent(&s);
						break;
					case sf::Keyboard::Add:
						s.setKey(Keyboard::PLUS);
						WM.onEvent(&s);
						break;
					case sf::Keyboard::Tilde:
						s.setKey(Keyboard::TILDE);
						WM.onEvent(&s);
						break;
					case sf::Keyboard::Period:
						s.setKey(Keyboard::PERIOD);
						WM.onEvent(&s);
						break;
					case sf::Keyboard::Comma:
						s.setKey(Keyboard::COMMA);
						WM.onEvent(&s);
						break;
					case sf::Keyboard::Slash:
						s.setKey(Keyboard::SLASH);
						WM.onEvent(&s);
						break;
					case sf::Keyboard::LControl:
						s.setKey(Keyboard::LEFTCONTROL);
						WM.onEvent(&s);
						break;
					//RIGHTCONTROL , LEFTSHIFT , RIGHTSHIFT ,
					case sf::Keyboard::RControl:
						s.setKey(Keyboard::RIGHTCONTROL);
						WM.onEvent(&s);
						break;
					case sf::Keyboard::LShift:
						s.setKey(Keyboard::LEFTSHIFT);
						WM.onEvent(&s);
						break;
					case sf::Keyboard::RShift:
						s.setKey(Keyboard::RIGHTSHIFT);
						WM.onEvent(&s);
						break;


				}
				
			}
			
			if (event.type == sf::Event::KeyReleased) {
			
				EventKeyboard s;
				s.setKeyboardAction(KEY_RELEASED);

				switch (event.key.code) {
					//ABC
				case sf::Keyboard::A:
					s.setKey(Keyboard::A);
					WM.onEvent(&s);
					break;
				case sf::Keyboard::B:
					s.setKey(Keyboard::B);
					WM.onEvent(&s);
					break;
				case sf::Keyboard::C:
					s.setKey(Keyboard::C);
					WM.onEvent(&s);
					break;
				case sf::Keyboard::D:
					s.setKey(Keyboard::D);
					WM.onEvent(&s);
					break;
				case sf::Keyboard::E:
					s.setKey(Keyboard::E);
					WM.onEvent(&s);
					break;
				case sf::Keyboard::F:
					s.setKey(Keyboard::F);
					WM.onEvent(&s);
					break;
				case sf::Keyboard::G:
					s.setKey(Keyboard::G);
					WM.onEvent(&s);
					break;
				case sf::Keyboard::H:
					s.setKey(Keyboard::H);
					WM.onEvent(&s);
					break;
				case sf::Keyboard::I:
					s.setKey(Keyboard::I);
					WM.onEvent(&s);
					break;
				case sf::Keyboard::J:
					s.setKey(Keyboard::J);
					WM.onEvent(&s);
					break;
				case sf::Keyboard::K:
					s.setKey(Keyboard::K);
					WM.onEvent(&s);
					break;
				case sf::Keyboard::L:
					s.setKey(Keyboard::L);
					break;
				case sf::Keyboard::M:
					s.setKey(Keyboard::M);
					WM.onEvent(&s);
					break;
				case sf::Keyboard::N:
					s.setKey(Keyboard::N);
					WM.onEvent(&s);
					break;
				case sf::Keyboard::O:
					s.setKey(Keyboard::O);
					WM.onEvent(&s);
					break;
				case sf::Keyboard::P:
					s.setKey(Keyboard::P);
					WM.onEvent(&s);
					break;
				case sf::Keyboard::Q:
					s.setKey(Keyboard::Q);
					WM.onEvent(&s);
					break;
				case sf::Keyboard::R:
					s.setKey(Keyboard::R);
					WM.onEvent(&s);
					break;
				case sf::Keyboard::S:
					s.setKey(Keyboard::S);
					WM.onEvent(&s);
					break;
				case sf::Keyboard::T:
					s.setKey(Keyboard::T);
					WM.onEvent(&s);
					break;
				case sf::Keyboard::U:
					s.setKey(Keyboard::U);
					WM.onEvent(&s);
					break;
				case sf::Keyboard::V:
					s.setKey(Keyboard::V);
					WM.onEvent(&s);
					break;
				case sf::Keyboard::W:
					s.setKey(Keyboard::W);
					WM.onEvent(&s);
					break;
				case sf::Keyboard::X:
					s.setKey(Keyboard::X);
					WM.onEvent(&s);
					break;
				case sf::Keyboard::Y:
					s.setKey(Keyboard::Y);
					WM.onEvent(&s);
					break;
				case sf::Keyboard::Z:
					s.setKey(Keyboard::Z);
					WM.onEvent(&s);
					break;
					//123
				case sf::Keyboard::Num0:
					s.setKey(Keyboard::NUM0);
					WM.onEvent(&s);
					break;
				case sf::Keyboard::Num1:
					s.setKey(Keyboard::NUM1);
					WM.onEvent(&s);
					break;
				case sf::Keyboard::Num2:
					s.setKey(Keyboard::NUM2);
					WM.onEvent(&s);
					break;
				case sf::Keyboard::Num3:
					s.setKey(Keyboard::NUM3);
					WM.onEvent(&s);
					break;
				case sf::Keyboard::Num4:
					s.setKey(Keyboard::NUM4);
					WM.onEvent(&s);
					break;
				case sf::Keyboard::Num5:
					s.setKey(Keyboard::NUM5);
					WM.onEvent(&s);
					break;
				case sf::Keyboard::Num6:
					s.setKey(Keyboard::NUM6);
					WM.onEvent(&s);
					break;
				case sf::Keyboard::Num7:
					s.setKey(Keyboard::NUM7);
					WM.onEvent(&s);
					break;
				case sf::Keyboard::Num8:
					s.setKey(Keyboard::NUM8);
					WM.onEvent(&s);
					break;
				case sf::Keyboard::Num9:
					s.setKey(Keyboard::NUM9);
					WM.onEvent(&s);
					break;
					//F1F2F3
				case sf::Keyboard::F1:
					s.setKey(Keyboard::F1);
					WM.onEvent(&s);
					break;
				case sf::Keyboard::F2:
					s.setKey(Keyboard::F2);
					WM.onEvent(&s);
					break;
				case sf::Keyboard::F3:
					s.setKey(Keyboard::F3);
					WM.onEvent(&s);
					break;
				case sf::Keyboard::F4:
					s.setKey(Keyboard::F4);
					WM.onEvent(&s);
					break;
				case sf::Keyboard::F5:
					s.setKey(Keyboard::F5);
					WM.onEvent(&s);
					break;
				case sf::Keyboard::F6:
					s.setKey(Keyboard::F6);
					WM.onEvent(&s);
					break;
				case sf::Keyboard::F7:
					s.setKey(Keyboard::F7);
					WM.onEvent(&s);
					break;
				case sf::Keyboard::F8:
					s.setKey(Keyboard::F8);
					WM.onEvent(&s);
					break;
				case sf::Keyboard::F9:
					s.setKey(Keyboard::F9);
					WM.onEvent(&s);
					break;
				case sf::Keyboard::F10:
					s.setKey(Keyboard::F10);
					WM.onEvent(&s);
					break;
				case sf::Keyboard::F11:
					s.setKey(Keyboard::F11);
					WM.onEvent(&s);
					break;
				case sf::Keyboard::F12:
					s.setKey(Keyboard::F12);
					WM.onEvent(&s);
					break;
					//SPACE , RETURN , ESCAPE , TAB , LEFTARROW , RIGHTARROW , UPARROW , DOWNARROW ,
				case sf::Keyboard::Space:
					s.setKey(Keyboard::SPACE);
					WM.onEvent(&s);
					break;
				case sf::Keyboard::Return:
					s.setKey(Keyboard::RETURN);
					WM.onEvent(&s);
					break;
				case sf::Keyboard::Escape:
					s.setKey(Keyboard::ESCAPE);
					WM.onEvent(&s);
					break;
				case sf::Keyboard::Tab:
					s.setKey(Keyboard::TAB);
					WM.onEvent(&s);
					break;
				case sf::Keyboard::Left:
					s.setKey(Keyboard::LEFTARROW);
					WM.onEvent(&s);
					break;
				case sf::Keyboard::Right:
					s.setKey(Keyboard::RIGHTARROW);
					WM.onEvent(&s);
					break;
				case sf::Keyboard::Up:
					s.setKey(Keyboard::UPARROW);
					WM.onEvent(&s);
					break;
				case sf::Keyboard::Down:
					s.setKey(Keyboard::DOWNARROW);
					WM.onEvent(&s);
					break;
					//PAUSE , MINUS , PLUS , TILDE , PERIOD , COMMA , SLASH , LEFTCONTROL
				case sf::Keyboard::Pause:
					s.setKey(Keyboard::PAUSE);
					WM.onEvent(&s);
					break;
				case sf::Keyboard::Dash:
					s.setKey(Keyboard::MINUS);
					WM.onEvent(&s);
					break;
				case sf::Keyboard::Add:
					s.setKey(Keyboard::PLUS);
					WM.onEvent(&s);
					break;
				case sf::Keyboard::Tilde:
					s.setKey(Keyboard::TILDE);
					WM.onEvent(&s);
					break;
				case sf::Keyboard::Period:
					s.setKey(Keyboard::PERIOD);
					WM.onEvent(&s);
					break;
				case sf::Keyboard::Comma:
					s.setKey(Keyboard::COMMA);
					WM.onEvent(&s);
					break;
				case sf::Keyboard::Slash:
					s.setKey(Keyboard::SLASH);
					WM.onEvent(&s);
					break;
				case sf::Keyboard::LControl:
					s.setKey(Keyboard::LEFTCONTROL);
					WM.onEvent(&s);
					break;
					//RIGHTCONTROL , LEFTSHIFT , RIGHTSHIFT ,
				case sf::Keyboard::RControl:
					s.setKey(Keyboard::RIGHTCONTROL);
					WM.onEvent(&s);
					break;
				case sf::Keyboard::LShift:
					s.setKey(Keyboard::LEFTSHIFT);
					WM.onEvent(&s);
					break;
				case sf::Keyboard::RShift:
					s.setKey(Keyboard::RIGHTSHIFT);
					WM.onEvent(&s);
					break;

				}

			}


			if (event.type == sf::Event::MouseMoved) {
				EventMouse m;
				m.setMouseAction(MOVED);

				WM.onEvent(&m);

			}

			if (event.type == sf::Event::MouseButtonPressed) {

				if (event.mouseButton.button == sf::Mouse::Left) {
					EventMouse m;
					m.setMouseAction(CLICKED);
					m.setMouseButton(Mouse::LEFT);
					
					WM.onEvent(&m);

				}

				if (event.mouseButton.button == sf::Mouse::Right) {
					EventMouse m;
					m.setMouseAction(CLICKED);
					m.setMouseButton(Mouse::RIGHT);

					WM.onEvent(&m);


				}

				if (event.mouseButton.button == sf::Mouse::Middle) {

					EventMouse m;
					m.setMouseAction(CLICKED);
					m.setMouseButton(Mouse::MIDDLE);

					WM.onEvent(&m);

				}

			}
			
		}//end while

		EventMouse m;

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

			m.setMouseButton(Mouse::LEFT);
			m.setMouseAction(PRESSED);

			WM.onEvent(&m);
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {

			m.setMouseButton(Mouse::RIGHT);
			m.setMouseAction(PRESSED);

			WM.onEvent(&m);
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Middle)) {

			m.setMouseButton(Mouse::MIDDLE);
			m.setMouseAction(PRESSED);

			WM.onEvent(&m);
		}


		EventKeyboard s;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {

			s.setKey(Keyboard::A);
			s.setKeyboardAction(KEY_DOWN);

			WM.onEvent(&s);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {

			s.setKey(Keyboard::B);
			s.setKeyboardAction(KEY_DOWN);

			WM.onEvent(&s);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {

			s.setKey(Keyboard::C);
			s.setKeyboardAction(KEY_DOWN);

			WM.onEvent(&s);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {

			s.setKey(Keyboard::D);
			s.setKeyboardAction(KEY_DOWN);

			WM.onEvent(&s);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {

			s.setKey(Keyboard::E);
			s.setKeyboardAction(KEY_DOWN);

			WM.onEvent(&s);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {

			s.setKey(Keyboard::F);
			s.setKeyboardAction(KEY_DOWN);

			WM.onEvent(&s);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::G)) {

			s.setKey(Keyboard::G);
			s.setKeyboardAction(KEY_DOWN);

			WM.onEvent(&s);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::H)) {

			s.setKey(Keyboard::H);
			s.setKeyboardAction(KEY_DOWN);

			WM.onEvent(&s);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)) {

			s.setKey(Keyboard::I);
			s.setKeyboardAction(KEY_DOWN);

			WM.onEvent(&s);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)) {

			s.setKey(Keyboard::J);
			s.setKeyboardAction(KEY_DOWN);

			WM.onEvent(&s);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {

			s.setKey(Keyboard::K);
			s.setKeyboardAction(KEY_DOWN);

			WM.onEvent(&s);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {

			s.setKey(Keyboard::L);
			s.setKeyboardAction(KEY_DOWN);

			WM.onEvent(&s);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)) {

			s.setKey(Keyboard::M);
			s.setKeyboardAction(KEY_DOWN);

			WM.onEvent(&s);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::O)) {

			s.setKey(Keyboard::O);
			s.setKeyboardAction(KEY_DOWN);

			WM.onEvent(&s);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {

			s.setKey(Keyboard::P);
			s.setKeyboardAction(KEY_DOWN);

			WM.onEvent(&s);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {

			s.setKey(Keyboard::Q);
			s.setKeyboardAction(KEY_DOWN);

			WM.onEvent(&s);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {

			s.setKey(Keyboard::R);
			s.setKeyboardAction(KEY_DOWN);

			WM.onEvent(&s);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {

			s.setKey(Keyboard::S);
			s.setKeyboardAction(KEY_DOWN);

			WM.onEvent(&s);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::T)) {

			s.setKey(Keyboard::T);
			s.setKeyboardAction(KEY_DOWN);

			WM.onEvent(&s);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::U)) {

			s.setKey(Keyboard::U);
			s.setKeyboardAction(KEY_DOWN);

			WM.onEvent(&s);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::V)) {

			s.setKey(Keyboard::V);
			s.setKeyboardAction(KEY_DOWN);

			WM.onEvent(&s);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {

			s.setKey(Keyboard::W);
			s.setKeyboardAction(KEY_DOWN);

			WM.onEvent(&s);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {

			s.setKey(Keyboard::X);
			s.setKeyboardAction(KEY_DOWN);

			WM.onEvent(&s);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) {

			s.setKey(Keyboard::Y);
			s.setKeyboardAction(KEY_DOWN);

			WM.onEvent(&s);

		}if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {

			s.setKey(Keyboard::Z);
			s.setKeyboardAction(KEY_DOWN);

			WM.onEvent(&s);

		}
		//NUMs
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0)) {

			s.setKey(Keyboard::NUM0);
			s.setKeyboardAction(KEY_DOWN);

			WM.onEvent(&s);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {

			s.setKey(Keyboard::NUM1);
			s.setKeyboardAction(KEY_DOWN);

			WM.onEvent(&s);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {

			s.setKey(Keyboard::NUM2);
			s.setKeyboardAction(KEY_DOWN);

			WM.onEvent(&s);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {

			s.setKey(Keyboard::NUM3);
			s.setKeyboardAction(KEY_DOWN);

			WM.onEvent(&s);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) {

			s.setKey(Keyboard::NUM4);
			s.setKeyboardAction(KEY_DOWN);

			WM.onEvent(&s);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5)) {

			s.setKey(Keyboard::NUM5);
			s.setKeyboardAction(KEY_DOWN);

			WM.onEvent(&s);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6)){

			s.setKey(Keyboard::NUM6);
			s.setKeyboardAction(KEY_DOWN);

			WM.onEvent(&s);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7)){

			s.setKey(Keyboard::NUM7);
			s.setKeyboardAction(KEY_DOWN);

			WM.onEvent(&s);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8)) {

			s.setKey(Keyboard::NUM8);
			s.setKeyboardAction(KEY_DOWN);

			WM.onEvent(&s);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9)) {

			s.setKey(Keyboard::NUM9);
			s.setKeyboardAction(KEY_DOWN);

			WM.onEvent(&s);

		}
		//F1F2F3
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1)) {

			s.setKey(Keyboard::F1);
			s.setKeyboardAction(KEY_DOWN);

			WM.onEvent(&s);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F2)) {

			s.setKey(Keyboard::F2);
			s.setKeyboardAction(KEY_DOWN);

			WM.onEvent(&s);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F3)) {

			s.setKey(Keyboard::F3);
			s.setKeyboardAction(KEY_DOWN);

			WM.onEvent(&s);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F4)) {

			s.setKey(Keyboard::F4);
			s.setKeyboardAction(KEY_DOWN);

			WM.onEvent(&s);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F5)) {

			s.setKey(Keyboard::F5);
			s.setKeyboardAction(KEY_DOWN);

			WM.onEvent(&s);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F6)) {

			s.setKey(Keyboard::F6);
			s.setKeyboardAction(KEY_DOWN);

			WM.onEvent(&s);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F7)) {

			s.setKey(Keyboard::F7);
			s.setKeyboardAction(KEY_DOWN);

			WM.onEvent(&s);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F8)) {

			s.setKey(Keyboard::F8);
			s.setKeyboardAction(KEY_DOWN);

			WM.onEvent(&s);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F9)) {

			s.setKey(Keyboard::F9);
			s.setKeyboardAction(KEY_DOWN);

			WM.onEvent(&s);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F10)) {

			s.setKey(Keyboard::F10);
			s.setKeyboardAction(KEY_DOWN);

			WM.onEvent(&s);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F11)) {

			s.setKey(Keyboard::F11);
			s.setKeyboardAction(KEY_DOWN);

			WM.onEvent(&s);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F12)) {

			s.setKey(Keyboard::F12);
			s.setKeyboardAction(KEY_DOWN);

			WM.onEvent(&s);

		}
		//SPACE, RETURN, ESCAPE, TAB, LEFTARROW, RIGHTARROW, UPARROW, DOWNARROW,
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {

			s.setKey(Keyboard::SPACE);
			s.setKeyboardAction(KEY_DOWN);

			WM.onEvent(&s);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {

			s.setKey(Keyboard::RETURN);
			s.setKeyboardAction(KEY_DOWN);

			WM.onEvent(&s);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {

			s.setKey(Keyboard::ESCAPE);
			s.setKeyboardAction(KEY_DOWN);

			WM.onEvent(&s);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)) {

			s.setKey(Keyboard::TAB);
			s.setKeyboardAction(KEY_DOWN);

			WM.onEvent(&s);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {

			s.setKey(Keyboard::LEFTARROW);
			s.setKeyboardAction(KEY_DOWN);

			WM.onEvent(&s);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {

			s.setKey(Keyboard::RIGHTARROW);
			s.setKeyboardAction(KEY_DOWN);

			WM.onEvent(&s);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {

			s.setKey(Keyboard::UPARROW);
			s.setKeyboardAction(KEY_DOWN);

			WM.onEvent(&s);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {

			s.setKey(Keyboard::DOWNARROW);
			s.setKeyboardAction(KEY_DOWN);

			WM.onEvent(&s);

		}
		//PAUSE, MINUS, PLUS, TILDE, PERIOD, COMMA, SLASH, LEFTCONTROL,
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Pause)) {

			s.setKey(Keyboard::PAUSE);
			s.setKeyboardAction(KEY_DOWN);

			WM.onEvent(&s);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Dash)) {

			s.setKey(Keyboard::MINUS);
			s.setKeyboardAction(KEY_DOWN);

			WM.onEvent(&s);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Add)) {

			s.setKey(Keyboard::PLUS);
			s.setKeyboardAction(KEY_DOWN);

			WM.onEvent(&s);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tilde)) {

			s.setKey(Keyboard::TILDE);
			s.setKeyboardAction(KEY_DOWN);

			WM.onEvent(&s);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Period)) {

			s.setKey(Keyboard::PERIOD);
			s.setKeyboardAction(KEY_DOWN);

			WM.onEvent(&s);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Comma)) {

			s.setKey(Keyboard::COMMA);
			s.setKeyboardAction(KEY_DOWN);

			WM.onEvent(&s);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Slash)) {

			s.setKey(Keyboard::SLASH);
			s.setKeyboardAction(KEY_DOWN);

			WM.onEvent(&s);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) {

			s.setKey(Keyboard::LEFTCONTROL);
			s.setKeyboardAction(KEY_DOWN);

			WM.onEvent(&s);

		}
		//RIGHTCONTROL, LEFTSHIFT, RIGHTSHIFT
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::RControl)) {

			s.setKey(Keyboard::RIGHTCONTROL);
			s.setKeyboardAction(KEY_DOWN);

			WM.onEvent(&s);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)) {

			s.setKey(Keyboard::RIGHTSHIFT);
			s.setKeyboardAction(KEY_DOWN);

			WM.onEvent(&s);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {

			s.setKey(Keyboard::LEFTSHIFT);
			s.setKeyboardAction(KEY_DOWN);

			WM.onEvent(&s);

		}
	}
}

