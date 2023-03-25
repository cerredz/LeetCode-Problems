class RandomizedSet {
public:

/*
    Problem: Implement the RandomizedSet class:RandomizedSet() Initializes the RandomizedSet object.
    bool insert(int val) Inserts an item val into the set if not present. Returns true if the item was not present, false otherwise.
    bool remove(int val) Removes an item val from the set if present. Returns true if the item was present, false otherwise.
    int getRandom() Returns a random element from the current set of elements (it's guaranteed that at least one element exists when this method is called) 
    Each element must have the same probability of being returned.
    You must implement the functions of the class such that each function works in average O(1) time complexity.


*/
    //Initialize Data structure here
    vector<int> vec;
    unordered_map<int, int> index;

    //Will use map for fast lookup time, and vector for our getRandom method

    bool insert(int val) {
        //if we already have the value in our data structure
        if (index.count(val)) {
            return false;
        }

        //make sure val is at the back of the vector
        vec.push_back(val);
        //store index of val in the map so we can have constant time removal for vector in the 
        //remove method
        index[val] = vec.size() - 1;
        return true;
    }

    bool remove(int val) {

        if (!index.count(val)) {
            return false;
        }

        //index of the current value
        int idx = index[val];
        //value of the last element in val
        int last = vec.back();
        //swap index we are removing to the back
        vec[idx] = last;
        index[last] = idx;

        //remove last element
        vec.pop_back();
        index.erase(val);
        return true;
    }

    int getRandom() {
        int idx = rand() % vec.size();
        return vec[idx];
    }
};
