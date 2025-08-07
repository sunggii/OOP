#include <iostream>
using namespace std;

main()
{
    try{
        try{
            try{
                char *s1 = "apin";
                if (s1 == "hello")
                {
                    throw s1;
                }
                cout << s1 <<endl;

                char *s2 = "hello";
                if (s2 == "hello")
                {
                    throw s2;
                }
                cout << s2 <<endl;
            }
            catch(char* s){
                cout << "Exception: " << s << endl;
                throw s;
            }

        }
        catch (...) //เข้านี่
        {
            cout << "Other exceptions" << endl;
            throw ;
        }

    }
    catch(double d){
        cout << "Exception: " << d << endl;
    }
    catch (int i)
    {
        cout << "Exception: " << i << endl;
    }
    catch (char *c)
    {
        cout << "Exception: " << c << endl;
    }
    
    cout << "continue to next step" << endl;

}