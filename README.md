# Внешняя сортировка с интерфейсом ленты

## Запуск

```bash
mkdir build && cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make
./tape_sort <input> <output> <memory size>
```

## Описание

- Интерфейс ленты представлен в файле [tape.h](tape.h) 
- Реализация интерфейса для файловой ленты: [file_tape.h](file_tape.h) и [file_tape.cpp](file_tape.cpp)

- Реализована внешняя сортировка слиянием
    - Файл разбивается на батчи передаваемого размера
    - После этого батчи сортируются в памяти (для этого использовался `std::sort`)
    - Затем файлы сливаются (использовался `k-merge` на куче)

- Ради простоты и наглядности использовалось текстовое представление файла 
