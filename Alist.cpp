template <class Elem>

class Alist {

public:

    Alist(int size = DefaultSize):
        maxSize(size), listSize(0), curr(0) {
        listArray = new Elem[maxSize];
    }
    ~Alist() { delete [] listArray; }
    void clear() { listSize = curr = 0; }
    void Prev() { if (curr != 0) curr--; }
    void Next() { if (curr < listSize) curr++; }
    bool setPos(int pos) {
        if (pos >= 0 && pos <= listSize) {
            curr = pos;
            return true;
        }
        return false;
    }
    int currPos() const { return curr; }
    int length() const { return listSize; }
    bool insert(const Elem& item) {
        if (listSize >= maxSize) return false;
        for (int i = listSize; i > curr; i--)
            listArray[i] = listArray[i-1];
        listArray[curr] = item;
        listSize++;
        return true;
    }
    bool append(const Elem& item) {
        if (listSize >= maxSize) return false;
        listArray[listSize++] = item;
        return true;
    }
    bool remove(Elem& item) {
        if ((curr < 0) || (curr >= listSize)) return false;
        item = listArray[curr];
        for (int i = curr; i < listSize-1; i++)
            listArray[i] = listArray[i+1];
        listSize--;
        return true;
    }

private:

    enum { DefaultSize = 10 };
    int maxSize;
    int listSize;
    int curr;
    Elem* listArray;
};