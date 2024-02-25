#include "Util/Animation.hpp"

#include "Util/Time.hpp"

namespace Util {
Animation::Animation(const std::vector<std::string> &paths, bool play,
                     std::size_t interval, bool looping, std::size_t cooldown)
    : m_State(play ? State::PLAY : State::PAUSE),
      m_PrevUpdateTime(Util::Time::GetElapsedTimeMs()),
      m_Interval(interval),
      m_Looping(looping),
      m_Cooldown(cooldown),
      m_Index(0) {
    m_Frames.reserve(paths.size());
    for (const auto &path : paths) {
        m_Frames.push_back(std::make_shared<Util::Image>(path));
    }
}

void Animation::SetCurrentFrame(std::size_t index) {
    m_Index = index;
    m_PrevUpdateTime = Util::Time::GetElapsedTimeMs();
}

void Animation::Draw(const Util::Transform &transform, const float zIndex) {
    m_Frames[m_Index]->Draw(transform, zIndex);
    Update();
}

void Animation::Play() {
    if (m_State == State::PLAY)
        return;
    m_State = State::PLAY;
    m_PrevUpdateTime = Util::Time::GetElapsedTimeMs();
}

void Animation::Pause() {
    if (m_State == State::PAUSE || m_State == State::ENDED)
        return;
    m_State = State::PAUSE;
}

void Animation::Update() {
    unsigned long nowTime = Util::Time::GetElapsedTimeMs();
    if (m_State == State::PAUSE || m_State == State::ENDED) {
        LOG_TRACE("[ANI] is pause");
        return;
    }

    if (m_State == State::COOLDOWN) {
        if (nowTime >= m_NextFrameTime) {
            m_NextFrameTime = nowTime + m_Interval;
            m_State = State::PLAY;
        }
        return;
    }

    m_NextFrameTime = m_PrevUpdateTime + m_Interval;
    unsigned int updateFrameCount = nowTime / m_NextFrameTime;
    unsigned int totalFramesCount = m_Frames.size();
    if (updateFrameCount <= 0)
        return;

    m_Index += updateFrameCount;
    m_PrevUpdateTime = nowTime;

    if (m_Index >= totalFramesCount) {
        m_Index = 0;
        if (m_Looping) {
            m_NextFrameTime = m_PrevUpdateTime + m_Cooldown;
        }
        m_State = m_Looping ? State::COOLDOWN : State::ENDED;
    }
};
} // namespace Util
