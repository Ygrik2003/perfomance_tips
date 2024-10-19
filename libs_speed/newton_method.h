#include <functional>

__declspec(dllexport) double newton_method(
    double x0, double h, double epsilon, std::function<double(double)>&& func);