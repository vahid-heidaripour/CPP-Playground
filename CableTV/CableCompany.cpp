#include "CableCompany.h"
#include <stdexcept>
#include <utility>

using namespace std;

void CableCompany::addPackage(std::string_view packageName, const std::bitset<kNumChannels> &channels)
{
    mPackages.emplace(packageName, channels);
}

void CableCompany::removePackage(std::string_view packageName)
{
    mPackages.erase(packageName.data());
}

const std::bitset<kNumChannels>& CableCompany::getPackage(std::string_view packageName) const
{
    auto it = mPackages.find(packageName.data());
    if (it == end(mPackages)) {
        throw out_of_range("Invalid package");
    }

    return it->second;
}

void CableCompany::newCustomer(std::string_view name, std::string_view package)
{
    auto& packageChannels = getPackage(package);
    newCustomer(name, packageChannels);
}

void CableCompany::newCustomer(std::string_view name, const std::bitset<kNumChannels> &channels)
{
    auto result = mCustomers.emplace(name, channels);
    if (!result.second) {
        throw invalid_argument("Duplicate customer");
    }
}

void CableCompany::addChannel(std::string_view name, int channel)
{
    auto& customerChannels = getCustomerChannelHelper(name);
    customerChannels.set(channel);
}

void CableCompany::removeChannel(std::string_view name, int channel)
{
    auto& customerChannels = getCustomerChannelHelper(name);
    customerChannels.reset(channel);
}

void CableCompany::addPackageToCustomer(std::string_view name, std::string_view package)
{
    auto& packageChannels = getPackage(package);
    auto& customerChannels = getCustomerChannelHelper(name);
    customerChannels |= packageChannels;
}

void CableCompany::deleteCustomer(std::string_view name)
{
    mCustomers.erase(name.data());
}

const std::bitset<kNumChannels>& CableCompany::getCustomerChannels(std::string_view name) const
{
    return const_cast<CableCompany*>(this)->getCustomerChannelHelper(name);
}

std::bitset<kNumChannels>& CableCompany::getCustomerChannelHelper(std::string_view name)
{
    auto it = mCustomers.find(name.data());
    if (it == end(mCustomers)) {
        throw invalid_argument("Unknown customer");
    }

    return it->second;
}