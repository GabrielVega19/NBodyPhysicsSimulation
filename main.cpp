#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "universe.h"

using std::cout;
using std::endl;
using std::cin;
using std::to_string;

int main(int argc, char* argv[]){
    if (argc != 3){
        cout << "You need to include 2 arguments 1st for the amount of time to run and 2nd for the amount of time to step" << endl;
        exit(-1);
    }

    //sets up variables for use in the program
    double t = 0;
    double T = atof(argv[1]);
    double deltaT = atof(argv[2]);
    int windowSize = 600;
    Universe universe(windowSize);
    
    //sets up the window for the simulation and limits framerate to 60 fps
    sf::RenderWindow window(sf::VideoMode(windowSize, windowSize), "Universe Window");
    window.setFramerateLimit(60);

    //sets up the text for the timer in the simulation
    sf::Font font;
    font.loadFromFile("arial.ttf");
    sf::Text titleText("Elapsed Time: ", font, 15);
    sf::Text numberText("0", font , 15);
    numberText.setPosition(100, 0);

    //sets up audio for the simulation
    sf::Music music;
    music.openFromFile("2001.wav");
    music.play();
    music.setLoop(true);

    //sets up the background for the simulation
    sf::Texture texture;
    texture.loadFromFile("starfield.jpg");
    sf::Vector2u size = texture.getSize();
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sf::Vector2f scale(static_cast<float>(windowSize) / size.x, static_cast<float>(windowSize) / size.y);
    sprite.setScale(scale);

    //main program loop for the window
    while (window.isOpen() && t < T)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //set up window for planets to be drawn 
        window.clear();
        window.draw(sprite);

        //computes the new frame 
        universe.step(deltaT);
        t += deltaT;
        numberText.setString(to_string(t));


        //print planets and timer
        for (auto x: universe.myVector){
            window.draw(*x);
        }
        window.draw(titleText);
        window.draw(numberText);
        window.display();
    }

    //prints out the ending planet information
    cout << std::scientific;
    for (auto x: universe.myVector){
        cout << *x;
    }

    return 0;
}