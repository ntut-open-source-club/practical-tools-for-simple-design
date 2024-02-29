#ifndef GIRAFFE_HPP
#define GIRAFFE_HPP

#include <utility>

#include "GiraffeText.hpp"
#include "Util/GameObject.hpp"
#include "Util/Text.hpp"

class Giraffe : public Util::GameObject {

public:
    void Update();

    void Start();

private:
    std::shared_ptr<GiraffeText> m_GiraffeText;
};

#endif
