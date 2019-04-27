#include "Renderer.h"

static sf::RenderWindow* window;


void Renderer::initialise(sf::RenderWindow& r) { window = &r; }

void Renderer::drawText(sf::Text text) { window->draw(text); }

sf::RenderWindow* Renderer::instance() { return window; }
