#ifndef REPORT_NOTIFIERS_HPP_
#define REPORT_NOTIFIERS_HPP_

#include <set>
#include "data_type.hpp"

class IReportNotifier {
public:
    virtual bool should_generate_report(Time currentTime) = 0;

    virtual ~IReportNotifier() = default;
};

class SpecificTurnsReportNotifier : public IReportNotifier {
private:
    std::set<Time> _turn;
public:
    SpecificTurnsReportNotifier(const std::set<Time>& turns) {_turn = std::move(turns);}
    bool should_generate_report(Time currentTime) override;

    ~SpecificTurnsReportNotifier() = default;

};

class IntervalReportNotifier : public IReportNotifier {
public:
    IntervalReportNotifier(TimeOffset interval) : _interval(interval) {}
    bool should_generate_report(Time currentTime) override;

    ~IntervalReportNotifier() = default;
private:
    const TimeOffset _interval;
};

#endif /* REPORT_NOTIFIERS_HPP_ */