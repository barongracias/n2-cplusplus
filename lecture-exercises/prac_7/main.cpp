#include <cassert>
#include "date.hpp"

int main(void) {
    Date startOfTerm(6, 10, 2023);
    startOfTerm.advance();

    assert( startOfTerm.getDay() == 7 );
    assert( startOfTerm.getMonth() == 10 );
    assert( startOfTerm.getYear() == 2023 );
    
    Date halloween(31, 10, 2023);
    halloween.advance();
    
    assert( halloween.getDay() == 1 );
    assert( halloween.getMonth() == 11 );
    assert( halloween.getYear() == 2023 );
    
    /* This should fail (exit) at run−time because
    there is no 31st November. */
    halloween.setDay(31);
    
    // This should succeed
    halloween.set(31, 10, 2023);
    
    /* This should fail (exit) at run−time because
    there is no 31st November. */
    halloween.setMonth(11);
    
    Date startOfYear(1, 1, 2024);
    startOfYear.back();
    assert( startOfYear.getDay() == 31 );
    assert( startOfYear.getMonth() == 12 );
    assert( startOfYear.getYear() == 2023 );
    
    const Date endOfYear = startOfYear;
    assert(endOfYear.getDay() == 31);
    
    // Should fail at *compile−time*
    // endOfYear.setMonth(10);
    // Should fail at *compile−time*
    // endOfYear = halloween;
}