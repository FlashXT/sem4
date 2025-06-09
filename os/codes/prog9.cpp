// implement LRU algorithm.

#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class LRUCache
{
    int capacity;
    list<int> lruList;
    unordered_map<int, pair<int, list<int>::iterator>> cache;

public:
    LRUCache(int cap)
    {
        capacity = cap;
    }
    int get(int key)
    {
        if (cache.find(key) == cache.end())
        {
            return -1;
        }
        lruList.erase(cache[key].second);
        lruList.push_front(key);
        cache[key].second = lruList.begin();
        return cache[key].first;
    }

    void put(int key, int value)
    {
        if (cache.find(key) != cache.end())
        {
            lruList.erase(cache[key].second);
        }
        else if (lruList.size() == capacity)
        {
            int lruKey = lruList.back();
            lruList.pop_back();
            cache.erase(lruKey);
        }
        lruList.push_front(key);
        cache[key] = {value, lruList.begin()};
    }

    void display()
    {
        cout << "Current LRU Cache: ";
        for (int key : lruList)
        {
            cout << "[" << key << ":" << cache[key].first << "] ";
        }
        cout << endl;
    }
};

int main()
{
    cout << endl;
    
    LRUCache lru(3);
    lru.put(1, 10);
    lru.put(2, 20);
    lru.put(3, 30);
    lru.display();
    lru.get(2);

    lru.display();
    lru.put(4, 40);
    lru.display();
    cout << "Get key 3: " << lru.get(3) << endl;
    lru.display();
    cout << endl;
    return 0;
}
