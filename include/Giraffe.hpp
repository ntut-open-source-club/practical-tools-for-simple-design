#ifndef GIRAFFE_HPP
#define GIRAFFE_HPP

#include "Util/Image.hpp"
#include "Util/Text.hpp"
#include "Util/Transform.hpp"

class Giraffe {
public:
    void Update();

private:
    Util::Image m_Image = Util::Image("../assets/sprites/giraffe.png");
    Util::Text m_Text = Util::Text("../assets/fonts/Inter.ttf", 500, "Giraffe");
};

#endif
