#include "Util/Animation.hpp"

#include "Util/Time.hpp"

namespace Util {
Animation::Animation(const std::vector<std::string> &paths, bool play,
                     std::size_t interval, bool looping, std::size_t cooldown)
    : m_LastFrameStartTime(Util::Time::GetElapsedTimeMs()),
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
        LOG_TRACE("[ANI] is pause");
        m_LastFrameStartTime = Util::Time::GetElapsedTimeMs();
        return;
    }

    if (!m_Looping && m_HasEnded) {
        LOG_TRACE("[ANI] not loop and is ended");
        m_LastFrameStartTime = Util::Time::GetElapsedTimeMs();
        return;
    }

    std::size_t delta = Util::Time::GetElapsedTimeMs() - m_LastFrameStartTime;

    // FIXME: maybe less if

    if (!m_Looping) {
        if (delta > m_Interval) {
            m_LastFrameStartTime += (delta / m_Interval) * m_Interval;
            m_Index += delta / m_Interval;
        }

        if (m_Index >= m_Frames.size() - 1) {
            m_HasEnded = true;
            m_Index = m_Frames.size() - 1;
        }
    } else {
        const auto totalSpan = m_Interval * m_Frames.size() + m_Cooldown;

        const auto spanCount = delta / totalSpan;
        m_LastFrameStartTime += totalSpan * spanCount;
        delta %= totalSpan;

        auto addFrameCount = 0;

        if (m_Index == m_Frames.size() - 1) {
            if (delta > m_Interval + m_Cooldown) {
                addFrameCount = (delta - m_Cooldown) / m_Interval;

                m_LastFrameStartTime += addFrameCount * m_Interval + m_Cooldown;
            }
        } else if (delta > m_Interval) {
            addFrameCount = delta / m_Interval;

            m_LastFrameStartTime += addFrameCount * m_Interval;
        }

        m_Index = (m_Index + addFrameCount) % m_Frames.size();

        LOG_DEBUG("{} {}", m_Index, delta);
    }
};
} // namespace Util
