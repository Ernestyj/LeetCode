
/**Design and implement a data structure for Least Recently Used (LRU) cache.
 It should support the following operations: get and set.
 get(key) - Get the value (will always be positive) of the key
 if the key exists in the cache, otherwise return -1.
 set(key, value) - Set or insert the value if the key is not already present.
 When the cache reached its capacity, it should invalidate
 the least recently used item before inserting a new item.
 * Created by eugene on 16/3/5.
 */
class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    int get(int key) {
        auto it = m.find(key);
        if(it == m.end()) return -1;
        l.splice(l.begin(), l, it->second); //转移到头部, STL 中的函数 splice，专门移动链表中的一个或若干个结点到某个特定的位置
        return it->second->second;
    }
    void put(int key, int value) {
        auto it = m.find(key);
        if(it != m.end()) l.erase(it->second);  //找到则移除
        l.push_front(make_pair(key, value));    //插入到头部
        m[key] = l.begin(); //记录
        if(m.size()>cap){   //超限则尾部移除
            int k = l.back().first;
            l.pop_back();
            m.erase(k);
        }
    }
private:
    int cap;
    list<pair<int, int>> l; // list of (key, value)
    unordered_map<int, list<pair<int, int>>::iterator> m;   // key map to *(key, value)
};
//public class LRUCache {
//    class CacheEntry {
//        int key, value;
//        CacheEntry pre, next;
//        public CacheEntry(int key, int value){
//            this.key = key;
//            this.value = value;
//        }
//    }
//    private int capacity;
//    private Map<Integer, CacheEntry> map = new HashMap<>();
//    private CacheEntry head, end;
//    /**
//     * http://www.programcreek.com/2013/03/leetcode-lru-cache-java/
//     * 如果要O(1)的查找复杂度，肯定要用哈希表.
//     * 如果要O(1)的cache替换复杂度,可以采用链表,保证从头到尾的顺序就是cache从新到旧的顺序.
//     对于任何一个节点，如果被访问了，那么就将该节点移至头部; 如果cache已满，那么就把尾部的删掉，从头部插入新节点。
//     * @param capacity
//     */
//    public LRUCache(int capacity) {
//        this.capacity = capacity;
//    }
//    public int get(int key) {
//        if(map.containsKey(key)){
//            CacheEntry entry = map.get(key);
//            remove(entry);//对于任何一个节点，如果被访问了，那么就将该节点移至头部
//            setHead(entry);
//            return entry.value;
//        }
//        return -1;
//    }
//    public void set(int key, int value) {
//        if (map.containsKey(key)){
//            CacheEntry entry = map.get(key);
//            entry.value = value;
//            remove(entry);//对于任何一个节点，如果被访问了，那么就将该节点移至头部
//            setHead(entry);
//        } else {
//            CacheEntry entry = new CacheEntry(key, value);
//            if (map.size()>=capacity){
//                map.remove(end.key);//如果cache已满，那么就把尾部的删掉，从头部插入新节点
//                remove(end);    //TODO 此操作不能位于map.remove之前,否则end被垃圾回收为null
//            }
//            setHead(entry);
//            map.put(key, entry);
//        }
//    }
//    private void remove(CacheEntry entry){
//        if(entry.pre!=null) entry.pre.next = entry.next;
//        else head = entry.next;
//        if(entry.next!=null) entry.next.pre = entry.pre;
//        else end = entry.pre;
//    }
//    private void setHead(CacheEntry entry){
//        entry.next = head;
//        entry.pre = null;
//        if(head!=null) head.pre = entry;
//        head = entry;
//        if(end==null) end = entry;
//    }
//
//}
