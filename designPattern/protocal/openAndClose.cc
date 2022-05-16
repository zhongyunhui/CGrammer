#include <iostream>
#include "openAndClose.h"
#include <utility>
using namespace std;

struct ColorSpecification : Specification<Product>
{
    Color  _color;
    explicit ColorSpecification(Color color): _color(color) {}
    bool is_satisfied(Product* item) {
        return item->color == _color;
    }
};

struct SizeSpecification : Specification<Product>
{
    Size _size;
    explicit SizeSpecification(Size size): _size(size) {}
    bool is_satisfied(Product* item) {
        return item->size == _size;
    }
};


int main() {

    Product apple{ "Apple", Color::Green, Size::Small };
    Product tree{ "Tree", Color::Green, Size::Large };
    Product house{ "House", Color::Blue, Size::Large };

    vector<Product*> all{ &apple, &tree, &house };
    BetterFilter bf;
    ColorSpecification greenSpec(Color::Green);
    SizeSpecification smallSpec(Size::Small);
    auto green_things = bf.filter(all, greenSpec);
    for (auto& x : green_things)
        cout << x->name << " is green" << endl;
    auto andspec = ColorSpecification(Color::Green) && SizeSpecification(Size::Small);
    auto green_small_things = bf.filter(all,andspec);
    for (auto& x : green_small_things)
        cout << x->name << " is green and small" << endl;
    return 0;
}
