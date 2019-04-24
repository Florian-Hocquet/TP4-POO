#include <iostream>
#include <string>

#include "CstCodErr.h"
#include "CException.h"

using namespace std;
using namespace nsUtil;

//#define CEXC nsUtil::CException




namespace {

char ChoixMenu() {

    cout << "A : exception 'exception' \n"
         << "B : exception standard specifique \n"
         << "C : exception CException \n"
         << "D : exception inconnue \n \n"
         << "Votre choix : ";

    char choix;
    cin >> choix;
    return choix;
}

void traiterCommande(char x) {

    switch(x)
    {
    case 'A':
    case 'a':
        throw exception();
    case 'B':
    case 'b':
    {
        string s;
        cout << s.at(0);
        break;
    }
    case 'C':
    case 'c':
        throw CException("Surprise !", 123);
    case 'D':
    case 'd':
        throw 123;
    }
}

void testExceptionInMain() {
    for (;;)
        traiterCommande(ChoixMenu());
}

}

int main()

{
    try {
        testExceptionInMain();
    }

    catch (const CException & e) {
        cerr << "Erreur : " << e.what() << '\n'
             << "CodeErr : " << e.getCodErr() << '\n';
        return e.getCodErr();
    }

    catch (const out_of_range & e) {
        cerr << "Exception out_of_range : " << e.what() << '\n';
        return KExcStd;
    }

    catch (const exception & e) {
        cerr << "Exception standard : " << e.what() << '\n';
        return KExcStd;
    }

    catch (const int & e) {
        cerr << "Exception int : " << e << endl;
        return KExcStd;
    }

    catch (const unsigned & e) {
        cerr << "Exception unsigned : " << e << endl;
        return KExcStd;
    }

    catch (...) {
        cerr << "Exception inconnue \n";
        return KExcInconnue;
    }
    return 0;
}




























