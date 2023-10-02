
#ifndef LABORATORY1_1_ENUMS_H
#define LABORATORY1_1_ENUMS_H

enum input_status_code{
    isc_invalid_parametr,
    isc_therearent_number,
    isc_need_help,
    isc_too_many_parameters,
    isc_h,
    isc_p,
    isc_s,
    isc_e,
    isc_a,
    isc_f,
};



enum p_status_code{
    psc_negative,
    psc_zero,
    psc_simple,
    psc_complicated,
    psc_one
};



enum s_status_code{
    ssc_normal,
    ssc_bad_input
};


enum e_status_code{
    esc_inappropriate,
    esc_normal
};


enum a_status_code{
    asc_normal,
    asc_negative
};


enum factorial_status_codes
{
    fsc_ok,
    fsc_invalid_parameter
};


#endif //LABORATORY1_1_ENUMS_H
