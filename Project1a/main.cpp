
#include <SFML/Graphics.hpp>
#include <iostream>
#include "LogManager.h"
#include "Clock.h"
#include "Object.h"
#include "GameManager.h"
#include "Windows.h"
#include "DisplayManager.h"
#include "Color.h"


int main(int argc, const char* argv[])
{
	LM.setFlush(true);

	GM.run();

}