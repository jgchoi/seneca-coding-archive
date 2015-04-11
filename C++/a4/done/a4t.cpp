/* OOP244.141 Assignment 2, 3, 4 Test Main
*  Bookstore Order Processor
*
*  Author: Chris Szalwinski
*  Nov 15 2013
*  a4test.cpp
*
*  Version 1.00
*  Version 1.01 - 9789995500009 returned false (not true) - Feb 23 2014 CS
*  Version 1.02 - inconsistencies in error messages fixed - Feb 23 2014 CS
*  Version 1.03 - has replaced by getEAN() in Special Order - April 2 2014 CS
*
*  Set   DEBUG to 1 for verbose debugging output
*  Reset DEBUG to 0 for submission version
*/

#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstring>

#define DEBUG 1                    // set to 1 for verbose output
#define PREFIX "prefixRanges.txt"  // file of EAN Prefix Ranges

#define EAN_PREFIX    1
#define ORDER         2
#define SPECIAL_ORDER 3

// set the test level here
#define TEST_LEVEL SPECIAL_ORDER

#include "GS1Prefix.h"

#if TEST_LEVEL == EAN_PREFIX
#include "EAN.h"
#else
#include "Order.h"
#endif

int  GS1PrefixTests(const Prefix& list, int& testNo, int* passed, int* tested);
int  EANTests(const Prefix& list, int& testNo, int* passed, int* tested);
int  RegisteredTests(const Prefix& list, int& testNo, int* passed, int* tested);
int  OrderTests(const Prefix& list, int& testNo, int* passed, int* tested);
int  SpecialOrderTests(const Prefix& list, int& testNo, int* passed, int* tested);
void testPassed(const char* message, int i, int* passed, int* total);
void testFailed(const char* message, int i, int* ok, int* total);

int main() {
    Prefix list(PREFIX);
    int passed = 0, tested = 0, testNo = 0;

    // GS1Prefix Tests
    if (DEBUG)
        std::cout << "GS1Prefix Tests\n===============\n";
    if(GS1PrefixTests(list, testNo, &passed, &tested))
        if (DEBUG)
            std::cout << "\nGS1 Prefix Tests passed!\n\n";
        else
            std::cout << "GS1 Prefix Tests passed!\n";
    else {
        std::cout << "\n";
        if (DEBUG)
            std::cout << "GS1 Prefix Tests had errors!\n\n";
        else
            std::cout << "GS1 Prefix Tests had errors!\n";
    }

    // EAN Tests
    if (DEBUG)
        std::cout << "EAN Tests\n=========\n";
    if(EANTests(list, testNo, &passed, &tested))
        if (DEBUG)
            std::cout << "\nEAN Tests passed!\n\n";
        else
            std::cout << "EAN Tests passed!\n";
    else {
        std::cout << "\n";
        std::cout << "\nEAN Tests had errors!\n\n";
    }

    // EAN Registered Tests
    if (DEBUG)
        std::cout << "EAN Registered Tests\n====================\n";
    if(RegisteredTests(list, testNo, &passed, &tested))
        if (DEBUG)
            std::cout << "\nEAN Registered Tests passed!\n\n";
        else
            std::cout << "EAN Registered Tests passed!\n";
    else {
        std::cout << "\n";
        std::cout << "\nRegistered Tests had errors!\n\n";
    }

    // Order Tests
    #if TEST_LEVEL == ORDER || TEST_LEVEL == SPECIAL_ORDER
    if (DEBUG)
        std::cout << "Order Tests\n===========\n";
    if(OrderTests(list, testNo, &passed, &tested))
        if (DEBUG)
            std::cout << "\nOrder Tests passed!\n\n";
        else
            std::cout << "Order Tests passed!\n";
    else {
        std::cout << "\n";
        std::cout << "\nOrder Tests had errors!\n\n";
    }
    #endif

    // Special Order Tests
    #if TEST_LEVEL == SPECIAL_ORDER
    if (DEBUG)
        std::cout << "Special Order Tests\n===================\n";
    if(SpecialOrderTests(list, testNo, &passed, &tested))
        if (DEBUG)
            std::cout << "\nSpecial Order Tests passed!\n\n";
        else
            std::cout << "Special Order Tests passed!\n";
    else {
        std::cout << "\n";
        std::cout << "\nSpecial Order Tests had errors!\n\n";
    }
    #endif

    // Conclusion
    std::cout << "\nYour Bookstore modules have passed " << passed << " of " << tested << " tests\n";
    if (passed == tested)
        std::cout << "\nCongratulations!!!   "
        "Your Bookstore modules are ready for submission\n\n";
    else
        std::cout << "Keep working on your code - good luck!\n";

    return 0;
}

/* GS1PrefixTests performs tests on the Prefix class and return false for
*  invalid results
*  *passed - total number of tests passed
*  *tested - total number of tests attempted
*/
int GS1PrefixTests(const Prefix& list, int& testNo, int* passed, int* tested) {
    int ok = true;

    // area identifiers
    //
    if(list.isRegistered(-1)) {
        testFailed("isRegistered(-1) did not return false", ++testNo, &ok,
         tested);
    } else
        testPassed("isRegistered(-1)", ++testNo, passed, tested);

    if(list.isRegistered(99955)) {
        testFailed("isRegistered(99955) did not return false", ++testNo, &ok,
         tested);
    } else
        testPassed("isRegistered(99955)", ++testNo, passed, tested);

    if(!list.isRegistered(0)) {
        testFailed("isRegistered(0) did not return true", ++testNo, &ok,
         tested);
    } else
        testPassed("isRegistered(0)", ++testNo, passed, tested);

    // publisher identifiers
    //
    if(list.isRegistered(-1, "0")) {
        testFailed("isRegistered(-1, 0) did not return false", ++testNo, &ok,
         tested);
    } else
        testPassed("isRegistered(-1, 0)", ++testNo, passed, tested);

    if(list.isRegistered(99955, "0")) {
        testFailed("isRegistered(99955, 0) did not return false", ++testNo,
         &ok, tested);
    } else
        testPassed("isRegistered(99955, 0)", ++testNo, passed, tested);

    if(!list.isRegistered(0, "10")) {
        testFailed("isRegistered(0, 10) did not return true", ++testNo, &ok,
         tested);
    } else
        testPassed("isRegistered(0, 10)", ++testNo, passed, tested);

    if(list.isRegistered(99955, "0")) {
        testFailed("isRegistered(99955, 0) did not return false", ++testNo,
         &ok, tested);
    } else
        testPassed("isRegistered(99955, 0)", ++testNo, passed, tested);

    if(list.isRegistered(0, "95000000")) {
        testFailed("isRegistered(0, 95000000) did not return false", ++testNo,
         &ok, tested);
    } else
        testPassed("isRegistered(0, 95000000)", ++testNo, passed, tested);

    // minimum number of digits
    //
    if(list.minNoDigits(-1) != 0) {
        testFailed("minNoDigits(-1) did not return 0", ++testNo, &ok,
         tested);
    } else
        testPassed("minNoDigits(-1)", ++testNo, passed, tested);

    if(list.minNoDigits(0) != 2) {
        testFailed("minNoDigits(0) did not return 2", ++testNo, &ok,
         tested);
    } else
        testPassed("minNoDigits(0)", ++testNo, passed, tested);

    if(list.minNoDigits(92) != 1) {
        testFailed("minNoDigits(92) did not return 1", ++testNo, &ok,
         tested);
    } else
        testPassed("minNoDigits(92)", ++testNo, passed, tested);

    if(list.minNoDigits(99955) != 0) {
        testFailed("minNoDigits(99955) did not return 0", ++testNo, &ok,
         tested);
    } else
        testPassed("minNoDigits(99955)", ++testNo, passed, tested);

    return ok;
}

/* EANTests performs tests on the EAN class and returns false for invalid
*  results
*  *passed - total number of tests passed
*  *tested - total number of tests attempted
*/
int EANTests(const Prefix& list, int& testNo, int* passed, int* tested) {
    int  ok = true;
    EAN ean, safe;
    char stra[18], strb[18];

    // EAN()
    //
    ean = EAN();
    if(ean.empty() == 0) {
        testFailed("empty() did not return true for EAN()", ++testNo, &ok,
         tested);
    } else
        testPassed("EAN() and empty()", ++testNo, passed, tested);

    if(ean.isRegistered() != 0) {
        testFailed("isRegistered() did not return false for EAN()", ++testNo,
         &ok, tested);
    } else
        testPassed("EAN() and isRegistered()", ++testNo, passed, tested);

    // EAN("9070002043", list)
    //
    ean = EAN("9789070002046", list);
    if(ean.empty() != 0) {
        testFailed("empty() did not return false for 9789070002046", ++testNo,
         &ok, tested);
    } else
        testPassed("EAN(\"9789070002046\", ) and empty()", ++testNo, passed,
         tested);

    if(ean.isRegistered() == 0) {
        testFailed("isRegistered() did not return true for 9789070002046",
         ++testNo, &ok, tested);
    } else
        testPassed("EAN(\"9789070002046\", ) and isRegistered()", ++testNo,
         passed, tested);

    // EAN("9789070002043", list)
    //
    ean = EAN("9789070002043", list);
    if(ean.empty() == 0) {
        testFailed("empty() did not return true for 9789070002043", ++testNo,
         &ok, tested);
    } else
        testPassed("EAN(9789070002043) and empty()", ++testNo, passed,
         tested);

    if(ean.isRegistered() != 0) {
        testFailed("isRegistered() did not return false for 9789070002043",
         ++testNo, &ok, tested);
    } else
        testPassed("EAN(\"9789070002043\", ) and isRegistered()", ++testNo,
         passed, tested);

    safe.toStr(stra);
    ean.toStr(strb);
    if (strcmp(stra, strb)) {
        testFailed("toStr does not return same string for EAN() and "
         "EAN(\"9789070002043\", )", ++testNo, &ok, tested);
    } else
        testPassed("toStr on EAN() and IBSN(\"9789070002043\", )", ++testNo,
         passed, tested);

    // toStr
    //
    ean = EAN("9789070002046", list);
    ean.toStr(stra);
    if(strcmp(stra, "9789070002046") != 0) {
        testFailed("toStr did not return 9789070002046", ++testNo, &ok,
         tested);
    } else
        testPassed("EAN(9789070002046) and toStr(char*)", ++testNo, passed,
         tested);

    ean = EAN("9789070002043", list);
    ean.toStr(strb);
    if(!strcmp(strb, "9789070002043")) {
        testFailed("toStr didn\'t return a string different from 9070002046",
         ++testNo, &ok, tested);
    } else
        testPassed("EAN(...) and toStr(char*)", ++testNo, passed, tested);

    ean = EAN("9789070002046", list);
    ean.style(' ');
    ean.toStr(stra);
    if(strcmp(stra, "9789070002046")) {
        testFailed("toStr did not return 9789070002046", ++testNo, &ok,
         tested);
    } else
        testPassed("EAN(9789070002046), style(' ') and toStr(char*)",
         ++testNo, passed, tested);

    ean.style('\0');
    ean.toStr(stra);
    if(strcmp(stra, "9789070002046")) {
        testFailed("toStr did not return 9789070002046", ++testNo, &ok,
         tested);
    } else
        testPassed("EAN(9789070002046), style('\\0') and toStr(char*)",
         ++testNo, passed, tested);

    // toStrWithStyle
    //
    ean = EAN("9789070002046", list);
    ean.toStrWithStyle(stra);
    if(strcmp(stra, "978-90-70002-04-6")) {
        testFailed("toStrWithStyle did not return 978-90-70002-04-6", ++testNo, &ok,
         tested);
    } else
        testPassed("EAN(9789070002046), style('-') and toStrWithStyle(char*)",
         ++testNo, passed, tested);

    ean.style(' ');
    ean.toStrWithStyle(stra);
    if(strcmp(stra, "978 90 70002 04 6")) {
        testFailed("toStrWithStyle did not return 978 90 70002 04 6", ++testNo, &ok,
         tested);
    } else
        testPassed("EAN(9789070002046), style(' ') and toStrWithStyle(char*)",
         ++testNo, passed, tested);

    ean.style('\0');
    ean.toStrWithStyle(stra);
    if(strcmp(stra, "9789070002046")) {
        testFailed("toStrWithStyle did not return 9789070002046", ++testNo, &ok,
         tested);
    } else
        testPassed("EAN(9789070002046), style('\\0') and toStrWithStyle(char*)",
         ++testNo, passed, tested);

    ean.style('-');
    ean.toStrWithStyle(stra);
    if(strcmp(stra, "978-90-70002-04-6")) {
        testFailed("toStrWithStyle did not return 978-90-70002-04-6", ++testNo, &ok,
         tested);
    } else
        testPassed("EAN(9789070002046), style('-') and toStrWithStyle(char*)",
         ++testNo, passed, tested);

    ean = EAN("9789070002043", list);
    ean.style('\0');
    ean.toStr(stra);
    if(!strcmp(stra, "9789070002043")) {
        testFailed("toStr did not return a string different from 9789070002043 ",
         ++testNo, &ok, tested);
    } else
        testPassed("EAN(9789070002043), style('\\0') and toStr(char*)",
         ++testNo, passed, tested);

    return ok;
}

/* RegisteredTests performs tests on the EAN and EANPrefix classes and
*  returns false for invalid results
*  *passed - total number of tests passed
*  *tested - total number of tests attempted
*/
int RegisteredTests(const Prefix& list, int& testNo, int* passed, int* tested) {
    EAN ean;
    int ok = true;

    ean = EAN("9789070002046", list);
    if(!ean.isRegistered()) {
        testFailed("isRegistered() did not return true for 9789070002046",
         ++testNo, &ok, tested);
    } else
        testPassed("isRegistered() returned true for 9789070002046", ++testNo,
         passed, tested);

    ean = EAN("9789995500009", list);
    if(ean.isRegistered()) {
        testFailed("isRegistered() did not return false for 9789995500009",
         ++testNo, &ok, tested);
    } else
        testPassed("isRegistered() returned false for 9789995500009", ++testNo,
         passed, tested);

    char value[1121][14] = {
     "9780000000002","9780190000004","9780200000000","9780699000000","9780700000005",
     "9780850000009","9780899990002","9780900000003","9780949999009","9780950000008",
     "9780999999905","9781000000009","9781090000002","9781100000008","9781399000000",
     "9781400000005","9781549900006","9781550000009","9781869790004","9781869800000",
     "9781998999002","9781999000004","9781999999902","9782000000006","9782190000008",
     "9782200000004","9782349000002","9782350000008","9782399990001","9782495000000",
     "9782699000004","9782700000009","9782839900003","9782840000006","9782899990006",
     "9782900000007","9782950000002","9782999999909","9783000000003","9783020000007",
     "9783030000004","9783033000001","9783034000000","9783036900001","9783037000007",
     "9783039990009","9783040000001","9783200000001","9783699000001","9783700000006",
     "9783849900007","9783850000000","9783899990003","9783949999000","9783950000009",
     "9784000000000","9784190000002","9784200000008","9784699000008","9784700000003",
     "9784849900004","9784850000007","9784899990000","9784900000001","9784949999007",
     "9784950000006","9784999999903","9785000000007","9785190000009","9785200000005",
     "9785699000005","9785700000000","9785849900001","9785850000004","9785899990007",
     "9785900000008","9785919999003","9785920000002","9785929900006","9785949990001",
     "9785950000003","9785979900001","9785980000004","9785989990009","9785990000001",
     "9785999999900","9787000000001","9787090000004","9787100000000","9787499000001",
     "9787500000006","9787799900001","9787800000003","9787899990001","9787900000002",
     "9787999999003","9788000000008","9788019000006","9788020000002","9788069900004",
     "9788070000007","9788084990004","9788085000009","9788090000001","9788099999900",
     "9788119000005","9788120000001","9788170000006","9788184990003","9788189999001",
     "9788190000000","9788200000006","9788219000004","9788220000000","9788269900002",
     "9788270000005","9788289990007","9788290000009","9788298999008","9788299000000",
     "9788299999908","9788300000005","9788319000003","9788320000009","9788369900001",
     "9788370000004","9788385000006","9788389999009","9788390000008","9788399999907",
     "9788400000004","9788419000002","9788420000008","9788469900000","9788470000003",
     "9788484990000","9788485000005","9788489999008","9788491990000","9788492000005",
     "9788492399901","9788492400003","9788492999002","9788493000004","9788494999901",
     "9788495000002","9788496999008","9788497000000","9788499990002","9788500000003",
     "9788519000001","9788520000007","9788569900009","9788570000002","9788584990009",
     "9788585000004","9788589999007","9788590000006","9788598000008","9788599999004",
     "9788600000002","9788629000007","9788630000003","9788669900008","9788670000001",
     "9788679990006","9788680000008","9788689999006","9788690000005","9788699999904",
     "9788700000001","9788729000006","9788740000009","9788764900002","9788779990005",
     "9788785000002","9788794999007","9788797000007","9788799999903","9788800000000",
     "9788819000008","9788820000004","9788860000002","9788884990006","9788885000001",
     "9788889999004","9788890000003","9788899999902","9788900000009","9788924000009",
     "9788925000008","9788954900003","9788955000009","9788984990005","9788985000000",
     "9788994999005","9788995000007","9788999999901","9789000000005","9789019000003",
     "9789020000009","9789049900007","9789050000000","9789069990002","9789070000004",
     "9789079999002","9789080000001","9789084999905","9789085000006","9789089990006",
     "9789090000008","9789090999906","9789094000004","9789094999902","9789100000004",
     "9789110000001","9789120000008","9789149000003","9789150000009","9789164900005",
     "9789179990008","9789185000005","9789194999000","9789197000000","9789199999906",
     "9789200000003","9789250000008","9789260000005","9789279000003","9789280000009",
     "9789289900003","9789290000006","9789294990006","9789295000001","9789298999005",
     "9789299999905","9789500000000","9789504900009","9789505000005","9789508990006",
     "9789509000001","9789509899001","9789509900004","9789509999909","9789510000007",
     "9789511000006","9789512000005","9789515400000","9789515500007","9789518890006",
     "9789518900002","9789519499000","9789519500003","9789519999906","9789520000004",
     "9789521900006","9789522000002","9789524990004","9789525000009","9789525999006",
     "9789526000008","9789526500003","9789526600000","9789526699004","9789526700007",
     "9789526999906","9789527000007","9789527999004","9789528900009","9789529400003",
     "9789529500000","9789529899005","9789529900008","9789529999903","9789530000001",
     "9789530000001","9789531400008","9789531500005","9789535990000","9789536000005",
     "9789539499004","9789539500007","9789539999900","9789540000008","9789542900009",
     "9789547990005","9789548000000","9789548999007","9789549000009","9789549299908",
     "9789549300000","9789549999006","9789550000005","9789551000004","9789552000003",
     "9789555400008","9789555500005","9789557990002","9789558000007","9789559499008",
     "9789559500001","9789559999904","9789560000002","9789561900004","9789562000000",
     "9789566990000","9789569999000","9789570000009","9789570200003","9789570300000",
     "9789570499001","9789571900001","9789572000007","9789572099001","9789572100004",
     "9789572700006","9789572800003","9789573100003","9789574300006","9789578200005",
     "9789579699006","9789579700009","9789579999908","9789585900004","9789586000000",
     "9789587990003","9789588000008","9789589499009","9789589500002","9789589999905",
     "9789590000003","9789591900005","9789596990001","9789597000006","9789598499007",
     "9789601900001","9789602000007","9789606590009","9789606600005","9789606899003",
     "9789606900006","9789606990007","9789608500006","9789609999908","9789610000006",
     "9789611900008","9789615990005","9789616000000","9789618999005","9789619000007",
     "9789619499900","9789620000003","9789622000001","9789626990001","9789627000006",
     "9789628499007","9789628500000","9789628699902","9789628700004","9789628999002",
     "9789629000004","9789629990008","9789630000000","9789631900002","9789632000008",
     "9789637000003","9789638499004","9789639000001","9789639999008","9789640000007",
     "9789642900008","9789643000004","9789645490001","9789645500007","9789648999006",
     "9789649000008","9789649999906","9789650000004","9789651900006","9789652000002",
     "9789655990003","9789657000007","9789657999004","9789659000005","9789659999903",
     "9789660000001","9789662900002","9789663000008","9789666990009","9789667000004",
     "9789668999000","9789669000002","9789669999900","9789670000008","9789675000003",
     "9789676000002","9789678900003","9789679000009","9789679890006","9789679900002",
     "9789679989007","9789679990003","9789679999907","9789680100002","9789683900005",
     "9789684000001","9789684990005","9789687999005","9789688000007","9789688990001",
     "9789690000002","9789691000001","9789692000000","9789693900002","9789694000008",
     "9789698000004","9789699999000","9789700100005","9789705900006","9789706000002",
     "9789708990004","9789709000009","9789709099003","9789709100006","9789709699906",
     "9789709700008","9789709999006","9789710000005","9789710190003","9789710200009",
     "9789710200009","9789710300006","9789710599004","9789710600007","9789710900008",
     "9789711000004","9789715000000","9789718490006","9789718500002","9789719099000",
     "9789719100003","9789720000002","9789721000001","9789722000000","9789725400005",
     "9789725500002","9789727990009","9789728000004","9789729499005","9789729500008",
     "9789729999901","9789731000008","9789732000007","9789735400002","9789735500009",
     "9789737690005","9789737700001","9789738499003","9789738500006","9789738999909",
     "9789739000000","9789739499002","9789739500005","9789739999908","9789740000006",
     "9789741900008","9789746990004","9789747000009","9789748499000","9789748500003",
     "9789748999906","9789749000007","9789749499900","9789749500002","9789749999004",
     "9789750000003","9789752400009","9789752500006","9789755990002","9789756000007",
     "9789759199005","9789759200008","9789759899905","9789760000000","9789763000007",
     "9789764000006","9789765900008","9789767990007","9789768000002","9789769499003",
     "9789769500006","9789769999909","9789770000007","9789771900009","9789772000005",
     "9789774990007","9789775000002","9789777000000","9789779990002","9789780000004",
     "9789781990007","9789782000002","9789782999009","9789783000001","9789787999905",
     "9789788000006","9789789000005","9789789990009","9789790000001","9789790000001",
     "9789792000009","9789792900002","9789793000008","9789793999005","9789794000007",
     "9789797990008","9789798000003","9789799499004","9789799500007","9789799999900",
     "9789800000007","9789801900009","9789802000005","9789805990006","9789806000001",
     "9789809999005","9789810000004","9789811900006","9789812000002","9789812990006",
     "9789813000001","9789819999002","9789820000001","9789821000000","9789826990009",
     "9789827000004","9789828900006","9789829000002","9789829999009","9789830000008",
     "9789830100005","9789830200002","9789831990001","9789832000006","9789834000004",
     "9789834999902","9789837900004","9789838000000","9789838990004","9789839000009",
     "9789839899009","9789839900002","9789839999907","9789840000005","9789843900005",
     "9789844000001","9789848000007","9789848999004","9789849000006","9789850000002",
     "9789853900002","9789854000008","9789855990001","9789856000006","9789858999001",
     "9789859999901","9789861100005","9789861200002","9789865600006","9789867999009",
     "9789868000001","9789869999908","9789870000006","9789870900009","9789871000005",
     "9789871999002","9789872999902","9789873000003","9789874900005","9789875000001",
     "9789878990002","9789879000007","9789879500002","9789879999905","9789880000003",
     "9789882000001","9789887990000","9789888000005","9789889699000","9789889999902",
     "9789890000000","9789891000009","9789892000008","9789895400003","9789895500000",
     "9789897990007","9789898000002","9789899499003","9789899500006","9789899999909",
     "9789946000008","9789946100005","9789946200002","9789946390000","9789946400006",
     "9789946899008","9789946900001","9789946999906","9789947000007","9789947100004",
     "9789947200001","9789947790007","9789947800003","9789947999004","9789948000006",
     "9789948390008","9789948400004","9789948849001","9789948850007","9789948999904",
     "9789949000005","9789949000005","9789949100002","9789949390007","9789949400003",
     "9789949899005","9789949999903","9789950000001","9789950000001","9789951000000",
     "9789951390002","9789951400008","9789951849005","9789951850001","9789951999908",
     "9789952000009","9789952100006","9789952200003","9789952390001","9789952400007",
     "9789952799002","9789952800005","9789952999907","9789953100005","9789953390000",
     "9789953400006","9789953599007","9789953600000","9789953890005","9789953900001",
     "9789953999906","9789954000007","9789954100004","9789954200001","9789954390009",
     "9789954400005","9789954799000","9789954999905","9789955000006","9789955400004",
     "9789955929000","9789955930006","9789956000005","9789956000005","9789956100002",
     "9789956390007","9789956400003","9789956899005","9789956900008","9789956999903",
     "9789957000004","9789957390006","9789957400002","9789957850005","9789957999902",
     "9789958000003","9789958000003","9789958100000","9789958490002","9789958500008",
     "9789958899003","9789958900006","9789958999901","9789959000002","9789959100009",
     "9789959200006","9789959790002","9789959800008","9789959949004","9789959999900",
     "9789960000008","9789960590004","9789960600000","9789960899008","9789960900001",
     "9789960999906","9789961000007","9789961200001","9789961300008","9789961690000",
     "9789961700006","9789961949009","9789961950005","9789961999905","9789962000006",
     "9789962540007","9789962550006","9789962559900","9789962560005","9789962590002",
     "9789962600008","9789962849001","9789962850007","9789962999904","9789963000005",
     "9789963200009","9789963300006","9789963540006","9789963550005","9789963749003",
     "9789963750009","9789963999903","9789964000004","9789964600006","9789964700003",
     "9789964940003","9789964950002","9789964999001","9789965390005","9789965400001",
     "9789965899003","9789965900006","9789965999901","9789966000002","9789966959003",
     "9789966960009","9789966999900","9789967000001","9789967400009","9789967900004",
     "9789968000000","9789968490009","9789968500005","9789968939003","9789968940009",
     "9789968999908","9789970000005","9789970390007","9789970400003","9789970899005",
     "9789970900008","9789970999903","9789971000004","9789971500009","9789971600006",
     "9789971890001","9789971900007","9789971990008","9789971999902","9789972000003",
     "9789972090004","9789972100000","9789972100000","9789972200007","9789972590009",
     "9789972600005","9789972899003","9789972900006","9789972999901","9789973000002",
     "9789973000002","9789973690005","9789973700001","9789973969002","9789973970008",
     "9789973999900","9789974000001","9789974200005","9789974300002","9789974540002",
     "9789974550001","9789974750005","9789974949904","9789974950009","9789974990005",
     "9789975000000","9789975400008","9789975500005","9789975890007","9789975900003",
     "9789975949002","9789975950008","9789975999908","9789976000009","9789976500004",
     "9789976600001","9789976890006","9789976900002","9789976989007","9789976999006",
     "9789976999907","9789977890005","9789977900001","9789977989006","9789977999906",
     "9789978000007","9789978290002","9789978300008","9789978399002","9789978400005",
     "9789978940006","9789978950005","9789978989005","9789978990001","9789978999905",
     "9789979000006","9789979400004","9789979750000","9789979760009","9789979900009",
     "9789980000002","9789980300003","9789980400000","9789980890009","9789980900005",
     "9789980989000","9789980990006","9789981000001","9789981100008","9789981160002",
     "9789981199903","9789981790001","9789981800007","9789981949003","9789981950009",
     "9789981999909","9789982000000","9789982790000","9789982800006","9789982889001",
     "9789982990004","9789982999908","9789983800005","9789983940008","9789983950007",
     "9789983990003","9789983999907","9789984000008","9789984490007","9789984500003",
     "9789984899008","9789984900001","9789984999906","9789985000007","9789985400005",
     "9789985500002","9789985790007","9789985800003","9789985899007","9789985900000",
     "9789985999905","9789986000006","9789986390008","9789986400004","9789986899006",
     "9789986939900","9789986940005","9789986970002","9789986990000","9789987000005",
     "9789987390007","9789987400003","9789987879007","9789987880003","9789987999903",
     "9789988000004","9789988200008","9789988540005","9789988550004","9789988749002",
     "9789988750008","9789988999902","9789989100000","9789989199004","9789989200007",
     "9789989299902","9789989300004","9789989590009","9789989600005","9789989950001",
     "9789989999901","9789990100006","9789990149005","9789990150001","9789990179903",
     "9789990180008","9789990199000","9789990300000","9789990310009","9789990320008",
     "9789990389005","9789990390001","9789990399905","9789990400007","9789990450002",
     "9789990460001","9789990489002","9789990490008","9789990500004","9789990530001",
     "9789990540000","9789990579000","9789990580006","9789990599909","9789990600001",
     "9789990620009","9789990630008","9789990659009","9789990699906","9789990800005",
     "9789990800005","9789990810004","9789990889000","9789990890006","9789990899900",
     "9789990900002","9789990930009","9789990940008","9789990994001","9789990995008",
     "9789990999907","9789991000008","9789991020006","9789991089003","9789991090009",
     "9789991099903","9789991100005","9789991159003","9789991160009","9789991200002",
     "9789991240008","9789991259901","9789991260006","9789991289007","9789991290003",
     "9789991299907","9789991300009","9789991320007","9789991330006","9789991335001",
     "9789991360409","9789991400006","9789991440002","9789991450001","9789991489001",
     "9789991490007","9789991494906","9789991500003","9789991540009","9789991550008",
     "9789991579009","9789991599908","9789991600000","9789991620008","9789991630007",
     "9789991669007","9789991670003","9789991699905","9789991700007","9789991720005",
     "9789991730004","9789991789002","9789991790008","9789991799902","9789991830001",
     "9789991840000","9789991889009","9789991890005","9789991899909","9789991900001",
     "9789991920009","9789991940007","9789991969008","9789991990002","9789991999906",
     "9789992000007","9789992040003","9789992050002","9789992089002","9789992090008",
     "9789992099902","9789992100004","9789992110003","9789992120002","9789992169001",
     "9789992179901","9789992180006","9789992180006","9789992190005","9789992199008",
     "9789992200001","9789992230008","9789992240007","9789992269008","9789992270004",
     "9789992299906","9789992300008","9789992310007","9789992320006","9789992379004",
     "9789992380000","9789992399903","9789992400005","9789992420003","9789992430002",
     "9789992479001","9789992480007","9789992490006","9789992530009","9789992540008",
     "9789992579008","9789992580004","9789992599907","9789992600009","9789992600009",
     "9789992659007","9789992660003","9789992699904","9789992700006","9789992730003",
     "9789992759004","9789992760000","9789992799901","9789992800003","9789992800003",
     "9789992810002","9789992879009","9789992880005","9789992899908","9789992900000",
     "9789992900000","9789993000006","9789993040002","9789993050001","9789993079002",
     "9789993080008","9789993099901","9789993100003","9789993140009","9789993150008",
     "9789993179009","9789993180005","9789993199908","9789993210009","9789993259008",
     "9789993260004","9789993269908","9789993270003","9789993270003","9789993280002",
     "9789993299004","9789993300007","9789993320005","9789993330004","9789993359005",
     "9789993360001","9789993399902","9789993400004","9789993410003","9789993479000",
     "9789993480006","9789993499909","9789993500001","9789993520009","9789993559009",
     "9789993560005","9789993579908","9789993580003","9789993580003","9789993590002",
     "9789993600008","9789993600008","9789993610007","9789993659006","9789993660002",
     "9789993700005","9789993710004","9789993720003","9789993759003","9789993760009",
     "9789993799900","9789993800002","9789993820000","9789993830009","9789993859000",
     "9789993899907","9789993900009","9789993950004","9789993960003","9789993989004",
     "9789993990000","9789993999904","9789994000005","9789994000005","9789994069002",
     "9789994070008","9789994099900","9789994100002","9789994130009","9789994190003",
     "9789994199907","9789994300006","9789994320004","9789994330003","9789994359004",
     "9789994360000","9789994400003","9789994440009","9789994479009","9789994480005",
     "9789994480005"};
    for (int i = 0; i < 1121; i++) {
        ean = EAN(value[i], list);
        std::ostringstream so;
        if(!ean.isRegistered()) {
            so << "isRegistered() did not return true for " << value[i];
            testFailed(so.str().c_str(), ++testNo, &ok, tested);
        } else if (i%100 == 0) {
            so << "isRegistered() returned true for " << value[i];
            testPassed(so.str().c_str(), ++testNo, passed, tested);
        } else {
            testPassed("", ++testNo, passed, tested);
        }
    }
    return ok;
}

/* OrderTests performs tests on the Order class and returns false for any
*  invalid results
*  *passed - total number of tests passed
*  *tested - total number of tests attempted
*/
#if TEST_LEVEL == ORDER || TEST_LEVEL == SPECIAL_ORDER
int OrderTests(const Prefix& list, int& testNo, int* passed, int* tested) {
    Order order;
    int ok = true;

    // Order()
    //
    if(!(order.getEAN() == EAN())) {
        testFailed("*Order()->getEAN() == EAN() did not return true", ++testNo,
         &ok, tested);
    } else
        testPassed("*Order()->getEAN() == EAN() returned true", ++testNo, passed,
         tested);

    if(order.outstanding() != 0) {
        testFailed("Order(), outstanding() did not return 0", ++testNo, &ok,
         tested);
    } else
        testPassed("Order(), outstanding() returned 0", ++testNo, passed,
         tested);

    // Order(EAN(9789070002046, ))
    //
	EAN ean("9789070002046", list);
    order = Order(EAN("9789070002046", list));
    if(!(order.getEAN() == ean) || order.outstanding() != 0) {
        testFailed("Order(EAN(9789070002046, list)), outstanding()",
         ++testNo, &ok, tested);
    } else
        testPassed("Order(EAN(9789070002046, list)), outstanding()", ++testNo, passed,
         tested);

    order = Order(EAN("9789070002046", list));
    order.add(5);
    if(!(order.getEAN() == ean) || order.outstanding() != 5) {
        testFailed("Order(EAN(9789070002046, list)), outstanding()",
         ++testNo, &ok, tested);
    } else
        testPassed("Order(EAN(9789070002046, list)), outstanding()", ++testNo, passed,
         tested);

    // Order(EAN(9789070002043, ))
    //
	ean = EAN();
    order = Order(EAN("9789070002043", list));
    if(!(order.getEAN() == ean) || order.outstanding() != 0) {
        testFailed("Order(EAN(9789070002046, list)), outstanding()",
         ++testNo, &ok, tested);
    } else
        testPassed("Order(EAN(9789070002046, list)), outstanding()", ++testNo, passed,
         tested);

    order.add(5);
    if(!(order.getEAN() == ean) || order.outstanding() != 0) {
        testFailed("Order(EAN(9789070002046, list)), add(5), outstanding()",
         ++testNo, &ok, tested);
    } else
        testPassed("Order(EAN(9789070002046, list)), add(5), outstanding()", ++testNo, passed,
         tested);

    return ok;
}
#endif

#if TEST_LEVEL == SPECIAL_ORDER
/* SpecialOrderTests performs tests on the Order class and returns false for any
*  invalid results
*  *passed - total number of tests passed
*  *tested - total number of tests attempted
*/
int SpecialOrderTests(const Prefix& list, int& testNo, int* passed, int* tested) {
    int ok = true;
    SpecialOrder order0, specialOrder;
    SpecialOrder order1(EAN("9789070002046", list), "note");
    SpecialOrder order2(EAN("9789070002046", list), "note");
    order2.Order::add(5);
    //SpecialOrder order3(EAN("9789070002046", list), 20, 25, "note");
    //SpecialOrder order4(EAN("9789070002046", list), -1, 0, "note");
    SpecialOrder order5(EAN("9789070002043", list), "note");
    SpecialOrder order6(EAN("9789070002043", list), "note");
    order6.Order::add(5);

    // SpecialOrder()
    //
    if(!(order0.getEAN() == EAN())) {
        testFailed("SpecialOrder().getEAN() == EAN() did not return true",
         ++testNo, &ok, tested);
    } else
        testPassed("SpecialOrder().getEAN() == EAN() returned true", ++testNo,
         passed, tested);

    if(order0.outstanding() != 0) {
        testFailed("SpecialOrder().outstanding() did not return 0", ++testNo,
         &ok, tested);
    } else
        testPassed("SpecialOrder().outstanding() returned 0", ++testNo, passed,
         tested);

    // SpecialOrder(EAN(9789070002046, ), "note")
    //
    if(!(order1.getEAN() == EAN("9789070002046", list)) || order1.outstanding() != 0) {
        testFailed("getEAN() == EAN(\"9789070002046\", ), outstanding()",
         ++testNo, &ok, tested);
    } else
        testPassed("getEAN() == EAN(\"9789070002046\"), outstanding()", ++testNo, passed,
         tested);

    if(!(order2.getEAN() == EAN("9789070002046", list)) || order2.outstanding() != 5) {
        testFailed("getEAN() == EAN(\"9789070002046\", ), add(5), outstanding()",
         ++testNo, &ok, tested);
    } else
        testPassed("getEAN() == EAN(\"9789070002046\"), add(5), outstanding()", ++testNo, passed,
         tested);

    /*if(order3.has(EAN("9789070002046", list)) != 0 || order3.outstanding() != 0) {
        testFailed("has(EAN(\"9789070002046\", ), 20, 25), outstanding()",
         ++testNo, &ok, tested);
    } else
        testPassed("has(\"9789070002046\"), outstanding()", ++testNo, passed,
         tested);

    if(order4.has(EAN("9789070002046", list)) != 0 || order4.outstanding() != 0) {
        testFailed("has(EAN(\"9789070002046\", ), -1, 0), outstanding()",
         ++testNo, &ok, tested);
    } else
        testPassed("has(\"9789070002046\"), outstanding()", ++testNo, passed,
         tested);
    */

    // SpecialOrder(EAN(9789070002043, ), "note")
    //
    if(!(order5.getEAN() == EAN("9789070002043", list)) || order5.outstanding() != 0) {
        testFailed("getEAN() == EAN(EAN(\"9789070002043\", ), outstanding()",
         ++testNo, &ok, tested);
    } else
        testPassed("getEAN() == EAN(\"9789070002043\"), outstanding()", ++testNo, passed,
         tested);

    if(!(order6.getEAN() == EAN("9789070002043", list)) || order6.outstanding() != 0) {
        testFailed("getEAN() == EAN(\"9789070002043\", ), add(5), outstanding()",
         ++testNo, &ok, tested);
    } else
        testPassed("getEAN() == EAN(\"9789070002043\"), add(5), outstanding()", ++testNo, passed,
         tested);

    if(!(order6.getEAN() == EAN())) {
        testFailed("SpecialOrder().getEAN() ==  EAN() did not return true",
         ++testNo, &ok, tested);
    } else
        testPassed("SpecialOrder().getEAN() ==  EAN() returned true", ++testNo, passed,
         tested);

    // assignment operator
    //
    order0 = order1;
    if(!(order0.getEAN() == EAN("9789070002046", list) && order0.outstanding() == 0)) {
        testFailed("Assignment operator - EAN(\"9789070002046\"), outstanding()", ++testNo, &ok,
         tested);
    } else
        testPassed("Assignment operator - EAN(\"9789070002046\")), outstanding()", ++testNo,
         passed, tested);

    // add(int)
    //
    order0.Order::add(1);
    if(order0.outstanding() != 1) {
        testFailed("++, outstanding()", ++testNo, &ok, tested);
    } else
        testPassed("++, outstanding()", ++testNo, passed, tested);

    // copy constructor
    //
    SpecialOrder s = order0;
    if(!(s.getEAN() == EAN("9789070002046", list) && s.outstanding() == 1)) {
        testFailed("Copy constructor - EAN(\"9789070002046\"), outstanding()", ++testNo, &ok,
         tested);
    } else
        testPassed("Copy constructor - EAN(\"9789070002046\")), outstanding()", ++testNo,
         passed, tested);

    // constructor - safe state
    //
    SpecialOrder c(EAN("9789070002043", list), "constructor");
    if(!(c.getEAN() == EAN() && c.outstanding() == 0)) {
        testFailed("Ctor safe state - EAN(\"9789070002043\"), outstanding()", ++testNo, &ok,
         tested);
    } else
        testPassed("Ctor safe state - EAN(\"9789070002043\")), outstanding()", ++testNo,
         passed, tested);

    return ok;
}
#endif

/* testPassed displays passing message, increments *passed and *total
*  i holds test number
*/
void testPassed(const char* message, int i, int* passed, int* total) {
    if (DEBUG && message[0] != '\0')
        std::cout << "Passed test " << std::setw(4) << i << " (" << message << ")\n";
    ++*passed;
    ++*total;
}

/* testFailed displays failure message, resets *ok to false, increments
*  *total i holds test number
*/
void testFailed(const char* message, int i, int* ok, int* total) {
    std::cout << "Failed test " << std::setw(4) << i << " (" << message << ")\n";
    *ok = false;
    ++*total;
}