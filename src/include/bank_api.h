#if defined(_WIN32)
#   define __export         __declspec(dllexport)
#elif defined(__GNUC__) && ((__GNUC__ >= 4) || (__GNUC__ == 3 && __GNUC_MINOR__ >= 3))
#   define __export         __attribute__((visibility("default")))
#else
#   define __export
#endif




//TODO: re-design for dynamic PIN length 
/*! calculate BANK_CHECK_PIN(int i1, int i2, int i3, int i4)
 *
 * @param i1~i4 PIN Number
 *
 * @return      0 : PIN Number is Correct
 *            500 : PIN Number is Correct
 */
__export int    BANK_CHECK_PIN(int i1, int i2, int i3, int i4);


