// first solution
// This one has a major problem, and it's using of expensive lock each time.
static Singleton* Instance() {
    Lock lock;
    if (NULL == mInstance) {
        mInstance = new Singleton();
    }

    return mInstance;
}

// second solution
// known as DCLP - double check locking pattern
static Singletion* Instance() {
    if (NULL == mInstance) {
        Lock lock;
        if (NULL == mInstance) {
            mInstance = new Singleton();
        }
    }

    return mInstance;
}