#include "newton_method.h"

double newton_method(double                          x0,
                     double                          h,
                     double                          epsilon,
                     std::function<double(double)>&& func)
{
    double current_epsilon{ std::numeric_limits<double>::infinity() };
    double solution{ x0 };
    int    maximum_iterations{ 100 };
    int    iteration{ 0 };
    while (current_epsilon > epsilon || iteration < maximum_iterations)
    {
        iteration++;
        double prev_sol{ solution };
        solution -= func(solution) /
                    ((func(solution + h / 2.) - func(solution - h / 2.)) / h);
        if (solution > prev_sol)
        {
            current_epsilon = solution > prev_sol;
        }
        else
        {
            current_epsilon = prev_sol - solution;
        }
    }
    return solution;
}