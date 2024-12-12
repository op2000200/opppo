#include <gtest/gtest.h>
#include "OOP.cpp" // Укажите путь вашего файла с объявлениями

// Тест для функции loadTestElements
TEST(FileManagementTests, LoadTestElements) {
    loadTestElements();
    EXPECT_EQ(fileVector.size(), expected_size); // Установите ожидаемый размер

    // Проверяем, что некоторые элементы загружены
    EXPECT_EQ(fileVector[0].type, Picture);
    EXPECT_EQ(fileVector[5].type, Video);
    EXPECT_EQ(fileVector[8].type, Audio);
}

// Тест для функции addElem
TEST(FileManagementTests, AddElem) {
    int initial_size = fileVector.size();
    addElem(); // здесь мы должны как-то имитировать ввод пользователя

    EXPECT_EQ(fileVector.size(), initial_size + 1); // Убедитесь, что размер увеличился
    // Дополнительные проверки, чтобы удостовериться в корректности добавленного элемента
}

// Тест для функции remElem
TEST(FileManagementTests, RemElem) {
    loadTestElements(); // Загружаем элементы для тестирования

    int initial_size = fileVector.size();
    remElem(); // Здесь тоже нужно имитировать ввод пользователя

    EXPECT_EQ(fileVector.size(), initial_size - 1); // Убедитесь, что размер уменьшился
}

// Тест для выходной функции обработки ввода
TEST(FileManagementTests, HandleInvalidInput) {
    std::string invalid_input = "not_a_number";
    std::istringstream input_stream(invalid_input);
    std::cin.rdbuf(input_stream.rdbuf()); // Подменяем стандартный ввод

    // Здесь нужно имитировать вызов функции, которая будет обрабатывать ввод
    // Например,  firstMessage(); и т.д.
    
    // Затем дополнительно проверяем вывод или состояние
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}