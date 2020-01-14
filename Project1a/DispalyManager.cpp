
#include <SFML/Graphics.hpp>
#include "DisplayManager.h"
#include "LogManager.h"

namespace df {

	DisplayManager::DisplayManager() {

		setType("DisplayManager");

		m_font;

		m_window_horizontal_pixels = WINDOW_HORIZONTAL_PIXELS_DEFAULT;

		m_window_vertical_pixels = WINDOW_VERTICAL_PIXELS_DEFAULT;

		m_window_horizontal_characters = WINDOW_HORIZONTAL_CHARS_DEFAULT;

		m_window_vertical_characters = WINDOW_VERTICAL_CHARS_DEFAULT;

		m_p_window = NULL;

	}

	DisplayManager& DisplayManager::getInstance() {

		static DisplayManager instance;
		return instance;

	}

	int DisplayManager::startUp() {

		bool var;

		if (m_p_window != NULL) {

			return 0;

		}

		m_p_window = new sf::RenderWindow(sf::VideoMode(m_window_horizontal_pixels, m_window_vertical_pixels),
			WINDOW_TITLE_DEFAULT);
		if (!m_p_window) {

			LM.writeLog("Error unable to allocate renderwindow");
			return -1;
		}

		if (m_p_window == NULL) {

			return -1;

		}

		m_p_window->setMouseCursorVisible(false);

		m_p_window->setVerticalSyncEnabled(true);

		sf::Font font;

		if (font.loadFromFile(FONT_FILE_DEFAULT) == false) {
			LM.writeLog("Failed to load font");
			return -1;
		}

		m_font.loadFromFile(FONT_FILE_DEFAULT);

		if (m_p_window != NULL) {
			Manager::startUp();
		}
		return 0;

	}

	void DisplayManager::shutDown() {

		m_p_window->close();

		Manager::shutDown();
	}

	float charHeight() {

		float num = DM.getVerticalPixels() / DM.getVertical();

		return num;

	}

	float charWidth() {

		float num = DM.getHorizontalPixels() / DM.getHorzontal();

		return num;

	}

	Vector spacesToPixels(Vector spaces) {

		Vector x;

		float numa = spaces.getX() * charWidth();

		float numb = spaces.getY() * charHeight();

		x.setXY(numa, numb);

		return x;

	}

	Vector pixelsToSpaces(Vector pixels) {

		Vector x;

		float numa = pixels.getX() / charWidth();

		float numb = pixels.getY() / charHeight();

		x.setXY(numa, numb);

		return x;

	}

	int DisplayManager::drawCh(Vector world_pos, char ch, Color color) {

		if (m_p_window == NULL) {

			return -1;
		}

		Vector pixel_pos = spacesToPixels(world_pos);

		static sf::RectangleShape rectangle;
		rectangle.setSize(sf::Vector2f(charWidth(), charHeight()));
		rectangle.setFillColor(WINDOW_BACKGROUND_COLOR_DEFAULT);
		rectangle.setPosition(pixel_pos.getX() - charWidth() / 10, pixel_pos.getY() + charHeight() / 5);
		m_p_window->draw(rectangle);

		static sf::Text text("", m_font);
		text.setString(ch);
		text.setStyle(sf::Text::Bold);

		if (charWidth() < charHeight()) {
			text.setCharacterSize(charWidth() * 2);
			
		}
		else {
			text.setCharacterSize(charHeight() * 2);
			
		}

		switch (color) {
		case YELLOW:

			text.setFillColor(sf::Color::Yellow);
			break;
		case RED:

			text.setFillColor(sf::Color::Red);
			break;
		case GREEN:
			
			text.setFillColor(sf::Color::Green);
			break;
		case BLUE:
			
			text.setFillColor(sf::Color::Blue);
			break;
		case MAGENTA:
			
			text.setFillColor(sf::Color::Magenta);
			break;
		case CYAN:
			
			text.setFillColor(sf::Color::Cyan);
			break;
		case WHITE:
			
			text.setFillColor(sf::Color::White);
			break;
		case BLACK:
			
			text.setFillColor(sf::Color::Black);
			break;
		case UNDEFINED_COLOR:
			
			text.setFillColor(sf::Color::White);
			break;
		default:
			LM.writeLog("Default");
			text.setFillColor(sf::Color::White);
			break;
		}

		text.setPosition(pixel_pos.getX(), pixel_pos.getY());

		m_p_window->draw(text);

	}

	int DisplayManager::drawString(Vector pos, std::string str, Justification just,
		Color color) const {

		Vector starting_pos = pos;
		switch (just){
		case CENTER_JUSTIFIED:
			starting_pos.setX(pos.getX() - str.size() / 2);
			break;
		case RIGHT_JUSTIFIED:
			starting_pos.setX(pos.getX() - str.size());
			break;
		case LEFT_JUSTIFIED:
		default:
			break;
		}

		for (int i = 0; i <= str.size(); i++) {

			Vector temp_pos(starting_pos.getX() + i, starting_pos.getY());
			DM.drawCh(temp_pos, str[i], color);

		}

		return 0;

	}

	int DisplayManager::getHorzontal() const {
		return m_window_horizontal_characters;;

	}

	int DisplayManager::getVertical() const {

		return m_window_vertical_characters;
	}

	int DisplayManager::getHorizontalPixels() {

		return m_window_horizontal_pixels;

	}

	int DisplayManager::getVerticalPixels() {

		return m_window_vertical_pixels;

	}

	int DisplayManager::swapBuffers() {
		if (m_p_window == NULL) {
			LM.writeLog("m_p_window == NULL. Return error.");
			return -1;

		}

		m_p_window->display();

		m_p_window->clear();

		return 0;

	}

	sf::RenderWindow* DisplayManager::getWindow() const {

		return m_p_window;

	}



};