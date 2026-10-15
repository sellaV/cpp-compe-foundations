#pragma once
#include <vector>
#include <string>

class Inventory {
struct Item {std::string name;int quantity;};
std::vector<Item> items_;
public:
    int count(const std::string& name) const {for(const Item& item:items_)if(item.name==name)return item.quantity;return 0;}
    bool add(const std::string& name,int quantity) {
        if(name.empty()||quantity<=0)return false;
        for(Item& item:items_)if(item.name==name){if(quantity>1000000-item.quantity)return false;item.quantity+=quantity;return true;}
        if(quantity>1000000)return false;
        items_.push_back({name,quantity});return true;
    }
    bool remove(const std::string& name,int quantity) {
        if(name.empty()||quantity<=0)return false;
        for(Item& item:items_)if(item.name==name){if(quantity>item.quantity)return false;item.quantity-=quantity;return true;}
        return false;
    }
};
