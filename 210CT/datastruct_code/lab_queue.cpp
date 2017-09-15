#include <exception>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Queue
{
private:
    const int maxSize;
    vector<char> queue;

public:
    class Full: public exception
    {
    public:
        virtual const char* what() const throw()
          {
            return "Queue is full";
          }
    };

    class Empty: public exception
    {
    public:
        virtual const char* what() const throw()
          {
            return "Queue is empty";
          }
    };

    /** Initialise the queue, maxSize is the maximum number of
        values that can be stored in the queue at any time **/
    Queue( const int _maxSize ) : maxSize(_maxSize)
    {
    }

    ~Queue()
    {
    }

    /** Returns the number of values currently stored in the
        queue **/
    int num_items() const
    {
        // COMPLETE ME
        return 0;
    }

    /** Add value to the front of the queue, raises Queue::Full
        exception is queue is full **/
    void push( char value )
    {
        if( num_items() < maxSize )
        {
            queue.emplace_back(value);
        }
        else
        {
            throw Full();
        }
    }

    /** Returns the value currently stored at the front of the
        queue, raises Queue::Empty exception is queue is
        empty **/
    char front() const
    {
        if( num_items() > 0 )
        {
            return queue.front();
        }
        else
        {
            throw Empty();
        }
    }

    /** Returns the value currently stored at the back of the
        queue, raises Queue.Empty exception if the queue is
        empty **/
    char back() const
    {
        // COMPLETE ME
        return 0;
    }

    /** Removes and returns the value currently stored at the
        front of the queue, raises Queue::Empty exception is queue
        is empty **/
    char pop()
    {
        // COMPLETE ME
        return 0;
    }
};












































/*  ========================================================
    Below this is the testing code for the queue class, feel
    free to have a look but you don't need to worry about it
    ========================================================
*/
int main()
{
    int errors = 0;
    string testvalues = "abcde";

    Queue q( testvalues.length() );

    // === pushing test ======
    for( int i=0; i<testvalues.length(); ++i )
    {
        char c = testvalues[i];
        q.push( testvalues[i] );

        cout << "Pushing " << c << endl;

        cout << "Test front of queue" << endl;
        try
        {
            if( q.front() != testvalues[0] )
            {
                cerr << "Error in front() - the front of the queue is wrong, expected " << testvalues[0] << " but got " << q.front() << endl;
                errors += 1;
            }

            cout << "Test back of queue" << endl;
            if( q.back() != c )
            {
                cerr << "Error in back() - last thing pushed was " << c << " but back of queue contains " << q.back() << endl;
                errors += 1;
            }
        }
        catch( Queue::Empty &error )
        {
            cerr << "Error - raised an Empty exception when there should be values in the queue" << endl;
            errors += 1;
        }

        cout << "Test size of queue" << endl;
        if( q.num_items() != i+1 )
        {
            cerr << "Error in num_items() - pushed " << i+1 << " values but queue reports size of " << q.num_items() << endl;
            errors += 1;
        }
    }

    // === is full test ======
    try
    {
        q.push( 'f' );
        cerr << "Error in push() - tried to push to a full queue but no exception" << endl;
        errors += 1;
    }
    catch( Queue::Full& error )
    {}

    // === pop test ======
    for( int i=0; i<testvalues.length(); ++i )
    {
        char c = testvalues[i];
        char val = q.pop();

        cout << "Popping " << val << endl;

        if( val != c )
        {
            cerr << "Error in pop() - wrong value was popped from the queue, expecting " << c << " but got " << val << endl;
            errors += 1;
        }

        int expectedsize = testvalues.length()-i-1;
        if( q.num_items() != expectedsize )
        {
            cerr << "Error in num_items() - queue should have " << expectedsize << " values but claims it has " << q.num_items() << " values" << endl;
            errors += 1;
        }
    }

    // === empty test ======
    try
    {
        q.pop();
        cerr << "Error in pop() - tried to pop from an empty queue but no exception" << endl;
        errors += 1;
    }
    catch( Queue::Empty& error )
    {}

    try
    {
        q.front();
        cerr << "Error in front() - tried to get front off an empty queue but no exception" << endl;
        errors += 1;
    }
    catch( Queue::Empty& error )
    {}

    cout << "Finished testing" << endl;

    return errors;
}
