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

    Clock clock;

    while (m_Window.isOpen())
    {
        Time elapsedTime = clock.restart();
        float seconds = elapsedTime.asSeconds();
        input();
        update(seconds);
        draw();
    }
}
void Engine::input()
{
    Event event;
    while (m_Window.pollEvent(event))
    {
        if (event.type == Event::Closed)
        {
           m_Window.close();
        }
        else if (event.type == Event::MouseButtonPressed)
        {
            Vector2i mousePixel{ event.mouseButton.x, event.mouseButton.y };
            cout << "Clicked at pixel coordinate: (" << mousePixel.x << ", " << mousePixel.y << ")" << endl;

            if (event.mouseButton.button == Mouse::Left)
            {
                for (int i = 0; i < 5; i++)
                {
                    int randNumPoints = rand() % (50 - 25 + 1) + 25;
                    Particle particle(m_Window, randNumPoints, mousePixel);
                }
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            m_Window.close();
        }
    }
}
void Engine::update(float dtAsSeconds)
{
    vector<Particle>::iterator iter;
    for (iter = m_particles.begin(); iter != m_particles.end();)
    {
        if (iter->getTTL() > 0.0)
        {
            iter->update(dtAsSeconds);
            iter++;
        }
        else
        {
                m_particles.erase(iter);
        }
    }
}
void Engine::draw()
{
    m_Window.clear();
    for (int i = 0; i < m_particles.size(); i++)
    {
        m_Window.draw(m_particles[i]);
    }
    m_Window.display();
}
