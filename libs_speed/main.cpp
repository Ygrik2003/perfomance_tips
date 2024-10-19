#include "newton_method.h"

#include <algorithm>
#include <chrono>
#include <iostream>
#include <numeric>
#include <vector>

double func(double x)
{
    return std::pow(x, 3) - 2 * std::pow(x, 2) + 1;
}

template <typename T>
void print_speed_info(T&& function_for_test, size_t count = 100000)
{
    using std::chrono::duration;
    using std::chrono::duration_cast;
    using std::chrono::high_resolution_clock;
    using std::chrono::milliseconds;

    std::vector<duration<double, std::milli>> durations;
    durations.resize(count);

    std::for_each(
        durations.begin(),
        durations.end(),
        [&function_for_test](duration<double, std::milli>& current_dur)
        {
            auto t1 = high_resolution_clock::now();
            function_for_test(0., 1e-6, 1e-12, func);
            auto t2     = high_resolution_clock::now();
            current_dur = t2 - t1;
        });

    double full_sum{ 0 };
    std::for_each(durations.begin(),
                  durations.end(),
                  [&full_sum](duration<double, std::milli>& current_dur)
                  { full_sum += current_dur.count(); });
    std::cout << full_sum / durations.size() << "ms\n";
}

int main()
{
    double result = newton_method(0., 1e-4, 1e-12, func);
    std::cout << "Root: " << result << std::endl;
    std::cout << "Result precision: " << func(result) << std::endl;

    print_speed_info(newton_method);

    return EXIT_SUCCESS;
}