#include <exception>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Stack
{
private:
    const int maxSize;
    vector<char> stack;

public:
    class Full: public exception
    {
    public:
        virtual const char* what() const throw()
        {
            return "Stack is full";
        }
    };

    class Empty: public exception
    {
    public:
        virtual const char* what() const throw()
        {
            return "Stack is empty";
        }
    };

    /** Initialise the stack, maxSize is the maximum number of
        values that can be stored in the stack at any time */
    Stack( const int _maxSize ) : maxSize(_maxSize)
    {
    }

    ~Stack()
    {
    }

    /** Returns the number of values currently stored in the
        stack */
    int num_items() const
    {
        // REPLACE ME
        return 0;
    }

    /** Add value to the top of the stack, raises Stack::Full
        exception if stack is full */
    void push( char value )
    {
        if( num_items() < maxSize )
        {
            stack.emplace_back( value );
        }
        else
        {
            throw Full();
        }
    }

    /** Returns the value currently stored at the top of the
        stack, raises Stack::Empty exception if stack is
        empty */
    char top()
    {
    }

    /** Removes and returns the value currently stored at the
        top of the stack, raises Stack::Empty exception if stack
        is empty */
    char pop()
    {
    }
};


































/*  ========================================================
    Below this is the testing code for the stack class, feel
    free to have a look but you don't need to worry about it
    ========================================================
*/
int main()
{
    int errors = 0;
    string testvalues = "abcde";
    Stack s( testvalues.length() );

    // === pushing test ======
    for( int i=0; i<testvalues.length(); ++i )
    {
        char c = testvalues[i];
        s.push( testvalues[i] );

        cout << "Pushing " << c << endl;

        if( s.top() != c )
        {
            cerr << "Error in top() - last thing pushed was " << c << " but top of stack contains " << s.top() << endl;
            errors += 1;
        }

        if( s.num_items() != i+1 )
        {
            cerr << "Error in num_items() - pushed " << i+1 << " values but stack reports size of " << s.num_items() << endl;
            errors += 1;
        }
    }

    // === is full test ======
    try
    {
        s.push( 'f' );
        cerr << "Error in push() - tried to push to a full stack but no exception" << endl;
        errors += 1;
    }
    catch( Stack::Full& error )
    {}

    // === pop test ======
    for( int i=testvalues.length()-1; i>=0; --i )
    {
        char c = testvalues[i];
        char val = s.pop();

        cout << "Popping " << val << endl;

        if( val != c )
        {
            cerr << "Error in pop() - wrong value was popped from the stack, expecting " << c << " but got " << val << endl;
            errors += 1;
        }

        if( s.num_items() != i )
        {
            cerr << "Error in num_items() or pop() - stack should have " << i << " values but claims it has " << s.num_items() << " values" << endl;
            errors += 1;
        }
    }

    // === empty test ======
    try
    {
        s.pop();
        cerr << "Error in pop() - tried to pop from an empty stack but no exception" << endl;
        errors += 1;
    }
    catch( Stack::Empty& error )
    {}

    try
    {
        s.top();
        cerr << "Error in top() - tried to get top off an empty stack but no exception" << endl;
        errors += 1;
    }
    catch( Stack::Empty& error )
    {}

    cout << "Finished testing" << endl;

    return errors;
}
