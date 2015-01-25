#include <Resources.hpp>
#include "GameManager.hpp"
#include <SFML/Audio.hpp>

int main() {
	//	WE LOVE PENGUINS
    Resources::load();
    
    sf::Music music;
    if (!music.openFromFile("res/music.ogg")) std::cout << " no puc carregar la musica  http://www.bensound.com/" << std::endl;
    music.play();
    music.setPitch(1);
    music.setLoop(true);

    GameManager gm(sf::VideoMode::getFullscreenModes()[0].width,sf::VideoMode::getFullscreenModes()[0].height // Size of the window <width,height>
            ,"What do we do now?" // Title of the window
            ,sf::Style::Default); // Style of the window
    gm.run();
    return 0;
}

