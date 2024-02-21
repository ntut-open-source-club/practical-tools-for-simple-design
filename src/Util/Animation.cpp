#include "Util/Animation.hpp"

#include "Util/Time.hpp"

namespace Util {
Animation::Animation(const std::vector<std::string> &paths, bool play,
                     std::size_t interval, bool looping, std::size_t cooldown)
    : m_StartTime(Util::Time::GetElapsedTimeMs()),
      m_Interval(interval),
      m_Looping(looping),
      m_Cooldown(cooldown),
      m_HasEnded(!play),
      m_Index(0) {
    m_Frames.reserve(paths.size());
    for (const auto &path : paths) {
        m_Frames.push_back(std::make_shared<Util::Image>(path));
    }

    Update();
}

void Animation::Draw(const Util::Transform &transform, const float zIndex) {
    m_Frames[m_Index]->Draw(transform, zIndex);
    Update();
}

void Animation::Update() {
    if (m_State == State::PAUSE) {
        LOG_DEBUG("[ANI] is pause");
        m_StartTime = Util::Time::GetElapsedTimeMs();
        return;
    }

    if (!m_Looping && m_HasEnded) {
        LOG_DEBUG("[ANI] not loop and is ended");
        m_StartTime = Util::Time::GetElapsedTimeMs();
        return;
    }

    std::size_t delta = Util::Time::GetElapsedTimeMs() - m_StartTime;

// #define TEST_UNFINISHED_OPTIMIZATION_CODE_IN_ANIMATION
#ifdef TEST_UNFINISHED_OPTIMIZATION_CODE_IN_ANIMATION
    // FIXME: while loop can be replaced with modulo
    // i.e. delta %= totalSpan

    // m_StartTime += delta;
    m_Index = 0;

    const auto totalSpan = m_Interval * m_Frames.size() + m_Cooldown;
    if (!m_Looping && delta > totalSpan) {
        LOG_DEBUG("[ANI] not loop and is end");
        m_HasEnded = true;
        m_Index = m_Frames.size() - 1;
        return;
    }

    delta %= totalSpan;

    auto step = delta / m_Interval;

    if (step < m_Frames.size()) {
        m_Index = step;
    } else {
        m_Index = m_Frames.size() - 1;
    }

    LOG_DEBUG("{} {}", m_Index, delta);
#else
    while (true) {
        auto this_interval =
            m_Interval + (m_Index >= m_Frames.size() - 1 ? m_Cooldown : 0);
        if (m_Index >= m_Frames.size() - 1) {
            if (!m_Looping) {
                m_HasEnded = true;
                return;
            }
            // if last frame it should wait for cooldown
            if (delta > m_Interval + m_Cooldown) {
                m_StartTime += m_Interval + m_Cooldown;
                m_Index = 0;
                delta -= this_interval;
            } else {
                break;
            }
        } else {
            if (delta > this_interval) {
                m_StartTime += this_interval;
                m_Index = (m_Index + 1) % m_Frames.size();
                delta -= this_interval;
            } else {
                break;
            }
        }
    }
#endif /* TEST_UNFINISHED_OPTIMIZATION_CODE_IN_ANIMATION */
};
} // namespace Util
