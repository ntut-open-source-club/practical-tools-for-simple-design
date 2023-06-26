#ifndef GIRAFFE_HPP
#define GIRAFFE_HPP

#include "Util/Image.hpp"

class Giraffe {
public:
    void Update();

private:
    Util::Image m_Image = Util::Image("../assets/sprites/giraffe.png");
};

#endif
