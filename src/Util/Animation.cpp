#include "Util/Animation.hpp"

#include "Util/Time.hpp"

namespace Util {
Animation::Animation(const std::vector<std::string> &paths, bool play,
                     int interval, bool looping, int cooldown)
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

void Animation::Play() {
    if (m_State == State::PLAY && !m_HasEnded) {
        return;
    }

    if (m_HasEnded) {
        m_StartTime = Util::Time::GetElapsedTimeMs();
        m_Index = 0;
        m_HasEnded = false;
    }

    if (m_State == State::PAUSE) {
        m_PauseOffset += Util::Time::GetElapsedTimeMs() - m_PauseTime;
    }

    m_State = State::PLAY;
}

void Animation::Pause() {
    if (m_State == State::PAUSE) {
        return;
    }

    m_State = State::PAUSE;
    m_PauseTime = Util::Time::GetElapsedTimeMs();
}

void Animation::Update() {
    std::size_t delta =
        Util::Time::GetElapsedTimeMs() - m_StartTime - m_PauseOffset;
    const auto totalSpan = m_Interval * m_Frames.size() + m_Cooldown;

    if (delta > totalSpan && !m_Looping) {
        m_HasEnded = true;
    }

    if (m_State == State::PAUSE || m_HasEnded) {
        return;
    }

    const auto _delta = delta % totalSpan;

    if (_delta > m_Interval * m_Frames.size()) {
        // if in cooldown, get the last frame
        m_Index = m_Frames.size() - 1;
    } else {
        m_Index = (_delta / m_Interval) % m_Frames.size();
    }

    // debug purposes
    // LOG_DEBUG("{} {}", m_Index, delta);
};
} // namespace Util
