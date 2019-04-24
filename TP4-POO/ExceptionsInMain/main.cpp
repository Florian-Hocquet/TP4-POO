#include <iostream>
#include <string>

#include "CstCodErr.h"
#include "CException.h"


using namespace std;
using namespace nsUtil;

void testExceptionInMain() {
    for (;;)
        traiterCommande(ChoixMenu());

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
    catch (...) {
        cerr << "Exception inconnue \n";
        return KExcInconnue;
    }
    return 0;
}
