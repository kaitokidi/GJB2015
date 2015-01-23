#include <Resources.hpp>
#include "GameManager.hpp"

int main() {
    Resources::load();
    GameManager gm(sf::VideoMode::getFullscreenModes()[0].width,sf::VideoMode::getFullscreenModes()[0].height // Size of the window <width,height>
            ,"What do we do now?" // Title of the window
            ,sf::Style::Default); // Style of the window
    gm.run();
    return 0;
}

