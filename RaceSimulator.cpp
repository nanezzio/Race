#include <iostream>
#include <locale>
#include <limits>
#include <memory>
#include <string>
#include <vector>

#ifdef _WIN32
#define NOMINMAX
#include <Windows.h>
#endif

#include "../RaceLibrary/Race.h"
#include "../RaceLibrary/Camel.h"
#include "../RaceLibrary/FastCamel.h"
#include "../RaceLibrary/Centaur.h"
#include "../RaceLibrary/Boots.h"
#include "../RaceLibrary/MagicCarpet.h"
#include "../RaceLibrary/Eagle.h"
#include "../RaceLibrary/Broom.h"

int getIntInput(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;
        if (std::cin.fail() || value < 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Некорректный ввод. Попробуйте снова.\n";
        }
        else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
    }
}

double getDoubleInput(const std::string& prompt) {
    double value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;
        if (std::cin.fail() || value <= 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Длина должна быть положительным числом. Попробуйте снова.\n";
        }
        else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
    }
}

std::unique_ptr<Vehicle> createVehicle(int choice) {
    switch (choice) {
    case 1: return std::unique_ptr<Vehicle>(new Boots());
    case 2: return std::unique_ptr<Vehicle>(new Broom());
    case 3: return std::unique_ptr<Vehicle>(new Camel());
    case 4: return std::unique_ptr<Vehicle>(new Centaur());
    case 5: return std::unique_ptr<Vehicle>(new Eagle());
    case 6: return std::unique_ptr<Vehicle>(new FastCamel());
    case 7: return std::unique_ptr<Vehicle>(new MagicCarpet());
    default: return nullptr;
    }
}

std::string getVehicleNameByIndex(int idx) {
    switch (idx) {
    case 1: return "Ботинки-вездеходы";
    case 2: return "Метла";
    case 3: return "Верблюд";
    case 4: return "Кентавр";
    case 5: return "Орёл";
    case 6: return "Верблюд-быстроход";
    case 7: return "Ковёр-самолёт";
    default: return "";
    }
}

void printRegistered(const Race& race) {
    const auto& participants = race.getParticipants();
    if (participants.empty()) {
        std::cout << "Пока нет зарегистрированных ТС.\n";
    }
    else {
        std::cout << "Зарегистрированные транспортные средства: ";
        for (size_t i = 0; i < participants.size(); ++i) {
            std::cout << participants[i]->getName();
            if (i != participants.size() - 1) std::cout << ", ";
        }
        std::cout << "\n";
    }
}

void printRegistrationMenu(const Race& race) {
    std::cout << "\nГонка ";
    switch (race.getRaceType()) {
    case RaceType::GroundOnly: std::cout << "для наземного транспорта"; break;
    case RaceType::AirOnly:    std::cout << "для воздушного транспорта"; break;
    case RaceType::Mixed:      std::cout << "для наземного и воздушного транспорта"; break;
    }
    std::cout << ". Расстояние: " << race.getDistance() << "\n";
    printRegistered(race);
    std::cout << "1. Ботинки-вездеходы\n";
    std::cout << "2. Метла\n";
    std::cout << "3. Верблюд\n";
    std::cout << "4. Кентавр\n";
    std::cout << "5. Орёл\n";
    std::cout << "6. Верблюд-быстроход\n";
    std::cout << "7. Ковёр-самолёт\n";
    std::cout << "8. Закончить регистрацию\n";
}

void runRaceLoop() {
    while (true) {
        std::cout << "\nДобро пожаловать в гоночный симулятор!\n";
        std::cout << "1. Гонка для наземного транспорта\n";
        std::cout << "2. Гонка для воздушного транспорта\n";
        std::cout << "3. Гонка для наземного и воздушного транспорта\n";
        int raceTypeChoice = getIntInput("Выберите тип гонки: ");

        RaceType raceType;
        if (raceTypeChoice == 1) raceType = RaceType::GroundOnly;
        else if (raceTypeChoice == 2) raceType = RaceType::AirOnly;
        else if (raceTypeChoice == 3) raceType = RaceType::Mixed;
        else {
            std::cout << "Неверный выбор. Попробуйте снова.\n";
            continue;
        }

        double distance = getDoubleInput("Укажите длину дистанции (должна быть положительна): ");
        Race race(raceType, distance);

        bool registrationComplete = false;
        while (!registrationComplete) {
            std::cout << "\n1. Зарегистрировать транспорт\n";
            std::cout << "2. Начать гонку\n";
            int action = getIntInput("Выберите действие: ");

            if (action == 1) {
                bool regMenu = true;
                while (regMenu) {
                    printRegistrationMenu(race);
                    int choice = getIntInput("Выберите транспорт или 8 для окончания регистрации: ");

                    if (choice >= 1 && choice <= 7) {
                        auto vehicle = createVehicle(choice);
                        if (vehicle) {
                            Vehicle* raw = vehicle.release();
                            if (race.addVehicle(raw)) {
                                std::cout << getVehicleNameByIndex(choice) << " успешно зарегистрирован!\n";
                            }
                            else {
                                delete raw;
                                std::cout << getVehicleNameByIndex(choice) << " не может быть зарегистрирован (возможно, уже участвует или не подходит для этого типа гонки).\n";
                            }
                        }
                    }
                    else if (choice == 8 || choice == 0) {
                        regMenu = false;
                    }
                    else {
                        std::cout << "Неверный выбор. Попробуйте снова.\n";
                    }
                }
            }
            else if (action == 2) {
                if (!race.canStart()) {
                    std::cout << "Недостаточно участников для гонки (нужно минимум 2). Зарегистрируйте ещё транспорт.\n";
                }
                else {
                    auto results = race.runRace();
                    std::cout << "\nРезультаты гонки:\n";
                    for (size_t i = 0; i < results.size(); ++i) {
                        std::cout << i + 1 << ". " << results[i].first->getName() << ". Время: " << results[i].second << "\n";
                    }
                    registrationComplete = true; 
                }
            }
            else {
                std::cout << "Неверный выбор. Попробуйте снова.\n";
            }
        }

        std::cout << "\n1. Провести ещё одну гонку\n";
        std::cout << "2. Выйти\n";
        int finalChoice = getIntInput("Выберите действие: ");
        if (finalChoice == 2) break;
    }
    std::cout << "До свидания!\n";
}

int main() 
{
#ifdef _WIN32
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
#endif

    runRaceLoop();

    return EXIT_SUCCESS;
}