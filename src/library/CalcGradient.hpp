#ifndef MPIC_CALCGRADIENT
#define MPIC_CALCGRADIENT






template<typename IteratorType, typename CallablePosition, typename CallableValue>
double CalcGradient(IteratorType itr, CallablePosition Position, CallableValue Value)
{

    auto back = itr--;

    auto front = itr++;


    auto GradientWithBack =  (Value(*itr) - Value(*back)) / (Position(*itr) - Position(*back));
     auto GradientWithFront =  (Value(*itr) - Value(*front)) / (Position(*itr) - Position(*front));

     return  0.5 * (GradientWithBack + GradientWithFront);


}





#endif /* MPIC_CALCGRADIENT */
