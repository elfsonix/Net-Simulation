#include <Ramp.hpp>

/*
#include "Factory.hpp"
#include "reporting.hpp"
#include <iostream>
#include <algorithm>


void generate_structure_report(const Factory& factory, std::ostream& os){
    os << "\n" << " == LOADING RAMPS ==" << "\n" << "\n";
    std::for_each(factory.ramp_cbegin(), factory.ramp_cend(), [&os](const Ramp& ramp) {
        generate_structure_record_ramp(ramp, os);
        os << "\n";
    });

    os << "\n" << " == WORKERS ==" << "\n" << "\n";
    std::for_each(factory.worker_cbegin(), factory.worker_cend(), [&os](const Worker& worker) {
        generate_structure_report_worker(worker, os);
        os << "\n";
    });

    os << "\n" << " == STOREHOUSES ==" << "\n" << "\n";
    std::for_each(factory.storehouse_cbegin(), factory.storehouse_cend(), [&os](const Storehouse& storehouse) {
        generate_structure_report_storehouse(storehouse, os);
        os << "\n";
    });
}
//do zintegrowania z Factory.hpp
void generate_receiver_report(const receiver_pref preferences, std::ostream& os) {
    bool isPrefs = !(prefs.cbegin() == prefs.cend());
    if (isPrefs) {
        for (const auto &entry : preferences) {
            const IPackageReceiver *receiver = entry.first;
            os << "      " << getReceiverTypeLabel(receiver->getReceiverType()) << "-" << receiver->getId() << " (p = " << entry.second << ")" << "\n";
        }
    }
}
*/
void generate_structure_report_ramp(/*const Ramp& ramp, std::ostream& os*/) {
/*
    os << "LOADING RAMP #" << ramp.getId() << "\n";
    os << "    Delivery interval: " << ramp.getDeliveryInterval() << "\n";
    os << "    Receivers:" << "\n";
    generate_receiver_report(ramp._receiver_pref, os);*/
}
/*
void generate_structure_report_worker(const Worker& worker, std::ostream& os) {
    os << "WORKER #" << worker.getId() << "\n";
    os << "    Processing time: " << worker.getProcessingDuration() << "\n";
    os << "    Queue type: " << getPackageQueueTypeLabel((worker.getQueue())->getQueueType()) << "\n";
    os << "    Receivers:" << "\n";
    generate_receiver_report(worker._receiverPreferences, os);
}

void generate_structure_report_storehouse(const Storehouse& storehouse, std::ostream& os) {
    os << "STOREHOUSE #" << storehouse.getId() << "\n";
}

void generate_simulation_turn_report(const Factory& factory, std::ostream& os, Time currentTime) {
    os << "\n" << "== WORKERS ==" << "\n" << "\n";
    std::for_each(factory.worker_cbegin(), factory.worker_cend(), [&os, &currentTime](const Worker& worker) {
        generate_sim_report_worker(worker, os, currentTime);
        os << "\n";
    });

    os << "\n" << "== STOREHOUSES ==" << "\n" << "\n";
    std::for_each(factory.storehouse_cbegin(), factory.storehouse_cend(), [&os](const Storehouse& storehouse) {
        generate_sim_report_storehouse(storehouse, os);
        os << "\n";
    });
}

void generate_queue_report(IPackageDepot::const_iterator i, IPackageDepot::const_iterator queueEnd, std::ostream& os) {
    for (auto n = i; i != queueEnd; ++i) {
        os << "#" << (*i).getID() << ((++n == queueEnd) ? "" : ", ");
    }
}

void generate_sim_report_worker(const Worker& worker, std::ostream& os, Time currentTime) {
    os << "WORKER #" << worker.getId() << "\n";
    os << "  Queue: ";
    auto i = worker.cbegin();
    const auto& sendingBuffer = worker.getSendingBuffer();
    if (!sendingBuffer.empty()) {
        os << "#" << sendingBuffer[0].getID() << " (pt = " << worker.getProcessingDuration() << ")";
        if (!(worker.getQueue())->empty()) {
            os << ", ";
        }
    } else if (!(worker.getQueue())->empty()) {
        TimeOffset processingTime = currentTime - worker.getPackageProcessingStartTime() + 1;
        os << "#" << (*it).getID() << " (pt = " << processingTime << ")";
        ++i;
        if ((worker.getQueue())->size() > 1) {
            os << ", ";
        }
    }
    if ((worker.getQueue())->size() > 1) {
        generate_queue_report(i, worker.cend(), os);
    }
    os << "\n";
}

void generate_sim_report_storehouse(const Storehouse& storehouse, std::ostream& os) {
    os << "STOREHOUSE #" << storehouse.getId() << "\n";
    os << "  Queue: ";
    generate_queue_report(storehouse.cbegin(), storehouse.cend(), os);
    os << "\n";
}*/
