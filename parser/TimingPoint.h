#include <vector>

class TimingPoint {
public:
    TimingPoint();
    ~TimingPoint();
    int time;
    double bpm;
    int meter;
    int sampleType;
    int sampleSet;
    int volume;
    int inherited;
    int kiai;
};

