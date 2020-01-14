#include "DisplayManager.h"
#include "GameManager.h"
#include "LogManager.h"
#include "Windows.h"
#include "Clock.h"
#include "Object.h"
#include "Vector.h"
#include "WorldManager.h"
#include "EventStep.h"
#include "InputManager.h"

#include "TestObject.h"


namespace df {

	GameManager::GameManager() {
	
		setType("GameManager");

		game_over = true;

		frame_time = FRAME_TIME_DEFAULT;
	
	}

	GameManager& GameManager::getInstance() {
		
		static GameManager instance;
		return instance;
	
	}

	//call all the manager startups
	int GameManager::startUp() {
	
		if (LM.startUp()) {
			printf("LM failed to start\n");
			return -1;
		}

		LM.setFlush();
		
		if (WM.startUp()) {
			LM.writeLog("WorldManager failed to start.");
			return -1;
		}

		TestObject *p_oa = new TestObject;

		p_oa->setPos(Vector(10, 5));

		p_oa->setCharacter('l');

		if (DM.startUp()) {
			LM.writeLog("DM failed to start");
			return -1;
		}

		if (IM.startUp()) {

			LM.writeLog("IM failed to start");
			return -1;
		}

		timeBeginPeriod(1);

		setGameOver(false);

		runTests(false);

		return 0;

	}

	void GameManager::shutDown() {
	
		LM.writeLog("IM shutDown()");
		IM.shutDown();
		LM.writeLog("DM shutDown()");
		DM.shutDown();
		LM.writeLog("WM shutDown()");
		WM.shutDown();
		
		setGameOver(true);

		timeEndPeriod(1);

		//logmanager goes last 
		LM.shutDown();

	}

	void GameManager::run() {
	
		startUp();

		//LM.writeLog("m_updates initial count: %d", WM.getAllObjects().size());

		Clock c;

		int loop_count = 0;

		int loop_time = 0;

		while (game_over == false) {

			//LM.writeLog("m_updates count: %d", WM.getAllObjects().size());

			c.delta();
			
			//game code goes here
			//get input
			//EventStep s;

			//WM.onEvent(&s);  

			IM.getInput();

			WM.update();

			WM.draw();

			DM.swapBuffers();
			
			loop_time = c.split();
			
			if (frame_time - loop_time <= 0) {
				Sleep(0);
			}
			else {
				Sleep(frame_time - loop_time);
			}

			loop_count++;
			
			
			//if (loop_count == 200) {
				//LM.writeLog("loop_count at shutdown = %d", loop_count);
				//setGameOver(true);
			//}
			
		}

		GM.shutDown();
	
	}

	void GameManager::setGameOver(bool new_game_over) {
	
		game_over = new_game_over;

	}

	bool GameManager::getGameOver() const {
	
		return game_over;

	}

	int GameManager::getFrameTime() {
	
		return frame_time;
	
	}

	void GameManager::runTests(bool run) {
		
		if (run == true) {

			LM.writeLog("");
			LM.writeLog("*******");

			Clock c;

			c.testClock();

			df::Object l;

			l.testObject();

			df::Vector g;

			g.testVector();

			WM.testWorldManager();

		}
		
	}

}