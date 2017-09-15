class Stack:
    class Full(Exception):
        pass
    class Empty(Exception):
        pass

    def __init__( self, maxSize ):
        """ Initialise the stack, maxSize is the maximum number of
            values that can be stored in the stack at any time """
        self.__maxSize = maxSize
        self.__stack = [None]*self.__maxSize
        self.__pos = 0

    def push( self, value ):
        """ Add value to the top of the stack, raises Stack.Full
            exception if stack is full """
        if self.__pos < self.__maxSize:
            self.__stack[self.__pos] = value
            self.__pos += 1
        else:
            raise self.Full( 'Can\'t push ' + str(value) )

    def num_items( self ):
        """ Returns the number of values currently stored in the
            stack """

        # COMPLETE ME
        return 0

    def top( self ):
        """ Returns the value currently stored at the top of the
            stack, raises Stack.Empty exception if stack is
            empty """

        # COMPLETE ME
        pass

    def pop( self ):
        """ Removes and returns the value currently stored at the
            top of the stack, raises Stack.Empty exception if stack
            is empty """

        # COMPLETE ME
        pass































''' ========================================================
    Below this is the testing code for the stack class, feel
    free to have a look but you don't need to worry about it
    ========================================================
'''
if __name__ == '__main__':
    import sys

    errors = 0
    testvalues = 'abcde'
    s = Stack( len(testvalues) )

    # === pushing test ======
    for i in range(len(testvalues)):
        c = testvalues[i]
        s.push( c )

        print( 'Pushing %s' % c )

        if s.top() != c:
            print( 'Error in top() - last thing pushed was %s but top of the stack contains %s' % (c, s.top()) )
            errors += 1

        if s.num_items() != i+1:
            print( 'Error in num_items() - pushed %d values but stack reports size of %d' % (i+1,s.num_items()) )
            errors += 1

    # === is full test ======
    try:
        s.push( 'f' )
        print( 'Error in push() - tried to push to a full stack but no exception' )
        errors += 1
    except Stack.Full:
        pass

    # === pop test ======
    for i in range(len(testvalues)-1,-1,-1):
        c = testvalues[i]
        val = s.pop()

        print( 'Popping %s' % val )

        if val != c:
            print( 'Error in pop() - wrong value was popped from the stack, expecting %s but got %s' % (c, val) )
            errors += 1

        if s.num_items() != i:
            print( 'Error in num_items() or pop() - stack should have %d values but claims it has %d values' % (i,s.num_items()) )
            errors += 1

    # === empty test ====
    try:
        s.pop()
        print( 'Error in pop() - tried to pop from an empty stack but no exception' )
        errors += 1
    except Stack.Empty:
        pass

    try:
        s.top()
        print( 'Error in top() - tried to get top of an empty stack but no exception' )
        errors += 1
    except Stack.Empty:
        pass

     print( 'Finished testing' )

    sys.exit(errors)
