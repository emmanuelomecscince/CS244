#ifdef CLOCK_H
#define CLOCK_H

# include <iostream>
# include <iomanip>
# include <string>
# include <sstream>

namespace oope {
    class Clock {
    private:
        int times[4]; // {time hour, time minute, alarm hour, alarm minute}
        int volume;
        bool switches[3]; // {format, alarm state, mode}
        static const std::string meridiems[2]; // {"AM", "PM"}
        static int count;

    public:
        // Default constructor
        Clock() : times{0, 0, 6, 0}, volume(30), switches{false, false, false} {
            ++count;
        }

        // Copy constructor
        Clock(const Clock& other) {
            for (int i = 0; i < 4; ++i) {
                times[i] = other.times[i];
            }

            volume = other.volume;
            for (int i = 0; i < 3; ++i) {
                switches[i] = other.switches[i];
            }

            ++count;

        }

        // Assignment operator
        Clock& operator=(const Clock& other) {
            if (this != &other) {
                for (int i = 0; i < 4; ++i) {
                    times[i] = other.times[i];

                }

                volume = other.volume;
                for (int i = 0; i < 3; ++i) {
                    switches[i] = other.switches[i];

                }

            }

            return *this;

        }

        // Destructor
        ~Clock() {
            --count;

        }

        // Toggle mode
        voidmode() {
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

        // Static method to get the count of Clock objects
        static int clocks() {
            return count;

        }

        // Getter for hour of the mode
        int hour() const {
            return switches[2] ? times[2] : times[0];

        }

        // Getter for minute of the mode
        int minute() const {
            return switches[2] ? times[3] : times[1];

        }

        // Getter for volume
        int level() const {
            return volume;

        }

        // Adjust time
        void adjustTime(bool isHour, bool increment) {
            int& component = isHour ? (switches[2] ? times[2] : times[0]) : (switches[2] ? times[3] : times[1]);
            if (increment) {
                if (isHour) {
                    component = (component + 1) % (switches[0] ? 12 : 24);
                } else {
                    component = (component + 1) % 60;
                }
            } else {
                if (isHour) {
                    component = (component - 1 + (switches[0] ? 12 : 24)) % (switches[0] ? 12 : 24);
                } else {
                    component = (component - 1 + 60) % 60;

                }

            }

        }

        // Adjust volume
        void adjustVolume(bool increment) {
            if (increment && volume < 100) {
                ++volume;
            } else if (!increment && volume > 0) {
                --volume;
            }
        }

        // Check if the alarm sounds
        bool sounds() const {
            return switches[1] && (times[0] > times[2] || (times[0] == times[2] && times[1] >= times[3]));

        }

        // Convert to string
        std::string toString() const {
            std::ostringstream oss;
            int h = hour();
            int m = minute();
            std::string meridiem = "";
            if (switches[0]) { // 12-hour format
                meridiem = meridiems[h / 12];
                h = h % 12;
                if (h == 0) h = 12;

            }

            oss << (switches[2] ? 'A' : 'T') << "(" << volume << ")"
                << std::setw(2) << std::setfill('0') << h << ":"
                << std::setw(2) << std::setfill('0') << m
                << meridiem;

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
#endif // CLOCK_H
