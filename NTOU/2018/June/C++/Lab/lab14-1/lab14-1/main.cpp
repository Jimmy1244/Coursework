#include "Fred.h"
#include "Wilson.h"
#include "HeapPtr.h"
#include <iostream>
using namespace std;

void main()
{
    HeapPtr<Fred> ptrFred1, ptrFred2(new Fred);
    HeapPtr<Fred> ptrFred3(new Fred);

    ptrFred1 = new Fred;
    ptrFred1 = 0;

    ptrFred1 = new Fred;
    ptrFred1 = ptrFred3;//operator =

    HeapPtr<Fred> ptrFred4 = ptrFred1;//«þ¨©«Øºc¤¸

    ptrFred2->service();
    (*ptrFred2).service();

    Fred *ptrFred;
    ptrFred = ptrFred2.relinguishOwnership();
    delete ptrFred; // without this line, memory is leaking

    HeapPtr<Wilson> ptrWilson(new Wilson);
    ptrWilson->service();
    HeapPtr<int> ptrIntAry(new int);
}