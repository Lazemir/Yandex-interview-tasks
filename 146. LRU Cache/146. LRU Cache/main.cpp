//
//  main.cpp
//  146. LRU Cache
//
//  Created by Артём Lazemir on 10.12.2022.
//

#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

class LRUCache {
public:

    LRUCache(int capacity) : capacity(capacity), key_list_map(capacity), size(0) {}
    
    void move_front(list<pair<int, int>>& val_list, list<pair<int, int>>::iterator& it) {
        val_list.push_front(*it);
        val_list.erase(it);
        it = val_list.begin();
    }
    
    int get(int key) {
        auto flag = key_list_map.find(key) != key_list_map.end();
        if (flag) {
            auto& it = key_list_map[key];
            move_front(val_list, it);
            return it->second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        auto flag = key_list_map.find(key) != key_list_map.end();
        auto& it = key_list_map[key];
        
        if (flag) {
            move_front(val_list, it);
            it->second = value;
        } else {
            if (size == capacity) {
                auto del_key = val_list.back().first;
                auto del_it = key_list_map[del_key];
                key_list_map.erase(del_key);
                val_list.erase(del_it);
                --size;
            }
            
            val_list.push_front({key, value});
            key_list_map[key] = val_list.begin();
            ++size;
        }
    }
private:
    list<pair<int, int>> val_list;
    unordered_map<int, list<pair<int, int>>::iterator> key_list_map;
    size_t size, capacity;
};

int main(int argc, const char * argv[]) {
    LRUCache container(2);
    
    container.put(2, 1);
    container.put(2, 2);
    cout << container.get(2);
    container.put(1, 1);
    container.put(4, 1);
    cout << container.get(2);

    
    return 0;
}
