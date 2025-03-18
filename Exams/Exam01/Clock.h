#ifndef CLOCK_H 
#define CLOCK_H

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 

namespace oope {

    class Clock {
        private: 
        int times [4] = {0, 0, 6, 0}; // time hour, time minute, alarm hour, alarm minute 
        int volume = 30; 
        bool switches [3] = {false, false, false}; // format, alarm state, mode 
        static const std::string meridiems[2]; // "AM", "PM"
        static int count; 

        public: 
        // Default constructor 
        Clock() {
            times[0] = 0; times[1] = 0; times[2] = 6; times[3] = 0; 
            volume = 30;
            switches[0] = false; switches[1] = false; switches[2] = false; 
            count++; 
        }

        // Copy constructor
        Clock(const Clock& other) {
            for (int i = 0; i < 4; i++) times[i] = other.times[i]; 
            volume = other.volume; 
            for (int i = 0; i < 3; i++) switches[i] = other.switches[i];
            count++; 
        }

        // Assignment operator 
        Clock& operator=(const Clock& other) {
            if (this != &other) {
                for (int i = 0; i < 4; i++) times[i] = other.times[i]; 
                volume = other.volume;
                for (int i = 0; i < 3; i++) switches[i] = other.switches[i];
            }
            return *this; 
        }

        // Destructor
        ~Clock() {
            count--; 
        }

        // Toggle mode
        void mode() {
            switches[2] = !switches[2]; 
        }

        // Toggle alarm state 
        void alarm() {
            switches[1] = !switches[1]; 
        }

        // Toggle format 
        void format() {
            switches[0] = !switches[0]; 
        }

        // Static method to return count 
        static int clocks() {
            return count; 
        }

        // Getter for hour 
        int hour() const {
            return switches[2] ? times[2] : times[0]; 
        }

        // Getter for minute
        int minute() const {
            return switches[2] ? times [3] : times[1]; 
        }

        // Getter for volume 
        int level() const {
            return volume; 
        }

        // Adjust time 
        void adjustTime(bool component, bool direction) {
            int& value = component ? (switches[2] ? times[2] : times[0]) :
            (switches[2] ? time[3] : times[1]); 
            if (direction) {
                value++; 
                if (component && value >= (switch[0] ? 13 : 24)) value = 0; 
                if (!component && value >= 60) value = 0; 
            } else {
                value--;
                if (component && value < 0) value = (switches[0] ? 12 : 23); 
                if (component && value < 0) value = 59; 
            }
        }

        // Adjust volume
        void adjustVolume (bool direction) {
            if (direction && volume < 100) volume++; 
            if (!direction && volume > 0) volume--; 
        }

        // Check if alarm sounds 
        bool sounds() const {
            return switches[1] && (times[0] > times[2] || (times[0] == times[2] && tiems[1] >= times[3])); 
        }

        // toString method 
        std::string toString() const{ 
            std::ostringstream oss; 
            int h = hour(); 
            int m = minute(); 
            if (switches[0]) { // 12-hour format 
                std::string meridiem = meridiems [h >= 12];
                h = h % 12 == 0 ? 12 : h % 12;
                oss << (switches[2] ? 'A' : 'T') << std::setw(2) << std::setfill('0') << h << ":"
                << std::setw(2) << std::setfill('0') << m << meridiem; 
            } else { // 24-hour format 
                oss << (switches[2] ? 'A' : 'T') << std::setw(2) << std::setfill('0') << h << ":"
                << std::setw(2) << std::setfill('0') << m; 
                }
                return oss.str(); 
        }

        // Friend ostream operator 
        friend std::ostream& operator<<(std::ostream& os, const Clock& clock) {
            os << clock.toString();
            return os; 
        }
    }; 

    // Static member initialization
    const std::string Clock::meridiems[2] = {"AM", "PM"}; 
    int Clock::count = 0; 

} // namespace oope 
# endif // CLOCK_H 