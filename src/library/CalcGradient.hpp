#ifndef MPIC_CALCGRADIENT
#define MPIC_CALCGRADIENT



#include <cmath>

/* This was the original function, notice that it is impossible to debug


template<typename IteratorType, typename CallablePosition, typename CallableValue>
double CalcGradient(IteratorType itr, CallablePosition Position, CallableValue Value)
{

    auto back = itr--;

    auto front = itr++;


    auto GradientWithBack =  (Value(*itr) - Value(*back)) / (Position(*itr) - Position(*back));
     auto GradientWithFront =  (Value(*itr) - Value(*front)) / (Position(*itr) - Position(*front));

     return  0.5 * (GradientWithBack + GradientWithFront);


}

*/


template<typename IteratorType, typename CallablePosition, typename CallableValue>
double CalcGradient(const IteratorType itr, const CallablePosition Position, const CallableValue Value)
{

    const auto back = itr - 1;

    const auto front = itr + 1;


    const auto PositionCurrent = Position(*itr);
    const auto PositionBack = Position(*back);
    const auto PositionFront = Position(*front);

    const auto ValueCurrent = Value(*itr) ;
    const auto ValueBack = Value(*back);
    const auto ValueFront = Value(*front);



    const auto PositionDifferenceWithBack = (PositionCurrent - PositionBack);
    const auto ValueDifferenceWithBack = (ValueCurrent - ValueBack) ;
    const auto PositionDifferenceWithFront = (PositionCurrent - PositionFront);
    const auto ValueDifferenceWithFront = (ValueCurrent - ValueFront) ;

    const auto GradientWithBack =  ValueDifferenceWithBack / PositionDifferenceWithBack;
    const auto GradientWithFront =  ValueDifferenceWithFront / PositionDifferenceWithFront;

    const auto FinalGradient = 0.5 * (GradientWithBack + GradientWithFront);

    return  FinalGradient;


}


template<typename IteratorType, typename CallablePosition, typename CallableValue>
double CalcLaplacian(const IteratorType itr, const CallablePosition Position, const CallableValue Value)
{

    const auto back = itr - 1;

    const auto front = itr + 1;


    const auto PositionCurrent = Position(*itr);
    const auto PositionBack = Position(*back);
    const auto PositionFront = Position(*front);

    const auto ValueCurrent = Value(*itr) ;
    const auto ValueBack = Value(*back);
    const auto ValueFront = Value(*front);



    const auto PositionDifferenceWithBack = (PositionCurrent - PositionBack);
    const auto ValueDifferenceWithBack = (ValueCurrent - ValueBack) ;
    const auto PositionDifferenceWithFront = (PositionCurrent - PositionFront);
    const auto ValueDifferenceWithFront = (ValueCurrent - ValueFront) ;

    const auto GradientWithBack =  ValueDifferenceWithBack / PositionDifferenceWithBack;
    const auto GradientWithFront =  ValueDifferenceWithFront / PositionDifferenceWithFront;

    const auto GradientDifference = (GradientWithBack - GradientWithFront);
    const auto PositionDifferencesOfGradients = (0.5 * (std::abs(PositionDifferenceWithBack) + std::abs(PositionDifferenceWithFront)) );

    const auto FinalLaplacian =  GradientDifference/ PositionDifferencesOfGradients;

    return  FinalLaplacian;


}





#endif /* MPIC_CALCGRADIENT */
