/**
 *
 * \file   : SqueletteMain.cpp
 *
 * \author :
 *
 * \date   :
 *
**/

#include <iostream>
#include <exception>

#include "CstCodErr.h"
#include "CException.h"

using namespace std;
using namespace nsUtil;

namespace
{

float divisionEntiere(int & a, int & b) throw(CException)
{
    if (b == 0)
        throw CException ("Diviser par zero est impossible : ", CstExcDivZero);
    return (float)a/(float)b;
}

void testDivisionParZero (void)
{
    vector <int> num = {1,2,3,4,5,6,7,8,9,10};
    vector <int> denom = {0,1,2,3,4,5,6,7,8,9};

    for (unsigned i = 0; i < denom.size(); ++i )
    {
        try {
            cout << "Division de : " << num[i] << " par : " << denom[i] << " est égale à : "
                 << divisionEntiere(num[i], denom[i]) << endl;
        }

        catch(const CException & e) {
            cerr << "Erreur : " << e.getLibelle() << "Code : " << e.getCodErr() << '\n';
        }

    }

} // testDivisionParZero ()

} // namespace

int main (void)
{
    try
    {
        testDivisionParZero ();

        return KNoExc;
    }
    catch (const CException & e)
    {
        cerr << "Erreur        : " << e.getLibelle () << '\n'
             << "Code d'erreur = " << e.getCodErr ()  << '\n';
        return e.getCodErr();
    }
    catch (const exception & e)
    {
        cerr << "Exception standard : " << e.what () << '\n';
        return KExcStd;
    }
    catch (...)
    {
        cerr << "Exception inconnue\n";
        return KExcInconnue;
    }

} // main()
