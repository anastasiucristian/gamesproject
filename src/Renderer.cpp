#include "Renderer.h"

static sf::RenderWindow* window;


void Renderer::initialise(sf::RenderWindow& r) { window = &r; }
sf::RenderWindow* Renderer::instance() { return window; }
