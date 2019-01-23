
#include "IReportNotifier.hpp"

/*
SpecificTurnsReportNotifier::SpecificTurnsReportNotifier(const std::set<Time>& turns) {
    _turns = turns;
}
*/

bool SpecificTurnsReportNotifier::should_generate_report(Time currentTime) {
    return (_turn.find(currentTime) != _turn.end());
}

bool IntervalReportNotifier::should_generate_report(Time currentTime) {
    return ((currentTime - 1) % _interval == 0);
}
