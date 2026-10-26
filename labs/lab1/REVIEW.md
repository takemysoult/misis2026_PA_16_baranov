# Замечания к лабораторной 1

## Соответствие заданию

Обязательные пункты закрыты в `header.h`, `source.cpp` и `main.cpp`. Факториал на `long long` для `n < 0` и `n > 20` возвращает `-1`. Количество и сумма цифр в `main.cpp` выведены для 123, 22345, -56, 7, 0, -1. `order` упорядочивает пару `int` и пару `double`. Четыре `inline`-варианта `maximum` записаны в заголовке. Для 1231 вызывается `removeFirstAndLastDigits`, для 123 — `swapFirstAndLastDigits`. Дополнительно сделаны `countBinaryDigits` и `equalsSumOfDigitPowers`.

## Ошибки

Логических ошибок по прочитанному коду не видно.

## Оформление

Заголовок закрыт `#ifndef LAB1_HEADER_H`. Реализация в `source.cpp`, `using namespace std` стоит только в `main.cpp`. У факториала граница 20 написана явно.
