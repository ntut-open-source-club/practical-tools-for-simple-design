#include "Util/Animation.hpp"

#include "Util/Time.hpp"

namespace Util {
Animation::Animation(const std::vector<std::string> &paths, int interval,
                     bool looping, int cooldown)
    : m_StartTime(Util::Time::GetElapsedTimeMs()),
      m_Interval(interval),
      m_Looping(looping),
      m_Cooldown(cooldown) {
    m_Frames.reserve(paths.size());
    for (const auto &path : paths) {
        m_Frames.push_back(std::make_shared<Util::Image>(path));
    }
}
std::shared_ptr<Util::Image> Animation::GetCurrentFrame() const {
    // TODO: doesn't account for interval, cooldown, frame changes
    auto delta = Util::Time::GetElapsedTimeMs() - m_StartTime;
    auto index = (delta / m_Interval) % m_Frames.size();
    return m_Frames[index];
};

} // namespace Util
