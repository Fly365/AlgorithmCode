/*-------------------------------------
*   日期：2015-04-03
*   作者：SJF0115
*   题目: 内存池实现
*   来源：阿里
*   博客：
------------------------------------*/
#include <iostream>
#include <time.h>
using namespace std;

// 内存块对象
class MemoryChunk{
public:
    // 构造函数
    MemoryChunk(MemoryChunk *nextChunk,size_t chunkSize);
    // 析构函数
    ~MemoryChunk();
    // 分配
    inline void* alloc(size_t size);
    // 释放
    inline void free(void* someElement);
    // 指向列表下一内存块的指针
    MemoryChunk* nextMemoryChunk();
    // 当前内存块剩余空间大小
    size_t spaceAvailable();
    // 内存块默认最小值
    enum{DEFAULT_CHUNK_SIZE = 4096};
private:
    // 指向下一个内存块
    MemoryChunk *next;
    // 内存
    void *mem;
    // 内存块实际大小
    size_t chunkSize;
    // 当前内存块中已分配的字节数
    size_t bytesAlreadyAllocated;
};
/**
构造函数
首先确定内存块的适当大小，然后根据这个大小从堆上分配私有存储空间。
**/
MemoryChunk::MemoryChunk(MemoryChunk *nextChunk,size_t reqSize){
    chunkSize = (reqSize > DEFAULT_CHUNK_SIZE) ? reqSize : DEFAULT_CHUNK_SIZE;
    next = nextChunk;
    bytesAlreadyAllocated = 0;
    mem = new char[chunkSize];
}
/**
析构函数
释放构造函数获得内存空间
**/
MemoryChunk::~MemoryChunk(){
    delete [] mem;
}
/**
处理内存分配请求，返回一个指针，指向mem所指向的MemoryChunk私有存储空间中的可用空间。
该方法通过更新该块中已分配字节数来记录可用空间大小
**/
void* MemoryChunk::alloc(size_t requestSize){
    // 可用起始地址
    void *addr = static_cast<void*> (static_cast<size_t>mem+bytesAlreadyAllocated);
    // 重新计算已分配字节数
    bytesAlreadyAllocated += requestSize;
    //  返回指向可用空间地址
    return addr;
}
/**
现实中，我们不用担心空闲内存段的释放。
当对象被删除之后，真个内存块将被释放并且返回到堆上。
**/
void MemoryChunk::free(void* doomed){

}
/**
指向列表下一内存块的指针
**/
MemoryChunk* MemoryChunk::nextMemoryChunk(){
    return next;
}
/**
当前内存块剩余空间大小
**/
size_t MemoryChunk::spaceAvailable(){
    return chunkSize - bytesAlreadyAllocated;
}






// 基于内存可变大小的内存池
class ByteMemoryPool{
public:
    // 构造函数
    ByteMemoryPool(size_t initSize = MemoryChunk::DEFAULT_CHUNK_SIZE);
    // 析构函数
    ~ByteMemoryPool();
    // 从私有内存池分配内存
    inline void* alloc(size_t size);
    // 释放先前从内存池分配的内存
    inline void free(void* someElement);
private:
    // 内存块列表
    MemoryChunk *memoryChunkList;
    // 向我们私有存储空间添加一个内存块
    void expandStorage(size_t reqSize);
};
// 内存块列表中可能包含多个块，但只有第一块拥有可用于分配的内存。
// 其他块表示已分配的内存。列表的首个元素是唯一能够用于分配可用内存的块
/**
构造函数接受initSize参数来设定一个内存块的大小
构造函数生成一个内存块
**/
ByteMemoryPool::ByteMemoryPool(size_t initSize){
    // 生成一个内存块
    expandStorage(initSize);
}
/**
析构函数遍历内存块列表并且删除它们
**/
ByteMemoryPool::~ByteMemoryPool(){
    MemoryChunk *memChunk = memoryChunkList;
    MemoryChunk *tmp;
    while(memChunk){
        // 保存一下节点指针
        tmp = memChunk->next;
        // 释放内存块
        delete memChunk;
        // 继续遍历内存块
        memChunk = tmp;
    }//while
}
/**
必须确保有足够的可用空间，而把分配任务委托给列表头的MemoryChunk
因为只有第一块拥有可用于分配的内存
**/
void* ByteMemoryPool::alloc(size_t requestSize){
    // 获取可用空间大小
    size_t avaliableSpace = memoryChunkList->spaceAvailable();
    // 没有足够的可用空间
    if(avaliableSpace < requestSize){
        expandStorage(requestSize);
    }//if
    // 在内存块中分配
    return memoryChunkList->alloc(requestSize);
}
/**
释放之前分配的内存任务被委派给列表头部的MemoryChunk来完成
**/
void ByteMemoryPool::free(void* doomed){
    memoryChunkList->free(doomed);
}
/**
若遇到内存块用尽的情况，我们通过创建新的内存块并把它添加到内存块列表的头部来扩展他。
**/
void ByteMemoryPool::expandStorage(size_t requestSize){
    memoryChunkList = new MemoryChunk(memoryChunkList,requestSize);
}

int main(){
    /*int start = clock();

    Complex *c[100];
    for (int i=0; i<1000000; i++){
        // 100个Complex对象
        for (int j=0; j<100; j++){
            c[j] = new Complex();
        }//for
        for(int j=0; j<100; j++){
            delete c[j];
        }//for
    }//for
    // 删除对象池
    Complex::deletePool();

    int end = clock();
    cout <<"start->"<<start<<" end->"<<end<<" 总共用时->"<<end-start<<endl;*/
    return 0;
}
