#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Seat {
public:
    int seatNumber;
    string passengerName;

    Seat(int number) : seatNumber(number), passengerName("") {}
};

class Bus {
public:
    string busNumber;
    string driverName;
    string arrivalTime;
    string departureTime;
    string source;
    string destination;
    vector<Seat> seats;

    Bus(const string& number, const string& driver, const string& arrival,
        const string& departure, const string& src, const string& dest,
        int totalSeats)
        : busNumber(number), driverName(driver), arrivalTime(arrival), departureTime(departure),
          source(src), destination(dest) {
        for (int i = 1; i <= totalSeats; ++i) {
            seats.push_back(Seat(i));
        }
    }
};

class ReservationSystem 
{
public:
    vector<Bus> buses;
 void installBusInformation(const string& busNumber, const string& driverName,
                               const string& arrivalTime, const string& departureTime,
                               const string& source, const string& destination,
                               int totalSeats) {
        buses.push_back(Bus(busNumber, driverName, arrivalTime, departureTime, source, destination, totalSeats));
 
    }

    void reserveSeat(const string& busNumber, int seatNumber, const string& passengerName) {
        for (auto& bus : buses) {
            if (bus.busNumber == busNumber) {
                for (auto& seat : bus.seats) {
                    if (seat.seatNumber == seatNumber) {
                        if (seat.passengerName.empty()) {
                            seat.passengerName = passengerName;
                            cout << "Seat Reserved Successfully!\n";
                        } else {
                            cout << "Seat already reserved!\n";
                        }
                        return;
                    }
                }
                cout << "Invalid Seat Number!\n";
                return;
            }
        }
        cout << "Invalid Bus Number!\n";
    }

    void showReservationInformation() const {
        for (const auto& bus : buses) {
            cout << "Bus Number: " << bus.busNumber << "\n";
            cout << "Source: " << bus.source << "\n";
            cout << "Destination: " << bus.destination << "\n";
            cout << "Driver: " << bus.driverName << "\n";
            cout << "Departure Time: " << bus.departureTime << "\n";
            cout << "Arrival Time: " << bus.arrivalTime << "\n";
            cout << "Seats:\n";
            for (const auto& seat : bus.seats) {
                cout << "Seat " << seat.seatNumber << ": ";
                if (seat.passengerName.empty()) {
                    cout << "Available\n";
                } else {
                    cout << "Reserved by " << seat.passengerName << "\n";
                }
            }
            cout << "\n";
        }
        cout << "\n";
    }

    void showAvailableBuses() const {
        cout << "Available Buses:\n";
        for (const auto& bus : buses) {
            cout << "Bus Number: " << bus.busNumber << "\n";
            cout << "Source: " << bus.source << "\n";
            cout << "Destination: " << bus.destination << "\n";
            cout << "\n";
        }
        cout<<"\n";
    }
};

int main() {

    cout << "-----------------------------------------------SRM BUS RESERVATION SYSTEM-----------------------------------------------" << endl << endl;
       ReservationSystem reservationSystem;

    reservationSystem.installBusInformation("SRM001", "Ram", "6am", "8am", "Srm_university", "vijyawada", 20);
    reservationSystem.installBusInformation("SRM002", "akhil", "7am", "8am", "Srm_university", "Guntur", 20);
    reservationSystem.installBusInformation("SRM003", "aman", "8am", "9am", "Srm_university", "manglagiri", 20);
   
    while (true) {
        //cout << "1. Install Bus Information\n";
        cout << "1. Reserve Seat\n";
        cout << "2. Show Reservation Information\n";
        cout << "3. Show Available Buses\n";
        cout << "4. Exit"<<endl<<endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                string busNumber, passengerName;
                int seatNumber;
                cout << "Enter Bus Number: ";
                cin >> busNumber;
                cout << "Enter Seat Number: ";
                cin >> seatNumber;
                cout << "Enter Passenger Name: ";
                cin >> passengerName;

                reservationSystem.reserveSeat(busNumber, seatNumber, passengerName);
                break;
            }
            case 2:
                reservationSystem.showReservationInformation();
                break;
            case 3:
                reservationSystem.showAvailableBuses();
                break;
            case 4:
                cout << "Exiting program...\n";
                return 0;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 4.\n";
        }
    }

    return 0;
}
