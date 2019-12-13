template<typename T>
class SortedList {
    void push(T x);        // Wstawia element 'x'
    T pop();               // Zwraca i usuwa pierwszy (najmniejszy) element
    iterator erase(iterator i); // Usuwa element na pozycji 'i'
    iterator find(T x);  // Zwraca pozycję elementu o wartości 'x' lub -1 gdy nie znaleziono
    int size();            // Zwraca liczbę elementów w liście
    void remove(T x);      // Usuwa wszystkie elementy równe 'x'
    static SortedList merge(const SortedList& a, const SortedList& b);
                           // Scala dwie posortowane listy i zwraca posortowaną listę
    void unique();         // Usuwa sąsiadujące duplikaty
    void print();          // Wypisuje elementy listy (w porządku rosnącym)
};