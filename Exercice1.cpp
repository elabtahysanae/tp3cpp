#include <iostream>

class IntegerSet {
private:
    int* elements;
    int size;
    int count;

public:
    // Constructeur
    IntegerSet(int s) : size(s), count(0) {
        elements = new int[size];
        for (int i = 0; i < size; ++i) {
            elements[i] = 0; // Initialisation
        }
    }

    // Destructeur
    ~IntegerSet() {
        delete[] elements;
    }

    // Vider l'ensemble
    void empty() {
        count = 0;
    }

    // Ajouter un entier à l'ensemble
    void add(int value) {
        if (count < size && !is_member(value)) {
            elements[count] = value;
            count++;
        }
    }

    // Retirer un entier de l'ensemble
    void remove(int value) {
        for (int i = 0; i < count; i++) {
            if (elements[i] == value) {
                elements[i] = elements[count - 1];
                count--;
                break;
            }
        }
    }

    // Copier l'ensemble
    IntegerSet copy() const {
        IntegerSet newSet(size);
        for (int i = 0; i < count; i++) {
            newSet.add(elements[i]);
        }
        return newSet;
    }

    // Vérifier si un entier est membre de l'ensemble
    bool is_member(int value) const {
        for (int i = 0; i < count; i++) {
            if (elements[i] == value) {
                return true;
            }
        }
        return false;
    }

    // Vérifier si deux ensembles sont égaux
    bool is_equal(const IntegerSet& otherSet) const {
        if (count != otherSet.count) {
            return false;
        }
        for (int i = 0; i < count; i++) {
            if (!otherSet.is_member(elements[i])) {
                return false;
            }
        }
        return true;
    }

    // Afficher l'ensemble
    void print() const {
        std::cout << "Set: { ";
        for (int i = 0; i < count; i++) {
            std::cout << elements[i] << (i < count - 1 ? ", " : " ");
        }
        std::cout << "}" << std::endl;
    }
};

int main() {
    IntegerSet set1(10);
    set1.add(1);
    set1.add(2);
    set1.add(3);
    set1.print();  // Set: { 1, 2, 3 }

    set1.remove(2);
    set1.print();  // Set: { 1, 3 }

    IntegerSet set2(10);
    set2.add(1);
    set2.add(3);

    std::cout << std::boolalpha << set1.is_equal(set2) << std::endl;  // true

    IntegerSet set3 = set1.copy();
    set3.print();  // Set: { 1, 3 }

    set1.empty();
    set1.print();  // Set: { }

    return 0;
}
