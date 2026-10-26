# Замечания к лабораторной 2

## Соответствие заданию

`Distance`, `Square` и `Distance_to_line` есть, проект разбит на `header.h`, `source.cpp` и `main.cpp`. В `main.cpp` для них напечатаны ожидаемые значения (5, 6, 3), но отдельного тестового файла нет. Функции лабораторной 1 тестами не покрыты. Дополнительно сделаны `struct point`, перегрузка `Distance(point, point)`, `enum triangle_type`, `Check_triangle_type` и `Check_triangle_type_new`.

## Ошибки

`Check_triangle_type` в `source.cpp` возвращает 0 и для произвольного треугольника, и когда треугольника нет:

```cpp
if (ab == 0.0 || bc == 0.0 || ca == 0.0 ||
    ab + bc <= ca || ab + ca <= bc || bc + ca <= ab) return 0;
```

В `enum triangle_type` ноль — это `tArbitrary`. `Check_triangle_type_new` делает `static_cast<triangle_type>` из этого кода, поэтому вырожденные точки получают то же значение, что и разносторонний треугольник.

## Оформление

Заголовок закрыт `#ifndef LAB2_HEADER_H`, тела функций лежат в `source.cpp`. Корень для расстояния написан своим циклом, `<cmath>` не нужен.
