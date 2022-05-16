#include <vector>
using namespace std;

enum class Color {
    Red,
    Green,
    Blue
};

enum class Size {
    Small,
    Medium,
    Large
};

struct Product
{
    string name;
    Color color;
    Size size;
};


template <typename T>
struct Specification
{
    virtual bool is_satisfied(T* item) = 0;
    
};


template <typename T>
struct Filter
{
    virtual vector<T*> filter(vector<Product*> items, Specification<Product>& spec) = 0;
};

struct BetterFilter : Filter<Product>
{
    vector<Product*> filter(
        vector<Product*> items, Specification<Product>& spec) override 
    {
        vector<Product*> result;
        for (auto& p : items) {
            if (spec.is_satisfied(p)) {
                result.push_back(p);
            }
        }
        return result;
    }
};

template<typename T>
struct AndSpecification: Specification<T>
{
    AndSpecification(Specification<T>& first, Specification<T>& second):
        _first(first), _second(second){}
    
    bool is_satisfied(T* item) override 
    {
        return _first.is_satisfied(item) && _second.is_satisfied(item);
    }

    Specification<T>& _first;
    Specification<T>& _second;
};

template <typename T> AndSpecification<T> operator&&
(Specification<T>&& first, Specification<T>&& second)
{
    return { first, second };
}

