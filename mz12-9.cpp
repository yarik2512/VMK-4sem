#include <thread>

template <typename F, typename G, class... Args>
void
async_launch(F f, G g, Args... args)
{
    std::thread t([&f, &g, &args...]() { g(f(args...)); });
    t.join();
}
