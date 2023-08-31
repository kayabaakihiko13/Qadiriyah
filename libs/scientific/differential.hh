#include<cmath>
#include<iostream>

namespace differential{
    /**
     * utility class for calculating derivatives using various
     * rules.
     * provides method to calculation deriveaties using power rule,
     * produce rule and quotion rule
    */
    float derivative(float(*f)(float),float x,float h =1e-6){
        /**
         * @brief  the divaritive of a function using limit definition
         * @param *f this is a input function value to be deviativetial
         * @param x this paramater for input value number for par *f
         * @param h this is a chance value form 0 to until value like
         *          diviatiavetial.
         * 
         * @return (float): the calculate derivative
        */
        return (f(x + h) - f(x))/h;
    }


    float power_derivative(int n,float x){
        /**
         * @brief the power derivative is function using the power rule
         * @param n is the exponent of power function
         * @param x is the value a which to calculate the derivate
         * 
         * @return (float): the calculate derivative
        */
        try
        {
            // change from int to float
            n =static_cast<float>(n);
            return n * pow(x, n-1);
        }
        catch(const std::exception& e)
        {
            std::cerr << "errors: " <<e.what() << '\n';
            return 0.0;
        }
        
    }


    float quotient_derivate(float(*u)(float),float(*v)(float),float x){
        /**
         * @brief the derivative of the quotient of two functions u(x)
         *        and v(x) using quitent rule
         * @param *u is a first numerator function u(x)
         * @param *v is a second numerator function v(x)
         * @param x is value at which to calculate the derivative
        */
        try
        {
            float u_devirative = u(x);
            float v_devirative = v(x);
            return (v_devirative * u(x) - u_devirative * v(x)) / pow(v(x),2);
        }

        catch(const std::exception& error_quotient_derivate)
        {
            std::cerr<<"Error: " << error_quotient_derivate.what()
            << std::endl;
            return 0.0;
        }

    }
}