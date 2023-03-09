#include <vector>
#include <limits>
#include <string>

class ArbitraryDecimal {

private:
    // ArbitraryDecimals are constructed as a set of two
    // vectors represeting the numerators and denominators
    // of an ordered set of fractional digits.
    std::vector<int> numerators;
    std::vector<int> denominators;
    
    // Utility values
    // Sign will be 1 if the value is positive and -1 if the value is negative.
    int sign;
    int separator_index;

    // Constants
    int const numerator_max = INT_MAX;
    int const denominator_max = INT_MAX;

public:
    // Getters
    std::vector<int> const getNumerators();
    std::vector<int> const getDenominators();
    int const getSeparatorIndex();
    int const getSign();

    // Constructors
    ArbitraryDecimal();
    ArbitraryDecimal(std::string value);
    ArbitraryDecimal(int);
    ArbitraryDecimal(long);
    ArbitraryDecimal(float);
    ArbitraryDecimal(double);

    // Arithmetic operations
    ArbitraryDecimal add (ArbitraryDecimal other);
    ArbitraryDecimal subtract (ArbitraryDecimal other);
    ArbitraryDecimal multiply (ArbitraryDecimal other);
    ArbitraryDecimal divide (ArbitraryDecimal other);
    ArbitraryDecimal pow (ArbitraryDecimal other);

    // Conversions
    int const asInt();
    long const asLong();
    double const asDouble();
    float const asFloat();
    std::string const asString();
};

ArbitraryDecimal::ArbitraryDecimal()  :
numerators{(0, 0, 0)}, 
denominators{(1, 0, 1)},
sign{1}, 
separator_index{1}
{
    // This space left intentionally blank.
}

std::vector<int> const ArbitraryDecimal::getDenominators() {return denominators;}
std::vector<int> const ArbitraryDecimal::getNumerators() {return numerators;}
int const ArbitraryDecimal::getSeparatorIndex() {return separator_index;}
int const ArbitraryDecimal::getSign() {return sign;}