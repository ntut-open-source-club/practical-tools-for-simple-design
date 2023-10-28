#ifndef GIRAFFE_HPP
#define GIRAFFE_HPP

#include "Util/GameObject.hpp"

class GiraffeText : public Util::GameObject {
public:
    GiraffeText() = default;

    GiraffeText(const std::string &font, const int size, const std::string &text)
            : m_Font(font), m_Size(size), m_Text(text) {}

    ~GiraffeText() = default;

    void Start() override;

    void Update(const Util::Transform &transform = Util::Transform()) override;

private:
    std::string m_Text;
    std::string m_Font;
    int m_Size;
};

class Giraffe : public Util::GameObject {

public:
    void Update(const Util::Transform &transform = Util::Transform()) override;

    void Start() override;
};

#endif
