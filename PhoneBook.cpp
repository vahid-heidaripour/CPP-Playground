#include <cstddef>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

template <typename T>
void printMap(const T& m)
{
    for (auto& [key, value] : m) {
        cout << key << " (Phone: " << value << ")" << endl;
    }

    // In case that the compiler doesn't support the C++17 structured bindings
    // yet, then use the following for loop.
    //for (auto& p : m) {
    //	cout << p.first << " (Phone: " << p.second << ")" << endl;
    //}

    cout << "------------------" << endl;
}

int main()
{
    //a hash table
    unordered_map<string, string> phoneBook = {
            { "Vahid H.", "123-456789"},
            { "Mori R.", "987-654321"}
    };

    printMap(phoneBook);

    //add or remove phone numbers
    phoneBook.insert(make_pair("Moji E.", "321-987654"));
    phoneBook["Emad A."] = "789-654321";
    phoneBook["Paulo C."] = "998-123123";
    phoneBook.erase("Paulo C.");
    printMap(phoneBook);

    //find the bucket index for a specific key.
    const size_t bucket = phoneBook.bucket("Emad A.");
    cout << "Emad A. is in bucket " << bucket
         << " which contains the following "
         << phoneBook.bucket_size(bucket) << " elements: " << endl;

    //get begin and end iterators for the elements in this bucket.
    //'auto' is used here. The compiler deduces the type of
    //both as unordered_map<string, string>::const_local_iterator
    auto localBegin = phoneBook.cbegin(bucket);
    auto localEnd = phoneBook.cend(bucket);
    for (auto iter = localBegin; iter != localEnd; ++iter) {
        cout << "\t" << iter->first << " (Phone: "
             << iter->second << ")" << endl;
    }
    cout << "------------------" << endl;

    //print some statistics about the hash table
    cout << "There are " << phoneBook.bucket_count() << " buckets." << endl;
    cout << "Average number of elements in a bucket is " << phoneBook.load_factor() << endl;

    return 0;
}