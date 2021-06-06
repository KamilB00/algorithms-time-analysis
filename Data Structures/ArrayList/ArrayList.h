//
// Created by Kamil Bonkowski on 25/05/2021.
//
template <class T>

class ArrayList {
private:

    int size{};

    T *array;
public:

    ArrayList<T>();

    ArrayList<T>(T *tmp, int size);

    void addFirst(T data);

    void addLast(T data);

    int get_size();

    void add(T data, int index);

    bool contains(T data);

    void removeFirst();

    void removeLast();

    void remove(int index);

    void removeAll();

    void show();

    void setArray(T *tmp);

    T get(int index);
};

