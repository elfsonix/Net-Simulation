/*
#include "factory_io.hpp"
#include "factory.hpp"
#include "nodes.hpp"
#include "reports.hpp"

#include <exception>
#include <sstream>
#include <cctype>
#include <iostream>
#include <utility>
#include <iomanip>
#include <cmath>

enum class ElementType {
    LOADING_RAMP, WORKER, STOREHOUSE, LINK
};

static std::map <ElementType, std::string> elementTypeLabels = {
        {ElementType::LOADING_RAMP, "LOADING_RAMP"},
        {ElementType::WORKER,       "WORKER"},
        {ElementType::STOREHOUSE,   "STOREHOUSE"},
        {ElementType::LINK,         "LINK"}
};

struct ParsedLine {
    ElementType elementType;
    std::map <std::string, std::string> parameters;
};


std::list<ParsedLine> parseFile(filePath) {
            fstream File;
            string line, type, params;
            std::list <ParsedLine> parsedFile;
            File.open(filePath);
            if (File.is_open()) {
                while (getline(File, line)) {
                    type = line.substr(0, input.find(" "));
                    params = line.substr(1, input.find(" "));
                    ParsedLine parsedLine;
                    if (type == "LOADING_RAMP")
                        parsedLine.elementType = ElementType::LOADING_RAMP;
                    if (type == "WORKER")
                        parsedLine.elementType = ElementType::WORKER;
                    if (type == "STOREHOUSE")
                        parsedLine.elementType = ElementType::STOREHOUSE;
                    if (type == "LINK")
                        parsedLine.elementType = ElementType::LINK;
                    else
                        continue;
                    for (const auto &p : params) {
                        auto sep = p.find('=');
                        std::string key = p.substr(0, sep);
                        std::string value = p.substr(sep + 1);
                        parsedLine.parameters[key] = value;
                    }
                    parsedFile.push_back(parsedLine);

                }
    }
    return parsedFile;
}

auto parseLink = [](std::string s) {
    auto p = s.find('-');
    std::string nodeType = s.substr(0, p);
    std::string id = s.substr(p + 1);
    return std::make_pair(nodeType, stoi(id, nullptr));
};

void load_factory_structure(pathToFile) {
    std::list<ParsedLine> parsedFile = parseFile(pathToFiled);
    Factory factory;


    for (const auto& item : parsedFile) {

        switch (item.elementType) {
            case ElementType::LOADING_RAMP: {
                ElementID id = std::stoi(parsedLine.parameters["id"], nullptr);
                TimeOffset deliveryInterval = std::stoi(parsedLine.parameters["delivery-interval"], nullptr);
                Ramp r(id, deliveryInterval);
                factory.addRamp(r);
            }
                break;
            case ElementType::WORKER:
            {
                ElementID id = std::stoi(parsedLine.parameters["id"], nullptr);
                TimeOffset processingTime = std::stoi(parsedLine.parameters["processing-time"], nullptr);
                auto queueType = (parsedLine.parameters["queue-type"] == "FIFO") ? PackageQueueType::FIFO : PackageQueueType::LIFO;
                Worker w(id, processingTime, std::make_unique<PackageQueue>(queueType));
                factory.addWorker(w);
            }
                break;
            case ElementType::STOREHOUSE:
            {
                ElementID id = std::stoi(parsedLine.parameters["id"], nullptr);
                Storehouse s(id);
                factory.addStorehouse(s);
            }
                break;
            case ElementType::LINK:
            {
                auto dest = parseLink(parsedLine.parameters["dest"]);
                IPackageReceiver* packageReceiver;
                if (dest.first == "store") { packageReceiver = &(*factory.findStorehouseById(destData.second));
                } else if (destData.first == "worker") { packageReceiver = &(*factory.findWorkerById(destData.second));
                } else { throw std::runtime_error("Invalid dest type: " + dest.first);
                }
                auto prob = std::stod(parsedLine.parameters["p"]);
                links[parsedLine.parameters["src"]][pr_ptr] = prob;
            }
                break;
        }
    }

    for (const auto& entry : links) {
        auto source = parseLink(entry.first);
        PackageSender* packageSender;
        if (src.first == "ramp") { packageSender = &(*factory.findRampById(srcData.second));
        } else if (src.first == "worker") { packageSender = &(*factory.findWorkerById(src.second));
        } else { throw std::runtime_error("Invalid src type: " + src.first);
        }

        packageSender->_receiverPreferences.setPreferences(entry.second);
    }

    return factory;
}

void save_factory_structure(const Factory& factory) {
    std::ofstream outfile ("Factory.txt");
    outfile << "; == LOADING RAMPS ==" << "\n";
    outfile << "\n";
    std::for_each(factory.ramp_cbegin(), factory.ramp_cend(),
                  [&outfile](const Ramp& ramp) {
                      outfile << elementTypeLabels[ElementType::RAMP] << " " << "id=" << ramp.getId()
                         << " " << "delivery-interval=" << ramp.getDeliveryInterval() << "\n";
                  });
    outfile << "\n";

    outfile << "; == WORKERS ==" << "\n";
    outfile << "\n";
    std::for_each(factory.worker_cbegin(), factory.worker_cend(),
                  [&outfile](const Worker& worker) {
                      outfile << elementTypeLabels[ElementType::WORKER] << " " << "id=" << worker.getId()
                         << " " << "processing-time=" << worker.getProcessingDuration()
                         << " " << "queue-type=" << getPackageQueueTypeLabel(worker.getQueue()->getQueueType()) << "\n";
                  });
    outfile << "\n";

    outfile << "; == STOREHOUSES ==" << "\n";
    outfile << "\n";
    std::for_each(factory.storehouse_cbegin(), factory.storehouse_cend(),
                  [&outfile](const Storehouse& storehouse) {
                      outfile << elementTypeLabels[ElementType::STOREHOUSE] << " " << "id=" << storehouse.getId() << "\n";
                  });
    outfile << "\n";

    auto putLinkToStream = [&outfile](std::string srcType, ElementID srcId, std::string destType, ElementID destId, double prob) {
        outfile << "LINK" << " " << "src=" << srcType << "-" << srcId << " "
           << "dest=" << destType << "-" << destId << " "
           << "p=";
        if (ceil(prob) == prob) {
            outfile << std::fixed << std::setprecision(1);
        }
        outfile << prob << std::defaultfloat << "\n";
    };
    static std::map<ReceiverType, std::string> receiverTypeLabels = {
            {ReceiverType::WORKER, "worker"},
            {ReceiverType::STOREHOUSE, "store"}
    };
    outfile << "; == LINKS ==" << "\n";
    std::for_each(factory.ramp_cbegin(), factory.ramp_cend(),
                  [&outfile, &putLinkToStream](const Ramp& ramp) {
                      outfile << "\n";
                      for (const auto& entry : ramp._receiverPreferences.getPreferences()) {
                          std::string destType = receiverTypeLabels[entry.first->getReceiverType()];
                          ElementID destId = entry.first->getId();
                          double prob = entry.second;
                          putLinkToStream("ramp", ramp.getId(), destType, destId, prob);
                      }
                  });
    std::for_each(factory.worker_cbegin(), factory.worker_cend(),
                  [&outfile, &putLinkToStream](const Worker& worker) {
                      outfile << "\n";
                      for (const auto& entry : worker._receiverPreferences.getPreferences()) {
                          std::string destType = receiverTypeLabels[entry.first->getReceiverType()];
                          ElementID destId = entry.first->getId();
                          double prob = entry.second;
                          putLinkToStream("worker", worker.getId(), destType, destId, prob);
                      }
                  });

    outfile.flush();
}
*/
