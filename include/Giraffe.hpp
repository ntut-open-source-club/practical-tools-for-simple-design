#ifndef GIRAFFE_HPP
#define GIRAFFE_HPP

#include <utility>

#include "Util/GameObject.hpp"

class GiraffeText : public Util::GameObject {
public:
    GiraffeText() = default;

    GiraffeText(std::string font, const int size, std::string text)
        : m_Font(std::move(font)),
          m_Size(size),
          m_Text(std::move(text)) {}

    ~GiraffeText() override = default;

    void Start() override;

    void Update(const Util::Transform &transform = Util::Transform()) override;

private:
    std::string m_Font;
    int m_Size;
    std::string m_Text;
};

class Giraffe : public Util::GameObject {

public:
    void Update(const Util::Transform &transform = Util::Transform()) override;

    void Start() override;
};

#endif
