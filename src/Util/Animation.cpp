#include "Util/Animation.hpp"

#include "Util/Time.hpp"

namespace Util {
Animation::Animation(const std::vector<std::string> &paths, int interval,
                     bool looping, int cooldown)
    : m_StartTime(Util::Time::GetElapsedTimeMs()),
      m_Interval(interval),
      m_Looping(looping),
      m_Cooldown(cooldown),
      m_Index(0) {
    m_Frames.reserve(paths.size());
    for (const auto &path : paths) {
        m_Frames.push_back(std::make_shared<Util::Image>(path));
    }
}

std::shared_ptr<Util::Image> Animation::GetCurrentFrame() {
    std::size_t delta = Util::Time::GetElapsedTimeMs() - m_StartTime;

    if (m_Looping) {
        // if looping, trim off extra time
        const auto totalSpan = m_Interval * m_Frames.size() + m_Cooldown;
        delta %= totalSpan;
    }

    if (delta > m_Interval * m_Frames.size()) {
        // if in cooldown, get the last frame
        m_Index = m_Frames.size() - 1;
    } else {
        m_Index = (delta / m_Interval) % m_Frames.size();
    }

    return m_Frames[m_Index];
};

} // namespace Util
