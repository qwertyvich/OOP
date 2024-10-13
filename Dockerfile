# Используем базовый образ с GCC и CMake
FROM gcc:14.2.0

# Устанавливаем необходимые зависимости
RUN apt-get update && apt-get install -y \
    cmake \
    && rm -rf /var/lib/apt/lists/*

# Устанавливаем рабочую директорию
WORKDIR /workspace

# Копируем все файлы проекта в контейнер
COPY . /workspace

# Собираем проект с помощью CMake
RUN cmake . && make

# Указываем команду для запуска тестов или программы
CMD ["./run_tests"]