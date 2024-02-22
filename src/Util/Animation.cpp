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
        m_State = State::PLAY;
        m_PrevUpdateTime = Util::Time::GetElapsedTimeMs();
    }

    void Animation::Update() {
        unsigned long nowTime = Util::Time::GetElapsedTimeMs();
        if (m_State == State::PAUSE) {
            LOG_TRACE("[ANI] is pause");
            if(!m_Looping) return;

            if (nowTime >= m_NextFrameTime)
            {
                m_NextFrameTime = nowTime + m_Interval;
                m_State = State::PLAY;
            }
            
            return;
        }

        m_NextFrameTime = m_PrevUpdateTime + m_Interval;
        unsigned int updateFrameCount = nowTime / m_NextFrameTime;
        unsigned int totalFramesCount = m_Frames.size();
        if(updateFrameCount > 0){
            m_Index += updateFrameCount;
            if(m_Index >= totalFramesCount ){
                m_NextFrameTime = nowTime + m_Cooldown;
                m_Index = 0;
                m_State = State::PAUSE;
            }
            m_PrevUpdateTime = nowTime;
        }
        LOG_DEBUG(m_Index);


    };
} // namespace Util
