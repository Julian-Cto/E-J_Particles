#include "Engine.h"

Engine::Engine()
{
    VideoMode vm(VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height);
    m_Window.create(vm, "Particle", Style::Default);
}
void Engine::run()
{
    cout << "Starting Particle unit tests..." << endl;
    Particle p(m_Window, 4, { (int)m_Window.getSize().x / 2, (int)m_Window.getSize().y / 2 });
    p.unitTests();
    cout << "Unit tests complete.  Starting engine..." << endl;
}
void Engine::input()
{

}
void Engine::update(float dtAsSeconds)
{

}
void Engine::draw()
{

}
