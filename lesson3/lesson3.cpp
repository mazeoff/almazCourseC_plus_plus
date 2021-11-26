#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class FracNum {
private:
    int numerator, denominator;
public:
    FracNum(int m_numerator = 0, int m_denominator = 0) {
        setNumerator(m_numerator);
        setDenominator(m_denominator);
    }
    void setDenominator(int m_denominator) {
        denominator = m_denominator;
    }
    void setNumerator(int m_numerator) {
        numerator = m_numerator;
    }
    int getDenominator() {
        return denominator;
    }
    int getNumerator() {
        return numerator;
    }
    string show() {
        return to_string(numerator) + "/" + to_string(denominator);
    }

    FracNum operator+(FracNum op) {
        return FracNum(numerator * op.denominator + op.numerator * denominator,
            denominator * op.denominator);
    }
    FracNum operator*(FracNum op) {
        return FracNum(numerator * op.numerator,
            denominator * op.denominator);
    }
    FracNum operator-(FracNum op) {
        return FracNum(numerator * op.denominator - op.numerator * denominator,
            denominator * op.denominator);
    }
    FracNum operator/(FracNum op) {
        return FracNum(numerator * op.denominator,
            denominator * op.numerator);
    }

    bool operator==(FracNum op) {
        return numerator == op.numerator && denominator == op.denominator;
    }
    bool operator!=(FracNum op) {
        return !(numerator == op.numerator && denominator == op.denominator);
    }

    bool operator>(FracNum op) {
        int commonDenominator;
        commonDenominator = denominator * op.denominator;
        numerator *= op.denominator;
        op.numerator *= denominator;

        return numerator > op.numerator;
    }
    bool operator<(FracNum op) {
        int commonDenominator;
        commonDenominator = denominator * op.denominator;
        numerator *= op.denominator;
        op.numerator *= denominator;

        return numerator < op.numerator;
    }

    bool operator>=(FracNum op) {
        int commonDenominator;
        commonDenominator = denominator * op.denominator;
        numerator *= op.denominator;
        op.numerator *= denominator;

        return numerator >= op.numerator;
    }
    bool operator<=(FracNum op) {
        int commonDenominator;
        commonDenominator = denominator * op.denominator;
        numerator *= op.denominator;
        op.numerator *= denominator;

        return numerator <= op.numerator;
    }

    void operator+=(FracNum op) {
        numerator = numerator * op.denominator + op.numerator * denominator;
        denominator = denominator * op.denominator;
    }
    void operator-=(FracNum op) {
        numerator = numerator * op.denominator - op.numerator * denominator;
        denominator = denominator * op.denominator;
    }
    void operator*=(FracNum op) {
        numerator = numerator * op.numerator;
        denominator = denominator * op.denominator;
    }
    void operator/=(FracNum op) {
        numerator = numerator * op.denominator;
        denominator = denominator * op.numerator;
    }

};
int main()
{
    FracNum a;
    FracNum b;
    FracNum c;

    a.setNumerator(3);
    a.setDenominator(4);

    b.setNumerator(5);
    b.setDenominator(6);
    a *= b;
    cout << a.show();
}
