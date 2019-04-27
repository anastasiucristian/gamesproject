#include "Renderer.h"

/*
Renderer Function Declarations

Author: Mark Pereira
*/

static sf::RenderWindow* window;

void Renderer::initialise(sf::RenderWindow& r) { window = &r; }

sf::RenderWindow* Renderer::instance() { return window; }

bool _paused = false;

bool Renderer::isPaused() { return _paused; }
void Renderer::pause() { _paused = true; }
void Renderer::resume() { _paused = false; }
