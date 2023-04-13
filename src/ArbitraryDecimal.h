#include <vector>
#include <limits>
#include <string>
#include <sstream>
#include <numeric>

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

    // Constants
    int const numerator_max = INT_MAX;
    int const denominator_max = INT_MAX;

public:
    // Getters
    std::vector<int> const getNumerators();
    std::vector<int> const getDenominators();
    int const getSign();

    // Constructors
    ArbitraryDecimal();
    ArbitraryDecimal(std::vector<int> n, std::vector<int> d, int sign);
    ArbitraryDecimal(std::string value);
    ArbitraryDecimal(int);
    ArbitraryDecimal(long);
    ArbitraryDecimal(float);
    ArbitraryDecimal(double);

    // Arithmetic operations
    ArbitraryDecimal add      (ArbitraryDecimal other);
    ArbitraryDecimal operator+(ArbitraryDecimal other);
    ArbitraryDecimal subtract (ArbitraryDecimal other);
    ArbitraryDecimal operator-(ArbitraryDecimal other);
    ArbitraryDecimal multiply (ArbitraryDecimal other);
    ArbitraryDecimal operator*(ArbitraryDecimal other);
    ArbitraryDecimal divide   (ArbitraryDecimal other);
    ArbitraryDecimal operator/(ArbitraryDecimal other);
    ArbitraryDecimal pow      (ArbitraryDecimal other);
    ArbitraryDecimal operator^(ArbitraryDecimal other);\

    // Utility functions
    void simplifyFraction(int &numerator, int &denominator);

    // Conversions
    int const asInt();
    long const asLong();
    double const asDouble();
    float const asFloat();
    std::string const asString(int precision);
};

ArbitraryDecimal::ArbitraryDecimal()  :
numerators{(0, 0, 0)}, 
denominators{(1, 0, 1)},
sign{1}
{
    // This space left intentionally blank.
}

ArbitraryDecimal::ArbitraryDecimal(std::vector<int> n, std::vector<int> d, int sign) {
    numerators = n;
    denominators = d;
    this->sign = sign;
}


std::vector<int> const ArbitraryDecimal::getDenominators() {return denominators;}
std::vector<int> const ArbitraryDecimal::getNumerators() {return numerators;}
int const ArbitraryDecimal::getSign() {return sign;}

void ArbitraryDecimal::simplifyFraction(int &numerator, int &denominator) {
    int gcd = std::gcd(numerator, denominator);
    if (gcd != 1) {
        numerator /= gcd;
        denominator /= gcd;
    }
    return;
}

// std::string const ArbitraryDecimal::asString(int precision) {
//     std::stringstream ss;
//     for (int i = precision, index = numerators.size(); i != 0;) {
//         
//     }
// }