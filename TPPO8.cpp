#include <iostream>
#include <stdexcept>
#include <limits.h>
#include <gtest/gtest.h>

int findRemainder(int x, int y) {
    if (y == 0) {
        throw std::invalid_argument("Деление на ноль не допускается");
    }
    if (x == INT_MIN && y == -1) {
        return 0; 
    }
    return x % y;
}

TEST(RemainderTest, PositiveNumbers) {
    EXPECT_EQ(2, findRemainder(5, 3));
    EXPECT_EQ(0, findRemainder(10, 2));
    EXPECT_EQ(1, findRemainder(10, 3));
}

TEST(RemainderTest, NegativeNumbers) {
    EXPECT_EQ(-1, findRemainder(-5, 2));
    EXPECT_EQ(-1, findRemainder(-5, -2));
    EXPECT_EQ(1, findRemainder(5, -2));
}

TEST(RemainderTest, ZeroCases) {
    EXPECT_EQ(0, findRemainder(0, 5));
    EXPECT_THROW(findRemainder(5, 0), std::invalid_argument);
}

TEST(RemainderTest, EdgeCases) {
    EXPECT_EQ(0, findRemainder(INT_MAX, 1));
    EXPECT_EQ(0, findRemainder(INT_MIN, 1));  
}

int main(int argc, char** argv) {
    system("chcp 1251");
    std::cout << "Калькулятор остатка\n";
    std::cout << "-------------------\n";

    try {
        int x, y;
        std::cout << "Введите x: ";
        std::cin >> x;
        std::cout << "Введите y: ";
        std::cin >> y;

        int remainder = findRemainder(x, y);
        std::cout << "Остаток " << x << " делится на " << y
            << " является: " << remainder << "\n";
    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << "\n";
    }

    std::cout << "\nЗапуск Unit-тестов...\n";
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
