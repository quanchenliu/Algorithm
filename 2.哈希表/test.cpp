class MyHashSet
{
public:
    vector<bool> tbl;
    MyHashSet() : tbl(1000001, false) { }
    void add(int key) { tbl[key] = true; }
    void remove(int key) { tbl[key] = false; }
    bool contains(int key) {  return tbl[key]; }
};