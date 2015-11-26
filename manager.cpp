    #include <stack>

    #include <SFML/Graphics.hpp>
    #include <SFML/System.hpp>

    #include "manager.hpp"
    #include "state.hpp"

    void Manager::pushState(State* state)
    {
        this->states.push(state);

        return;
    }

    void Manager::popState()
    {
        delete this->states.top();
        this->states.pop();

        return;
    }

    void Manager::changeState(GameState* state)
    {
        if(!this->states.empty())
            popState();
        pushState(state);

        return;
    }

    State* Manager::peekState()
    {
        if(this->states.empty()) return nullptr;
        return this->states.top();
    }

    void Game::gameLoop()
    {
        sf::Clock clock;

        while(this->window.isOpen())
        {
            sf::Time elapsed = clock.restart();
            float dt = elapsed.asSeconds();

            if(peekState() == nullptr) continue;
            peekState()->handleInput();
            peekState()->update(dt);
            this->window.clear(sf::Color::Black);
            peekState()->draw(dt);
            this->window.display();
        }
    }

    Manager::Manager()
    {
        this->window.create(sf::VideoMode(800, 600), "City Builder");
        this->window.setFramerateLimit(60);
    }

    Manager::~Manager()
    {
        while(!this->states.empty()) popState();
    }
