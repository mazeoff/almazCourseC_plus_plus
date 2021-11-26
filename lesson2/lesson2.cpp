#include <iostream>
#include <string>

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

    FracNum add(FracNum op) {
        return FracNum(numerator * op.denominator + op.numerator * denominator,
            denominator * op.denominator);
    }
    FracNum mul(FracNum op) {
        return FracNum(numerator * op.numerator,
            denominator * op.denominator);
    }
    FracNum sub(FracNum op) {
        return FracNum(numerator * op.denominator - op.numerator * denominator,
            denominator * op.denominator);
    }
    FracNum div(FracNum op) {
        return FracNum(numerator * op.denominator,
            denominator * op.numerator);
    }

    string comp(FracNum op) {
        if (numerator == op.numerator && denominator == op.denominator)
            return "true";
        else
            return "false";
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

    c = a.add(b);
    cout << "Add: " + c.show() << endl;

    c = a.sub(b);
    cout << "Sub: " + c.show() << endl;

    c = a.mul(b);
    cout << "Mul: " + c.show() << endl;

    c = a.div(b);
    cout << "Div: " + c.show() << endl;

    cout << "is equal: " + a.comp(b) << endl;
}