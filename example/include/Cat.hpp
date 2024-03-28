#ifndef CAT_HPP
#define CAT_HPP

#include "pch.hpp"

#include "Util/Animation.hpp"
#include "Util/GameObject.hpp"

class Cat : public Util::GameObject {
public:
    Cat();

    void Update();

private:
    std::shared_ptr<Util::Animation> m_Animation;
};

#endif
