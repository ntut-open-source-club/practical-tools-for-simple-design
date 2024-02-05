#ifndef GIRAFFE_HPP
#define GIRAFFE_HPP

#include <utility>

#include "Util/GameObject.hpp"
#include "Util/Text.hpp"

class Giraffe : public Util::GameObject {

public:
    void Update(const Util::Transform &transform = Util::Transform()) override;

    void Start() override;
};

#endif
