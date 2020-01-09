#ifndef _CABLECOMPANY_H_
#define _CABLECOMPANY_H_

#include <cstddef>
#include <bitset>
#include <map>
#include <string>
#include <string_view>

const size_t kNumChannels = 10;

class CableCompany final
{
public:
    void addPackage(std::string_view packageName, const std::bitset<kNumChannels>& channels);
    void removePackage(std::string_view packageName);

    const std::bitset<kNumChannels>& getPackage(std::string_view packageName) const;

    void newCustomer(std::string_view name, std::string_view package);
    void newCustomer(std::string_view name, const std::bitset<kNumChannels>& channels);

    void addChannel(std::string_view name, int channel);
    void removeChannel(std::string_view name, int channel);

    void addPackageToCustomer(std::string_view name, std::string_view package);
    void deleteCustomer(std::string_view name);

    const std::bitset<kNumChannels>& getCustomerChannels(std::string_view name) const;

private:
    std::bitset<kNumChannels>& getCustomerChannelHelper(std::string_view name);

    using MapType = std::map<std::string, std::bitset<kNumChannels>>;
    MapType mPackages, mCustomers;
};

#endif //_CABLECOMPANY_H_
