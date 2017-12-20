#include <iostream>
#include <utility>

class Cheburek {

private:
    std::string justField;

public:
    explicit Cheburek(std::string field)
            : justField(std::move(field)) {}

    friend bool operator==(const Cheburek &o1, const Cheburek &o2);

    friend bool operator!=(const Cheburek &o1, const Cheburek &o2);

    friend bool operator<=(const Cheburek &o1, const Cheburek &o2);

    friend bool operator>=(const Cheburek &o1, const Cheburek &o2);
};

bool operator==(const Cheburek &o1, const Cheburek &o2) {
    return (o1.justField == o2.justField);
}

bool operator!=(const Cheburek &o1, const Cheburek &o2) {
    return !(o1.justField == o2.justField);
}

bool operator<=(const Cheburek &o1, const Cheburek &o2) {
    return (o1.justField.length() <= o2.justField.length());
}

bool operator>=(const Cheburek &o1, const Cheburek &o2) {
    return (o1.justField.length() >= o2.justField.length());
}

int main() {
    Cheburek cheburek1("lol");
    Cheburek cheburek2("kek");

    if (cheburek1 == cheburek2) std::cout << "lol and kek the same\n";
    if (cheburek1 != cheburek2) std::cout << "lol and kek not the same\n";
    if (cheburek1 <= cheburek2) std::cout << "lol better than kek\n";
    if (cheburek1 >= cheburek2) std::cout << "kek better than lol\n";

    return 0;
}