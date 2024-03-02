#ifndef SPRITESHEETTESTER_HPP
#define SPRITESHEETTESTER_HPP

#include "Util/GameObject.hpp"
#include "Util/Image.hpp"
class SpriteSheetTester : public Util::GameObject {
public:
    SpriteSheetTester();

    void Update();

private:
    std::shared_ptr<Util::Image> image;
};

#endif
