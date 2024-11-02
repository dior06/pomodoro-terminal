# Таймер метода Помодоро в терминале

## Задача

Создание удобного и функционального таймера метода Помодоро, работающего в терминале. Проект поможет пользователям эффективно управлять своим временем и повышать продуктивность.

## Сколько человек

Проект рассчитан на 1 человека.

## Функционал

1. **Основной функционал**:
    - Запуск таймера с предустановленными интервалами работы (25 минут) и отдыха (5 минут).
    - Отображение оставшегося времени в терминале.
    - Автоматический переход между рабочими и отдыхательными сессиями.

2. **Дополнительные функции**:
    - **Настройка интервалов**: возможность задавать длительность работы и отдыха через параметры командной строки (например, `pomodoro -w 30 -r 10` для 30 минут работы и 10 минут отдыха).
    - **Уведомления**: звуковые уведомления о начале и окончании сессий.
    - **Статистика**: сохранение данных о завершённых циклах в файл (например, количество выполненных Помодоро за день).

## Распределение задач

**Участник: Диёр Султонов**

- **Разработка основного функционала**:
    - Реализация запуска таймера и автоматического переключения между сессиями на языке C.
    - Отображение оставшегося времени в терминале.
    - Обработка команд командной строки для настройки интервалов.

- **Дополнительные функции**:
    - Реализация звуковых уведомлений с использованием ассемблера (например, для воспроизведения простого звукового сигнала).
    - Разработка системы сохранения и отображения статистики.
    - Добавление функций приостановки и сброса таймера.

- **Тестирование и документация**:
    - Тестирование всех функций на различных системах.
    - Подготовка подробной документации и инструкции по запуску.

## Цели проекта

1. **Основная цель**:
    - Разработать простой и эффективный таймер метода Помодоро, работающий в терминале, позволяющий пользователям устанавливать интервалы работы и отдыха.

2. **Дополнительные цели**:
    - Добавить возможность отслеживания выполненных циклов.
    - Реализовать звуковые уведомления о начале и окончании сессий.
    - Обеспечить настройку длительности рабочих и перерывных интервалов через параметры командной строки.
    - Внедрить возможность сохранения статистики в файл для анализа продуктивности.

## Definition of Done (DoD)

- Таймер запускается и работает без ошибок.
- Дополнительные функции реализованы и протестированы.
- Репозиторий содержит README с инструкциями по установке и использованию.
- Код документирован и соответствует стандартам кодирования.
- Все задачи выполнены согласно плану.

## Технологии проекта

- **Языки программирования**: C, Ассемблер.
- **Инструменты**:
    - Makefile для автоматизации сборки.
    - Git для контроля версий.
- **Библиотеки**:
    - Для уведомлений: использование стандартных возможностей терминала или простых звуковых сигналов через ассемблер.
    - Для работы с командной строкой: стандартные библиотеки C (`getopt`).
    - Для сохранения статистики: стандартные файловые операции в C.


## Инструкция по запуску

1. **Установка**:
    - Клонировать репозиторий:
      ```bash
      git clone https://github.com/ваш_аккаунт/pomodoro-terminal.git
      ```
    - Перейти в директорию проекта:
      ```bash
      cd pomodoro-terminal
      ```
    - Установить необходимые инструменты (если они ещё не установлены):
      - GCC:
        ```bash
        sudo apt-get install build-essential
        ```
      - NASM:
        ```bash
        sudo apt-get install nasm
        ```
      - Make:
        ```bash
        sudo apt-get install make
        ```

2. **Сборка проекта**:
    - Выполните команду:
      ```bash
      make
      ```
    - Это скомпилирует все исходные файлы и создаст исполняемый файл `pomodoro`.

3. **Запуск таймера**:
    - По умолчанию:
      ```bash
      ./pomodoro
      ```
    - С настройкой интервалов:
      ```bash
      ./pomodoro -w 30 -r 10
      ```

4. **Команды управления**:
    - Приостановить таймер:
      ```bash
      ./pomodoro pause
      ```
    - Сбросить таймер:
      ```bash
      ./pomodoro reset
      ```

5. **Просмотр статистики**:
    - Просмотреть количество выполненных циклов:
      ```bash
      ./pomodoro stats
      ```

## Полезная информация

- Для работы с уведомлениями в терминале буду использовать стандартные возможности терминала и простые звуковые сигналы через ассемблер.
- Планирую использовать Makefile для автоматизации сборки и управления зависимостями.
