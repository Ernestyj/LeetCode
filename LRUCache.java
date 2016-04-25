package leetcode141_150;

import java.util.HashMap;
import java.util.Map;

/**Design and implement a data structure for Least Recently Used (LRU) cache.
 It should support the following operations: get and set.
 get(key) - Get the value (will always be positive) of the key
 if the key exists in the cache, otherwise return -1.
 set(key, value) - Set or insert the value if the key is not already present.
 When the cache reached its capacity, it should invalidate
 the least recently used item before inserting a new item.
 * Created by eugene on 16/3/5.
 */
public class LRUCache {
    class CacheEntry {
        int key;
        int value;
        CacheEntry pre;
        CacheEntry next;
        public CacheEntry(int key, int value){
            this.key = key;
            this.value = value;
        }
    }
    private int capacity;
    private Map<Integer, CacheEntry> map = new HashMap<>();
    private CacheEntry head=null;
    private CacheEntry end=null;
    /**
     * http://www.programcreek.com/2013/03/leetcode-lru-cache-java/
     * 如果要O(1)的查找复杂度，肯定要用哈希表.
     * 如果要O(1)的cache替换复杂度,可以采用链表,保证从头到尾的顺序就是cache从新到旧的顺序.
     对于任何一个节点，如果被访问了，那么就将该节点移至头部;
     如果cache已满，那么就把尾部的删掉，从头部插入新节点。
     * @param capacity
     */
    public LRUCache(int capacity) {
        this.capacity = capacity;
    }
    public int get(int key) {
        if (map.containsKey(key)){
            CacheEntry cacheEntry = map.get(key);
            //对于任何一个节点，如果被访问了，那么就将该节点移至头部
            remove(cacheEntry);
            setHead(cacheEntry);
            return cacheEntry.value;
        }
        return -1;
    }
    public void set(int key, int value) {
        if (map.containsKey(key)){
            CacheEntry old = map.get(key);
            old.value = value;
            //对于任何一个节点，如果被访问了，那么就将该节点移至头部
            remove(old);
            setHead(old);
        } else {
            CacheEntry newCacheEntry = new CacheEntry(key, value);
            if (map.size()>=capacity){
                //如果cache已满，那么就把尾部的删掉，从头部插入新节点
                map.remove(end.key);
                remove(end);
            }
            setHead(newCacheEntry);
            map.put(key, newCacheEntry);
        }
    }
    private void remove(CacheEntry cacheEntry){
        if (cacheEntry.pre!=null) cacheEntry.pre.next = cacheEntry.next;
        else head = cacheEntry.next;
        if (cacheEntry.next!=null) cacheEntry.next.pre = cacheEntry.pre;
        else end = cacheEntry.pre;
    }
    private void setHead(CacheEntry cacheEntry){
        cacheEntry.next = head;
        cacheEntry.pre = null;
        if (head!=null) head.pre = cacheEntry;
        head = cacheEntry;
        if (end==null) end = head;
    }

}
