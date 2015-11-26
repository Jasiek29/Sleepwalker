    #ifndef MANAGER_HPP
    #define MANAGER_HPP

    #include <stack>
    #include <SFML/Graphics.hpp>

    class State;

    class Game
    {
        public:

        std::stack<State*> states;

        sf::RenderWindow window;

        void pushState(GameState* state);
        void popState();
        void changeState(GameState* state);
        GameState* peekState();

        void gameLoop();

        Game();
        ~Game();
    };

    #endif /* MANAGER_HPP */
