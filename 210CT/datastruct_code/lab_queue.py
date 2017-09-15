class Queue:
    class Full(Exception):
        pass
    class Empty(Exception):
        pass

    def __init__( self, maxSize ):
        """ Initialise the queue, maxSize is the maximum number of
            values that can be stored in the queue at any time """
        self.__maxSize = maxSize
        self.__queue = [None]*self.__maxSize
        self.__items = 0

    def push( self, value ):
        """ Add value to the top of the queue, raises queue.Full
            exception is queue is full """
        if self.num_items() < self.__maxSize:
            self.__queue[self.__items] = value
            self.__items += 1
        else:
            raise self.Full( 'Can\'t push ' + str(value) )

    def num_items( self ):
        """ Returns the number of values currently stored in the
            queue """

        # COMPLETE ME
        return 0

    def front( self ):
        """ Returns the value currently stored at the top of the
            queue, raises queue.Empty exception if queue is
            empty """
        if self.num_items() > 0:
            return self.__queue[0]
        else:
            raise self.Empty()

    def back( self ):
        """ Returns the value currently stored at the back of the
            queue, raises Queue.Empty exception if the queue is
            empty """

        # COMPLETE ME
        return None

    def pop( self ):
        """ Removes and returns the value currently stored at the
            top of the queue, raises queue.Empty exception is queue
            is empty """

        # COMPLETE ME
        return None






































''' ========================================================
    Below this is the testing code for the stack class, feel
    free to have a look but you don't need to worry about it
    ========================================================
'''
if __name__ == '__main__':
    import sys

    errors = 0
    testvalues = 'abcde'
    q = Queue( len(testvalues) )

    # === pushing test ======
    for i in range(len(testvalues)):
        c = testvalues[i]
        q.push( c )

        print( 'Pushing %s' % c )

        try:
            print( 'Test front of queue' )
            if q.front() != testvalues[0]:
                print( 'Error in front() - the front of the queue is wrong, expected %s but got %s' % (testvalues[0], q.front()) )
                errors += 1

            print( 'Test back of queue' )
            if q.back() != c:
                print( 'Error in back() - last thing pushed was %s but back of the queue contains %s' % (c, q.back()) )
                errors += 1

        except Queue.Empty:
            print( 'Error - raised an Empty exception when there should be values in the queue' )
            errors += 1;

        print( 'Test size of queue' )
        if q.num_items() != i+1:
            print( 'Error in num_items() - pushed %d values but queue reports size of %d' % (i+1,q.num_items()) )
            errors += 1

    # === is full test ======
    try:
        q.push( 'f' )
        print( 'Error in push() - tried to push to a full queue but no exception' )
        errors += 1
    except Queue.Full:
        pass

    # === pop test ======
    for i in range(len(testvalues)):
        c = testvalues[i]
        val = q.pop()

        print( 'Popping %s' % val )

        if val != c:
            print( 'Error in pop() - wrong value was popped from the queue, expecting %s but got %s' % (c, val) )
            errors += 1

        expectedsize = len(testvalues)-i-1
        if q.num_items() != expectedsize:
            print( 'Error in num_items() - queue should have %d values but claims it has %d values' % (expectedsize,q.num_items()) )
            errors += 1

    # === empty test ====
    try:
        q.pop()
        print( 'Error in pop() - tried to pop from an empty queue but no exception' )
        errors += 1
    except Queue.Empty:
        pass

    try:
        q.front()
        print( 'Error in front() - tried to get top of an empty queue but no exception' )
        errors += 1
    except Queue.Empty:
        pass

    print( "Finished testing" )

    sys.exit(errors)
