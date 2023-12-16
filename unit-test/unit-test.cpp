
#include "pch.h"
#include "CppUnitTest.h"
#include "../precipitations/process.h"
#include "../precipitations/prepositions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


TEST_CLASS(PRPTests)
{
public:
    TEST_METHOD(TestMonthlyPrepositions)
    {
        int testSize = 2;
        prp_stuff** testSubscriptions = new prp_stuff * [testSize];

        // Подготовка тестовых данных
        testSubscriptions[0] = new prp_stuff{ {15, 3}, 100.0, "Type1" };
        testSubscriptions[1] = new prp_stuff{ {20, 5}, 150.0, "Type2" };

        // Тестирование для определенного месяца
        int testMonth = 5;

        // Расчет ожидаемой суммы на основе тестовых данных
        float expectedSum = 150.0;

        // Вызов функции для получения результата
        float result = monthly_prepositions(testSubscriptions, testSize, testMonth);

        // Проверка результата с использованием утверждения
        Assert::AreEqual(expectedSum, result, L"The monthly prepositions calculation is incorrect.");

        // Очистка динамически выделенной памяти
        for (int i = 0; i < testSize; i++)
        {
            delete testSubscriptions[i];
        }
        delete[] testSubscriptions;
    }
};
