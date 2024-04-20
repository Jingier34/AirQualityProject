#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>

#include "AirQuality.h"
#include "AirQuality.cpp"
#include "Vector.h"

using namespace std;

void readCSV(const std::string& filename, Vector<AirQuality>& data);

void showMenu(Vector<AirQuality>& data);
double averageTem(Vector<AirQuality> airLog, int year, int month);
double averageRHum(Vector<AirQuality> airLog, int year, int month);
double averageAHum(Vector<AirQuality> airLog, int year, int month);
void displayTandRH(Vector<AirQuality> airLog, Date date, Time time);
double highestT(Vector<AirQuality> airLog, int year, int month);
double highestRH(Vector<AirQuality> airLog, int year, int month);
double highestAH(Vector<AirQuality> airLog, int year, int month);
void higherThanAverageT(Vector<AirQuality> airLog, int year, int month);
void higherThanAverageRH(Vector<AirQuality> airLog, int year, int month);
void higherThanAverageAH(Vector<AirQuality> airLog, int year, int month);

int main() {
    Vector<AirQuality> airLog;
    readCSV("AirQualityUCI.csv", airLog);
    showMenu(airLog);
    return 0;
}


void showMenu(Vector<AirQuality>& data) {
    int choice;
    do {
        cout << "\nMenu:" << endl;
        cout << "1) Display the average temperature for a month" << endl;
        cout << "2) Display the average relative humidity for a month" << endl;
        cout << "3) Display the average absolute humidity for a month" << endl;
        cout << "4) Display the temperature and relative humidity for a specific date and time" << endl;
        cout << "5) Display the highest temperature for a month" << endl;
        cout << "6) Display the highest relative humidity for a month" << endl;
        cout << "7) Display the highest absolute humidity for a month" << endl;
        cout << "8) Display dates and times when temperature is higher than average for a month" << endl;
        cout << "9) Display dates and times when relative humidity is higher than average for a month" << endl;
        cout << "10) Display dates and times when absolute humidity is higher than average for a month" << endl;
        cout << "0) Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int year;
                cout << "Enter year: ";
                cin >> year;
                int month;
                cout << "Enter month: ";
                cin >> month;
                cout << "The average temperature for that month is "
                     << averageTem(data, year, month) << endl;
                break;
            }
            case 2: {
                int year;
                cout << "Enter year: ";
                cin >> year;
                int month;
                cout << "Enter month: ";
                cin >> month;
                cout << "The average relative humidity for that month is "
                     << averageRHum(data, year, month) << endl;
                break;
            }
            case 3: {
                int year;
                cout << "Enter year: ";
                cin >> year;
                int month;
                cout << "Enter month: ";
                cin >> month;
                cout << "The average absolute humidity for that month is "
                     << averageAHum(data, year, month) << endl;
                break;
            }
            case 4: {
                Date date;
                cout << "Enter date: ";
                cin >> date;
                Time time;
                cout << "Enter time: ";
                cin >> time;
                displayTandRH(data, date, time);
                break;
            }
            case 5: {
                int year;
                cout << "Enter year: ";
                cin >> year;
                int month;
                cout << "Enter month: ";
                cin >> month;
                cout << "The highest temperature for that month is "
                     << highestT(data, year, month) << endl;
                break;
            }
            case 6: {
                int year;
                cout << "Enter year: ";
                cin >> year;
                int month;
                cout << "Enter month: ";
                cin >> month;
                cout << "The highest relative humidity for that month is "
                     << highestRH(data, year, month) << endl;
                break;
            }
            case 7: {
                int year;
                cout << "Enter year: ";
                cin >> year;
                int month;
                cout << "Enter month: ";
                cin >> month;
                cout << "The highest absolute humidity for that month is "
                     << highestAH(data, year, month) << endl;
                break;
            }
            case 8: {
                int year;
                cout << "Enter year: ";
                cin >> year;
                int month;
                cout << "Enter month: ";
                cin >> month;
                higherThanAverageT(data, year, month);
                break;
            }
            case 9: {
                int year;
                cout << "Enter year: ";
                cin >> year;
                int month;
                cout << "Enter month: ";
                cin >> month;
                higherThanAverageRH(data, year, month);
                break;
            }
            case 10: {
                int year;
                cout << "Enter year: ";
                cin >> year;
                int month;
                cout << "Enter month: ";
                cin >> month;
                higherThanAverageAH(data, year, month);
                break;
            }
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);
}

double averageTem(Vector<AirQuality> airLog, int year, int month) {
    double sum = 0.0;
    int count = 0;
    for (const auto& entry : airLog) {
        if (entry.GetDate().getYear() == year && entry.GetDate().getMonth() == month) {
            sum += entry.GetTemperature();
            count++;
        }
    }
    if (count == 0) {
        cout << "No data available for the specified month." << endl;
        return 0.0;
    }
    return sum / count;
}

double averageRHum(Vector<AirQuality> airLog, int year, int month) {
    double sum = 0;
    int count = 0;
    for (const auto& entry : airLog) {
        if (entry.GetDate().getYear() == year && entry.GetDate().getMonth() == month) {
            sum += entry.GetRelativeHumidity();
            count++;
        }
    }
    if (count == 0) {
        cout << "No data available for the specified month." << endl;
        return 0;
    }
    return sum / count;
}

double averageAHum(Vector<AirQuality> airLog, int year, int month) {
    double sum = 0;
    int count = 0;
    for (const auto& entry : airLog) {
        if (entry.GetDate().getYear() == year && entry.GetDate().getMonth() == month) {
            sum += entry.GetAbsoluteHumidity();
            count++;
        }
    }
    if (count == 0) {
        cout << "No data available for the specified month." << endl;
        return 0;
    }
    return sum / count;
}

void displayTandRH(Vector<AirQuality> airLog, Date date, Time time) {
    bool found = false;
    for (const auto& entry : airLog) {
        if (entry.GetDate() == date && entry.GetTime() == time) {
            found = true;
            cout << "Temperature at " << date << " " << time << " is: " << entry.GetTemperature() << endl;
            cout << "Relative humidity at " << date << " " << time << " is: " << entry.GetRelativeHumidity() << endl;
            break;
        }
    }
    if (!found) {
        cout << "No data available for the specified date and time." << endl;
    }
}

double highestT(Vector<AirQuality> airLog, int year, int month) {
    double highest = -9999;
    for (const auto& entry : airLog) {
        if (entry.GetDate().getYear() == year && entry.GetDate().getMonth() == month) {
            if (entry.GetTemperature() > highest) {
                highest = entry.GetTemperature();
            }
        }
    }
    if (highest == -9999) {
        cout << "No data available for the specified month." << endl;
        return 0;
    }
    return highest;
}

double highestRH(Vector<AirQuality> airLog, int year, int month) {
    double highest = -9999;
    for (const auto& entry : airLog) {
        if (entry.GetDate().getYear() == year && entry.GetDate().getMonth() == month) {
            if (entry.GetRelativeHumidity() > highest) {
                highest = entry.GetRelativeHumidity();
            }
        }
    }
    if (highest == -9999) {
        cout << "No data available for the specified month." << endl;
        return 0;
    }
    return highest;
}

double highestAH(Vector<AirQuality> airLog, int year, int month) {
    double highest = -9999;
    for (const auto& entry : airLog) {
        if (entry.GetDate().getYear() == year && entry.GetDate().getMonth() == month) {
            if (entry.GetAbsoluteHumidity() > highest) {
                highest = entry.GetAbsoluteHumidity();
            }
        }
    }
    if (highest == -9999) {
        cout << "No data available for the specified month." << endl;
        return 0;
    }
    return highest;
}

void higherThanAverageT(Vector<AirQuality> airLog, int year, int month) {
    double avgTemp = averageTem(airLog, year, month);
    if (avgTemp == 0) return;

    cout << "Dates and times when temperature is higher than the average for the month:" << endl;
    for (const auto& entry : airLog) {
        if (entry.GetDate().getYear() == year && entry.GetDate().getMonth() == month) {
            if (entry.GetTemperature() > avgTemp) {
                cout << entry.GetDate() << " " << entry.GetTime() << " - Temperature: " << entry.GetTemperature() << endl;
            }
        }
    }
}

void higherThanAverageRH(Vector<AirQuality> airLog, int year, int month) {
    double avgRH = averageRHum(airLog, year, month);
    if (avgRH == 0) return;

    cout << "Dates and times when relative humidity is higher than the average for the month:" << endl;
    for (const auto& entry : airLog) {
        if (entry.GetDate().getYear() == year && entry.GetDate().getMonth() == month) {
            if (entry.GetRelativeHumidity() > avgRH) {
                cout << entry.GetDate() << " " << entry.GetTime() << " - Relative Humidity: " << entry.GetRelativeHumidity() << endl;
            }
        }
    }
}

void higherThanAverageAH(Vector<AirQuality> airLog, int year, int month) {
    double avgAH = averageAHum(airLog, year, month);
    if (avgAH == 0) return;

    cout << "Dates and times when absolute humidity is higher than the average for the month:" << endl;
    for (const auto& entry : airLog) {
        if (entry.GetDate().getYear() == year && entry.GetDate().getMonth() == month) {
            if (entry.GetAbsoluteHumidity() > avgAH) {
                cout << entry.GetDate() << " " << entry.GetTime() << " - Absolute Humidity: " << entry.GetAbsoluteHumidity() << endl;
            }
        }
    }
}
bool isNumeric(const std::string& str) {
    bool has_digit = false;  // Check if the string contains at least one digit
    for (char c : str) {
        if (std::isdigit(c)) {
            has_digit = true;
            break;
        }
    }
    return has_digit && !str.empty();
}

void readCSV(const std::string& filename, Vector<AirQuality>& data) {
    std::ifstream file(filename);
    std::string line;

    // 读取并忽略第一行的标题
    getline(file, line);

    while (getline(file, line)) {
        if (line.empty() || line.find_first_not_of(", ") == std::string::npos) continue; // 忽略空行或全逗号行

        std::stringstream lineStream(line);
        std::string dateStr, timeStr, temp, relHum, absHum;

        getline(lineStream, dateStr, ',');
        getline(lineStream, timeStr, ',');
        // 跳过中间不需要的字段直到温度、相对湿度和绝对湿度字段
        for (int i = 0; i < 11; ++i) {
            lineStream.ignore(std::numeric_limits<std::streamsize>::max(), ',');
        }
        getline(lineStream, temp, ',');
        getline(lineStream, relHum, ',');
        getline(lineStream, absHum, ',');

        try {
            Date date;
            Time time;
            std::stringstream dateStream(dateStr);
            std::stringstream timeStream(timeStr);

            dateStream >> date; // 使用重载的>>操作符
            timeStream >> time; // 使用重载的>>操作符

            // 校验并转换温度、相对湿度、绝对湿度
            double temperature = (!temp.empty() && std::all_of(temp.begin(), temp.end(), ::isdigit)) ? std::stod(temp) : std::numeric_limits<double>::quiet_NaN();
            double relativeHumidity = (!relHum.empty() && std::all_of(relHum.begin(), relHum.end(), ::isdigit)) ? std::stod(relHum) : std::numeric_limits<double>::quiet_NaN();
            double absoluteHumidity = (!absHum.empty() && std::all_of(absHum.begin(), absHum.end(), ::isdigit)) ? std::stod(absHum) : std::numeric_limits<double>::quiet_NaN();

            data.push_back(AirQuality(date, time, temperature, relativeHumidity, absoluteHumidity));
        } catch (const std::invalid_argument& e) {
            std::cerr << "Error parsing numeric fields in line: " << line << "\nException: Invalid numeric format." << std::endl;
        } catch (const std::out_of_range& e) {
            std::cerr << "Error parsing numeric fields in line: " << line << "\nException: Number out of range." << std::endl;
        }
    }

    file.close();
}


