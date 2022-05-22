class Counter:
    __keep_track = 0
    def __init__(self) -> None:
        self.__current = 0
    def increment(self):
        self.__current += 1
    def value(self):
        return self.__current
    def reset(self):
        self.__current = 0

counter = Counter()
counter._Counter__current
Counter._Counter__keep_track