### Define a class that has only one instance and provides a global point of access that instance.

### Requirements:
    - one and only one instance
    - global access
    - no ownership
    - lazy initialization

### Advantages:
    - save memory: only one object is required so why to create so many
    - single access point: logger, database connection
    - flexibility: change anytime you want to.

### Usage:
    - multi-threaded: thread pool
    - database application: logging
    - configuration settings: game setting, application setting, etc.

### How to create:
    - static member
    - private constructor
    - static function
