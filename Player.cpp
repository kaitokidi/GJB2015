#include "Player.hpp"
#include "Stone.hpp"
#include "Resources.hpp"
#include "GameManager.hpp"


Player::Player() {}


Player::Player(GameManager *gm) /*: Collisionable(gm, &Resources::playerTexture, PLAYER_SIZE_X[PState::shoes], PLAYER_SIZE_Y[PState::shoes], 1, 1)*/:
    Collisionable(gm, &Resources::playerTexture, Resources::playerTexture.getSize().x/4, Resources::playerTexture.getSize().y/4, 4, 4) {
    direction = Dir::none;
    level= PState::shoes;
    spriteSource = sf::Vector2u(0,Dir::none);
    scont = 0;
    sprite.setPosition(2600,400);
    jumping = false;
    jumpTimer = 0;
    lastDir = Dir::none;
    lastState = PState::idleRight;
    loadNewLevel(level);
    pushing = false;
    sprint = false;
    maxS = PLAYER_MAX_SPEED[level];
}


Player::Player(GameManager *gm, float px, float py) /*: Collisionable(gm, &Resources::playerTexture, PLAYER_SIZE_X[PState::shoes], PLAYER_SIZE_Y[PState::shoes], 1, 1)*/:
    Collisionable(gm, &Resources::playerTexture, Resources::playerTexture.getSize().x/4, Resources::playerTexture.getSize().y/4, 4, 4) {
    direction = Dir::none;
    level = PState::shoes;
    spriteSource = sf::Vector2u(0,Dir::none);
    scont = 0;
    sprite.setPosition(px,py);
    sprint=false;
    maxS = PLAYER_MAX_SPEED[level];
}

Player::~Player() {

}


void Player::draw(sf::RenderWindow* window) {
    window->draw(sprite);
}

void Player::jump(bool jump){
    if (onGround && jump) {
        jumping = true;
        speed.y = 0;
        jumpTimer = PLAYER_JUMP_TIME[level]/1000;
    }
    else if (!(jumping && jump)) jumping = false;
}

Dir::Direction Player::getDirection() {
    return direction;
}

void Player::update(float deltaTime) {  
    maxS = PLAYER_MAX_SPEED[level]; 
    if(sprint)maxS= PLAYER_MAX_SPEED[level]*2;
    if (direction == Dir::none or lastDir != direction) pushing = false;
    if (jumping && jumpTimer > 0) {
        speed.y = -PLAYER_JUMP_SPEED;
        jumpTimer -= deltaTime;
    }
    else speed.y += GRAVITY*deltaTime;
    if(direction == Dir::none){
        if (speed.x > 0){
            speed.x -= 1.5*PLAYER_ACCELERATION[level]*deltaTime;
            if(speed.x < 0) speed.x = 0;
        }
        else if( speed.x < 0) {
            speed.x += 1.5*PLAYER_ACCELERATION[level]*deltaTime;
            if (speed.x > 0) speed.x = 0;
        }
    }
    else if(direction == Dir::left){
        lastDir = direction;
        if (speed.x > 0){
            speed.x -= 1.5*PLAYER_ACCELERATION[level]*deltaTime;
        }
        else {
            speed.x -= PLAYER_ACCELERATION[level]*deltaTime;
            if (speed.x < -maxS) speed.x = -maxS;
        }
    }
    else if(direction == Dir::right){
        lastDir = direction;
        if (speed.x < 0) {
            speed.x += 1.5*PLAYER_ACCELERATION[level]*deltaTime;
        }
        else {
            speed.x += PLAYER_ACCELERATION[level]*deltaTime;
            if (speed.x > maxS) speed.x = maxS;
        }
//        if (speed.x >= 0){
//            speed.x += PLAYER_ACCELERATION[level]*deltaTime;
//            if(speed.x > maxS) speed.x = maxS;
//        }
//        else {
//            speed.x += 1.5*PLAYER_ACCELERATION[level]*deltaTime;
//            if (speed.x > 0) speed.x = 0;
//        }
    }


    //Colisions amb el mon & moviment
    float x = sprite.getPosition().x;
    float y = sprite.getPosition().y;
    
    int collision1 = collisionVertical(x,y+deltaTime*speed.y);
    int collision2 = collisionHorizontal(x+deltaTime*speed.x,y);
    int collision3 = collisionHorizontal(x+deltaTime*speed.x,y+deltaTime*speed.y);
    if (collision1 == 2 || collision2 == 2) {
        speed = sf::Vector2f(0,0);
        sprite.setPosition(lastGround);
    }
    else {
        if (collision1) {
            if (speed.y > 0) onGround = true;
            speed.y = 0;
        }
        else onGround = false;
        if (collision2) speed.x = 0;
        if (collision3 && !collision1 && !collision2) speed = sf::Vector2f(0,0);
        //colisions amb caixes
        for(uint i = 0; i < this->gm->getStones().size();++i){
            Collisionable* c = gm->getStones()[i];
            Collisionable p = *this;
            p.setPosition(sprite.getPosition().x+speed.x*deltaTime,sprite.getPosition().y+speed.y*deltaTime);
            if (Collisionable::areCollisioning(&p, c)) {
                if (y+spriteHeight < c->getPosition().y) {
                    speed.y = 0;
                    onGround = true;
                }
                else {
                    speed.x = 0;
                    if(level >= 2) {
                        pushing = true;
                        c->move(direction);
                    }

                }
            }
        }

        //colisions amb bodyParts
        for(uint i = 0; i < this->gm->getBodyParts().size();++i){
            BodyPart* c = gm->getBodyParts()[i];
            Collisionable p = *this;
            p.setPosition(sprite.getPosition().x+speed.x*deltaTime,sprite.getPosition().y+speed.y*deltaTime);
//             std::cout << " " << level << " , "  << std::endl;
            if (Collisionable::areCollisioning(&p, c)) {
//                  std::cout << "COOOOOOOOOOOOL" << level << " , " << c->getId() << std::endl;
                if(c->getId() == level+1){
                    level = level+1;
                    loadNewLevel(level);
                    gm->eliminaElBody(i);
                }
            }
        }
        
        //colisions Doors
        for(uint i = 0; i < this->gm->getDoors().size();++i){
            Collisionable* c = gm->getDoors()[i];
            Collisionable p = *this;
            p.setPosition(sprite.getPosition().x+speed.x*deltaTime,sprite.getPosition().y+speed.y*deltaTime);
            if (Collisionable::areCollisioning(&p, c)) {
                if (y+spriteHeight < c->getPosition().y) {
                    speed.y = 0;
                }
                else {
                    speed.x = 0;
                }
            }
        }
        
        //colisions Buttons
        for(uint i = 0; i < this->gm->getButtons().size();++i){
            Collisionable* c = gm->getButtons()[i];
            Collisionable p = *this;
            p.setPosition(sprite.getPosition().x+speed.x*deltaTime,sprite.getPosition().y+speed.y*deltaTime);
            if (Collisionable::areCollisioning(&p, c) && level >= 5) {
                if (gm->getButtons()[i]->getID() == 1) { //aball
                    gm->getDoors()[2]->moveDown(true);
                }
                if (gm->getButtons()[i]->getID() == 2) { //aball
                    gm->getDoors()[0]->moveDown(true);
                }
                else {
                    gm->getDoors()[gm->getButtons()[1]->getID()]->moveDown(true);
                }
            }
        }
        
        if(level > 2) {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
                sprint=true;
            }
            else sprint=false;
        }

        sprite.setPosition(sprite.getPosition().x+speed.x*deltaTime,sprite.getPosition().y+speed.y*deltaTime);
    }
    if (onGround) lastGround = sprite.getPosition();

    animation(deltaTime);

}


void Player::loadNewLevel(int level) {
    spriteHeight = PLAYER_SIZE_Y[level];
    spriteWidth = PLAYER_SIZE_X[level];
    scont = 0;

    switch (level) {
    case PState::shoes:
        sprite.setTexture(Resources::playerShoes);
        nSprites = SHOES_N;
        time_to_next_sprite = SHOES_TIMER;
        break;
    case PState::legs:
        sprite.setTexture(Resources::playerLegs);
        nSprites = LEGS_N;
        time_to_next_sprite = LEGS_TIMER;
        sprite.setPosition(sprite.getPosition().x,sprite.getPosition().y-125);
        break;
    case PState::body:
    case PState::arms:
        sprite.setTexture(Resources::playerArms);
        nSprites = ARMS_N;
        time_to_next_sprite = ARMS_TIMER;
        break;
    case PState::hands:
        sprite.setTexture(Resources::playerHands);
        nSprites = HANDS_N;
        time_to_next_sprite = HANDS_TIMER;
        break;
    case PState::head:
        sprite.setTexture(Resources::playerHead);
        nSprites = HEAD_N;
        time_to_next_sprite = HEAD_TIMER;
        break;
    default:
        break;
    }
}

void Player::animation(float deltaTime) {
    scont += deltaTime;
    if (speed.x == 0) {
        if (direction == Dir::right or lastDir == Dir::right) spriteSource.y = PState::idleRight;
        else spriteSource.y = PState::idleLeft;
    }
    else if (speed.x > 0) {
        if (sprint) spriteSource.y = PState::runningRight;
        else spriteSource.y = PState::walkingRight;
    }
    else {
        if (sprint) spriteSource.y = PState::runningLeft;
        else spriteSource.y = PState::walkingLeft;
    }
    if (pushing && level > 2) {
        if (direction == Dir::right or lastDir == Dir::right) spriteSource.y = PState::pushingRight;
        else spriteSource.y = PState::pushingLeft;
    }
    if (!onGround && level > 0) {
        if (direction == Dir::right or lastDir == Dir::right) spriteSource.y = PState::jumpingRight;
        else spriteSource.y = PState::jumpingLeft;
    }

    nextFrame();
    sprite.setTextureRect(sf::IntRect(spriteSource.x*spriteWidth,
                                      spriteSource.y*spriteHeight, spriteWidth, spriteHeight));
}

void Player::nextFrame() {
    if ((lastState == PState::jumpingLeft  && spriteSource.y == PState::jumpingRight) ||
        (lastState == PState::jumpingRight && spriteSource.y == PState::jumpingLeft)) spriteSource.x = 6-spriteSource.x;
    else if (lastState != spriteSource.y) spriteSource.x = 0;
    lastState = spriteSource.y;
    int n = 1;
    if (spriteSource.y % 2 == 1) n = -1;
    if (scont >= time_to_next_sprite[spriteSource.y]){
        scont = 0;
        if (spriteSource.y == PState::jumpingLeft || spriteSource.y == PState::jumpingRight) {
            if ((speed.y < 0 && spriteSource.x < 3) || (speed.y > 0 && spriteSource.x < 6)) spriteSource.x = (spriteSource.x+n)%nSprites[spriteSource.y];
        }
        else spriteSource.x = (spriteSource.x+n)%nSprites[spriteSource.y];
    }
}
