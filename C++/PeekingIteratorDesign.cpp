
/**Given an Iterator class interface with methods: next() and hasNext(),
 design and implement a PeekingIteratorDesign that support the peek() operation --
 it essentially peek() at the element that will be returned by the next call to next().
 * Created by eugene on 16/5/23.
 */
class Iterator {
    struct Data;
    Data* data;
public:
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);
    virtual ~Iterator();
    // Returns the next element in the iteration.
    int next();
    // Returns true if the iteration has more elements.
    bool hasNext() const;
};
class PeekingIterator : public Iterator {//定义一个变量专门来保存下一个值，再用一个bool型变量标记是否保存了下一个值
    bool _hasSaveNext;
    int _next;
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        _hasSaveNext = false;
    }
    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        if(!_hasSaveNext) {
            _next = Iterator::next();
            _hasSaveNext = true;
        }
        return _next;
    }
    // hasNext() and next() should behave the same as in the Iterator interface.
    int next() {
        if(!_hasSaveNext) return Iterator::next();
        _hasSaveNext = false;
        return _next;
    }
    bool hasNext() const {
        return  _hasSaveNext || Iterator::hasNext();
    }
};
//public class PeekingIteratorDesign {
//    class PeekingIterator implements Iterator<Integer> {
//        private Integer next = null;
//        private Iterator<Integer> iterator = null;
//
//        public PeekingIterator(Iterator<Integer> iterator) {
//            // initialize any member here.
//            this.iterator = iterator;
//            if (iterator.hasNext()) this.next = iterator.next();
//        }
//
//        // Returns the next element in the iteration without advancing the iterator.
//        public Integer peek() {
//            return next;
//        }
//
//        // hasNext() and next() should behave the same as in the Iterator interface.
//        // Override them if needed.
//        @Override
//        public Integer next() {
//            Integer temp = next;
//            if (iterator.hasNext()) next = iterator.next();
//            else next = null;
//            return temp;
//        }
//
//        @Override
//        public boolean hasNext() {
//            return next==null? false : true;
//        }
//    }
//}
